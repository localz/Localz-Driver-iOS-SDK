//
//  ViewController.swift
//  SampleLocalzDriverApp-Swift
//
//  Created by Daniel Sykes-Turner on 25/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var txtOrderNumber: UITextField!
    @IBOutlet weak var btnDriverOnDuty: UIButton!
    var orders: [LocalzDriverOrder]! = [LocalzDriverOrder]()
    
    let driverUsername = "enter_driver_username_here"
    let driverPassword = "enter_driver_password_here"

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.tableView.delegate = self
        self.tableView.dataSource = self
        
        LocalzDriverSDK.shared().login(withUsername: driverUsername, password: driverPassword, branchId: nil, force: true, options: nil) { (error:Error?, attendant:LocalzDriverAttendant?) in
            print("User logged in")
            self.reloadOrders()
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func reloadOrders() {
        
        var component = DateComponents()
        component.year = 1
        let nextYear = NSCalendar.current.date(byAdding: component, to: Date())
        component.year = -1
        let lastYear = NSCalendar.current.date(byAdding: component, to: Date())
        
        LocalzDriverSDK.shared().retrieveOrders(from: lastYear, to: nextYear) { (error:Error?, orders:[Any]?) in
            if let orders = orders as? [LocalzDriverOrder] {
                self.orders = orders
            }
            self.tableView.reloadData()
        }
    }
    
    // MARK: - Driver Handling
    
    @IBAction func toggleDriverOnDuty() {
        
        let onDuty = LocalzDriverSDK.shared().isOnDuty()
        LocalzDriverSDK.shared().onDuty(!onDuty) { (error:Error?) in
            let isOnDutyStr = LocalzDriverSDK.shared().isOnDuty() ? "Is On Duty" : "Is Not On Duty"
            self.btnDriverOnDuty.setTitle(isOnDutyStr, for: UIControlState.normal)
        }
    }
    
    // MARK: - Order Flow
    
    @IBAction func createOrder() {
        
        let orderNumber:String! = self.txtOrderNumber.text
        if orderNumber == "" {
            let alert = UIAlertController.init(title: "No Order Number", message: "Please enter a number to create an order", preferredStyle: UIAlertControllerStyle.alert)
            alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: nil))
            self.present(alert, animated: true, completion: nil)
        } else {
            let order:LocalzDriverOrder! = LocalzDriverOrder.init(data: [
                "orderNumber":orderNumber,
                "specific":[
                        "address":"412 Collins St, Melbourne, Victoria"
                    ]
                ])
            
            LocalzDriverSDK.shared().createOrUpdate(order) { (error:Error?) in
                self.reloadOrders()
            }
        }
        
        self.txtOrderNumber.resignFirstResponder()
    }
    
    func trackOrder(orderNumber: String!) {
        
        LocalzDriverSDK.shared().sendEtaNotification(orderNumber, etaBufferInMinutes: 0) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    func acknowledgeOrder(orderNumber: String!) {
        
        LocalzDriverSDK.shared().acknowledgeOrder(orderNumber) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    func completeOrder(orderNumber: String!) {
        
        LocalzDriverSDK.shared().completeOrderNumber(orderNumber, signature: nil, notes: nil) { (error:Error?) in
            self.reloadOrders()
        }
    }
    
    // MARK: - UITableViewDataSource
    
    func numberOfSections(in tableView: UITableView) -> Int {
        
        return 1
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return self.orders.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var cell = tableView.dequeueReusableCell(withIdentifier: "cell")
        if cell == nil {
            cell = UITableViewCell.init(style: UITableViewCellStyle.subtitle, reuseIdentifier: "cell")
        }
        
        let order = self.orders[indexPath.row]
        cell?.textLabel?.text = order.orderNumber
        cell?.detailTextLabel?.text = order.status
        
        return cell!
    }
    
    // MARK: - UITableViewDelegate
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.deselectRow(at: indexPath, animated: true)
        
        let order = self.orders[indexPath.row]
        if order.status == ORDER_STATUS_PENDING || order.status == ORDER_STATUS_READY {
            self.trackOrder(orderNumber: order.orderNumber)
        } else if order.status == ORDER_STATUS_UNASSIGNED {
            self.acknowledgeOrder(orderNumber: order.orderNumber)
        } else if order.status == ORDER_STATUS_ASSIGNED {
            self.completeOrder(orderNumber: order.orderNumber)
        } else {
            print("Unhandled order status: \(order.status)")
        }
    }
}


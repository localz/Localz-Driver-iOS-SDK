//
//  AppDelegate.swift
//  SampleLocalzDriverApp-Swift
//
//  Created by Daniel Sykes-Turner on 25/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, LocalzDriverSDKDelegate {

    var window: UIWindow?
    let spotzAppId = "enter_spotz_app_id_here"
    let spotzAppKey = "enter_spotz_app_key_here"
    let spotzCNCKey = "enter_spotz_cnc_key_here"

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        LocalzDriverSDK.initWithAppId(spotzAppId, appKey: spotzAppKey, cncKey: spotzCNCKey, delegate: self, options: nil)
        
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }

    // MARK: - LocalzDriverSDKDelegate
    
    func localzDriverSDKInit(_ error: Error?) {
        if let error = error {
            print("LocalzDriverSDK init failed with error \(error)");
        } else {
            print("LocalzDriverSDK init successful");
        }
    }
    
    func localzDriverSDKSiteInit(_ error: Error?) {
        if let error = error {
            print("LocalzDriverSDK site init failed with error \(error)");
        } else {
            print("LocalzDriverSDK site init successful");
        }
    }
}


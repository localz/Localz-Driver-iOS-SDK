//
//  ViewController.m
//  SampleLocalzDriverApp-ObjC
//
//  Created by Daniel Sykes-Turner on 25/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import "ViewController.h"
#import <LocalzDriverSDK/LocalzDriverSDK.h>

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, weak) IBOutlet UITableView *tableView;
@property (nonatomic, weak) IBOutlet UITextField *txtOrderNumber;
@property (nonatomic, weak) IBOutlet UIButton *btnDriverOnDuty;
@property (nonatomic, strong) NSMutableArray *orders;
@property (nonatomic, strong) NSString *driverUsername;
@property (nonatomic, strong) NSString *driverPassword;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.driverUsername = @"enter_driver_username_here";
    self.driverPassword = @"enter_driver_password_here";

    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    [[LocalzDriverSDK shared] loginWithUsername:self.driverUsername password:self.driverPassword branchId:nil force:true options:nil completion:^(NSError * _Nullable error, LocalzDriverAttendant * _Nullable user) {
        NSLog(@"User logged in");
        [self reloadOrders];
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)reloadOrders {
    
    NSDateComponents *components = [NSDateComponents new];
    components.year = 1;
    NSDate *nextYear = [[NSCalendar currentCalendar] dateByAddingComponents:components toDate:[NSDate new] options:0];
    components.year = -1;
    NSDate *lastYear = [[NSCalendar currentCalendar] dateByAddingComponents:components toDate:[NSDate new] options:0];
    
    [[LocalzDriverSDK shared] retrieveOrdersFromDate:lastYear toDate:nextYear completion:^(NSError * _Nullable error, NSArray * _Nullable orders) {
        self.orders = orders.mutableCopy;
        [self.tableView reloadData];
    }];
}

#pragma mark - Driver Handling

- (IBAction)toggleDriverOnDuty:(id)sender {

    BOOL onDuty = [[LocalzDriverSDK shared] isOnDuty];
    [[LocalzDriverSDK shared] onDuty:!onDuty completion:^(NSError * _Nullable error) {
        NSString *isOnDutyStr = [[LocalzDriverSDK shared] isOnDuty] ? @"Is On Duty" : @"Is Not On Duty";
        [self.btnDriverOnDuty setTitle:isOnDutyStr forState:UIControlStateNormal];
    }];
}

#pragma mark - Order Flow

- (IBAction)createOrder:(id)sender {
    
    NSString *orderNumber = self.txtOrderNumber.text;
    if (orderNumber.length == 0) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"No Order Number" message:@"Please enter a number to create an order" preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
        [self presentViewController:alert animated:true completion:nil];
    } else {
        LocalzDriverOrder *order = [[LocalzDriverOrder alloc] initWithData:@{
                                                                             @"orderNumber":orderNumber,
                                                                             @"specific":@{
                                                                                     @"address":@"412 Collins Street, Melbourne, Victoria"
                                                                                     }
                                                                             }];
        
        [[LocalzDriverSDK shared] createOrUpdateOrder:order completion:^(NSError * _Nullable error) {
            [self reloadOrders];
        }];
    }
    
    [self.txtOrderNumber resignFirstResponder];
}

- (void)trackOrder:(NSString *)orderNumber {
    
    [[LocalzDriverSDK shared] sendEtaNotification:orderNumber etaBufferInMinutes:0 completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

- (void)acknowledgeOrder:(NSString *)orderNumber {
    
    [[LocalzDriverSDK shared] acknowledgeOrder:orderNumber completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

- (void)completeOrder:(NSString *)orderNumber {
    
    [[LocalzDriverSDK shared] completeOrderNumber:orderNumber signature:nil notes:nil completion:^(NSError * _Nullable error) {
        [self reloadOrders];
    }];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return self.orders.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cell"];
    }
    
    LocalzDriverOrder *order = self.orders[indexPath.row];
    cell.textLabel.text = order.orderNumber;
    cell.detailTextLabel.text = order.status;
    
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    
    LocalzDriverOrder *order = self.orders[indexPath.row];
    if ([order.status isEqualToString:ORDER_STATUS_PENDING] || [order.status isEqualToString:ORDER_STATUS_READY]) {
        [self trackOrder:order.orderNumber];
    } else if ([order.status isEqualToString:ORDER_STATUS_UNASSIGNED]) {
        [self acknowledgeOrder:order.orderNumber];
    } else if ([order.status isEqualToString:ORDER_STATUS_ASSIGNED]) {
        [self completeOrder:order.orderNumber];
    } else {
        NSLog(@"Unhandled order status: %@", order.status);
    }
}

@end

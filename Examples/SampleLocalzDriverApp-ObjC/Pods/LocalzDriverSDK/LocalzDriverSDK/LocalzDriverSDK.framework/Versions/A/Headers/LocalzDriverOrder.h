//
//  LocalzDriverOrder.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 4/09/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverOrderItem.h"

extern NSString * const ORDER_STATUS_PENDING;
extern NSString * const ORDER_STATUS_PENDING_PACKED;
extern NSString * const ORDER_STATUS_UNASSIGNED;
extern NSString * const ORDER_STATUS_ASSIGNED;
extern NSString * const ORDER_STATUS_COMPLETE;
extern NSString * const ORDER_STATUS_READY;

@interface LocalzDriverOrder : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *deliveryName;
@property (nonatomic, readonly, strong) NSString *deliveryEmail;
@property (nonatomic, readonly, strong) NSString *deliveryPhone;
@property (nonatomic, readonly, strong) NSString *deliveryAddress;
@property (nonatomic, readonly, strong) NSString *orderAmount;
@property (nonatomic, readonly, strong) NSDate *orderDate;
@property (nonatomic, readonly, strong) NSString *orderNumber;
@property (nonatomic, readonly, strong) NSDate *expectedDateFrom;
@property (nonatomic, readonly, strong) NSDate *expectedDateTo;
@property (nonatomic, readonly, strong) NSString *shopperId;
@property (nonatomic, readonly, strong) NSString *selectedPickupId;
@property (nonatomic, readonly, strong) NSNumber *totalItems;
@property (nonatomic, readonly, strong) NSDictionary *specific;
@property (nonatomic, readonly, strong) NSString *locationId;
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSArray *orderItems;
@property (nonatomic, readonly, strong) NSDate *checkinDate;
@property (nonatomic, readonly, strong) NSString *checkinMethod;
@property (nonatomic, readonly, strong) NSString *pickupLocation;
@property (nonatomic, readonly, strong) NSString *status;
@property (nonatomic, readonly) BOOL shouldGiveFeedback; // whether the user should provide feedback on the order after completion
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;

- (LocalzDriverOrder *)initWithData:(NSDictionary *)data;

/**
 * Is order is still within the expected period?
 * @returns False if order is outside the expected period, true if it is still within.
 */
- (BOOL) isWithinExpectedWindow;

- (void) updateOrderItems:(NSArray *)items;

/**
 * Updates the order status. If status == LocalzDriverOrderStatusComplete, all orderItems are set to status "COMPLETE".
 * NOTE 1: This may not be the desired outcome as orderItem.status == PENDING should not be COMPLETED
 * Instead use completOrderIfReady which will only complete those orderItem with status of READY
 * NOTE 2: moving from complete status to other statuses will not revert the orderItem's status
 */
- (void) updateStatus:(NSString *)status;

/**
 * This completes orderItem.status == READY to COMPLETE and set the orderStatus = LocalzDriverOrderStatusComplete
 * if all orderItems are COMPLETE and LocalzDriverOrderStatusNotReady if only some are COMPLETE
 */
- (void) completeOrderIfReady;
@end

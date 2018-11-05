//
//  LocalzDriverOrder.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 4/09/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverOrderItem.h"
#import "LocalzDriverOrderAddress.h"
#import "LocalzDriverOrderLocation.h"

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
@property (nonatomic, readonly, strong) NSNumber *orderAmount;
@property (nonatomic, readonly, strong) NSDate *orderDate;
@property (nonatomic, readonly, strong) NSString *orderNumber;
@property (nonatomic, readonly, strong) NSDate *pickupStart;
@property (nonatomic, readonly, strong) NSDate *pickupEnd;
@property (nonatomic, readonly, strong) NSDate *expectedDateFrom __deprecated_msg("Please use 'pickupStart' instead");
@property (nonatomic, readonly, strong) NSDate *expectedDateTo __deprecated_msg("Please use 'pickupEnd' instead");
@property (nonatomic, readonly, strong) NSString *shopperId;
@property (nonatomic, readonly, strong) NSNumber *totalItems;
@property (nonatomic, readonly, strong) NSDictionary *specific;
@property (nonatomic, readonly, strong) NSString *locationId __deprecated_msg("Please use location.locationId instead");
@property (nonatomic, readonly, strong) NSString *branchId __deprecated_msg("Please use location.branchId instead");
@property (nonatomic, readonly, strong) NSArray *items;
@property (nonatomic, readonly, strong) NSArray *orderItems __deprecated_msg("Please use 'items' instead");
@property (nonatomic, readonly, strong) NSString *pickupLocation;
@property (nonatomic, readonly, strong) NSString *orderStatus;
@property (nonatomic, readonly, strong) NSString *status __deprecated_msg("Please use 'orderStatus' instead");
@property (nonatomic, readonly) BOOL shouldGiveFeedback __deprecated_msg("'shouldGiveFeedback' is no longer supported");
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSString *secondaryReference;
@property (nonatomic, readonly, strong) NSArray *customerInstructions;
@property (nonatomic, readonly, strong) NSArray *nominees;
@property (nonatomic, readonly, strong) LocalzDriverOrderAddress *address;
@property (nonatomic, readonly, strong) LocalzDriverOrderLocation *location;


- (LocalzDriverOrder *) initWithData:(NSDictionary *)data;

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

- (NSDictionary *) toJSON;

@end

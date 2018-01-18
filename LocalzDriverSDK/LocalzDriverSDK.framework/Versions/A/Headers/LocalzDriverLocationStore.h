//
//  LocalzDriverLocationStore.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 24/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverLocationStorePickup.h"

@interface LocalzDriverLocationStore : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *identifier;
@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *defaultPickupId;
@property (nonatomic, readonly, strong) NSArray *workingHours;
@property (nonatomic, readonly, strong) NSNumber *latitude;
@property (nonatomic, readonly, strong) NSNumber *longitude;
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSString *siteId;
@property (nonatomic, readonly, strong) NSString *address;
@property (nonatomic, readonly, strong) NSDictionary<NSString *,LocalzDriverLocationStorePickup *> *locationPickups;
@property (nonatomic, readonly, strong) NSString *timezone;

- (instancetype)initWithData:(NSDictionary *)data;

@end

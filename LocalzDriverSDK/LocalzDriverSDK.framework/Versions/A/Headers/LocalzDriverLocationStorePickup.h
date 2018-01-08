//
//  LocalzDriverLocationStorePickup.h
//  LocalzDriverLocationStorePickup
//
//  Created by Daniel Sykes-Turner on 4/09/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverLocationStorePickup : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *identifier;
@property (nonatomic, readonly, strong) NSString *desc;
@property (nonatomic, readonly, strong) NSString *imgUrl;
@property (nonatomic, readonly, strong) NSString *pickupId;
@property (nonatomic, readonly) BOOL isDefault;
@property (nonatomic, readonly, strong) NSArray *closestSpotIds;

- (LocalzDriverLocationStorePickup *)initWithData:(NSDictionary *)data;

@end

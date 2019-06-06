//
//  LocalzDriverSite.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 14/1/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverOrderAddress.h"

NS_ASSUME_NONNULL_BEGIN

@interface LocalzDriverSite : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *siteId;
@property (nonatomic, readonly, strong) NSString *storeCode;
@property (nonatomic, readonly, strong) NSString *path;
@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly) BOOL isMobile;
@property (nonatomic, readonly, strong) NSNumber *level;
@property (nonatomic, readonly) BOOL isLeaf;
@property (nonatomic, readonly, strong) NSString *phone;
@property (nonatomic, readonly, strong) LocalzDriverOrderAddress *address;
@property (nonatomic, readonly, strong) NSString *desc;
@property (nonatomic, readonly, strong) NSString *timezone;
@property (nonatomic, readonly, strong) NSArray *assignedUsers;
@property (nonatomic, readonly, strong) NSString *parentSiteId;

- (LocalzDriverSite *) initWithData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END

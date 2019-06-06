//
//  LocalzDriverOrderAddress.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 6/7/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverGeoJson.h"

@interface LocalzDriverOrderAddress : NSObject<NSCoding>
@property (nonatomic, readwrite, strong) NSString *country;
@property (nonatomic, readwrite, strong) NSString *region;
@property (nonatomic, readwrite, strong) NSString *postcode;
@property (nonatomic, readwrite, strong) NSString *locality;
@property (nonatomic, readwrite, strong) NSString *streetAddress;
@property (nonatomic, readwrite, strong) NSString *subStreetAddress;
@property (nonatomic, readonly) double latitude;
@property (nonatomic, readonly) double longitude;
@property (nonatomic, readonly, strong) LocalzDriverGeoJson *geoJson;

- (instancetype) initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;
@end

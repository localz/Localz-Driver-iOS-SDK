//
//  LocalzDriverGeoJson.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 11/7/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface LocalzDriverGeoJson : NSObject<NSCoding>

@property (nonatomic, readonly, strong) NSArray *coordinates;
@property (nonatomic, readonly, strong) NSString *type;

- (instancetype)initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;
@end


//
//  LocalzEta.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 1/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

@import CoreLocation;
#import <Foundation/Foundation.h>

@interface LocalzEta : NSObject
@property (nonatomic, readonly, strong) NSString *trackId;
@property (nonatomic, readonly, strong) NSDate *etaFrom;
@property (nonatomic, readonly, strong) NSDate *etaTo;
@property (nonatomic, readonly, strong) NSNumber *seconds;
@property (nonatomic, readonly, strong) NSNumber *minutes;
@property (nonatomic, readonly, strong) NSArray *destinations;

- (instancetype)initWithData:(NSDictionary *)data;
- (NSDictionary *) toDictionary;
@end

@interface LocalzDestEta : NSObject
@property (nonatomic, readonly, strong) NSDate *etaFrom;
@property (nonatomic, readonly, strong) NSDate *etaTo;
@property (nonatomic, readonly, strong) NSNumber *seconds;
@property (nonatomic, readonly, strong) NSNumber *minutes;
@property (nonatomic, readonly) BOOL isVisited;
@property (nonatomic, readonly, strong) CLLocation *location;

- (instancetype)initWithData:(NSDictionary *)data;
- (NSDictionary *) toDictionary;
@end

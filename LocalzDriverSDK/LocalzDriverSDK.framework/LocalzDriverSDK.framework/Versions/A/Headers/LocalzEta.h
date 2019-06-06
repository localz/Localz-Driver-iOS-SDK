//
//  LocalzEta.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 1/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

@interface LocalzEta : NSObject
@property (nonatomic, readonly, strong) NSString *trackId;
@property (nonatomic, readonly, strong) NSDate *etaFrom;
@property (nonatomic, readonly, strong) NSDate *etaTo;
@property (nonatomic, readonly, strong) NSNumber *etaSeconds;
@property (nonatomic, readonly, strong) NSNumber *etaMinutes;
@property (nonatomic, readonly, strong) NSNumber *seconds __deprecated_msg("Please use 'etaSeconds' instead");
@property (nonatomic, readonly, strong) NSNumber *minutes __deprecated_msg("Please use 'etaMinutes' instead");
@property (nonatomic, readonly, strong) NSArray *destinations;

- (instancetype) initWithData:(NSDictionary *)data;
- (NSDictionary *) toDictionary;
@end

@interface LocalzDestEta : NSObject
@property (nonatomic, readonly, strong) NSDate *etaFrom;
@property (nonatomic, readonly, strong) NSDate *etaTo;
@property (nonatomic, readonly, strong) NSNumber *etaSeconds;
@property (nonatomic, readonly, strong) NSNumber *etaMinutes;
@property (nonatomic, readonly, strong) NSNumber *seconds __deprecated_msg("Please use 'etaSeconds' instead");
@property (nonatomic, readonly, strong) NSNumber *minutes __deprecated_msg("Please use 'etaMinutes' instead");
@property (nonatomic, readonly) BOOL visited;
@property (nonatomic, readonly) BOOL isVisited __deprecated_msg("Please use 'visited' instead");
@property (nonatomic, readonly) CLLocationCoordinate2D coordinates;
@property (nonatomic, readonly, strong) CLLocation *location __deprecated_msg("Please use 'coordinates' instead");

- (instancetype) initWithData:(NSDictionary *)data;
- (NSDictionary *) toDictionary;
@end

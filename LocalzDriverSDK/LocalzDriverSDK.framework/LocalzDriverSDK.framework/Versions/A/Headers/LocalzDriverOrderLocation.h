//
//  LocalzDriverOrderLocation.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 25/10/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverOrderLocation : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *locationId;
@property (nonatomic, readonly, strong) NSString *branchId;
@property (nonatomic, readonly, strong) NSString *timezone;
@property (nonatomic, readonly, strong) NSString *desc;

- (LocalzDriverOrderLocation *) initWithData:(NSDictionary *)data;
- (NSDictionary *) toJSON;

@end

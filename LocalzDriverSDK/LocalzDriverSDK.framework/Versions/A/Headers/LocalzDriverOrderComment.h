//
//  LocalzDriverOrderComments.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 31/1/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LocalzDriverOrderComment : NSObject<NSCoding>

@property (nonatomic, readonly, strong) NSString *text;
@property (nonatomic, readonly, strong) NSDate *dateTime;
@property (nonatomic, readonly) BOOL isCustomer;

- (instancetype) initWithData:(id)data;

- (NSDictionary *) toJSON;

@end

NS_ASSUME_NONNULL_END

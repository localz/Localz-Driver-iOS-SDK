//
//  LocalzProofOfDeliveryValue.h
//  LocalzDriverSDK
//
//  Created by Terence Huynh on 11/6/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzProofOfDeliveryValue : NSObject <NSCoding>

@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *value;
@property (nonatomic, readonly, strong) NSString *contentType;
@property (nonatomic, readonly, strong) NSString *itemId;
@property (nonatomic, readonly, strong) NSString *subItemId;

- (LocalzProofOfDeliveryValue *)initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;

@end

//
//  LocalzDriverOrderItem.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 25/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverOrderSubItem.h"

@interface LocalzDriverOrderItem : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *itemId;
@property (nonatomic, readonly, strong) NSString *stockCode;
@property (nonatomic, readonly, strong) NSString *stockName;
@property (nonatomic, readonly, strong) NSString *status;
@property (nonatomic, readonly, strong) NSNumber *amount;
@property (nonatomic, readonly, strong) NSNumber *quantity;
@property (nonatomic, readonly, strong) NSDictionary *attributes;
@property (nonatomic, readonly, strong) NSArray *subItems;

- (instancetype) initWithData:(id)data;
- (void) status:(NSString *)status;
- (NSDictionary *) toJSON;

@end

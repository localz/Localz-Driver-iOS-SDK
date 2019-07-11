//
//  LocalzDriverOrderSubItem.h
//  LocalzDriverSDK
//
//  Created by Terence Huynh on 11/7/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverOrderSubItem : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *subItemId;
@property (nonatomic, readonly, strong) NSDictionary *attributes;

- (instancetype) initWithData:(id)data;
- (NSDictionary *) toJSON;

@end

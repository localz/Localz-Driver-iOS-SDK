//
//  LocalzDriverOrderItem.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 25/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverOrderItem : NSObject<NSCoding>
@property (nonatomic,readonly,strong) NSString *itemId;
@property (nonatomic,readonly,strong) NSString *status;
@property (nonatomic,readonly,strong) NSString *amount;
@property (nonatomic,readonly,strong) NSDictionary *attributes;

- (instancetype) initWithData:(id)data;
- (void) status:(NSString *)status;
@end

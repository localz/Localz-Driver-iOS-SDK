//
//  LocalzDriverUser.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 6/2/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LocalzDriverUser : NSObject <NSCoding>
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSString *mobile;

- (LocalzDriverUser *)initWithData:(NSDictionary *)data;
- (NSDictionary *)toJSON;
@end

NS_ASSUME_NONNULL_END

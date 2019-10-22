//
//  LocalzDriverAttendant.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 18/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverEditProfile : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSString *email;
@property (nonatomic, readonly, strong) NSString *phoneNumber;
@property (nonatomic, readonly, strong) NSString *avatarUrl;
@property (nonatomic, readonly, strong) NSString *prefBranchId;

- (LocalzDriverEditProfile *) initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;

@end

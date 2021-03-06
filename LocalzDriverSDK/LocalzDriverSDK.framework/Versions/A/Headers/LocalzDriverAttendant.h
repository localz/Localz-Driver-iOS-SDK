//
//  LocalzDriverAttendant.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 18/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverAttendant : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *userId;
@property (nonatomic, readonly, strong) NSString *attendantId;
@property (nonatomic, readonly, strong) NSString *username;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSString *email;
@property (nonatomic, readonly, strong) NSString *phoneNumber;
@property (nonatomic, readonly, strong) NSString *avatarUrl;
@property (nonatomic, readonly, strong) NSString *type;
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSArray *attributesPresentation;
@property (nonatomic, readonly, strong) NSString *prefBranchId;

- (LocalzDriverAttendant *) initWithData:(NSDictionary *)data;

- (void) updateProfile:(LocalzDriverAttendant *)newProfile;

@end

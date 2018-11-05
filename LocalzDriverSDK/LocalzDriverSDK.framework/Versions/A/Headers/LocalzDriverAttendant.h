//
//  LocalzDriverAttendant.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 18/09/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverAttendant : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *attendantId;
@property (nonatomic, readonly, strong) NSString *username;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly, strong) NSArray *proofOfDeliveryFlow;
@property (nonatomic, readonly, strong) NSArray *attributesPresentation;

- (LocalzDriverAttendant *) initWithData:(NSDictionary *)data;

@end

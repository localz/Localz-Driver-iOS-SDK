//
//  LocalzDriverReport.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 17/1/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocalzDriverReportItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    DriverReportTypeAccident,
    DriverReportTypeInspection
} LocalzDriverReportType;

@interface LocalzDriverReport : NSObject<NSCoding>

@property (nonatomic, readonly, strong) NSString *identifier;
@property (nonatomic, readonly, strong) NSString *reportId;
@property (nonatomic, readonly, strong) NSString *firstName;
@property (nonatomic, readonly, strong) NSString *lastName;
@property (nonatomic, readonly) LocalzDriverReportType type;
@property (nonatomic, readonly) NSArray *content;
@property (nonatomic, readonly, strong) NSString *userId;
@property (nonatomic, readonly, strong) NSString *username;

- (LocalzDriverReport *) initWithData:(NSDictionary *)data;

- (NSDictionary *) toJSON;

- (NSString *)reportTypeString;

- (BOOL)isEqual:(id)object;

@end

NS_ASSUME_NONNULL_END

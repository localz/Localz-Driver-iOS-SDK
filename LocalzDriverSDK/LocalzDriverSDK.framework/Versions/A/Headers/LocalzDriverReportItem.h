//
//  LocalzDriverReportItem.h
//  LocalzDriverSDK
//
//  Created by Rashmi Sivaramareddy on 29/1/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    DriverReportContentBarcode,
    DriverReportContentGeo,
    DriverReportContentImage,
    DriverReportContentText,
    DriverReportContentUrl,
    DriverReportContentVideo,
    DriverReportContentVoice
} LocalzDriverReportContent;


@interface LocalzDriverReportItem : NSObject<NSCoding>

@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, readonly, strong) NSString *value;
@property (nonatomic, readonly) LocalzDriverReportContent contentType;

- (instancetype) initWithData:(id)data;

- (NSDictionary *) toJSON;

- (NSString *)reportContentString;

@end

NS_ASSUME_NONNULL_END

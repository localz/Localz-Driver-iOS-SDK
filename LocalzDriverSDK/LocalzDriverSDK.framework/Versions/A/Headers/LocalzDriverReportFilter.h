//
//  LocalzDriverReportFilter.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 28/6/19.
//  Copyright © 2019 Localz Pty Ltd. All rights reserved.
//

#import "LocalzDriverReport.h"

@interface LocalzDriverReportFilter : NSObject
@property (nonatomic) int page;
@property (nonatomic, strong) NSString *reportId;
@property (nonatomic, strong) NSString *siteId;
@property (nonatomic) LocalzDriverReportType type;
@property (nonatomic, strong) NSDate *dateFrom;
@property (nonatomic, strong) NSDate *dateTo;
@end

//
//  LocalzDriverConfiguration.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 21/08/2015.
//  Copyright (c) 2015 Localz Pty Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LocalzDriverConfiguration : NSObject

/**
 *  Returns an instance of this class
 *
 *  @return instance of the class
 */
+ (LocalzDriverConfiguration *_Nonnull) shared;

/**
 *  Configurable level of accuracy for when the GPS accuracy is considered accurate enough to process queued customer ETA notifications
 *  The default value is 250 meters
 */
@property (nonatomic) double etaNotificationGpsAccuracyThreshold;

/**
 *  Configurable timeout in seconds for when a GPS accuracy cannot meet the accuracy threshold. On timeout the queued customer ETA notifications will be processed
 *  The default value is 10 seconds
 */
@property (nonatomic) int etaNotificationTimeout;

@end

//
//  LocalzDriverConstants.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 4/10/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//
// Notification of network status
extern NSString * const SPOTZ_CNC_NETWORK_NOTIFICATION;
extern int const SPOTZ_CNC_IGNORE_ALERT_NOTIFICATION_PERIOD;
typedef enum {
    EPushInitError = 510,
    EOrderAlreadyActioned = 4001,
    ESyncInProgress = 5001,
    ECacheExists = 5002
} LocalzDriverErrorType;

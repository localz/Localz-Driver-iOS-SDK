//
//  LocalzDriverConstants.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 4/10/2015.
//  Copyright © 2015 Localz Pty Ltd. All rights reserved.
//

extern int const SPOTZ_CNC_IGNORE_ALERT_NOTIFICATION_PERIOD;
typedef enum {
    EPushInitError = 510,
    EOrderAlreadyActioned = 4001,
    ESyncInProgress = 5001,
    ECacheExists = 5002
} LocalzDriverErrorType;


/**
 *  Notification when changes in network status are detected. Boolean connected status can be found in userInfo["connection"]
 */
extern NSString * const SpotzCNCNetworkNotification;

/**
 Notification when a request to send an ETA notification has completed successfully or encountered an error.
 
 `LocalzDriverETARequestNotification` userInfo contains:
 ```
 userInfo {
    "orderNumber":NSString
    "error":NSError (optional)
 }
 ```
 */
extern NSNotificationName const LocalzDriverETARequestNotification;

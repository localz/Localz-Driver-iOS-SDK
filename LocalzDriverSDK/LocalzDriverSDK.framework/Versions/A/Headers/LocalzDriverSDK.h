//
//  LocalzDriverSDK.h
//  LocalzDriverSDK
//
//  Created by Daniel Sykes-Turner on 22/12/17.
//  Copyright © 2017 Localz Pty Ltd. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#import <Foundation/Foundation.h>
#import <SpotzSDK/SpotzSDK.h>
#import <UserNotifications/UserNotifications.h>

#import "LocalzDriverAttendant.h"
#import "LocalzDriverOrder.h"
#import "LocalzEta.h"

extern NSString * _Nonnull const kLocalzEnv;
extern NSString * _Nonnull const kLocalzDriverL2LMode;
extern NSString * _Nonnull const kLocalzDriverLocationInterval;

#ifdef DEBUG
extern NSString * _Nonnull const kLocalzDebugEnable;
#endif


#pragma mark Notification Events
extern NSString * _Nonnull const LocalzDriverTrackOrderNotification;
extern NSString * _Nonnull const LocalzDriverAcknowledgedOrderNotification;
extern NSString * _Nonnull const LocalzDriverCompletedOrderNotification;
extern NSString * _Nonnull const LocalzDriverResetOrderNotification;
extern NSString * _Nonnull const LocalzDriverHelpRequestNotification;
extern NSString * _Nonnull const LocalzDriverReminderUnassignedOrdersNotification;
extern NSString * _Nonnull const LocalzDriverForceLogoutNotification;
extern NSString * _Nonnull const LocalzDriverUnexpectedLogoutNotification;

@protocol LocalzDriverSDKDelegate <NSObject>
- (void)localzDriverSDKInit:(NSError * _Nullable)error;
@optional
/**
 * Order management delegates
 */
- (void) localzDriverSDKTrackOrder:(LocalzDriverOrder *  _Nonnull)order data:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKAcknowledgedOrderNumber:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKCompletedOrderNumber:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKResetOrder:(NSString * _Nonnull)orderNumber data:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKHelpRequestWithData:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKReminderWithNumberOfUnassignedOrderNumbers:(NSArray * _Nonnull)orders;
- (void) localzDriverSDKForceLogout:(NSDictionary * _Nullable)data;
- (void) localzDriverSDKUnexpectedLogout;

/**
 * Only applicable for if Spotz is enabled
 */
- (void) localzDriverSDKSiteInit:(NSError * _Nullable)error;
//- (void)localzDriverSDKEnteredSite:(SpotzSiteDetails * _Nonnull)site;

@end

@protocol LocalzDriverSDKDataSource <NSObject>
@end

@interface LocalzDriverSDK : NSObject

+ (instancetype _Nonnull)shared;

#pragma mark SDK management

/**
 * Initialise the SDK. All keys are available on the Localz web console. If you have no access to the console, please contact your one of Localz's reps.
 * @param appId Application ID
 * @param appKey Application Key
 * @param delegate LocalzDriverSDKDelegate instance to handle the SDK events (optional)
 * @param options Additional configuration options. Please see Localz's documentation for more details. (optional)
 */
+ (void)initWithAppId:(NSString * _Nonnull)appId appKey:(NSString * _Nonnull)appKey delegate:(id<LocalzDriverSDKDelegate> _Nullable)delegate options:(NSDictionary * _Nullable)options;

/**
 * Initialise the SDK. All keys are available on the Localz web console. If you have no access to the console, please contact your one of Localz's reps.
 * @param appId Application ID
 * @param appKey Application Key
 * @param cncKey CNC Key is required to enable features such as creating a new order from the app
 * @param delegate LocalzDriverSDKDelegate instance to handle the SDK events (optional)
 * @param options Additional configuration options. Please see Localz's documentation for more details. (optional)
 */
+ (void) initWithAppId:(NSString * _Nonnull)appId appKey:(NSString * _Nonnull)appKey cncKey:(NSString * _Nullable)cncKey delegate:(id<LocalzDriverSDKDelegate> _Nullable)delegate options:(NSDictionary * _Nullable)options;

/**
 * Request location services permission
 */
- (void) requestLocationPermission;

/**
 * Starts the Push notification. This will initialise push notification service and prompt user for enabling push notification if not yet enabled.
 */
- (void) startPush;

/**
 * Indicates whether SDK has been initialised.
 * @returns True if device and configuration have been registered successfully in the SDK.
 */
- (BOOL) isInitialised;

#pragma mark User Management

/**
 * Login user with username / password. This is one of the login method which requires the username and password be setup through the Localz web console. See other login implementations for more details.
 * @param username Username
 * @param password The password
 * @param force Force logout the other user's session if exists. If user has logged in elsewhere and force is false, an error will be returned in the completion block
 * @param completion Completion block returns LocalzDriverAttendant object if successful or error if any
 */
- (void) loginWithUsername:(NSString * _Nonnull)username password:(NSString * _Nonnull)password force:(BOOL)force completion:(void (^_Nullable)(NSError * _Nullable error, LocalzDriverAttendant * _Nullable user))completion;
- (void) loginWithUsername:(NSString * _Nonnull)username password:(NSString * _Nonnull)password branchId:(NSString * _Nullable)branchId force:(BOOL)force options:(NSDictionary * _Nullable)options completion:(void (^_Nullable)(NSError * _Nullable error, LocalzDriverAttendant * _Nullable user))completion __deprecated_msg("'branchId' and 'options' are no longer in use. Please use loginWithUsername:password:force:completion instead");

/**
 * Is user currently logged in?
 * @returns True if user is logged in
 */
- (BOOL) isLoggedIn;

/**
 * Logs the user out of the device.
 *
 * This method will throw an error if
 * - Offline data exists
 * - Network connection error
 * You can override the above by setting force = true
 *
 * @param force Will force logout of the device, regardless of network status.
 * @param completion Sets the error if logout was unsuccessful
 */
- (void) logoutWithForce:(BOOL)force completion:(void (^_Nullable)(NSError * _Nullable error))completion;

#pragma mark Awesome core functions

/**
 * Set user on/off duty. Device will not be tracked during offline mode. Setting onDuty to false is the same as stopping the SDK completely. isStarted will return false.
 * NOTE: When device is set to offDuty, LocalzDriverSDK.currentLocation may still return the last device's location.
 * @param onDuty True to enable, false to disable
 * @param completion Returns NSError if there were any issues setting the on/off mode
 */
- (void) onDuty:(BOOL)onDuty completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 * @returns the on/off duty status
 */
- (BOOL) isOnDuty;

/**
 * Pause location tracking while on-duty to conserve battery. Note: This will reduce resolution and update frequency.
 */
- (void) pause;

/**
 * Returns the pause status
 * @returns True if location is in paused mode
 */
- (BOOL) isPaused;

/**
 * Resumes realtime location update
 */
- (void) resume;

/**
 * Returns the unique device ID for this device.
 * @returns The device Id if already initialised, otherwise returns a nil.
 */
- (NSString * _Nullable) deviceId;

#pragma mark Order management

/**
 * Create or update a new order for the attendant. This will require cncKey (Attendant Key) to be supplied into the SDK
 * @param order LocalzDriverOrder with the details of the order
 * @param completion The completion block which will return error if any
 */
- (void) createOrUpdateOrder:(LocalzDriverOrder * _Nonnull)order completion:(void (^ _Nullable)(NSError * _Nullable))completion;

/**
 * Retrieves orders that are assigned to the logged in user within a certain date range as specified in startDate and fromDate
 * If you set BOTH fromDate and toDate to nil, it will retrieve all orders dated today.
 * However if you supply a fromDate or toDate but NOT both, an error will be returned.
 * @param fromDate The from UTC date filter
 * @param toDate The from UTC date filter
 * @param completion The completion block which will return error if any
 */
- (void) retrieveOrdersFromDate:(NSDate * _Nullable)fromDate toDate:(NSDate * _Nullable)toDate completion:(void (^ _Nullable)(NSError * _Nullable, NSArray * _Nullable))completion;

/**
 * Sets the status of the order to acknowledged
 * @param orderNumber The order number
 * @param completion The completion block which will return error if any
 */
- (void) acknowledgeOrder:(NSString * _Nonnull)orderNumber completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

/**
 * Sends ETA notification to the customer. This will also take background tracking out of resume.
 *  A warning will be issued if a buffer of over 24 hours is passed in.
 * @param orderNumber The order number
 * @param buffer Number of minutes (int) as buffer to be added to ETA for next order
 * @param completion The completion block which returns the ETA or error if any
 */
- (void) sendEtaNotification:(NSString * _Nonnull)orderNumber etaBufferInMinutes:(int)buffer completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 * Retrieves the ETA to the location specified in the order and the current location of the device
 * @param orderNumber The order number to get ETA for
 * @param completion The completion block which returns the error if any
 */
- (void) getEtaForOrderNumber:(NSString * _Nonnull)orderNumber completion:(void (^_Nullable)(NSError * _Nullable error, LocalzEta * _Nullable))completion;

/**
 * Completes the given order
 * @param orderNumber The order number
 * @param signature The image of the captured signature (optiona)
 * @param notes Additional notes (optional)
 */
- (void) completeOrderNumber:(NSString * _Nonnull)orderNumber signature:(UIImage * _Nullable)signature notes:(NSString * _Nullable)notes completion:(void (^_Nullable)(NSError * _Nullable error))completion;

#pragma mark Location management

/**
 * This method returns current location. The location may not be initialised at the time when this method is called therefore please check that the value is not null. You may need to call on-duty to retrieve the most up-to-date location.
 * When device is off-duty, current location may still return the last location of the device. Check the location.timestamp to see when the location was last determined.
 * @returns The current location. Null if not available.
 */
- (CLLocation * _Nullable) currentLocation;

#pragma mark Offline cached data handler

/**
 * Indicates whether there are offline data in the cached that needs syncing with the server
 * Ensure you check this method prior to logging out as logging out will wipe all un-synced data.
 * @return true if there is cached data
 */
- (BOOL) isCachedData;

/**
 * Force sync data with the server. This method is only run if there are cached data and a connection to the Localz server.
 * @param completion Returns error if it was not successful
 */
- (void) syncDataWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;

#pragma mark Push notification management

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData * _Nonnull)deviceToken;

/**
 * This method should be implemented by the matching AppDelegate notification method.
  * For all versions of iOS.
 */
- (void) applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError * _Nonnull)error;

/**
 * This method should be implemented by the matching AppDelegate notification method.
  * For versions before iOS 10
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
- (void) applicationDidRegisterUserNotificationSettings:(UIUserNotificationSettings * _Nonnull)notificationSettings;
#pragma GCC diagnostic pop

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo applicationState:(UIApplicationState)state;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationDidReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo applicationState:(UIApplicationState)state fetchCompletionHandler:(void (^_Nullable)(UIBackgroundFetchResult))completionHandler;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For all versions of iOS.
 */
- (void) applicationHandleActionWithIdentifier:(NSString * _Nonnull)identifier forRemoteNotification:(NSDictionary * _Nullable)userInfo applicationState:(UIApplicationState)state completionHandler:(void (^_Nullable)(void))completionHandler;

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For versions of iOS 10 and later
 */
- (void) userNotificationCenter:(UNUserNotificationCenter * _Nonnull)center willPresentNotification:(UNNotification * _Nullable)notification withCompletionHandler:(void (^_Nullable)(UNNotificationPresentationOptions))completionHandler NS_AVAILABLE_IOS(10.0);

/**
 * This method should be implemented by the matching AppDelegate notification method.
 * For versions of iOS 10 and later
 */
- (void) userNotificationCenter:(UNUserNotificationCenter * _Nonnull)center didReceiveNotificationResponse:(UNNotificationResponse * _Nullable)response withCompletionHandler:(void (^_Nullable)(void))completionHandler NS_AVAILABLE_IOS(10.0);
    
@end

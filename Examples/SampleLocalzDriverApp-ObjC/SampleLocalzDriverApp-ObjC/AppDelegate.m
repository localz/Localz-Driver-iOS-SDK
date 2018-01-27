//
//  AppDelegate.m
//  SampleLocalzDriverApp-ObjC
//
//  Created by Daniel Sykes-Turner on 25/1/18.
//  Copyright © 2018 Localz Pty Ltd. All rights reserved.
//

#import "AppDelegate.h"
#import <LocalzDriverSDK/LocalzDriverSDK.h>

@interface AppDelegate () <LocalzDriverSDKDelegate>
@property (nonatomic, strong) NSString *spotzAppId;
@property (nonatomic, strong) NSString *spotzAppKey;
@property (nonatomic, strong) NSString *spotzCNCKey;
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.spotzAppId = @"enter_spotz_app_id_here";
    self.spotzAppKey = @"enter_spotz_app_key_here";
    self.spotzCNCKey = @"enter_spotz_cnc_key_here";
    
    [LocalzDriverSDK initWithAppId:self.spotzAppId appKey:self.spotzAppKey cncKey:self.spotzCNCKey delegate:self options:nil];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - LocalzDriverSDKDelegate

- (void)localzDriverSDKInit:(NSError *)error {
    
    if (error) {
        NSLog(@"LocalzDriverSDK init failed with error %@", error);
    } else {
        NSLog(@"LocalzDriverSDK init successful");
    }
}

- (void)localzDriverSDKSiteInit:(NSError *)error {
    
    if (error) {
        NSLog(@"LocalzDriverSDK site init failed with error %@", error);
    } else {
        NSLog(@"LocalzDriverSDK site init successful");
    }
}

@end

// Copyright (c) 2023 Nightwind. All rights reserved.

@import UIKit;
#import "HelperFunctions.h"

NSString *const kFilePath = @"settings.json";

%hook AppDelegate

// Source: https://www.reddit.com/r/TweakBounty/comments/17spyhf/comment/k8rdrgn
- (BOOL)application:(id)application didFinishLaunchingWithOptions:(id)options {
	/**
	 * Basic technique:
	 * The app detects the jailbreak and then writes that to the "ios_enable_jailbreak_detection" key in the "settings.json" file in the app container.
	 * Here, we override that key and make it false, so that the app continues functioning after the jailbreak getting detected.
	 */

	NSDictionary *data = dataOfFileCalled(kFilePath);
	NSDictionary *newData = dataWithOverridenBoolean(data, @"ios_enable_jailbreak_detection", false);

	NSError *err = nil;

	NSData *jsonData = [NSJSONSerialization dataWithJSONObject:newData options:0 error:&err];
	NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];

	err = nil;

	[jsonString writeToFile:pathForFile(kFilePath) atomically:YES encoding:NSUTF8StringEncoding error:&err];

	return %orig;
}

%end

%ctor {
	%init(AppDelegate = NSClassFromString(@"swiggy.AppDelegate"));
}

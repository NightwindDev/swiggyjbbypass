// Copyright (c) 2023 Nightwind. All rights reserved.

// Gets the path for the inputted fileName
static inline NSString *pathForFile(NSString *fileName) {
    NSString *path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
    NSString *appFilePath = [[path stringByAppendingPathComponent:@"responses"] stringByAppendingPathComponent:fileName];
	return appFilePath;
}

// Gets the json data for the specified fileName
static NSDictionary *dataOfFileCalled(NSString *fileName) {
	NSData *data = [NSData dataWithContentsOfFile:pathForFile(fileName)];

	return [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];
}

// Returns an NSDictionary with an overridden boolean value in the inputted NSDictionary
static NSDictionary *dataWithOverridenBoolean(NSDictionary *dictionary, NSString *boolValue, BOOL value) {
	NSMutableDictionary *mutDict = [dictionary mutableCopy];
	mutDict[boolValue] = @(value);
	return [mutDict copy];
}
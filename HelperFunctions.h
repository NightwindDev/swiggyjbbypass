static inline NSString *pathForFile(NSString *fileName) {
    NSString *path = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0];
    NSString *appFilePath = [[path stringByAppendingPathComponent:@"responses"] stringByAppendingPathComponent:fileName];
	return appFilePath;
}

static NSDictionary *dataOfFileCalled(NSString *fileName) {
	NSData *data = [NSData dataWithContentsOfFile:pathForFile(fileName)];

	return [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:nil];
}

static NSDictionary *dataWithOverridenBoolean(NSDictionary *dictionary, NSString *boolValue, BOOL value) {
	NSMutableDictionary *mutDict = [dictionary mutableCopy];
	mutDict[boolValue] = @(value);
	return [mutDict copy];
}
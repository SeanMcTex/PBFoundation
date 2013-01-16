//
//  NSString+PBFoundation.h
//  PBFoundation
//
//  Created by Nick Bolton on 1/1/13.
//  Copyright (c) 2013 Pixelbleed. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (PBFoundation)

+ (NSString *)machineName;
+ (NSString *)safeString:(NSString *)value;
- (NSString *)trimmedValue;

@end

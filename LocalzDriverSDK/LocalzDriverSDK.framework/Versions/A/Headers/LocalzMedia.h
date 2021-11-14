//
//  LocalzMedia.h
//  LocalzDriverSDK
//
//  Created by Melvin Artemas on 10/11/21.
//  Copyright © 2021 Localz Pty Ltd. All rights reserved.
//

#ifndef LocalzMedia_h
#define LocalzMedia_h

typedef enum LocalzMimeType {
    UNKNOWN = 0,
    PDF,
    JPEG,
    GIF,
    PNG
} LocalzMimeType;

@interface LocalzMedia : NSObject<NSCoding>
@property (nonatomic, readonly, strong) NSString *identifier;
@property (nonatomic, readonly, strong) NSDictionary *attributes;
@property (nonatomic, readonly, strong) NSString *mime;
@property (nonatomic, readonly) LocalzMimeType mimeType;
@property (nonatomic, readonly, strong) NSString *uri;

- (LocalzMedia *) initWithData:(NSDictionary *)data;

@end

#endif /* LocalzMedia_h */

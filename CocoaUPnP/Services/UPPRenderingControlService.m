// CocoaUPnP by A&R Cambridge Ltd, http://www.arcam.co.uk
// Copyright 2015 Arcam. See LICENSE file.

#import "UPPRenderingControlService.h"
#import "UPPParameters.h"

@implementation UPPRenderingControlService

- (NSURLSessionDataTask *)muteWithInstanceID:(NSString *)instanceId channel:(NSString *)channel completion:(UPPResponseBlock)completion
{
    if (!instanceId || !completion) { return nil; }

    NSArray *keys = @[ @"InstanceID", @"Channel" ];
    NSArray *values = @[ instanceId, channel ?: @"Master" ];
    UPPParameters *params = [UPPParameters paramsWithKeys:keys values:values];

    return [self _sendPostRequestWithParameters:params
                                  action:@"GetMute"
                              completion:completion];
}

- (NSURLSessionDataTask *)setMute:(BOOL)mute withInstanceID:(NSString *)instanceId channel:(NSString *)channel success:(UPPSuccessBlock)success
{
    if (!instanceId) { return nil; }

    NSArray *keys = @[ @"InstanceID", @"Channel", @"DesiredMute" ];
    NSArray *values = @[ instanceId, channel ?: @"Master", @(mute)];
    UPPParameters *params = [UPPParameters paramsWithKeys:keys values:values];

    return [self _sendPostRequestWithParameters:params
                                  action:@"SetMute"
                                 success:success];
}

- (NSURLSessionDataTask *)volumeWithInstanceID:(NSString *)instanceId channel:(NSString *)channel completion:(UPPResponseBlock)completion
{
    if (!instanceId || !completion) { return nil; }

    NSArray *keys = @[ @"InstanceID", @"Channel" ];
    NSArray *values = @[ instanceId ?: @"0",
                         channel ?: @"Master" ];
    UPPParameters *params = [UPPParameters paramsWithKeys:keys values:values];

    return [self _sendPostRequestWithParameters:params
                                  action:@"GetVolume"
                              completion:completion];
}

- (NSURLSessionDataTask *)setVolume:(NSNumber *)volume withInstanceID:(NSString *)instanceId channel:(NSString *)channel success:(UPPSuccessBlock)success
{
    if (!volume || !instanceId) { return nil; }

    NSArray *keys = @[ @"InstanceID", @"Channel", @"DesiredVolume" ];
    NSArray *values = @[ instanceId, channel ?: @"Master", volume ];
    UPPParameters *params = [UPPParameters paramsWithKeys:keys values:values];

    return [self _sendPostRequestWithParameters:params
                                  action:@"SetVolume"
                                 success:success];
}

@end

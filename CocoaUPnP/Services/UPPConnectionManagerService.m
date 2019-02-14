// CocoaUPnP by A&R Cambridge Ltd, http://www.arcam.co.uk
// Copyright 2015 Arcam. See LICENSE file.

#import "UPPConnectionManagerService.h"
#import "UPPSessionManager.h"
#import "UPPConstants.h"
#import "UPPParameters.h"

@implementation UPPConnectionManagerService

- (NSURLSessionDataTask *)protocolInfoWithCompletion:(UPPResponseBlock)completion
{
    if (!completion) { return nil; }

    return [self _sendPostRequestWithParameters:nil
                                  action:@"GetProtocolInfo"
                              completion:completion];
}

- (NSURLSessionDataTask *)prepareForConnectionWithProtocolInfo:(NSString *)protocolInfo peerConnectionManager:(NSString *)peerConnectionManager peerConnectionID:(NSString *)peerConnectionId direction:(NSString *)direction completion:(UPPResponseBlock)completion
{
    if (!protocolInfo || !peerConnectionManager || !peerConnectionId || !completion) { return nil; }

    NSArray *k = @[ @"RemoteProtocolInfo",
                    @"PeerConnectionManager",
                    @"PeerConnectionID",
                    @"Direction" ];

    NSArray *v = @[ protocolInfo,
                    peerConnectionManager,
                    peerConnectionId,
                    direction ];

    UPPParameters *params = [UPPParameters paramsWithKeys:k values:v];

    return [self _sendPostRequestWithParameters:params
                                  action:@"PrepareForConnection"
                              completion:completion];
}

- (NSURLSessionDataTask *)connectionCompleteWithConnectionID:(NSString *)connectionId success:(UPPSuccessBlock)success;
{
    if (!connectionId || !success) { return nil; }

    UPPParameters *params = [UPPParameters paramsWithKey:@"ConnectionID"
                                                   value:connectionId];

    return [self _sendPostRequestWithParameters:params
                                  action:@"ConnectionComplete"
                                 success:success];
}

- (NSURLSessionDataTask *)currentConnectionIDsWithCompletion:(UPPResponseBlock)completion
{
    if (!completion) { return nil; }

    return [self _sendPostRequestWithParameters:nil
                                  action:@"GetCurrentConnectionIDs"
                              completion:completion];
}

- (NSURLSessionDataTask *)currentConnectionInfoWithConnectionID:(NSString *)connectionId completion:(UPPResponseBlock)completion
{
    if (!connectionId || !completion) { return nil; }

    UPPParameters *params = [UPPParameters paramsWithKey:@"ConnectionID" value:connectionId];

    return [self _sendPostRequestWithParameters:params
                                  action:@"GetCurrentConnectionInfo"
                              completion:completion];
}

@end

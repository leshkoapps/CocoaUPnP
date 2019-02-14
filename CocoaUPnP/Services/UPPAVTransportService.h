// CocoaUPnP by A&R Cambridge Ltd, http://www.arcam.co.uk
// Copyright 2015 Arcam. See LICENSE file.

#import "UPPBasicService.h"

NS_ASSUME_NONNULL_BEGIN

/**
 This class contains all the network calls needed for the UPnP [AVTransport1
 service](http://upnp.org/specs/av/UPnP-av-AVTransport-v1-Service.pdf).
 */
@interface UPPAVTransportService : UPPBasicService

#pragma mark - Transport URI Methods

///-----------------------------------------------------------------------------
/// @name Transport URI Methods
///-----------------------------------------------------------------------------

/**
 Set the current transport URI

 @param currentURI         The URI of the media item
 @param currentURIMetaData The meta data for the media item
 @param instanceId         The instance identifier
 @param success            An optional block which returns the success state of
 the call, along with an error object if the call was unsuccessful.

 */
- (NSURLSessionDataTask *)setAVTransportURI:(NSString *)currentURI currentURIMetaData:(nullable NSString *)currentURIMetaData instanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Set the next transport URI

 @param nextURI         The URI for the next media item
 @param nextURIMetaData The meta data for the next media item
 @param instanceId      The instance identifier
 @param success         An optional block which returns the success state of the
 call, along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)setNextAVTransportURI:(NSString *)nextURI nextURIMetaData:(nullable NSString *)nextURIMetaData instanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;


#pragma mark - Getting Information

///-----------------------------------------------------------------------------
/// @name Getting Information
///-----------------------------------------------------------------------------

/**
 Get media information from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)mediaInfoWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;

/**
 Get transport information from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)transportInfoWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;

/**
 Get position information from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)positionInfoWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;

/**
 Get device capabilities from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)deviceCapabilitiesWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;

/**
 Get tranport settings from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)transportSettingsWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;

/**
 Get tranport actions from the service

 @param instanceId The instance identifier
 @param completion A required completion block which returns the parsed response,
 or an error if unsuccessful
 */
- (NSURLSessionDataTask *)transportActionsWithInstanceID:(nullable NSString *)instanceId completion:(UPPResponseBlock)completion;


#pragma mark - General Transport Controls

///-----------------------------------------------------------------------------
/// @name General Transport Controls
///-----------------------------------------------------------------------------

/**
 Send stop command

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.

 */
- (NSURLSessionDataTask *)stopWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Send play command, with speed set to `1`

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)playWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Send play command with a speed setting

 @param instanceId The instance identifier
 @param speed      Playback speed
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)playWithInstanceID:(nullable NSString *)instanceId speed:(nullable NSString *)speed success:(nullable UPPSuccessBlock)success;

/**
 Send pause command

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)pauseWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Send record command

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)recordWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Seek to time

 @param instanceId The instance identifier
 @param unit       The seek mode
 @param target     The time to seek to
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)setSeekWithInstanceID:(nullable NSString *)instanceId unit:(NSString *)unit target:(NSString *)target success:(nullable UPPSuccessBlock)success;

/**
 Send next command

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)nextWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Send previous command

 @param instanceId The instance identifier
 @param success    An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)previousWithInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;


#pragma mark - Mode Setting

///-----------------------------------------------------------------------------
/// @name Mode Setting
///-----------------------------------------------------------------------------

/**
 Set play mode

 @param newPlayMode The new play mode
 @param instanceId  The instance identifier
 @param success     An optional block which returns the success state of the call,
 along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)setPlayMode:(NSString *)newPlayMode withInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

/**
 Set record mode

 @param newRecordMode The new record mode
 @param instanceId    The instance identifier
 @param success       An optional block which returns the success state of the
 call, along with an error object if the call was unsuccessful.
 */
- (NSURLSessionDataTask *)setRecordMode:(NSString *)newRecordMode withInstanceID:(nullable NSString *)instanceId success:(nullable UPPSuccessBlock)success;

@end

NS_ASSUME_NONNULL_END

//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: /Users/ex3ndr/Develop/actor-proprietary/actor-apps/core/src/main/java/im/actor/model/Messenger.java
//

#ifndef _AMMessenger_H_
#define _AMMessenger_H_

#include "J2ObjC_header.h"

@class AMAppStateVM;
@class AMAuthStateEnum;
@class AMConfiguration;
@class AMFastThumb;
@class AMFileReference;
@class AMFileVM;
@class AMGroupAvatarVM;
@class AMGroupVM;
@class AMI18nEngine;
@class AMMVVMCollection;
@class AMNetworkStateEnum;
@class AMOwnAvatarVM;
@class AMPeer;
@class AMUploadFileVM;
@class AMUserVM;
@class AMValueModel;
@class APRequest;
@class APSexEnum;
@class IOSIntArray;
@class IOSLongArray;
@class ImActorModelModulesModules;
@class JavaUtilArrayList;
@protocol AMCommand;
@protocol AMFileCallback;
@protocol AMFileVMCallback;
@protocol AMUploadFileCallback;
@protocol AMUploadFileVMCallback;
@protocol DKPreferencesStorage;

@interface AMMessenger : NSObject {
 @public
  ImActorModelModulesModules *modules_;
}

#pragma mark Public

- (instancetype)initWithConfiguration:(AMConfiguration *)configuration;

- (id<AMCommand>)addContactCommandWithUid:(jint)uid;

- (AMFileVM *)bindFileWithReference:(AMFileReference *)fileReference
                          autoStart:(jboolean)isAutoStart
                       withCallback:(id<AMFileVMCallback>)callback;

- (void)bindRawFileWithReference:(AMFileReference *)fileReference
                       autoStart:(jboolean)isAutoStart
                    withCallback:(id<AMFileCallback>)callback;

- (void)bindRawUploadFileWithRid:(jlong)rid
                    withCallback:(id<AMUploadFileCallback>)callback;

- (AMUploadFileVM *)bindUploadWithRid:(jlong)rid
                         withCallback:(id<AMUploadFileVMCallback>)callback;

- (void)cancelDownloadingWithFileId:(jlong)fileId;

- (void)changeConversationTonesEnabledWithValue:(jboolean)val;

- (void)changeGroupAvatarWithGid:(jint)gid
                  withDescriptor:(NSString *)descriptor;

- (void)changeInAppNotificationsEnabledWithValue:(jboolean)val;

- (void)changeInAppNotificationSoundEnabledWithValue:(jboolean)val;

- (void)changeInAppNotificationVibrationEnabledWithValue:(jboolean)val;

- (void)changeMarkdownWithValue:(jboolean)val;

- (void)changeMyAvatarWithDescriptor:(NSString *)descriptor;

- (void)changeNotificationsEnabledWithValue:(jboolean)val;

- (void)changeNotificationsEnabledWithPeer:(AMPeer *)peer
                                 withValue:(jboolean)val;

- (void)changeNotificationSoundWithSound:(NSString *)sound;

- (void)changeNotificationSoundEnabledWithValue:(jboolean)val;

- (void)changeNotificationVibrationEnabledWithValueWithBoolean:(jboolean)val;

- (void)changeSendByEnterWithValue:(jboolean)val;

- (void)changeShowNotificationTextEnabledWithValue:(jboolean)val;

- (id<AMCommand>)clearChatCommandWithPeer:(AMPeer *)peer;

- (id<AMCommand>)createGroupCommandWithTitle:(NSString *)title
                                  withAvatar:(NSString *)avatarDescriptor
                                    withUids:(IOSIntArray *)uids;

- (id<AMCommand>)deleteChatCommandWithPeer:(AMPeer *)peer;

- (void)deleteMessagesWithPeer:(AMPeer *)peer
                      withRids:(IOSLongArray *)rids;

- (id<AMCommand>)editGroupTitleCommandWithGid:(jint)gid
                                    withTitle:(NSString *)title;

- (id<AMCommand>)editMyNameCommandWithName:(NSString *)newName;

- (id<AMCommand>)editMyNickCommandWithNick:(NSString *)newNick;

- (id<AMCommand>)editNameCommandWithUid:(jint)uid
                               withName:(NSString *)name;

- (id<AMCommand>)executeExternalCommand:(APRequest *)request;

- (id<AMCommand>)findUsersCommandWithQuery:(NSString *)query;

- (void)forceNetworkCheck;

- (AMAppStateVM *)getAppState;

- (NSString *)getAuthEmail;

- (jlong)getAuthPhone;

- (AMAuthStateEnum *)getAuthState;

- (NSString *)getDownloadedDescriptorWithFileId:(jlong)fileId;

- (AMI18nEngine *)getFormatter;

- (AMGroupVM *)getGroupWithGid:(jint)gid;

- (AMGroupAvatarVM *)getGroupAvatarVMWithGid:(jint)gid;

- (AMMVVMCollection *)getGroups;

- (AMValueModel *)getGroupTypingWithGid:(jint)gid;

- (NSString *)getNotificationSound;

- (AMOwnAvatarVM *)getOwnAvatarVM;

- (id<DKPreferencesStorage>)getPreferences;

- (AMValueModel *)getTypingWithUid:(jint)uid;

- (AMUserVM *)getUserWithUid:(jint)uid;

- (AMMVVMCollection *)getUsers;

- (id<AMCommand>)inviteMemberCommandWithGid:(jint)gid
                                    withUid:(jint)uid;

- (jboolean)isConversationTonesEnabled;

- (jboolean)isInAppNotificationsEnabled;

- (jboolean)isInAppNotificationSoundEnabled;

- (jboolean)isInAppNotificationVibrationEnabled;

- (jboolean)isLoggedIn;

- (jboolean)isMarkdownEnabled;

- (jboolean)isNotificationsEnabled;

- (jboolean)isNotificationsEnabledWithPeer:(AMPeer *)peer;

- (jboolean)isNotificationSoundEnabled;

- (jboolean)isNotificationVibrationEnabled;

- (jboolean)isRenameHintShown;

- (jboolean)isSendByEnterEnabled;

- (jboolean)isShowNotificationsText;

- (id<AMCommand>)joinGroupViaLinkCommandWithUrl:(NSString *)url;

- (id<AMCommand>)joinPublicGroupCommandWithGig:(jint)gid
                                withAccessHash:(jlong)accessHash;

- (id<AMCommand>)kickMemberCommandWithGid:(jint)gid
                                  withUid:(jint)uid;

- (id<AMCommand>)leaveGroupCommandWithGid:(jint)gid;

- (id<AMCommand>)listPublicGroups;

- (NSString *)loadDraftWithPeer:(AMPeer *)peer;

- (id<AMCommand>)loadSessionsCommand;

- (jint)myUid;

- (void)onAppHidden;

- (void)onAppVisible;

- (void)onConversationClosedWithPeer:(AMPeer *)peer;

- (void)onConversationOpenWithPeer:(AMPeer *)peer;

- (void)onDialogsClosed;

- (void)onDialogsOpen;

- (void)onLoggedIn;

- (void)onNetworkChangedWithAMNetworkStateEnum:(AMNetworkStateEnum *)state;

- (void)onPhoneBookChanged;

- (void)onProfileClosedWithUid:(jint)uid;

- (void)onProfileOpenWithUid:(jint)uid;

- (void)onPushReceivedWithSeq:(jint)seq;

- (void)onTypingWithPeer:(AMPeer *)peer;

- (void)pauseUploadWithRid:(jlong)rid;

- (void)registerApplePushWithApnsId:(jint)apnsId
                          withToken:(NSString *)token;

- (void)registerGooglePushWithProjectId:(jlong)projectId
                              withToken:(NSString *)token;

- (id<AMCommand>)removeContactCommandWithUid:(jint)uid;

- (void)removeGroupAvatarWithGid:(jint)gid;

- (void)removeMyAvatar;

- (id<AMCommand>)requestCompleteOAuthCommandWithCode:(NSString *)code;

- (id<AMCommand>)requestGetOAuthParamsCommand;

- (id<AMCommand>)requestIntegrationTokenCommandWithGid:(jint)gid;

- (id<AMCommand>)requestInviteLinkCommandWithGid:(jint)gid;

- (id<AMCommand>)requestSmsObsoleteCommandWithPhone:(jlong)phone;

- (id<AMCommand>)requestStartEmailAuthCommandWithEmail:(NSString *)email;

- (id<AMCommand>)requestStartPhoneAuthCommandWithEmail:(jlong)phone;

- (void)requestStateWithFileId:(jlong)fileId
                  withCallback:(id<AMFileCallback>)callback;

- (void)requestUploadStateWithRid:(jlong)rid
                     withCallback:(id<AMUploadFileCallback>)callback;

- (void)resetAuth;

- (void)resumeUploadWithRid:(jlong)rid;

- (id<AMCommand>)revokeIntegrationTokenCommandWithGid:(jint)gid;

- (id<AMCommand>)requestRevokeLinkCommandWithGid:(jint)gid;

- (void)saveDraftWithPeer:(AMPeer *)peer
                withDraft:(NSString *)draft;

- (id<AMCommand>)sendCodeObsoleteCommand:(jint)code;

- (void)sendDocumentWithPeer:(AMPeer *)peer
                    withName:(NSString *)fileName
                    withMime:(NSString *)mimeType
                   withThumb:(AMFastThumb *)fastThumb
              withDescriptor:(NSString *)descriptor;

- (void)sendDocumentWithPeer:(AMPeer *)peer
                    withName:(NSString *)fileName
                    withMime:(NSString *)mimeType
              withDescriptor:(NSString *)descriptor;

- (void)sendMessageWithPeer:(AMPeer *)peer
                   withText:(NSString *)text;

- (void)sendMessageWithPeer:(AMPeer *)peer
                   withText:(NSString *)text
               withMentions:(JavaUtilArrayList *)mentions;

- (void)sendMessageWithPeer:(AMPeer *)peer
                   withText:(NSString *)text
           withMarkdownText:(NSString *)markDownText;

- (void)sendMessageWithPeer:(AMPeer *)peer
                   withText:(NSString *)text
           withMarkdownText:(NSString *)markDownText
               withMentions:(JavaUtilArrayList *)mentions;

- (void)sendPhotoWithPeer:(AMPeer *)peer
                 withName:(NSString *)fileName
                    withW:(jint)w
                    withH:(jint)h
                withThumb:(AMFastThumb *)fastThumb
           withDescriptor:(NSString *)descriptor;

- (void)sendVideoWithPeer:(AMPeer *)peer
                 withName:(NSString *)fileName
                    withW:(jint)w
                    withH:(jint)h
             withDuration:(jint)duration
                withThumb:(AMFastThumb *)fastThumb
           withDescriptor:(NSString *)descriptor;

- (id<AMCommand>)signUpCommandWithName:(NSString *)name
                               WithSex:(APSexEnum *)sex
                            withAvatar:(NSString *)avatarPath;

- (id<AMCommand>)signUpObsoleteCommandWithName:(NSString *)name
                                    withAvatar:(NSString *)avatarPath
                                      silently:(jboolean)isSilent;

- (void)startDownloadingWithReference:(AMFileReference *)reference;

- (id<AMCommand>)terminateAllSessionsCommand;

- (id<AMCommand>)terminateSessionCommandWithId:(jint)id_;

- (void)trackActionCancel:(NSString *)action;

- (void)trackActionError:(NSString *)action
                 withTag:(NSString *)tag
             withMessage:(NSString *)message;

- (void)trackActionSuccess:(NSString *)action;

- (void)trackActionTryAgain:(NSString *)action;

- (void)trackAuthCodeClosed;

- (void)trackAuthCodeOpen;

- (void)trackAuthCodeTypeWithValue:(NSString *)newValue;

- (void)trackAuthCodeWrongNumber;

- (void)trackAuthCodeWrongNumberCancel;

- (void)trackAuthCodeWrongNumberChange;

- (void)trackAuthCountryClosed;

- (void)trackAuthCountryOpen;

- (void)trackAuthCountryPickedWithCountry:(NSString *)country;

- (void)trackAuthPhoneInfoOpen;

- (void)trackAuthPhoneOpen;

- (void)trackAuthPhoneTypeWithValue:(NSString *)newValue;

- (void)trackAuthSignupAvatarCanelled;

- (void)trackAuthSignupAvatarDeleted;

- (void)trackAuthSignupAvatarPicked;

- (void)trackAuthSignupClosed;

- (void)trackAuthSignupNameTypeWithValue:(NSString *)newValue;

- (void)trackAuthSignupOpen;

- (void)trackAuthSignupPressedAvatar;

- (void)trackAuthSuccess;

- (void)trackBackPressed;

- (void)trackCodeRequest;

- (void)trackContactsClosed;

- (void)trackContactsOpen;

- (void)trackDialogsClosed;

- (void)trackDialogsOpen;

- (void)trackDocumentSendWithPeer:(AMPeer *)peer;

- (void)trackMainScreensClosed;

- (void)trackMainScreensOpen;

- (void)trackOwnProfileClosed;

- (void)trackOwnProfileOpen;

- (void)trackPhotoSendWithPeer:(AMPeer *)peer;

- (void)trackTextSendWithPeer:(AMPeer *)peer;

- (void)trackUpPressed;

- (void)trackVideoSendWithPeer:(AMPeer *)peer;

- (void)unbindRawFileWithFileId:(jlong)fileId
                     autoCancel:(jboolean)isAutoCancel
                   withCallback:(id<AMFileCallback>)callback;

- (void)unbindRawUploadFileWithRid:(jlong)rid
                      withCallback:(id<AMUploadFileCallback>)callback;

- (id<AMCommand>)validateCodeCommandWithCode:(NSString *)code;

@end

J2OBJC_EMPTY_STATIC_INIT(AMMessenger)

J2OBJC_FIELD_SETTER(AMMessenger, modules_, ImActorModelModulesModules *)

FOUNDATION_EXPORT void AMMessenger_initWithConfiguration_(AMMessenger *self, AMConfiguration *configuration);

FOUNDATION_EXPORT AMMessenger *new_AMMessenger_initWithConfiguration_(AMConfiguration *configuration) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(AMMessenger)

typedef AMMessenger ImActorModelMessenger;

#endif // _AMMessenger_H_

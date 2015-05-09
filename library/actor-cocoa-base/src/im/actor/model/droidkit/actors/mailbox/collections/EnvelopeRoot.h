//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: /Users/ex3ndr/Develop/actor-model/library/actor-cocoa-base/build/java/im/actor/model/droidkit/actors/mailbox/collections/EnvelopeRoot.java
//

#ifndef _ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_H_
#define _ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_H_

#include "J2ObjC_header.h"

@class DKEnvelope;
@class DKMailboxesQueue;
@class ImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection;
@class ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult;

@interface ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot : NSObject

#pragma mark Public

- (instancetype)initWithDKMailboxesQueue:(DKMailboxesQueue *)queue;

- (void)attachCollectionWithImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection:(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection *)collection;

- (void)detachCollectionWithImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection:(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection *)collection;

- (ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult *)fetchCollectionWithLong:(jlong)time;

- (jint)getAllCount;

#pragma mark Package-Private

- (jlong)buildKeyWithLong:(jlong)time;

- (void)changedTopKeyWithImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection:(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeCollection *)collection;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot)

FOUNDATION_EXPORT void ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_initWithDKMailboxesQueue_(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot *self, DKMailboxesQueue *queue);

FOUNDATION_EXPORT ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot *new_ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_initWithDKMailboxesQueue_(DKMailboxesQueue *queue) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot)

@interface ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult : NSObject

#pragma mark Public

+ (ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult *)delayWithLong:(jlong)delay;

+ (ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult *)envelopeWithDKEnvelope:(DKEnvelope *)envelope;

- (jlong)getDelay;

- (DKEnvelope *)getEnvelope;

- (void)recycle;

- (void)updateWithDKEnvelope:(DKEnvelope *)envelope
                    withLong:(jlong)delay;

@end

J2OBJC_STATIC_INIT(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult)

FOUNDATION_EXPORT ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult *ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult_envelopeWithDKEnvelope_(DKEnvelope *envelope);

FOUNDATION_EXPORT ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult *ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult_delayWithLong_(jlong delay);

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_FetchResult)

#endif // _ImActorModelDroidkitActorsMailboxCollectionsEnvelopeRoot_H_

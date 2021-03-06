//
//  CleverTapPlugin.h
//  Copyright (C) 2015 CleverTap 
//
//  This code is provided under a comercial License.
//  A copy of this license has been distributed in a file called LICENSE
//  with this source code.
//
//

#import <Cordova/CDVPlugin.h>

@interface CleverTapPlugin : CDVPlugin


# pragma mark Developer Options

/** Set CleverTap debug logging
 0 = off, 1 = on;
 */
- (void) setDebugLevel:(CDVInvokedUrlCommand *)command;


# pragma mark enable Personalization API

/** Enable the Personalization API
 must be invoked before calling most Event, Profile, or Session getters, see below
 */
- (void) enablePersonalization:(CDVInvokedUrlCommand *)command;


#pragma mark Push Notifications

/** Request user push notification permission
 */
- (void) registerPush:(CDVInvokedUrlCommand *)command;

/** Set the user push token
 */
- (void) setPushTokenAsString:(CDVInvokedUrlCommand *)command;
- (void) setPushToken:(NSData*)pushToken;

/** Let CleverTap handle the push notification
 CleverTap will insure your AppDelege OpenUrl: sourceApplication: is called with a deep link, if included in notification
 */
- (void) handleNotification:(id)notification;


#pragma mark Event API

/** Record an event
 */
- (void) recordEventWithName:(CDVInvokedUrlCommand *)command;

/** Record an event with event properties
 */
- (void) recordEventWithNameAndProps:(CDVInvokedUrlCommand *)command;

/** Record special "Charged" event with event details and array of purchased item objects
 see https://support.clevertap.com/profiles/recording-actions/#user-action-best-practices
 */
- (void) recordChargedEventWithDetailsAndItems:(CDVInvokedUrlCommand *)command;

/** Get event first time recorded in seconds
 requires prior enablePersonalization call
 */
- (void) eventGetFirstTime:(CDVInvokedUrlCommand *)command;

/** Get event last time recorded in seconds
 requires prior enablePersonalization call
 */
- (void) eventGetLastTime:(CDVInvokedUrlCommand *)command;

/** Get num times an event has been recorded
 requires prior enablePersonalization call
 */
- (void) eventGetOccurrences:(CDVInvokedUrlCommand *)command;

/** Get event details summary - first time, last time, occurrences
 requires prior enablePersonalization call
 */
- (void) eventGetDetails:(CDVInvokedUrlCommand *)command;

/** Get history of events recorded with details
 requires prior enablePersonalization call
 */
- (void) getEventHistory:(CDVInvokedUrlCommand *)command;


#pragma mark Profile API

/** Set location
 */
- (void) setLocation:(CDVInvokedUrlCommand *)command;

/** Set properties on the CleverTap device user profile
 */
- (void) profileSet:(CDVInvokedUrlCommand *)command;

/** Set facebook graph user object properties on the CleverTap device user profile
 */
- (void) profileSetGraphUser:(CDVInvokedUrlCommand *)command;

/** Set google plus user object properties on the CleverTap device user profile
 */
- (void) profileSetGooglePlusUser:(CDVInvokedUrlCommand *)command;

/** Get property from the CleverTap device user profile
 requires prior enablePersonalization call
 */
- (void) profileGetProperty:(CDVInvokedUrlCommand *)command;

/** Get the CleverTap ID of the User Profile. The CleverTap ID is the unique identifier assigned to the User Profile by CleverTap.
 */
-(void)profileGetCleverTapID:(CDVInvokedUrlCommand *)command;

/** Remove the property specified by key from the user profile.
 */
- (void)profileRemoveValueForKey:(CDVInvokedUrlCommand *)command;

/** Method for setting a multi-value user profile property.
 Any existing value(s) for the key will be overwritten.
 Key must be String.
 Values must be Strings, max 40 bytes.  Longer will be truncated.
 Max 100 values, on reaching 100 cap, oldest value(s) will be removed.
 */
- (void)profileSetMultiValues:(CDVInvokedUrlCommand *)command;

/** Method for adding a unique value to a multi-value profile property (or creating if not already existing).
 If the key currently contains a scalar value, the key will be promoted to a multi-value property
 with the current value cast to a string and the new value(s) added.
 Key must be String.
 Values must be Strings, max 40 bytes. Longer will be truncated.
 Max 100 values, on reaching 100 cap, oldest value(s) will be removed.
 */
- (void)profileAddMultiValue:(CDVInvokedUrlCommand *)command;

/**  Method for adding multiple unique values to a multi-value profile property (or creating if not already existing).
 If the key currently contains a scalar value, the key will be promoted to a multi-value property
 with the current value cast to a string and the new value(s) added.
 Key must be String.
 Values must be Strings, max 40 bytes. Longer will be truncated.
 Max 100 values, on reaching 100 cap, oldest value(s) will be removed.
 */
- (void)profileAddMultiValues:(CDVInvokedUrlCommand *)command;

/**  Method for removing a unique value from a multi-value profile property.
 If the key currently contains a scalar value, prior to performing the remove operation the key will be promoted to a multi-value property with the current value cast to a string.
 If the multi-value property is empty after the remove operation, the key will be removed.
 */
- (void)profileRemoveMultiValue:(CDVInvokedUrlCommand *)command;

/**   Method for removing multiple unique values from a multi-value profile property.
 If the key currently contains a scalar value, prior to performing the remove operation the key will be promoted to a multi-value property with the current value cast to a string.
 If the multi-value property is empty after the remove operation, the key will be removed.
 */
- (void)profileRemoveMultiValues:(CDVInvokedUrlCommand *)command;

#pragma mark Session API

/** Get CleverTap session time in seconds
 */
- (void) sessionGetTimeElapsed:(CDVInvokedUrlCommand *)command;

/** Get total user visits
 requires prior enablePersonalization call
 */
- (void) sessionGetTotalVisits:(CDVInvokedUrlCommand *)command;

/** Get CleverTap session screens viewed count
 */
- (void) sessionGetScreenCount:(CDVInvokedUrlCommand *)command;

/** Get previous user visit time in epoch seconds
 requires prior enablePersonalization call
 */
- (void) sessionGetPreviousVisitTime:(CDVInvokedUrlCommand *)command;

/** Get session referrer utm source, campaign and medium, if applicable
 */
- (void) sessionGetUTMDetails:(CDVInvokedUrlCommand *)command;


@end

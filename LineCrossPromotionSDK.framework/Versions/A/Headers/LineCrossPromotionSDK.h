//
//  LineCrossPromotionSDK.h
//  LineCrossPromotionSDKLib
//
//  Created by wonje,song on 2016. 4. 11..
//  Copyright © 2016년 wonje,song. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol LineCrossPromotionSDKInterstitialAdDelegate;
@protocol LineCrossPromotionSDKOfferwallDelegate;

typedef enum _LineCrossPromotionSDKLogLevel
{
    /*! only info logging  */
    LineCrossPromotionSDKLogInfo,
    /*! info, debug logging  */
    LineCrossPromotionSDKLogDebug,
    /*! all logging */
    LineCrossPromotionSDKLogTrace
} LineCrossPromotionSDKLogLevel;

/*!
 @abstract
 Activity Event : SIGN_UP, SIGN_IN
 */
typedef enum _ActivityEvent
{
    SIGN_UP,
    SIGN_IN
} ActivityEvent;

@interface LineCrossPromotionSDK : NSObject


@property (nonatomic, weak, nullable) id<LineCrossPromotionSDKOfferwallDelegate> offerwallDelegate;
@property (nonatomic, weak, nullable) id<LineCrossPromotionSDKInterstitialAdDelegate> interstitialAdDelegate;

@property (nonatomic, getter=isOfferwallAvailable, readonly) BOOL offerwallAvailable;

/*!
 @abstract
 init.
 
 @discussion
 init
 
 @param appKey            app key
 @param hashKey           hash key
 */
+ (void)initCrossPromotionWithAppKey:(nonnull NSString *)appKey andHashKey:(nonnull NSString *)hashKey;

/*!
 @abstract
 singleton LineCrossPromotionSDK 객체를 반환한다.
 */
+ (nonnull LineCrossPromotionSDK *)shared;


/*!
 @abstract
 로그를 level를 설정한다.
 
 @discussion
 보고자 하는 로그 level을 info, debug, trace으로 설정한다.
 
 @param LogLevel            log level
 */
+ (void)setLogLevel:(LineCrossPromotionSDKLogLevel)logLevel;

/*!
 @abstract
 사용자의 user id를 전송하고자 할때 호출한다.
 
 @param userId              user id.
 */
+ (void)setUserId:(nonnull NSString *)userId;

/*!
 @abstract
 set language
 
 @discussion
 [language designator]-[script designator] 의 포멧으로 설정한다.
 https://developer.apple.com/library/ios/documentation/MacOSX/Conceptual/BPInternational/LanguageandLocaleIDs/LanguageandLocaleIDs.html
 "ko",
 "zh-Hans",
 "zh-Hant",
 "zh-HK",
 "ja"
 */
+ (void)setLanguage:(nonnull NSString *)language;

/*!
 @abstract
 Apple AdvertisingIdentifier를 전송한다.
 
 @param appleAdvertisingIdentifier              Apple AdvertisingIdentifier.
 
 @discussion
 광고 목적이 아닌 경우, Apple AdvertisingIdentifier를 사용하면, app reject 사유가 되기 때문에, iAd(AdSupport.framework), AdPopcornOfferwall, AdPopcornDA 등의 광고 기능을 사용하지 않는다면 값을 전송하지 않는다.
 IgaworksCore에서는 전달받은 Apple AdvertisingIdentifier 값이 없는경우, identifierForVendor 값을 identifier로 사용한다.
 */
+ (void)setAppleAdvertisingIdentifier:(nonnull NSString *)appleAdvertisingIdentifier isAppleAdvertisingTrackingEnabled:(BOOL)isAppleAdvertisingTrackingEnabled;


/*!
 @abstract
 Unlock activity event : SIGN_UP, SIGN_IN
 */
+ (void)unlock:(ActivityEvent)event;

/*!
 @abstract
 Get offerwall
 
 @discussion
 Get offerwall
 
 @param spotKey                    spot key
 @param userDataDictionaryForFilter     filtering(targeting)을 위한 user data
 */
+ (void)getOfferwall:(nonnull NSString *)spotKey userDataDictionaryForFilter:(nullable NSDictionary *)userDataDictionaryForFilter;

/*!
 @abstract
 Show offerwall
 
 @discussion
 Show offerwall
 
 @param viewController                    노출시키고자 하는 view controller
 */
+ (void)showOfferwall:(nonnull UIViewController *)viewController;

/*!
 @abstract
 Show interstitial
 
 @discussion
 Show interstitial
 
 @param space key                         space key
 @param viewController                    노출시키고자 하는 view controller
 */
+ (void)showInterstitial:(nonnull NSString *)spaceKey viewController:(nonnull UIViewController *)viewController;

/*!
 @abstract
 url scheme를 통해 open된 url을 전달한다.
 
 @discussion
 
 */
+ (void)passOpenURL:(nonnull NSURL *)URL;

/*!
 @abstract
 App.이 최초 실행될때 시작되었음을 서버로 전송하기 위해 호출한다.
 한번만 호출한다.
 
 @discussion
 AppDelegate의 - application:didFinishLaunchingWithOptions: 메소드에서 IgaworksCore -igaworksCoreWithAppKey:andHashKey:andIsUseIgaworksRewardServer: 메소드를 호출하는 경우에는 start 메소드를 호출하지 않는다.
 */
+ (void)start;

@end

@protocol LineCrossPromotionSDKOfferwallDelegate <NSObject>

@optional

/*!
 @abstract
 get offerwall 성공시 호출된다.
 */
- (void)getOfferwallDidComplete;


/*!
 @abstract
 get offerwall 실패시 호출된다.
 
 @param NSError                          error
 */
- (void)getOfferwallDidFailWithError:(nullable NSError *)error;

/*!
 @abstract
 offerwall open되기 직전에 호출된다.
 */
- (void)offerwallWillOpen;

/*!
 @abstract
 offerwall open된 직후에 호출된다.
 */
- (void)offerwallDidOpen;

/*!
 @abstract
 offerwall close되기 직전에 호출된다.
 */
- (void)offerwallWillClose;

/*!
 @abstract
 offerwall close된 직후에 호출된다.
 */
- (void)offerwallDidClose;

@end



@protocol LineCrossPromotionSDKInterstitialAdDelegate <NSObject>

@optional

/*!
 @abstract
 Interstitial ad load되기 직전에 호출된다.
 */
- (void)interstitialAdWillLoad;

/*!
 @abstract
 Interstitial ad load된 후 호출된다.
 */
- (void)interstitialAdDidLoad;

/*!
 @abstract
 Interstitial ad unload된 후 호출된다.
 */
- (void)interstitialAdDidUnload;

/*!
 @abstract
 user가 interstitial ad의 action에 의해 App.을 leave하기 전에 호출된다.
 */
- (void)willLeaveApplicationByInterstitialAd;

/*!
 @abstract
 Interstitial ad load하는 과정에서 오류 발생시 호출된다.
 
 @param NSError                          error
 */
- (void)interstitialAdDidFailWithError:(nullable NSError *)error;


@end

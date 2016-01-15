//
//  UMOpenIM.h
//  UMOpenIM
//
//  Created by maojianxin on 15/6/12.
//  Copyright (c) 2015年 umeng.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WXOpenIMSDKFMWK/YWFMWK.h>

/** UMOpenIM：开发者使用主类（API）
 */
@interface UMOpenIM : NSObject


///---------------------------------------------------------------------------------------
/// @name settings（most required）
///---------------------------------------------------------------------------------------

//--required

/**
 *  异步初始化
 *  @param appKey IM后台生成的appKey
 *  @param umengAppkey umeng主站生成的appKey,对应的是IM里的子App
 *  @param aCompletionBlock 初始化结果，错误的类型见 WXOSdkErrorCode 定义
 */
+ (void)asyncInitWithAppKey:(NSString *)appKey
            withUmengAppKey:(NSString *)umengAppkey
            completionBlock:(YWCompletionBlock)aCompletionBlock;

/**
 *  同步初始化，首次初始化会发起网络请求，获取你的应用信息，所以可能被阻塞，最长阻塞时间为5秒。初始化成功一次后，后面的初始化不会被阻塞。
 *  @param appKey umeng主站生成的appKey
 *  @param umengAppkey umeng主站生成的appKey,对应的是IM里的子App
 */
+ (BOOL)syncInitWithAppKey:(NSString *)appKey
           withUmengAppKey:(NSString *)umengAppkey
                     getError:(NSError **)aGetError;


/** 设置应用的日志输出的开关（默认关闭）
 @param value 是否开启标志，注意App发布时请关闭日志输出
 */
+ (void)setLogEnabled:(BOOL)value;

/** 向友盟注册该设备的deviceToken，便于发送Push消息
 @param deviceToken APNs返回的deviceToken
 */
+ (void)registerDeviceToken:(NSData *)deviceToken;

/**
 *  获取PushService
 */
+ (id<IYWPushService>)getGlobalPushService;

/**
 *  获取cacheService
 */
- (id<IYWUtilService4Cache>)getGlobalUtilService4Cache;

/**
 *  获取UtilService4Network
 */
- (id<IYWUtilService4Network>)getGlobalUtilService4Network;

/**
 *  获取UtilService4Security
 */
- (id<IYWUtilService4Security>)getGlobalUtilService4Security;

@end


#pragma mark - 配置信息

@interface UMOpenIM ()

/**
 *  网络环境，可以通过这个属性，在初始化WXOSdk之前设置网络环境的初始值
 *  热切换网络环境功能暂时不支持。（即如果已经初始化Sdk，则无法切换）
 */
@property (nonatomic, assign, readwrite) YWEnvironment environment;

/**
 *  日志开关
 */
@property (nonatomic, assign) BOOL logEnabled;

@end


#pragma mark - IMKit for OpenIM

@class YWIMKit;

@interface UMOpenIM ()

/**
 *  初始化IMKit实例，类型为OpenIM。
 *  您获取该实例后，需要retain住该实例，建议将其作为全局单例使用
 *
 *  注意：目前暂不支持获取多个IMKit实例同时使用
 *  注意：获取IMKit实例后，您无需再获取YWIMCore实例，您可以从IMKit实例中得到YWIMCore实例
 */
+ (YWIMKit *)fetchIMKitForOpenIM;

@end


#pragma mark - UserContext

@interface UMOpenIM ()

/**
 *  获取一个OpenIM的YWIMCore实例。
 *  建议在获取一个YWIMCore后，将其保存为全局单例使用。
 */
+ (YWIMCore *)fetchNewIMCoreForOpenIM;

/// YWIMCore被新建的通知
typedef void (^YWSDKIMCoreCreatedBlock)(YWIMCore *aIMCore);

/**
 *  监听新的YWIMCore被生成
 *  @param aKey 用来区分不同的监听者，一般可以使用监听对象的description
 *  @param aPriority 有多个监听者时，调用的优先次序。开发者一般设置：YWBlockPriority
 */
- (void)addIMCoreCreatedBlock:(YWSDKIMCoreCreatedBlock)aBlock forKey:(NSString *)aKey priority:(YWBlockPriority)aPriority;

- (void)removeIMCoreCreatedBlockForKey:(NSString *)aKey;


@end
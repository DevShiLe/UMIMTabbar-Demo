//
//  WXOConversationListViewController.h
//  TAEDemo
//
//  Created by Jai Chen on 14/12/24.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "IYWUIServiceDef.h"

@class YWConversation;
@class YWIMCore;
@class YWIMKit;


@interface YWConversationListViewController : UITableViewController
<YWViewControllerEventProtocol>

/**
 *  创建一个会话列表Controller
 *  @param aIMKit kit对象
 */
+ (instancetype)makeControllerWithIMKit:(YWIMKit *)aIMKit;


/**
 *  IMKit对象的弱引用
 */
@property (nonatomic, weak, readonly) YWIMKit *kitRef;

/**
 *  选中某个会话后的回调
 *  @param aConversation 被选中的会话
 */
typedef void(^YWConversationsListDidSelectItemBlock)(YWConversation *aConversation);

/**
 *  选中某个会话后的回调
 */
@property (nonatomic, copy, readonly) YWConversationsListDidSelectItemBlock didSelectItemBlock;

/**
 *  设置选中某个会话后的回调
 */
- (void)setDidSelectItemBlock:(YWConversationsListDidSelectItemBlock)didSelectItemBlock;

/**
 *  删除某个会话后的回调
 *  @param aConversation 被选中的会话
 */
typedef void(^YWConversationsListDidDeleteItemBlock)(YWConversation *aConversation);

/**
 *  删除某个会话后的回调
 */
@property (nonatomic, copy, readonly) YWConversationsListDidDeleteItemBlock didDeleteItemBlock;

/**
 *  设置删除某个会话后的回调
 */
- (void)setDidDeleteItemBlock:(YWConversationsListDidSelectItemBlock)didDeleteItemBlock;

/**
 *  设置某个会话的最近消息内容后的回调
 *  @param aConversation 需要设置最近消息内容的会话
 *  @return 无需自定义最近消息内容返回nil
 */
typedef NSString *(^YWConversationsLatestMessageContent)(YWConversation *aConversation);

/**
 *  设置某个会话的最近消息内容后的回调
 */
@property (nonatomic, copy, readonly) YWConversationsLatestMessageContent latestMessageContentBlock;

/**
 *  设置某个会话的最近消息内容后的回调
 */
- (void)setLatestMessageContentBlock:(YWConversationsLatestMessageContent)latestMessageContentBlock;

@end

@interface YWConversationListViewController ()

/**
 *  在没有数据时显示该view，占据Controller的View整个页面
 */
@property (nonatomic, strong) UIView *viewForNoData;

/*
 *  会话左滑菜单设置block
 *  @ret,   需要显示的菜单数组
 *  @param, aConversation, 会话
 *  @param, editActions, 默认的菜单数组，成员为YWMoreActionItem类型
 */
typedef NSArray *(^YWConversationEditActionsBlock)(YWConversation *aConversation, NSArray *editActions);

/**
 *  可以通过这个block设置会话列表中每个会话的左滑菜单，这个是同步调用的，需要尽快返回，否则会卡住UI
 */
@property (nonatomic, strong) YWConversationEditActionsBlock conversationEditActionBlock;

@end

@interface YWConversationListViewController (YWSearchSupport)

/**
 *  与会话列表关联的 UISearchBar
 */
@property(nonatomic, readonly, strong) UISearchBar *searchBar;

@end

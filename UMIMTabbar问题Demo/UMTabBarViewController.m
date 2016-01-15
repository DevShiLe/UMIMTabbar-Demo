//
//  UMTabBarViewController.m
//  UMIMTabbar问题Demo
//
//  Created by 石乐 on 16/1/15.
//  Copyright © 2016年 石乐. All rights reserved.
//

#import "UMTabBarViewController.h"
#import "SPKitExample.h"
#import <WXOpenIMSDKFMWK/YWFMWK.h>
#import <WXOUIModule/YWUIFMWK.h>
#import <UMOpenIMSDKFMWK/UMOpenIM.h>
#import "SPUtil.h"
#import "UMSingleChatViewController.h"
@interface UMTabBarViewController ()

@end

@implementation UMTabBarViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self _tryLogin];
    [self addcontrollers];
}

#pragma mark 增加控制器
- (void)addcontrollers
{
    
    __weak typeof(self) weakSelf = self;
    YWConversationListViewController *conversationListController = [[SPKitExample sharedInstance] exampleMakeConversationListControllerWithSelectItemBlock:^(YWConversation *aConversation) {
        if ([aConversation isKindOfClass:[YWCustomConversation class]]) {
            YWCustomConversation *customConversation = (YWCustomConversation *)aConversation;
            [customConversation markConversationAsRead];
        } else {
            [[SPKitExample sharedInstance] exampleOpenConversationViewControllerWithConversation:aConversation fromNavigationController:weakSelf.navigationController];
        }
    }];
    [self addChildVc:conversationListController title:@"会话列表" image:@"news_nor" selectedimage:@"news_pre"];
    
    UMSingleChatViewController* messagecenter = [[UMSingleChatViewController alloc] init];
    [self addChildVc:messagecenter title:@"单聊" image:@"contact_nor" selectedimage:@"contact_pre"];

    
    UIViewController* discover = [[UIViewController alloc] init];
    [self addChildVc:discover title:@"设置" image:@"set_nor" selectedimage:@"set_pre"];
}

- (void)addChildVc:(UIViewController*)childVc title:(NSString*)title image:(NSString*)image selectedimage:(NSString*)selectedimage
{
    UINavigationController* nav = [[UINavigationController alloc] initWithRootViewController:childVc];
    //1.设置文本
    childVc.title = title;
    //2.设置图片
    childVc.tabBarItem.image = [[UIImage imageNamed:image] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    childVc.tabBarItem.selectedImage = [[UIImage imageNamed:selectedimage] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    
    //3.设置文本样式
    NSMutableDictionary* textattri = [NSMutableDictionary dictionary];
    textattri[NSForegroundColorAttributeName] = [UIColor whiteColor];
    NSMutableDictionary* selecttextattri = [NSMutableDictionary dictionary];
    selecttextattri[NSForegroundColorAttributeName] = [UIColor whiteColor];
    [childVc.tabBarItem setTitleTextAttributes:textattri forState:UIControlStateNormal];
    [childVc.tabBarItem setTitleTextAttributes:selecttextattri forState:UIControlStateSelected];
    [self addChildViewController:nav];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)_tryLogin
{
    __weak typeof(self) weakSelf = self;
    
    [[SPUtil sharedInstance] setWaitingIndicatorShown:YES withKey:self.description];
    
    //这里先进行应用的登录
    
    //应用登陆成功后，登录IMSDK//visitor568
    [[SPKitExample sharedInstance] callThisAfterISVAccountLoginSuccessWithYWLoginId:@"visitor345"
                                                                           passWord:@"taobao1234"
                                                                    preloginedBlock:^{
                                                                        [[SPUtil sharedInstance] setWaitingIndicatorShown:NO withKey:weakSelf.description];
                                                                        //                                                                        [weakSelf _pushMainControllerAnimated:YES];
                                                                    } successBlock:^{
                                                                        
                                                                        NSLog(@"登录");
                                                                    } failedBlock:^(NSError *aError) {
                                                                        
                                                                    
                                                                        
                                                                    }];
}

@end

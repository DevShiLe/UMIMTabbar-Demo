//
//  UMSingleChatViewController.m
//  UMIMTabbar问题Demo
//
//  Created by 石乐 on 16/1/15.
//  Copyright © 2016年 石乐. All rights reserved.
//

#import "UMSingleChatViewController.h"
#import "SPKitExample.h"
#import <WXOpenIMSDKFMWK/YWFMWK.h>
#import <WXOUIModule/YWUIFMWK.h>
#import <UMOpenIMSDKFMWK/UMOpenIM.h>
@interface UMSingleChatViewController ()<UITableViewDataSource,UITableViewDelegate>
@property (nonatomic,strong)  NSArray *userarray;
@end

@implementation UMSingleChatViewController

-(void)viewWillAppear:(BOOL)animated
{
    self.tableview=[[UITableView alloc]initWithFrame:CGRectMake(0, 64, self.view.frame.size.width, self.view.frame.size.height-64)];
    self.tableview.dataSource=self;
    self.tableview.delegate=self;
    [self.view addSubview:self.tableview];
 self.userarray=@[@"visitor345",@"visitor346",@"visitor347",@"visitor348",@"visitor349",@"visitor543",@"visitor544",@"visitor315",@"visitor45",@"visitor145",@"visitor245",@"visitor845",@"visitor345",@"visitor645",@"visitor745"];
    
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.userarray.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *ID=@"cell";
    
    UITableViewCell *cell=[tableView dequeueReusableCellWithIdentifier:ID];
    if (!cell) {
        cell=[[UITableViewCell alloc]initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:ID];
        //cell的颜色
        //cell.backgroundColor=SLRandomColor;
    }
    
    //设置cell的文本信息
    cell.textLabel.text=self.userarray[indexPath.row];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    __weak typeof(self) weakSelf = self;
    YWPerson *person = [[YWPerson alloc] initWithPersonId:self.userarray[indexPath.row]];
    
    [[SPKitExample sharedInstance] exampleOpenConversationViewControllerWithPerson:person fromNavigationController:weakSelf.tabBarController.navigationController];
}
@end

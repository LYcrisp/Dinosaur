#ifndef CONFIG_H
#define CONFIG_H



//******************游戏配置数据 *********************             根据背景图设计
#define GAME_WIDTH 2400//图片宽度
#define GAME_HEIGHT  700//界面高度
#define WIN_LONG 1200  //窗口长度
#define GAME_TITLE "恐龙快跑"//标题
//游戏图标
#define GAME_ICON ":/1/up.png"//  图片加载路径
#define GAME_RATE 10          // 10毫秒刷新一次


//******************恐龙配置数据 *********************
#define DINO_SAUR ":/1/left.png"
#define DINO_SAUR1 ":/1/left.png"
#define DINO_SAUR2 ":/1/right.png"
#define DINO_SAUR3 ":/1/up.png"



//******************地图配置数据 *********************
#define MAP_PATH ":/dino/ground.png"  //地图路径
#define MAP_SCROLL_SPEED      2       //地图滚动速度2像素

//******************云朵配置数据 *********************
#define CLOUD_PATH ":/1/cloud.png"
#define CLOUD_SPEED 1  //云速度
#define CLOUD_NUM 20   //云总量
#define CLOUD_INTERVAL 750  //云出场间隔

//******************仙人掌配置数据 *********************
#define ENERMY_PATH ":/dino/cactuses_small_1.png" //仙人掌路径
#define ENERMY_PATH1 ":/dino/cactuses_big_1.png" //仙人掌路径
#define ENERMY_PATH2 ":/dino/cactuses_big_2.png" //仙人掌路径
#define ENERMY_PATH3 ":/1/two_1.png" //仙人掌路径
#define ENERMY_PATH4 ":/dino/cactuses_small_1.png" //仙人掌路径
#define ENERMY_PATH5 ":/dino/cactuses_small_2.png" //仙人掌路径
#define ENERMY_PATH6 ":/dino/cactuses_small_3.png" //仙人掌路径

#define ENERMY_SPEED 3  //仙人掌速度
#define ENERMY_NUM 12   //仙人掌总量
#define ENERMY_INTERVAL 200  //仙人掌出场间隔

#define HEART_SPEED 3  //爱心速度
#define HEART_NUM 2   //爱心总量
#define HEART_INTERVAL 2345  //爱心出场间隔
#define HEART_PATH ":/HEART/HEARTs.png"

#define BIRD_SPEED 4  //鸟速度
#define BIRD_NUM 2   //鸟总量
#define BIRD_INTERVAL 3219  //鸟出场间隔
#define BIRD_PATH ":/1/bird_1.png"
#define BIRD_PATH1 ":/1/bird_1.png"
#define BIRD_PATH2 ":/1/bird_2.png"

#define HIT ":/1/hit.wav"
#define JUMP ":/1/jump1_.wav"
#define REACH ":/1/reach.wav"

#define RESTART ":/dino/restart.png"
#endif // CONFIG_H

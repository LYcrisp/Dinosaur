//#include "Error in " Util.relativeFilePath('D:/QT'code/RunningDinosaur/cloud.h', 'D:/QT'code/RunningDinosaur' + '/' + Util.path('cloud.cpp'))": SyntaxError: Expected token `)'"




#include<cloud.h>
#include"config.h"
Cloud::Cloud()
{
    //资源的加载
    c_cloud.load(CLOUD_PATH);

    //仙人掌位置
    c_x = 0;
    c_y = 0;

    //仙人掌状态
    c_Free = true;

    //仙人掌速度
    c_Speed = CLOUD_SPEED;

}


void Cloud::updatePosition()
{
    //空闲仙人掌状态 不计算坐标
    if (c_Free)
    {
        return;
    }

    c_x -= c_Speed;


    //如果超出屏幕 重置空闲状态
    if (c_x <= - 100)
    {
        c_Free = true;
    }
}

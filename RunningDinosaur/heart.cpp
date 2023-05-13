#include "heart.h"
#include"config.h"
Heart::Heart()
{
    //资源的加载
    h_heart.load(HEART_PATH);

    //爱心位置
    h_x = 0;
    h_y = 0;

    //爱心状态
    h_Free = true;

    //爱心速度
    h_Speed = HEART_SPEED;

    //爱心边框（碰撞检测）
    h_Rect.setWidth(h_heart.width());
    h_Rect.setHeight(h_heart.height());
    h_Rect.moveTo(h_x,h_y);


}

void Heart::updatePosition()
{
    //空闲爱心状态 不计算坐标
    if (h_Free)
    {
        return;
    }

    h_x -= h_Speed;
    h_Rect.moveTo(h_x,h_y);

    //如果超出屏幕 重置空闲状态
    if (h_x <= - 50)
    {
        h_Free = true;
    }
}

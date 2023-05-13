#include "bird.h"
#include"config.h"
Bird::Bird()
{
    //鸟的加载
    b_bird.load(BIRD_PATH);
    b_bird1.load(BIRD_PATH1);
    b_bird2.load(BIRD_PATH2);

    //鸟位置
    b_x = 200;
    b_y = 100;

    //鸟状态
    b_Free = true;

    //鸟速度
    b_Speed = BIRD_SPEED;

    //边框（碰撞检测）
    b_Rect.setWidth(20);
    b_Rect.setHeight(10);
    b_Rect.moveTo(b_x,b_y);


}

void Bird::updatePosition()
{
    //空闲鸟状态 不计算坐标
    if (b_Free)
    {
        return;
    }

    b_x -= b_Speed;
    b_Rect.moveTo(b_x,b_y);

    //如果超出屏幕 重置空闲状态
    if (b_x <= - 100)
    {
        b_Free = true;
    }
}

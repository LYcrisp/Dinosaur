#include "dinosaur.h"
#include "config.h"
#include<QKeyEvent>
Dinosaur::Dinosaur()
{
    //初始化加载恐龙图片
    d_dinosaur.load(DINO_SAUR1);
    d_dinosaur1.load(DINO_SAUR1);
    d_dinosaur2.load(DINO_SAUR2);
    d_dinosaur3.load(DINO_SAUR3);

    //初始化恐龙坐标
    d_x = 150;
    d_y = 200;

    //初始化边框
//    d_rect.setWidth(d_dinosaur1.width()-75);
    d_rect.setWidth(5);
    d_rect.setHeight(10);        //d_dinosaur1.height()-45);
    d_rect.moveTo(d_x,d_y);

}


void Dinosaur::setPosition(int x, int y)
{
    d_x = x;
    d_y = y;
    d_rect.moveTo(d_x,d_y);
}



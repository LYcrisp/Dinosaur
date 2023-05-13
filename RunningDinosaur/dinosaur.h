#ifndef DINOSAUR_H
#define DINOSAUR_H


#include<QPixmap>
#include<QRect>
#include<QKeyEvent>
class Dinosaur
{
public:
    Dinosaur();

    //设置恐龙位置
    void setPosition(int x,int y);


    QPixmap d_dinosaur;
    QPixmap d_dinosaur1;
    QPixmap d_dinosaur2;
    QPixmap d_dinosaur3;
    //恐龙坐标
    int d_x;
    int d_y;


    //恐龙的矩形边框，用于碰撞检测
    QRect d_rect;
};

#endif

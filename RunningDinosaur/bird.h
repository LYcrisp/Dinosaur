#ifndef BIRD_H
#define BIRD_H


#include<QPixmap>
#include<QRect>
class Bird
{
public:
    Bird();
    //更新坐标

    void updatePosition();
    //鸟资源对象
    QPixmap b_bird;
    QPixmap b_bird1;
    QPixmap b_bird2;

    QRectF b_Collision; // 添加 m_Collision 成员变量
    //位置
    int b_x;
    int b_y;

    //边距检测
    QRect b_Rect;

    //状态
    bool b_Free;
    //速度
    int b_Speed;
};

#endif // BIRD_H

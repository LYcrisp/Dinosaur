#ifndef HEART_H
#define HEART_H

#include<QPixmap>
#include<QRect>
class Heart
{
public:
    Heart();
    //更新坐标
    void updatePosition();
public:

    QPixmap h_heart;

    QRectF h_Collision; // 添加 m_Collision 成员变量

    int h_x;
    int h_y;


    QRect h_Rect;


    bool h_Free;

    int h_Speed;
};

#endif // HEART_H

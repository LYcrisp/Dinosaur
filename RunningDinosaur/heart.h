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
    //低级资源对象
    QPixmap h_heart;

    QRectF h_Collision; // 添加 m_Collision 成员变量
    //位置
    int h_x;
    int h_y;

    //边距检测
    QRect h_Rect;

    //状态
    bool h_Free;
    //速度
    int h_Speed;
};

#endif // HEART_H

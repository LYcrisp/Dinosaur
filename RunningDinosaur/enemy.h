#ifndef ENERMYPLANE_H
#define ENERMYPLANE_H

#include<QPixmap>
#include<QRect>
class Enermy
{
public:
    Enermy();
    //更新坐标
    void updatePosition();
public:
    //低级资源对象
    QPixmap m_enermy;
    QPixmap m_enermy1;
    QPixmap m_enermy2;
    QPixmap m_enermy3;
    QPixmap m_enermy4;
    QPixmap m_enermy5;
    QPixmap m_enermy6;
    QRectF m_Collision; // 添加 m_Collision 成员变量
    //位置
    int m_x;
    int m_y;

    //边距检测
    QRect m_Rect;
    QRect m_Rect1;
    QRect m_Rect2;
    QRect m_Rect3;
    QRect m_Rect4;
    QRect m_Rect5;
    QRect m_Rect6;
    //状态
    bool m_Free;
    //速度
    int m_Speed;
};

#endif // ENERMYPLANE_H

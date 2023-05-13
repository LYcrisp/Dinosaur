#ifndef CLOUD_H
#define CLOUD_H

#include<QPixmap>
#include<QRect>
class Cloud
{
public:
    Cloud();
    //更新坐标

public:
    void updatePosition();

    QPixmap c_cloud;

    //位置
    int c_x;
    int c_y;

    //状态
    bool c_Free;

    //速度
    int c_Speed;
};

#endif

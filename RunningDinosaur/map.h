#ifndef MAP_H
#define MAP_H
#include <QPixmap>//绘图设备
//地图类
class Map{

public:
    //构造函数
    Map();
    //地图滚动坐标计算
    void mapPosition();
public:

    QPixmap m_map1;
    QPixmap m_map2;

    //地图X轴坐标
    int m_map1_posX;
    int m_map2_posX;




    int m_scroll_speed;

};

#endif // MAP_H

//#include "Error in " Util.relativeFilePath('D:/QT'code/RunningDinosaur/map.h', 'D:/QT'code/RunningDinosaur' + '/' + Util.path('map.cpp'))": SyntaxError: Expected token `)'"
#include<map.h>
#include<config.h>
Map::Map()
{
    //初始化加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);


    //初始化X轴坐标
    m_map1_posX = GAME_WIDTH;
    m_map2_posX = 0;

    //地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posX -= m_scroll_speed;     //向左
    if(m_map1_posX <= 0)
    {
        m_map1_posX = GAME_WIDTH;
    }

    //处理第二张图片滚动位置
    m_map2_posX -= m_scroll_speed;
    if(m_map2_posX <= -GAME_WIDTH)
    {
        m_map2_posX = 0;
    }

}

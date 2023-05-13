//#include "Error in " Util.relativeFilePath('D:/QT'code/RunningDinosaur/enemy.h', 'D:/QT'code/RunningDinosaur' + '/' + Util.path('enemy.cpp'))": SyntaxError: Expected token `)'"
#include"enemy.h"
#include"config.h"
Enermy::Enermy()
{
    //资源的加载
    m_enermy.load(ENERMY_PATH);
   
    //仙人掌位置
    m_x = 0;
    m_y = 0;

    //仙人掌状态
    m_Free = true;

    //仙人掌速度
    m_Speed = ENERMY_SPEED;

    //仙人掌边框（碰撞检测）
    m_Rect.setWidth(m_enermy.width());
    m_Rect.setHeight(m_enermy.height());
    m_Rect.moveTo(m_x,m_y-50);

    m_Rect1.setWidth(30);
    m_Rect1.setHeight(15);
    m_Rect1.moveTo(m_x,m_y-30);

    m_Rect2.setWidth(30);
    m_Rect2.setHeight(15);
    m_Rect2.moveTo(m_x,m_y-40);

    m_Rect3.setWidth(30);
    m_Rect3.setHeight(15);
    m_Rect3.moveTo(m_x,m_y-40);

    m_Rect4.setWidth(30);
    m_Rect4.setHeight(15);
    m_Rect4.moveTo(m_x,m_y-40);

    m_Rect5.setWidth(30);
    m_Rect5.setHeight(15);
    m_Rect5.moveTo(m_x,m_y-30);

    m_Rect6.setWidth(80);
    m_Rect6.setHeight(15);
    m_Rect6.moveTo(m_x,m_y-40);
}

void Enermy::updatePosition()
{
    //空闲仙人掌状态 不计算坐标
    if (m_Free)
    {
        return;
    }

    m_x -= m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //如果超出屏幕 重置空闲状态
    if (m_x <= - m_Rect.width())
    {
        m_Free = true;
    }
}

#include <QSound>
#include<QKeyEvent>
#include<QIcon>
#include<mainscene.h>
#include<config.h>
#include<map.h>
#include<QPainter>
#include<enemy.h>
#include<QPushButton>
#include<QDebug>
#include<heart.h>
#include<bird.h>
Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent),  y(200.0), v(0.0), g(0.13), ground(200), is_jumping(false), is_releasing(false), last_v(0.0)
{
    //调用初始化场景
    initScene();


    //启动游戏
    playgame();
}

Mainscene::~Mainscene()
{
}

void Mainscene::initScene()
{
    //窗口大小
    setFixedSize(WIN_LONG,GAME_HEIGHT);

    //标题
    setWindowTitle(GAME_TITLE);

    //图标
    setWindowIcon(QIcon( GAME_ICON));

    //定时器
    m_Timer.setInterval(GAME_RATE);



    //仙人掌出现的时间间隔
    m_recorder= 0;

    // 初始化重新开始按钮
        m_restartBtn = new QPushButton(this);
        m_restartBtn->setIcon(QIcon(RESTART));
        m_restartBtn->setFixedSize(100, 100);
        m_restartBtn->move(500, 200);
        m_restartBtn->setVisible(false);
        m_restartBtn->setFocusPolicy(Qt::NoFocus);


        connect(m_restartBtn, &QPushButton::clicked, this, &Mainscene::restartGame);

}





void Mainscene::playgame()
{

    m_Timer.start();

    connect(&m_Timer, &QTimer::timeout,[=](){

        enermyToScene();

        birdToScene();

        cloudToScene();

        heartToScene();

        updatePosition();

        updateMark();

        update();//重新绘制窗口中所有信息

        if(checkCollision())
        {
            m_gameover ++;
            QSound::play(REACH);
        }
        if (collisiondDetection()||checkbirdCollision()) { // 检查碰撞
            m_gameover --;
            QSound::play(HIT);
             if (m_gameover == 0)
              m_Timer.stop();
                    // 标记游戏结束
                }
    });
   connect(&m_Timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

//重新开始
void Mainscene::restartGame()
{
    mark = 0;
    m_gameover = 1; // 重置游戏结束标志
        y = ground; // 重置角色位置
        v = 0.0; // 重置速度
        is_jumping = false; // 重置跳跃状态
        is_jumping = false;
        is_releasing = false;

        m_restartBtn->setVisible(false);
        // 重新初始化游戏

        for (int i = 0; i < ENERMY_NUM; i++) {
            m_enermys[i].m_Free = true;
        }


        for(int i = 0;i < ENERMY_NUM; i++)
        {

                m_enermys[i].m_x = -100;

        }

        for (int i = 0; i < BIRD_NUM; i++) {
            b_birds[i].b_Free = true;
        }
        for(int i = 0;i < BIRD_NUM; i++)
        {

                b_birds[i].b_x = -100;

        }

        for (int i = 0; i < HEART_NUM; i++) {
            h_hearts[i].h_Free = true;
        }
        for(int i = 0;i < HEART_NUM; i++)
        {

                h_hearts[i].h_x = -100;

        }




        m_Timer.start();
        //仙人掌出场
        enermyToScene();
        //更新元素坐标
        updatePosition();
        //绘制到屏幕中
        update();//重新绘制窗口中所有信息

        if(checkCollision())
        {
            m_gameover ++;
        }
        if (collisiondDetection()) { // 检查碰撞
            m_gameover --;
             if (m_gameover == 0)
              m_Timer.stop();
                    // 标记游戏结束
                }


}




void Mainscene::updatePosition()
{
    //更新坐标
    m_map.mapPosition();

    //仙人掌
    for(int i = 0;i < ENERMY_NUM; i++)
    {
        if(m_enermys[i].m_Free == false)
        {
            m_enermys[i].updatePosition();
        }
    }
    //鸟
    for(int i = 0;i < BIRD_NUM; i++)
    {
        if(b_birds[i].b_Free == false)
        {
            b_birds[i].updatePosition();
        }
    }
    //云
    for(int i = 0;i < CLOUD_NUM; i++)
    {
        if(c_clouds[i].c_Free == false)
        {
            c_clouds[i].updatePosition();
        }
    }
    //爱心
    for(int i = 0;i < HEART_NUM; i++)
    {
        if(h_hearts[i].h_Free== false)
        {
            h_hearts[i].updatePosition();
        }
    }
}

void Mainscene::updateMark()
{
    mark++;
}

void Mainscene::paintEvent(QPaintEvent *)  //绘制
{
    QPainter painter(this);

    //地图
    painter.drawPixmap(m_map.m_map1_posX,280,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,280,m_map.m_map2);
    //恐龙
    painter.drawPixmap(d_dinosaur.d_x,d_dinosaur.d_y,d_dinosaur.d_dinosaur);
    if (d_dinosaur.d_y == ground) {
        static int frame = 0;
        frame++;
        if (frame >= 20) {
            frame = 0;
        }
        if (frame < 10) {
            painter.drawPixmap(d_dinosaur.d_x,d_dinosaur.d_y,d_dinosaur.d_dinosaur1);
        } else {
            painter.drawPixmap(d_dinosaur.d_x,d_dinosaur.d_y,d_dinosaur.d_dinosaur2);
        }
    } else {
        painter.drawPixmap(d_dinosaur.d_x,d_dinosaur.d_y,d_dinosaur.d_dinosaur3);
    }

    //鸟


    for(int i = 0;i < BIRD_NUM; i++)
    {
        if(b_birds[i].b_Free == false)
        {
            static int frame1 = 0;
            static int frame2 = 0;
            frame1++;
            frame2++;
            if (frame1 >= 40) {
                frame1 = 0;
            }

            if (frame1 < 20) {
                painter.drawPixmap(b_birds[i].b_x,b_birds[i].b_y - 90 + ((frame2/2000) * 20)%60 ,b_birds[i].b_bird1);
            } else {
                painter.drawPixmap(b_birds[i].b_x,b_birds[i].b_y - 90 + (frame2/2000 * 20)%60,b_birds[i].b_bird2);
            }
        }
    }

    //仙人掌
    for(int i = 0;i < ENERMY_NUM; i++)
    {
        if(m_enermys[i].m_Free == false)
        {
            painter.drawPixmap(m_enermys[i].m_x,m_enermys[i].m_y,m_enermys[i].m_enermy);
        }
    }
    //绘制云

    for(int i = 0;i < CLOUD_NUM; i++)
    {
        if(c_clouds[i].c_Free == false)
        {
            painter.drawPixmap(c_clouds[i].c_x,c_clouds[i].c_y,c_clouds[i].c_cloud);
        }
    }



    //绘制爱心

    for(int i = 0;i < HEART_NUM; i++)
    {
        if(h_hearts[i].h_Free == false)
        {
            painter.drawPixmap(h_hearts[i].h_x,h_hearts[i].h_y,h_hearts[i].h_heart);
        }
    }

    //画左上角爱心
    painter.scale(0.5, 0.5);
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::red);

        // 绘制爱心左半部分
        QPainterPath path1;
        path1.moveTo(75, 40);
        path1.cubicTo(75, 15, 50, 0, 25, 0);
        path1.cubicTo(0, 0, 0, 30, 0, 30);
        path1.cubicTo(0, 60, 75, 105, 75, 105);
        path1.cubicTo(75, 105, 150, 60, 150, 30);
        path1.cubicTo(150, 30, 150, 0, 125, 0);
        path1.cubicTo(100, 0, 75, 15, 75, 40);
        painter.drawPath(path1);

        // 绘制爱心右半部分
        QPainterPath path2;
        path2.moveTo(75, 40);
        path2.cubicTo(75, 15, 100, 0, 125, 0);
        path2.cubicTo(150, 0, 150, 30, 150, 30);
        path2.cubicTo(150, 60, 75, 105, 75, 105);
        path2.cubicTo(75, 105, 0, 60, 0, 30);
        path2.cubicTo(0, 30, 0, 0, 25, 0);
        path2.cubicTo(50, 0, 75, 15, 75, 40);
        painter.drawPath(path2);

        // 绘制生命
        QFont font("Arial", 30, QFont::Bold);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(55, 75, QString::number(m_gameover));

        // 绘制得分
            QFont font1;
            font.setPointSize(20);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(rect().adjusted(0, 0, -10, 0), Qt::AlignRight | Qt::AlignTop, QString("Your mark : %1").arg(mark/10));



    if (m_gameover == 0) { // 游戏结束，显示重新开始按钮
            m_restartBtn->setVisible(true);
        } else { // 游戏未结束，隐藏重新开始按钮
            m_restartBtn->setVisible(false);
        }

}

void Mainscene::onTimer()
{
    if (is_jumping) {
        y += v;
        v += g;

        if (y >= ground) {
            y = ground;
            v = -v; // 碰到地面后反弹
            is_jumping = false;
        }
    } else { // 自由落体
        if (y < ground) {
            if (is_releasing && v < 0 && y < last_h) {
                // 继续向上运动
                y += v;
                v += g;
            } else {
                // 自由落体
                y += v;
                v += g;
                if (y >= ground) {
                    y = ground;
                    v = 0.0;
                }
            }
        }
    }

    d_dinosaur.setPosition(150, y);
    last_h = y;
}

void Mainscene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space && !is_jumping ) {



        QSound::play(JUMP);
        //qDebug()<<m_gameover;
    }
    if (event->key() == Qt::Key_Space && !is_jumping && y == ground) {

        is_jumping = true;
        v = -6.5;
        is_jumping = true;
        is_releasing = false;


    }

}

void Mainscene::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Space && is_jumping) {

        is_jumping = false;
        is_releasing = true;
        last_v = v;
    }
}


void Mainscene::enermyToScene()
{
    m_recorder++;
    if(m_recorder < ENERMY_INTERVAL)
    {
        return;
    }

    m_recorder = 0;
    for(int i = 0;i < ENERMY_NUM; i++)
    {
        if(m_enermys[i].m_Free)
        {

            int type = qrand() % 6 + 1;
            QPixmap pixmap;
            if (type == 1) {
                pixmap.load(ENERMY_PATH1);
                m_enermys[i].m_Collision.setWidth(15);
                m_enermys[i].m_Collision.setHeight(25);
            } else if (type == 2) {
                pixmap.load(ENERMY_PATH2);
                m_enermys[i].m_Collision.setWidth(15);
                m_enermys[i].m_Collision.setHeight(25 );
            } else if (type == 3) {
                pixmap.load(ENERMY_PATH3);
                m_enermys[i].m_Collision.setWidth(15);
                m_enermys[i].m_Collision.setHeight(25);
            } else if (type == 4) {
                pixmap.load(ENERMY_PATH4);
               m_enermys[i].m_Collision.setWidth(15);
               m_enermys[i].m_Collision.setHeight(25);
            } else if (type == 5) {
                pixmap.load(ENERMY_PATH5);
                m_enermys[i].m_Collision.setWidth(15);
                m_enermys[i].m_Collision.setHeight(25);
            } else if (type == 6) {
                pixmap.load(ENERMY_PATH6);
                m_enermys[i].m_Collision.setWidth(40);
                m_enermys[i].m_Collision.setHeight(25);
            }

            m_enermys[i].m_enermy = pixmap;
            m_enermys[i].m_Free = false;
            m_enermys[i].m_x = WIN_LONG + m_enermys[i].m_enermy.width();
            m_enermys[i].m_y = 289 - m_enermys[i].m_enermy.height();
            break;
        }
    }
}

void Mainscene::birdToScene()
{
    b_recorder++;
    if(b_recorder < BIRD_INTERVAL)
    {
        return;
    }

    b_recorder = 0;
    for(int i = 0;i < BIRD_NUM; i++)
    {
        if(b_birds[i].b_Free)
        {

            b_birds[i].b_Free = false;
            QPixmap pixmap;
            pixmap.load(BIRD_PATH);


            b_birds[i].b_bird = pixmap;
            b_birds[i].b_Free = false;
            b_birds[i].b_x = WIN_LONG + 50;
            b_birds[i].b_y = 120 ;

            break;
        }
    }

}

void Mainscene::heartToScene()
{
    h_recorder++;
    if(h_recorder < HEART_INTERVAL)
    {
        return;
    }

    h_recorder = 0;
    for(int i = 0;i < HEART_NUM; i++)
    {
        if(h_hearts[i].h_Free)
        {


            QPixmap pixmap;
            pixmap.load(HEART_PATH);


                h_hearts[i].h_Collision.setWidth(1);
                h_hearts[i].h_Collision.setHeight(1);


            h_hearts[i].h_heart = pixmap;
            h_hearts[i].h_Free = false;
            h_hearts[i].h_x = WIN_LONG + 50;
            h_hearts[i].h_y = 240 ;

            break;
        }
    }
}

void Mainscene::cloudToScene()
{
    c_recorder++;
    if(c_recorder < CLOUD_INTERVAL)
    {
        return;
    }

    c_recorder = 0;
    for(int i = 0;i < CLOUD_NUM; i++)
    {
        if(c_clouds[i].c_Free)
        {

            QPixmap pixmap;
            pixmap.load(CLOUD_PATH);


            c_clouds[i].c_cloud = pixmap;
            c_clouds[i].c_Free = false;
            c_clouds[i].c_x = WIN_LONG ;
            c_clouds[i].c_y = qrand() % 151;
            break;
        }
    }
}


bool Mainscene::collisiondDetection()
{
    QRect dinosaurRect(d_dinosaur.d_x, d_dinosaur.d_y, d_dinosaur.d_dinosaur.width(), d_dinosaur.d_dinosaur.height());
    for (int i = 0; i < ENERMY_NUM; i++)
    {
        if (m_enermys[i].m_Free == false){
        QRect enermyRect(m_enermys[i].m_x, m_enermys[i].m_y, m_enermys[i].m_enermy.width(), m_enermys[i].m_enermy.height());
        if (dinosaurRect.intersects(enermyRect))
        {
            m_enermys[i].m_Free = true;
            return true; // 碰撞检测成功
        }
       }
    return false; // 没有碰撞
    }
}
// bool Mainscene::checkCollision()
bool Mainscene::checkCollision()
{

    QRect dinoRect(d_dinosaur.d_x, d_dinosaur.d_y, d_dinosaur.d_dinosaur.width(), d_dinosaur.d_dinosaur.height());
    for (int i = 0; i < HEART_NUM; i++) {
        if (h_hearts[i].h_Free == false) {
            QRect heartRect(h_hearts[i].h_x, h_hearts[i].h_y, h_hearts[i].h_heart.width(), h_hearts[i].h_heart.height());
            if (dinoRect.intersects(heartRect)) {

                h_hearts[i].h_Free = true;

                return true;
            }
        }
    }


    return false;
}

bool Mainscene::checkbirdCollision()
{
    QRect dinosaurRect(d_dinosaur.d_x, d_dinosaur.d_y, d_dinosaur.d_dinosaur.width(), d_dinosaur.d_dinosaur.height());
    for (int i = 0; i < BIRD_NUM; i++)
    {
        if (b_birds[i].b_Free == false){
        QRect enermyRect(b_birds[i].b_x, b_birds[i].b_y, b_birds[i].b_bird.width(), b_birds[i].b_bird.height());
        if (dinosaurRect.intersects(enermyRect))
        {
            b_birds[i].b_Free = true;
            return true; // 碰撞检测成功
        }
       }
    return false; // 没有碰撞
    }
}

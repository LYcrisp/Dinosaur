#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QTimer>
#include<map.h>
#include<dinosaur.h>
#include<QKeyEvent>
#include<config.h>
#include<enemy.h>
#include<QPushButton>
#include<cloud.h>
#include<heart.h>
#include<bird.h>
#include <QLineEdit>
#include <QVBoxLayout>

class Mainscene : public QWidget
{
    Q_OBJECT

public:


    Mainscene(QWidget *parent = nullptr);
   // void enableCollisionDetection();
    ~Mainscene();
    //初始化场景
    void  initScene();

    //启动游戏

    void playgame();

    //更新游戏元素坐标
    void updatePosition();
    int mark = 0;
    void updateMark();
    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //地图对象
    Map m_map;

    //恐龙对象
    Dinosaur d_dinosaur;
    Dinosaur d_dinosaur1;
    Dinosaur d_dinosaur2;
    Dinosaur d_dinosaur3;

    //鸟对象
    Bird b_bird;

    //跳跃判断
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    
    //仙人掌出现
    void enermyToScene();
    Enermy m_enermys[ENERMY_NUM];//仙人掌数组
    int m_recorder;//仙人掌出现间隔

    //鸟出现
    void birdToScene();
    Bird b_birds[ENERMY_NUM];//仙人掌数组
    int b_recorder;//仙人掌出现间隔

    //爱心出现
    void heartToScene();
    Heart h_hearts[ENERMY_NUM];//仙人掌数组
    int h_recorder;//爱心出现间隔

    //云出现
    void cloudToScene();
    Cloud c_clouds[CLOUD_NUM];//云数组
    int c_recorder;//云出现间隔

    //碰撞检测
    bool collisiondDetection();
    bool checkCollision();
    bool checkbirdCollision();

    //重新开始
//    void mousePressEvent(QMouseEvent *event);

    //定时器
    QTimer m_Timer;
    //QTimer* m_collisionTimer;


private:
    double y ;  // 恐龙的纵坐标
    double v;  // 恐龙的竖直速度
    const double g;  // 重力加速度
    const int ground;  // 地面的高度
    bool is_jumping;  // 标志恐龙是否正在跳跃
    bool is_releasing;
    double last_v;
    double last_h = 0.0; // 上一次跳跃的高度

    //重新开始按钮
    QPushButton* m_restartBtn;

    int m_gameover = 1;
    void restartGame();

public slots:
    void onTimer();


};
#endif // MAINSCENE_H

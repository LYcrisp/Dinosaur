#include "newscene.h"
#include "mainscene.h"
#include <QPushButton>
#include<QDebug>
#include<mainscene.h>
#include<config.h>
#include<map.h>
#include<QIcon>
#include<QPainter>
#include<QKeyEvent>
#include<enemy.h>
#include<dinosaur.h>

void NewScene::initScene()
{
    //初始化窗口大小
    setFixedSize(WIN_LONG,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));
}



NewScene::NewScene(Mainscene *mainscene,QWidget *parent) : QWidget(parent)
{
    //调用初始化场景
    initScene();
    //QPushButton *button = new QPushButton("点击空格以开始", this);
    //button->setFocusPolicy(Qt::NoFocus);
    //button->setGeometry(300, 200, 100, 50);
    //setFixedSize(800, 600);
    this->mainscene = mainscene;
    connect(this, &NewScene::space_key_pressed, this, &NewScene::onSpaceKeyPressed); // 连接信号和槽
}

NewScene::~NewScene()
{
}

void NewScene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Signal connection:" << connect(this, &NewScene::space_key_pressed, this, &NewScene::onSpaceKeyPressed);

    if (event->key() == Qt::Key_Space)
    {
        emit space_key_pressed(event);
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}


void NewScene::onSpaceKeyPressed(QKeyEvent *event)
{

        hide(); // 隐藏当前窗口

        mainscene->show(); // 显示MainScene窗口
}




void NewScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(150, 200, QPixmap(":/1/up.png"));
    painter.drawPixmap(0, 280, QPixmap(":/dino/ground.png"));

    // 绘制文本
    painter.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "按下空格以开始");
}


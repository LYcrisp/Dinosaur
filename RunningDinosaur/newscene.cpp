#include "mainscene.h"
#include <QPushButton>
#include<QDebug>
#include<mainscene.h>
#include<map.h>
#include<QIcon>
#include<QPainter>
#include<QKeyEvent>
#include<enemy.h>
#include<dinosaur.h>
#include "newscene.h"
#include<config.h>
void NewScene::initScene()
{

    setFixedSize(WIN_LONG,GAME_HEIGHT);


    setWindowTitle(GAME_TITLE);


    setWindowIcon(QIcon( GAME_ICON));
}



NewScene::NewScene(Mainscene *mainscene,QWidget *parent) : QWidget(parent)
{
    //初始化场景
    initScene();
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

        mainscene->show(); // 显示MainScene
}




void NewScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(150, 200, QPixmap(":/1/up.png"));
    painter.drawPixmap(0, 280, QPixmap(":/dino/ground.png"));


    painter.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, "按下空格以开始");
}


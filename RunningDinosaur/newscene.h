#ifndef NEWSCENE_H
#define NEWSCENE_H
#include<QIcon>
#include<QPainter>
#include <QWidget>
#include<QTimer>
#include <QWidget>
#include<dinosaur.h>
#include <QKeyEvent>
class Mainscene;
class NewScene : public QWidget
{
    Q_OBJECT

public:
    //初始化场景
    void  initScene();

    void paintEvent(QPaintEvent* event) override;

    explicit NewScene(Mainscene *mainscene,QWidget *parent = nullptr);
    ~NewScene();
    Mainscene *mainscene;
public slots:
    void onSpaceKeyPressed(QKeyEvent *event);    //用于界面跳转


signals:
    void space_key_pressed(QKeyEvent *event); // 定义一个信号，提供一个QKeyEvent参数，在按下空格键时发出

private:
    void keyPressEvent(QKeyEvent *event) override; // 重写键盘按下事件处理函数
};

#endif // NEWSCENE_H

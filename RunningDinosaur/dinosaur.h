#ifndef DINOSAUR_H
#define DINOSAUR_H


#include<QPixmap>
#include<QRect>
#include<QKeyEvent>
class Dinosaur
{
public:
    Dinosaur();


    void setPosition(int x,int y);


    QPixmap d_dinosaur;
    QPixmap d_dinosaur1;
    QPixmap d_dinosaur2;
    QPixmap d_dinosaur3;

    int d_x;
    int d_y;



    QRect d_rect;
};

#endif

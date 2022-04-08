#include <math.h>
#include <QPainter>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)//метод перемещение виджета
{
    //поворот на угол Alpha
 dx=halflen*cos(Alpha);
 dy=halflen*sin(Alpha);
 draw(Painter);//отображение фигуры
}
void MyLine::draw(QPainter *Painter)//метод рисования
{
 Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//рисует линию, повернутую на угол Alpha
}
void MyRect::draw(QPainter *Painter)//метод рисования
{//рисует стороны прямоугольника, повернутые на угол Alpha
 Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
 Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
 Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
 Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}

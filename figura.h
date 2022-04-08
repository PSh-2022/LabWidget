#ifndef FIGURA_H
#define FIGURA_H
#include <QApplication>
class Figura//класс фигура
{
protected:
 int x,y,halflen,dx,dy,r;
 virtual void draw(QPainter *Painter)=0;//виртуальный метод рисования
public:
 Figura(int X,int Y,int Halflen)://конструктор
 x(X),y(Y),halflen(Halflen){}
 void move(float Alpha,QPainter *Painter);//метод перемещение виджета
};
class MyLine:public Figura//класс линия
{
protected:
 void draw(QPainter *Painter);//метод рисования
public:
 MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор
};
class MyRect:public Figura//класс прямоугольник
{
protected:
 void draw(QPainter *Painter);//метод рисования
public:
 MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор
};
#endif // FIGURA_H

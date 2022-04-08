#ifndef AREA_H
#define AREA_H
#include "figura.h"
#include <QPaintEvent>
#include <QWidget>
class Area : public QWidget//класс область
{
 int myTimer; // идентификатор таймера
 float alpha; // угол поворота
public:
 Area(QWidget *parent = 0);// конструктор
 ~Area();// деструктор
 MyLine *myline;//линия
 MyRect *myrect;//прямоугольник
protected:
// обработчики событий
 void paintEvent(QPaintEvent *event);//событие - – рисование пошагово перемещающихся фигур
 void timerEvent(QTimerEvent *event);//событие - инициация перерисовки Холста
 void showEvent(QShowEvent *event);//событие - включение таймера
 void hideEvent(QHideEvent *event);//событие - выключение таймера
};
#endif // AREA_H

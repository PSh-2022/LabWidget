#include "area.h"
#include <QPainter>
Area::Area(QWidget *parent):QWidget(parent)//конструктор
{
setFixedSize(QSize(300,200));//размер области
myline=new MyLine(80,100,50);//создает линию
myrect=new MyRect(220,100,50);//создает прямоугольник
alpha=0;
}
void Area::showEvent(QShowEvent *)//событие - включение таймера
{
 myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *)//событие - – рисование пошагово перемещающихся фигур
{
 QPainter painter(this);//объект класса QPainter. Объект этого класса получает доступ к фрагменту экрана, отведенному под окно, в котором выполняется рисование
 painter.setPen(Qt::red);//Устанавливает новое перо, цвет: красный
 myline->move(alpha,&painter);//смещает линию на alpha
 myrect->move(alpha*(-0.5),&painter);//смещает прямоугольник  на alpha
}
void Area::timerEvent(QTimerEvent *event)//событие - включение таймера
{
 if (event->timerId() == myTimer) // если наш таймер
 {
 alpha=alpha+0.2;//увеличить значение
 update(); // обновить внешний вид
 }
 else
 QWidget::timerEvent(event); // иначе передать для стандартной обработки
}
void Area::hideEvent(QHideEvent *)//событие - выключение таймера
{
killTimer(myTimer); // уничтожить таймер
}
Area::~Area()//деструктор
{
 delete myline;//удаляем указатель myline
 delete myrect;//удаляем указатель myrect
}

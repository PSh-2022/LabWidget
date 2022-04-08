#ifndef WINDOW_H
#define WINDOW_H
#include <QPushButton>
#include "area.h"
class Window : public QWidget// класс окна
{
protected:
 Area * area; // область отображения рисунка
 QPushButton * btn;// кнопка
public:
 Window();// конструктор
};
#endif // WINDOW_H

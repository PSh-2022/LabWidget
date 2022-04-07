#ifndef WINDOW_H
#define WINDOW_H
#include <QPushButton>
#include "area.h"
class Window : public QWidget
{
protected:
 Area * area; // область отображения рисунка
 QPushButton * btn;
public:
 Window();
};
#endif // WINDOW_H

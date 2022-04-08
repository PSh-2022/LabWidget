#include "window.h"
#include <QHBoxLayout>
Window::Window()
{
 auto codec = QStringLiteral("Обработка событий");//локализация, <QTextCodec> устарел, начиная с qt5 не используется. у меня qt6
 setWindowTitle(codec);// устанавливаем заголовок
 area = new Area( this );//новый объект класса Area
 codec = QStringLiteral("Завершить");
 btn = new QPushButton(codec);//кнопка Завершить
 QVBoxLayout *layout = new QVBoxLayout(this);//вертикальный компоновщик, связанный с оконным объектом this
 layout->addWidget(area);//добавление области к компоновщику
 layout->addWidget(btn);//добавление кнопки к компоновщику
 connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));// связь сигнала нажатия кнопки и слота закрытия окна
};

#include "window.h"
#include <QHBoxLayout>
Window::Window()
{
 auto codec = QStringLiteral("Обработка событий");//локализация, <QTextCodec> устарел, начиная с qt5 не используется. у меня qt6
 setWindowTitle(codec);
 area = new Area( this );
 codec = QStringLiteral("Завершить");
 btn = new QPushButton(codec);
 QVBoxLayout *layout = new QVBoxLayout(this);
 layout->addWidget(area);
 layout->addWidget(btn);
 connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

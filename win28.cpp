#include "win28.h"
#include <QHBoxLayout>
Win1::Win1(QWidget *parent):QWidget(parent)
{
 auto codec = QStringLiteral("Счетчик");//локализация, <QTextCodec> устарел, начиная с qt5 не используется. у меня qt6
 setWindowTitle(codec);// устанавливаем заголовок
 codec = QStringLiteral("Cчет по 1");
 label1 = new QLabel(codec);// метка Cчет по 1
 codec = QStringLiteral("Cчет по 5");
 label2 = new QLabel(codec);// метка Cчет по 5
 edit1 = new Counter("0",this);// Counter редактор ввода
 edit2 = new Counter("0",this);// Counter редактор ввода
 calcbutton=new QPushButton("+1",this);// кнопка +1
 codec = QStringLiteral("Выход");
 exitbutton=new QPushButton(codec);// кнопка Выход

 QHBoxLayout *layout1 = new QHBoxLayout();//горизонтальный компоновщик 1
 layout1->addWidget(label1);//добавление метки увеличения счетчика по 1 к компоновщику
 layout1->addWidget(label2);//добавление метки увеличения счетчика по 5 к компоновщику
 QHBoxLayout *layout2 = new QHBoxLayout();//горизонтальный компоновщик 2
 layout2->addWidget(edit1);//добавление Counter редактора ввода к компоновщику
 layout2->addWidget(edit2);//добавление Counter редактора ввода к компоновщику
 QHBoxLayout *layout3 = new QHBoxLayout();//горизонтальный компоновщик 3
 layout3->addWidget(calcbutton);//добавление кнопки +1 к компоновщику
 layout3->addWidget(exitbutton);//добавление кнопки Выход к компоновщику
 QVBoxLayout *layout4 = new QVBoxLayout(this);//вертикальный компоновщик 3
 layout4->addLayout(layout1);//добавление компановщика в контейнер другого компановщика
 layout4->addLayout(layout2);//добавление компановщика в контейнер другого компановщика
 layout4->addLayout(layout3);//добавление компановщика в контейнер другого компановщика
 // связь сигнала нажатия кнопки и слота добавления 1 в счетчике 1
 connect(calcbutton,SIGNAL(clicked(bool)),
 edit1,SLOT(add_one()));
 // связь сигнала нажатия кнопки и слота добавления 1 в счетчике 2
 connect(edit1,SIGNAL(tick_signal()),
 edit2,SLOT(add_one()));
 // связь сигнала нажатия кнопки и слота закрытия окна
 connect(exitbutton,SIGNAL(clicked(bool)),
 this,SLOT(close()));
}

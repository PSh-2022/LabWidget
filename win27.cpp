#include "win27.h"//39
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
Win::Win(QWidget *parent):QWidget(parent)
{
 auto codec = QStringLiteral("Возведение в квадрат");//локализация, <QTextCodec> устарел, начиная с qt5 не используется. у меня qt6
 setWindowTitle(codec);// устанавливаем заголовок
 frame = new QFrame(this);// рамка
 frame->setFrameShadow(QFrame::Raised);//устанавливаем тень рамки. рамка и содержимое кажутся приподнятыми;
 frame->setFrameShape(QFrame::Panel);// устанавливаем форму рамки. рисует панель, чтобы содержимое выглядело приподнятым или утопленным
 codec = QStringLiteral("Введите число:");
 inputLabel = new QLabel(codec, this);// метка ввода
 inputEdit = new QLineEdit("",this);// строчный редактор ввода
 StrValidator *v=new StrValidator(inputEdit);//объект класса компонета проверки ввода, строчный
 inputEdit->setValidator(v);//устанавливаем валидатор, вводятся корректные данные
 codec = QStringLiteral("Результат:");
 outputLabel = new QLabel(codec, this);// метка вывода
 outputEdit = new QLineEdit("",this);// строчный редактор вывода
 codec = QStringLiteral("Следующее");
 nextButton = new QPushButton(codec, this);// кнопка Следующее
 codec = QStringLiteral("Выход");
 exitButton = new QPushButton(codec, this);// кнопка Выход
 // компоновка приложения выполняется согласно рисунку 2.
 QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//вертикальный компоновщик, связанный с оконным объектом frame
 vLayout1->addWidget(inputLabel);//добавление метки ввода к компоновщику
 vLayout1->addWidget(inputEdit);//добавление строчного редактора ввода к компоновщику
 vLayout1->addWidget(outputLabel);//добавление метки вывода к компоновщику
 vLayout1->addWidget(outputEdit);//добавление строчного редактора вывода к компоновщику
 vLayout1->addStretch();//добавление пружины
 QVBoxLayout *vLayout2 = new QVBoxLayout();//вертикальный компоновщик
 vLayout2->addWidget(nextButton);//добавление кнопки Следующее к компоновщику
 vLayout2->addWidget(exitButton);//добавление кнопки Выход к компоновщику
 vLayout2->addStretch();//добавление пружины
 QHBoxLayout *hLayout = new QHBoxLayout(this);//горизонтальный компоновщик
 hLayout->addWidget(frame);//добавление рамки к компоновщику
 hLayout->addLayout(vLayout2);//добавление компановщика в контейнер другого компановщика
 begin();// метод начальной настройки интерфейса
 connect(exitButton,SIGNAL(clicked(bool)),// связь сигнала нажатия кнопки и слота закрытия окна
 this,SLOT(close()));
 connect(nextButton,SIGNAL(clicked(bool)),// связь сигнала нажатия кнопки и начальной настройки интерфейса
 this,SLOT(begin()));
 connect(inputEdit,SIGNAL(returnPressed()),// связь сигнала нажатия кнопки и метода реализации вычислений
 this,SLOT(calc()));
}
void Win::begin()// метод начальной настройки интерфейса
{
 inputEdit->clear();
 nextButton->setEnabled(false);
 nextButton->setDefault(false);
 inputEdit->setEnabled(true);
 outputLabel->setVisible(false);
 outputEdit->setVisible(false);
 outputEdit->setEnabled(false);
 inputEdit->setFocus();
}
void Win::calc()// метод реализации вычислений
{
 bool Ok=true; float r,a;
 QString str=inputEdit->text();
 a=str.toDouble(&Ok);
 if (Ok)
 {
 r=a*a;
 str.setNum(r);
 outputEdit->setText(str);
 inputEdit->setEnabled(false);
 outputLabel->setVisible(true);
 outputEdit->setVisible(true);
 nextButton->setDefault(true);
 nextButton->setEnabled(true);
 nextButton->setFocus();
 }
 else
 if (!str.isEmpty())
 {
 auto codec = QStringLiteral("Возведение в квадрат.");
 auto codec1 = QStringLiteral("Введено неверное значение.");
 QMessageBox msgBox(QMessageBox::Information, codec, codec1, QMessageBox::Ok);
 msgBox.exec();
 }
}

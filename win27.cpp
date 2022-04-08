#include "win27.h"
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
 inputEdit->clear();//очищает
 nextButton->setEnabled(false);//изменение свойства способности принимать и обрабатывать сообщения от клавиатуры и мыши: не способно
 nextButton->setDefault(false);//устанавливает значение кнопки по умолчанию: false
 inputEdit->setEnabled(true);//изменение свойства способности принимать и обрабатывать сообщения от клавиатуры и мыши: способно
 outputLabel->setVisible(false);//видимость виджета и, соответственно, всех его подчиненных виджетов изменение на false
 outputEdit->setVisible(false);//видимость виджета и, соответственно, всех его подчиненных виджетов изменение на false
 outputEdit->setEnabled(false);//изменение свойства способности принимать и обрабатывать сообщения от клавиатуры и мыши: не способно
 inputEdit->setFocus();//ставит фокус ввода с клавиатуры на виджет inputEdit
}
void Win::calc()// метод реализации вычислений
{
 bool Ok=true; float r,a;
 QString str=inputEdit->text();//передает значение из inputEdit
 a=str.toDouble(&Ok);//конвертирует в Double
 if (Ok)//если сконвертировал
 {
 r=a*a;//возводим в квадрат
 str.setNum(r);//Задает для строки напечатанное значение r и возвращает ссылку на строку
 outputEdit->setText(str);//передает значение из outputEdit
 inputEdit->setEnabled(false);//изменение свойства способности принимать и обрабатывать сообщения от клавиатуры и мыши: не способно
 outputLabel->setVisible(true);//видимость виджета и, соответственно, всех его подчиненных виджетов изменение на true
 outputEdit->setVisible(true);//видимость виджета и, соответственно, всех его подчиненных виджетов изменение на true
 nextButton->setDefault(true);//устанавливает значение кнопки по умолчанию: false
 nextButton->setEnabled(true);//изменение свойства способности принимать и обрабатывать сообщения от клавиатуры и мыши: способно
 nextButton->setFocus();//ставит фокус ввода с клавиатуры на виджет nextButton
 }
 else
 if (!str.isEmpty())//если строка пуста
 {
 auto codec = QStringLiteral("Возведение в квадрат.");
 auto codec1 = QStringLiteral("Введено неверное значение.");
 QMessageBox msgBox(QMessageBox::Information, codec, codec1, QMessageBox::Ok);//отображает ошибку
 msgBox.exec();
 }
}

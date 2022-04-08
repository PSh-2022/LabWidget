#ifndef WIN28_H
#define WIN28_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
class Counter:public QLineEdit//класс счетчик
{
 Q_OBJECT// макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
    //конструктор
 Counter(const QString & contents, QWidget *parent=0):
 QLineEdit(contents,parent){}
signals:
 void tick_signal();//метод - сигнал достижения пяти нажатий
public slots:
 void add_one()//метод - слот, счетчик добавления 1
 {
 QString str=text();//задает строку
 int r=str.toInt();//конвертирует в Int
 if (r!=0 && r%5 ==0) emit tick_signal();//необходимо увеличение второго счетчика
 r++;
 str.setNum(r);
 setText(str);
 }
};
class Win1: public QWidget//класс объекта управления окном
{
 Q_OBJECT// макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
 QLabel *label1,*label2;// метки ввода
 Counter *edit1,*edit2;//счетчики
 QPushButton *calcbutton;//кнопка вычисление
 QPushButton *exitbutton;// кнопка выход
public:
 Win1(QWidget *parent = 0);//конструктор
};

#endif // WIN28_H

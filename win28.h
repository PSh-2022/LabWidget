#ifndef WIN28_H
#define WIN28_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
class Counter:public QLineEdit
{
 Q_OBJECT
public:
 Counter(const QString & contents, QWidget *parent=0):
 QLineEdit(contents,parent){}
signals:
 void tick_signal();
public slots:
 void add_one()
 {
 QString str=text();
 int r=str.toInt();
 if (r!=0 && r%5 ==0) emit tick_signal();
 r++;
 str.setNum(r);
 setText(str);
 }
};
class Win1: public QWidget
{
 Q_OBJECT
protected:
 QLabel *label1,*label2;
 Counter *edit1,*edit2;
 QPushButton *calcbutton;
 QPushButton *exitbutton;
public:
 Win1(QWidget *parent = 0);
};

#endif // WIN28_H

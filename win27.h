#ifndef WIN27_H
#define WIN27_H
/*Класс окна. Включает рамки, метки, строчные редакторы, кнопки,
русификатор интерфейса, менеджеры вертикальной и горизонтальной компоновки*/
#include <QApplication>
#include <QLineEdit>
#include <QValidator>
#include <QMessageBox>
class Win:public QWidget // класс окна
{
 Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
 QFrame *frame; // рамка
 QLabel *inputLabel; // метка ввода
 QLineEdit *inputEdit; // строчный редактор ввода
 QLabel *outputLabel; // метка вывода
 QLineEdit *outputEdit; // строчный редактор вывода
 QPushButton *nextButton; // кнопка Следующее
 QPushButton *exitButton; // кнопка Выход
public:
 Win(QWidget *parent = 0); // конструктор
public slots:
 void begin(); // метод начальной настройки интерфейса
 void calc(); // метод реализации вычислений
};
class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
 StrValidator(QObject *parent):QValidator(parent){}
 virtual State validate(QString &str,int &pos)const{
 return Acceptable; // метод всегда принимает вводимую строку
 }
};
#endif // WIN27_H

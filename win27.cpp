#include "win27.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
Win::Win(QWidget *parent):QWidget(parent)
{
 auto codec = QStringLiteral("Возведение в квадрат");//локализация, <QTextCodec> устарел, начиная с qt5 не используется. у меня qt6
 setWindowTitle(codec);
 frame = new QFrame(this);
 frame->setFrameShadow(QFrame::Raised);
 frame->setFrameShape(QFrame::Panel);
 codec = QStringLiteral("Введите число:");
 inputLabel = new QLabel(codec, this);
 inputEdit = new QLineEdit("",this);
 StrValidator *v=new StrValidator(inputEdit);
 inputEdit->setValidator(v);
 codec = QStringLiteral("Результат:");
 outputLabel = new QLabel(codec, this);
 outputEdit = new QLineEdit("",this);
 codec = QStringLiteral("Следующее");
 nextButton = new QPushButton(codec, this);
 codec = QStringLiteral("Выход");
 exitButton = new QPushButton(codec, this);
 // компоновка приложения выполняется согласно рисунку 2.
 QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
 vLayout1->addWidget(inputLabel);
 vLayout1->addWidget(inputEdit);
 vLayout1->addWidget(outputLabel);
 vLayout1->addWidget(outputEdit);
 vLayout1->addStretch();
 QVBoxLayout *vLayout2 = new QVBoxLayout();
 vLayout2->addWidget(nextButton);
 vLayout2->addWidget(exitButton);
 vLayout2->addStretch();
 QHBoxLayout *hLayout = new QHBoxLayout(this);
 hLayout->addWidget(frame);
 hLayout->addLayout(vLayout2);
 begin();
 connect(exitButton,SIGNAL(clicked(bool)),
 this,SLOT(close()));
 connect(nextButton,SIGNAL(clicked(bool)),
 this,SLOT(begin()));
 connect(inputEdit,SIGNAL(returnPressed()),
 this,SLOT(calc()));
}
void Win::begin()
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
void Win::calc()
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

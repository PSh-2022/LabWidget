//#include "win27.h" //пример 2.7
//#include "win28.h" //пример 2.8
#include "window.h" //пример 2.9
int main(int argc, char *argv[])
{
QApplication app(argc, argv);
//Win win(0);//пример 2.7
//Win1 win(0);//пример 2.8
Window win;//пример 2.9
win.show();
return app.exec();
}

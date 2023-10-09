#include "widget.h"
#include"servers.h"
#include"client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    servers s;
    //s.show();
    client c;
    //c.show();
    return a.exec();
}

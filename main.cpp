#include "mainwindow.h"
#include "filterdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SearchWindow w;
//    FilterDialog w;
    w.show();
    return a.exec();
}

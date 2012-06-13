#include <QApplication>

#include "uvoip.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UVoip w;

    w.show();
    
    return a.exec();
}

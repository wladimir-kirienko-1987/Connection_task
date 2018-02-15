#include "server.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Server";
    Server server;
    return a.exec();
}

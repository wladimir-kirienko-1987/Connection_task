#include "server.h"
#include <QImage>

using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

  server.listen(QHostAddress::Any, 8888);
}

Server::~Server()
{
  server.close();
}

void Server::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void Server::startRead()
{
  //char buffer[1024] = {0};

  //qDebug() << client->read(buffer, client->bytesAvailable());
  QByteArray ba;
  ba = client->readAll();
  qDebug() << ba.size();

  QImage myImage;
  QBuffer buffer(&ba);
  buffer.open(QIODevice::ReadOnly);
  myImage.load(&buffer, "PNG"); // read image into ba in PNG format

  if ( myImage.save("D:\\test.png")){
    qDebug() << "Image save success";
  }
  else{
    qDebug() << "Image save fail";
  }
  client->close();
}

#include "client.h"
#include <QApplication>
#include <QImage>

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  qDebug() << "Client";

  QImage myImage;
  if (myImage.load("C:\\test.png")){
    qDebug() << "Image load success";
  }
  else{
    qDebug() << "Image load fail";
  }

  QByteArray ba;
  QBuffer buffer(&ba);
  buffer.open(QIODevice::WriteOnly);
  myImage.save(&buffer, "PNG"); // writes image into ba in PNG format


  Client client;
  client.SetImageData(&ba);

  client.start("127.0.0.1", 8888);


  return app.exec();
}

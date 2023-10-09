#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
//#include<QTcpServer>
#include<QTcpSocket>
#include<QTimer>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QHostAddress>
#include<QDebug>
namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    QTcpSocket*tcp;
void get_ip_port(QHostAddress id,qint64 port);
private:
    QString filename;
    qint64 filesize;
    QFile*save;
    qint64 recive=0;
void save_file();
bool is_header;
QHostAddress ips;
qint16 ports;
void send();
    Ui::client *ui;
};

#endif // CLIENT_H

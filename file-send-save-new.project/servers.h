#ifndef SERVERS_H
#define SERVERS_H
#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QTimer>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QtDebug>
namespace Ui {
class servers;
}

class servers : public QWidget
{
    Q_OBJECT

public:
    explicit servers(QWidget *parent = nullptr);
    ~servers();
QTcpServer *server;
QTcpSocket* tcp;
void get_ip_port(QHostAddress ip,qint16 port);
private:
    Ui::servers *ui;
    qint64 file_size;//发送文件的大小
    qint64  send_size;//已发送文件的大小
    QTimer* timer;//定时器
    QString filename;//文件名字
    void  send_file_head();//发送文件
    void  send_file();//发送文件的本体
    void  select();
    void  tcp_creat();
    QFile *local;
qint16 ports;
QHostAddress IP;
};

#endif // SERVERS_H

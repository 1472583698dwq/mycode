#include "client.h"
#include "ui_client.h"
client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    tcp=new QTcpSocket(this);
    ui->progressBar->reset();
    is_header=true;
    ui->ip->setText(ips.toString());

    ui->port->setText(QString::number(ports));
    connect(ui->connect,&QPushButton::clicked,this,[=](){
        send();
    });
    connect(tcp,&QTcpSocket::readyRead,this,[=](){
save_file();

    });
}
void client::send(){
    tcp->connectToHost(ui->ip->text().toUtf8(),ui->port->text().toInt());

}
void client::save_file(){
    QByteArray buff=tcp->readAll();
    if(is_header){
        is_header=false;
        filename=QString(buff).section("#",0,0);
        filesize=QString(buff).section("#",1,1).toInt();
        recive=0;
        save=new QFile(filename);
        ui->filename->setText(filename);
        save->open(QFile::WriteOnly);

        ui->progressBar->setRange(0,filesize);
    }else{
        qint64 len=save->write(buff);
        recive+=len;
        ui->progressBar->setValue(recive);
        if(recive==filesize){
            QMessageBox::information(this, "完成", "接受文件成功");
save->close();
  tcp->disconnectFromHost();
tcp->close();
        }
    }
}
void client::get_ip_port(QHostAddress id, qint64 port){
    ips=id;
   //ports=port;
    ports=6666;
   ui->ip->setText(ips.toString());

   ui->port->setText(QString::number(ports));
}
client::~client()
{
    delete ui;
}

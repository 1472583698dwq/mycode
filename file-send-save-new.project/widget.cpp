#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    udp=new QUdpSocket(this);
    group=new QButtonGroup;
    serves=new servers;
    clients=new client;
//ui->scrollArea->verticalScrollBar();
    udp->bind(QHostAddress::Any,8888);//绑定端口
    connect(ui->seach,&QPushButton::clicked,this,[=](){
       if(!checkBox.empty())checkBox.clear();//开始时清空设备列表
        if(!ports.empty())ports.clear();//清空端口列表
        seach();
        shows();
    });
    connect(udp,&QUdpSocket::readyRead,this,[=](){
      recive();
      shows();
    });

connect(group, SIGNAL(buttonPressed(int)), this, SLOT(onIdClicked(int)));

connect(ui->connect,&QPushButton::clicked,this,[=](){
    udp->writeDatagram("按下",IP,Port);
    connected();
});
}
void Widget::seach(){//搜索设备
    QString str=QString("##%1");
    QByteArray byte;
    byte.append(str);
    udp->writeDatagram(byte.data(),QHostAddress::Broadcast,6666);
}
void Widget::recive(){//接收其他设备发送的消息
    while (udp->hasPendingDatagrams()) {
      QByteArray by;
        QHostAddress id;
        quint16 port=0;
      by.resize(udp->pendingDatagramSize());

      udp->readDatagram(by.data(),by.size(),&id,&port);
      qDebug()<<id.toString()<<port;
      QString str=by.data();
if(str=="##%1"){
QString send="@@@@#";
QByteArray s;
s.append(s);
udp->writeDatagram(send.toUtf8(),id,port);
}
 if(str=="@@@@#") {
     QCheckBox *box=new QCheckBox;
     QString set=id.toString();
     box->setText(set);
     checkBox.push_back(box);
     ports.push_back(port);
 }
    if(str=="请求连接"){
        bool a=false;
         a=QMessageBox::question(this,"询问","是否连接");
         if(a){
             udp->writeDatagram("Ok",id,port);
             IP="::ffff:127.0.0.1";
             Port=port;
             clients->get_ip_port(IP,Port);
             clients->show();
         }
    }
    if(str=="OK"){
         serves->get_ip_port(IP,Port);
         serves->show();
    }
    }
}
void Widget:: shows(){//展示设备列表
    QWidget*widget=new QWidget(ui->verticalLayout);
    widget->setGeometry(0, 0, 700, 1200);
     QGridLayout *layout = new QGridLayout(widget);
    for(int c=0;c<checkBox.size();c++){
layout->addWidget(checkBox[c]);

group->addButton(checkBox[c],c);

    }
    group->setExclusive(true);
}
/*void Widget::select(){
for(int c=0;c<checkBox.size();c++){
   if(checkBox[c]->isChecked()){
       IP=QHostAddress(checkBox[c]->text());
   }
}
}*/
void Widget::connected(){//连接设备
QByteArray send;
send.append("请求连接");
udp->writeDatagram(send,IP,Port);
serves->show();
}
void Widget::onIdClicked(int a){
    //QMessageBox::warning(this,"000","000");
QHostAddress id(checkBox[a]->text());
IP=id;
Port=ports[a];
}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_canel_clicked()
{
   for(int c=0;c<checkBox.size();c++){
group->setExclusive(false);
       checkBox[c]->setChecked(false);
       group->setExclusive(true);
   }
IP.clear();
Port=0;
}

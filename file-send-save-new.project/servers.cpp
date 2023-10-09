
#include "servers.h"
#include "ui_servers.h"
servers::servers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::servers)
{
    ui->setupUi(this);
    timer=new QTimer;
    send_size=0;
    file_size=0;
    server=new QTcpServer(this);
     ui->progressBar->reset();
    server->listen(QHostAddress::LocalHost,6666);
    ui->select->setEnabled(false);
    ui->send->setEnabled(false);

    connect(server,&QTcpServer::newConnection,this,[=](){
        tcp_creat();
    });
    connect(ui->select,&QPushButton::clicked,this,[=](){
        select();
    });
    connect(ui->send,&QPushButton::clicked,this,[=](){
        send_file_head();
    });
    connect(timer,&QTimer::timeout,this,[=](){
        timer->stop();
        send_file();
    });


}
void servers::tcp_creat(){
    tcp=server->nextPendingConnection();
    QString ip=tcp->peerAddress().toString();
    qint16 port=tcp->peerPort();
    QString str = QString("[%1 : %2]:成功连接").arg(ip).arg(port);
    ui->ip->setText(str);
    ui->select->setEnabled(true);
}
void servers::select(){
    QString filePath = QFileDialog::getOpenFileName(this, "open", "../");//文件选择对话框的内容
       if(!filePath.isEmpty())//文件选择成功
       {
           //初始化信息
           filename.clear();
          file_size = 0;

           QFileInfo info(filePath);
           filename = info.fileName();
            file_size = info.size();
   local=new QFile;
           local->setFileName(filePath);

           bool isOK = local->open(QIODevice::ReadOnly);
           if(!isOK)
           {
               qDebug() << "只读方式打开失败";
           }

           ui->file_path->setText(filePath);

           }else{
                qDebug() << "文件选择失败";
           }
       ui->send->setEnabled(true);

}
void servers::send_file_head(){
QString str=QString("%1#%2").arg(filename).arg(file_size);//将文件头保存
qint64 len=tcp->write(str.toUtf8());
if(len>0){//头文件发送成功
    timer->start(20);//启动定时器
}else{
    QMessageBox::warning(this,"警告","头文件发送失败");
}

}
void servers::send_file(){
    ui->progressBar->setRange(0,file_size);
    qint64 len=0;
    do{
        qDebug()<<"正在发送";
       char buf[4*1024] = {0}; //每次发送的文件大小
       len=0;
       len=local->read(buf,sizeof (buf));
       tcp->write(buf,len);
       send_size+=len;
       qDebug()<<len<<" "<<send_size<<" "<<file_size;
       ui->progressBar->setValue(send_size);

    }while(len>0);
    if(send_size==file_size){
        QMessageBox::warning(this,"提示","发送成功");
    }
}
void servers::get_ip_port(QHostAddress ip, qint16 port){
    IP=ip;
    ports=port;
}
servers::~servers()
{
    delete ui;
}

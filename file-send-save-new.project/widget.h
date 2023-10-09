#ifndef WIDGET_H
#define WIDGET_H
#include<QCheckBox>
#include <QWidget>
#include<QVector>
#include<QUdpSocket>
#include<QHostInfo>
#include<QtDebug>
#include<QNetworkInterface>
#include<QPair>
#include<QMessageBox>
#include<QButtonGroup>
#include"servers.h"
#include"client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
QUdpSocket *udp;

private:
void seach();//永与广播
QVector<QCheckBox*>checkBox;//用于保存设备信息
QVector<qint16>ports;//用来保存端口号
void recive();//用于接收消息
void connected();//用于双方设备沟通
void  shows();
void  select();
QButtonGroup*group;
qint16 Port=0;
QHostAddress IP;
    Ui::Widget *ui;
    servers*serves;//服务器
    client *clients;//客户端
private slots:
   void onIdClicked(int a);
   void on_canel_clicked();
};
#endif // WIDGET_H

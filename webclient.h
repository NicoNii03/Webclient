#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include <QAbstractSocket>
#include <QTcpSocket>

#include "ui_webclient.h"

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();

private:
    QTcpSocket *m_socket;
    QString m_hostname;
    unsigned short m_zahl = 80;
    void readyRead();
    void connected();
};

#endif // WEBCLIENT_H

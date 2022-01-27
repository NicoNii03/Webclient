#include "webclient.h"
#include <QCoreApplication>
#include <QDebug>

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &Webclient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::readyRead);


}

void Webclient::on_pushButton_clicked()
{
    textFeld->clear();                                                              // Das Text Feld muss nach jedem Durchlauf gelcleared werden
    m_hostname = Webseite->text();                                                  // Die Variable nimmt den Text der TextBox an

    m_socket->connectToHost(m_hostname, m_zahl);
    if (!m_socket->waitForConnected(6000)) {                                        // Wenn nach 6 Sekunden keine Verbindung zum Server ist dann wird im Text Feld no Connection ausgegeben
        textFeld->setText("No Connectiion");
    }
}

void Webclient::connected()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n").toLocal8Bit());
}

void Webclient::readyRead()
{
    textFeld->setText( m_socket->readAll());
    m_socket->disconnectFromHost();
}



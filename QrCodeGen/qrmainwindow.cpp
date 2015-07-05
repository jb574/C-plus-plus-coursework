#include "qrmainwindow.h"
#include "ui_qrmainwindow.h"

#include <QMainWindow>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
 #include <QFileDialog>
 #include <QMessageBox>
 #include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
using namespace std;
#include <iostream>

void QrMainWindow::connectUIToCode()
{
    connect(man,&QNetworkAccessManager::finished,this,&QrMainWindow::loadDownloadedImage);
    connect(ui->saveButton,&QPushButton::clicked,this,&QrMainWindow::saveQRCodeData);
   connect(ui->printButton,&QPushButton::clicked,this,&QrMainWindow::printQRCode);
}

QrMainWindow::QrMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QrMainWindow)
{

    ui->setupUi(this);
    connect(ui->submItButton,SIGNAL(clicked()),this,SLOT(genrateQRCode()));
    ui->resultBox->setText("your image will appear here");
    content = "";
    man = new QNetworkAccessManager(this);
    connectUIToCode();
}



void QrMainWindow::printQRCode()
{
    QPrinter myPrinter;
    QPrintDialog box(&myPrinter, this);
    if(box.exec() == QDialog::Accepted)
    {
        QPainter mypainter;
        mypainter.begin(&myPrinter);
        mypainter.drawImage(mypainter.viewport(),ui->resultBox->pixmap()->toImage());
        mypainter.end();
    }
}

void QrMainWindow::reportNetworkError()
{
    QString errorMesage = "a network error has occoured, please try again";
    error(errorMesage);
    ui->resultBox->setText(errorMesage);
}

void QrMainWindow::loadDownloadedImage(QNetworkReply *reply)
{
    if(reply->error())
    {
        reportNetworkError();
        return;
    }
    QByteArray data = reply->readAll();
     QPixmap rawImage;
     rawImage.loadFromData(data);
     ui->resultBox->setScaledContents(true);
     ui->resultBox->setPixmap(rawImage);
}


QrMainWindow::~QrMainWindow()
{
    delete ui;
}

void QrMainWindow::error(QString message)
{
    QMessageBox box;
    box.setText(message);
    box.exec();
}

void QrMainWindow::saveQRCodeData()
{
    QString filename = QFileDialog::getSaveFileName(this,"save qr code", "","Images (*.png)");

    if(!filename.isEmpty())
    {
        if(!ui->resultBox->pixmap()->save(filename))
        {
            QString message = "can't save file";
            error(message);
        }

    }

}

void QrMainWindow::startNetworkRequest()
{
    QString urlString = "http://chart.apis.google.com/chart?cht=qr&chs=100x100&chl=";
    urlString = urlString + content;
    urlString = urlString + "&chld=H|0";

      QUrl url(urlString);
      QNetworkRequest request(url);
      man->get(request);
}

void QrMainWindow::genrateQRCode()
{
    if(!man->networkAccessible())
    {
        reportNetworkError();
        return;
    }
    QString text = ui->userTextArea->toPlainText();
    content = ui->userTextArea->toPlainText();
    startNetworkRequest();
}

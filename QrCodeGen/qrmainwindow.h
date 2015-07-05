#ifndef QRMAINWINDOW_H
#define QRMAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class QrMainWindow;
}

/**
 * class that is the main window for th application
 *@version 6th Febraury 2014
 *@author Jack Davey
 */
class QrMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * constructor for this class
     * @param parent normally null
     */
    explicit QrMainWindow(QWidget *parent = 0);

    /**
      *destructor for this class
      */
    ~QrMainWindow();

public slots:

    /**
     * method that does the job of generating a qr code
     * from the user supplied text
     */
    void genrateQRCode();

    /**
     * method that does the job of displaying
     * the qr code on screen once downlaoded
     * @param reply the response from the ntework access manager
     */
    void loadDownloadedImage(QNetworkReply *reply);
    /**
     * method to save a qr code to disk
     */
    void saveQRCodeData();
    /**
     * method ot load a qr code from disk
     */
    void printQRCode();
private:


    /**
     * method to connect the ui to the code
     */
    void connectUIToCode();

    /**
     * report an error to the user
     * @param message the error to report
     */
    void error(QString message);


    /**
     * method to report a network error
     */
    void reportNetworkError();



    /**
    * method to get a network request going
    */
   void startNetworkRequest();

    QString content;
    QNetworkAccessManager *man;
    Ui::QrMainWindow *ui;
};

#endif // QRMAINWINDOW_H

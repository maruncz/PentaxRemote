#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H

#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <cstring>


class HttpInterface : public QObject
{
    Q_OBJECT
public:
    explicit HttpInterface(QObject *parent = 0);

    void get(QUrl path);

    void setparams(QByteArray data);

    void shoot(QByteArray af);

signals:
    void finished(QByteArray buffer);

public slots:



private:

    QUrl url;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QByteArray buffer;


};

#endif // HTTPINTERFACE_H

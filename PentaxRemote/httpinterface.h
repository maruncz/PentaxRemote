#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H

#include <QObject>
#include <QUrl>

#include <QNetworkAccessManager>
#include <QNetworkReply>


class HttpInterface : public QObject
{
    Q_OBJECT
public:
    explicit HttpInterface(QObject *parent = 0);


    void get(QUrl url, HttpInterface *interface);

    void put(QUrl url, QByteArray data, HttpInterface *interface);

    void post(QUrl url, QByteArray data, HttpInterface *interface);

signals:

    void finished(QByteArray data, HttpInterface *interface);

public slots:
};

#endif // HTTPINTERFACE_H

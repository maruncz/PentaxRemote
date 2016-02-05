#include "httpinterface.h"

HttpInterface::HttpInterface(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);

}

void HttpInterface::get(QUrl path)
{
    buffer.clear();
    reply = manager->get(QNetworkRequest(path));
    connect(reply,&QNetworkReply::readyRead,[=](){buffer.append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){emit finished(buffer);});
}

void HttpInterface::setparams(QByteArray data)
{
    buffer.clear();
    url = QUrl("http://192.168.0.1/v1/params/camera");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("text/xml"));
    request.setUrl(url);
    reply = manager->put(request,data);
    connect(reply,&QNetworkReply::readyRead,[=](){buffer.append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){emit finished(buffer);});
}

void HttpInterface::shoot(QByteArray af)
{
    buffer.clear();
    url = QUrl("http://192.168.0.1/v1/camera/shoot");
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("text/xml"));
    request.setUrl(url);
    reply = manager->put(request,af);
    connect(reply,&QNetworkReply::readyRead,[=](){buffer.append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){emit finished(buffer);});
}

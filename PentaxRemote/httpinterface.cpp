#include "httpinterface.h"

HttpInterface::HttpInterface(QObject *parent) : QObject(parent)
{

}

void HttpInterface::get(QUrl url, HttpInterface *interface)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QByteArray *buffer = new QByteArray();
    buffer->clear();
    QNetworkReply *reply = manager->get(QNetworkRequest(url));
    connect(reply,&QNetworkReply::readyRead,[=](){buffer->append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){finished(*buffer, interface);});
}

void HttpInterface::put(QUrl url, QByteArray data, HttpInterface *interface)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QByteArray *buffer = new QByteArray();
    buffer->clear();
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("text/xml"));
    request.setUrl(url);
    QNetworkReply *reply = manager->put(request,data);
    connect(reply,&QNetworkReply::readyRead,[=](){buffer->append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){finished(*buffer, interface);});
}

void HttpInterface::post(QUrl url, QByteArray data, HttpInterface *interface)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QByteArray *buffer = new QByteArray();
    buffer->clear();
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("text/xml"));
    request.setUrl(url);
    QNetworkReply *reply = manager->post(request,data);
    connect(reply,&QNetworkReply::readyRead,[=](){buffer->append(reply->readAll());});
    connect(reply,&QNetworkReply::finished,[=](){finished(*buffer, interface);});
}

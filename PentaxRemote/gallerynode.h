#ifndef GALLERYNODE_H
#define GALLERYNODE_H

#include <QObject>
#include <QIcon>
#include <QJsonObject>
#include <QJsonDocument>
#include <QListWidgetItem>
#include "httpinterface.h"

class GalleryNode : public QObject, public QListWidgetItem
{
    Q_OBJECT
public:
    explicit GalleryNode(QString file, QObject *parent = 0);

    QIcon getPicture() const;
    void setPicture(const QIcon &value);

    QString getProperties() const;
    void setProperties(const QString &value);


    QString getFilename() const;
    void setFilename(const QString &value);

    QString time_to_string(QString time);
    QString string_to_time(QString string);


    QListWidgetItem *getItem() const;
    void setItem(QListWidgetItem &value);

signals:

public slots:

    void on_pic_info(QByteArray data, HttpInterface *iface);

    void on_pic_thumb(QByteArray data, HttpInterface *iface);


private:

    QIcon picture;
    QString properties;
    QString filename;

};

#endif // GALLERYNODE_H

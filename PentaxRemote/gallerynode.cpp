#include "gallerynode.h"

GalleryNode::GalleryNode(QString file, QObject *parent) : QListWidgetItem(), QObject(parent), filename(file)
{
    HttpInterface *params2 = new HttpInterface();
    connect(params2,&HttpInterface::finished,this,&GalleryNode::on_pic_thumb);
    params2->get(QUrl("http://192.168.0.1/v1/photos/"+filename+"?size=view"),params2);

    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&GalleryNode::on_pic_info);
    params->get(QUrl("http://192.168.0.1/v1/photos/"+filename+"/info"),params);
}

QIcon GalleryNode::getPicture() const
{
    return picture;
}

void GalleryNode::setPicture(const QIcon &value)
{
    picture = value;
}

QString GalleryNode::getProperties() const
{
    return properties;
}

void GalleryNode::setProperties(const QString &value)
{
    properties = value;
}

QString GalleryNode::getFilename() const
{
    return filename;
}

void GalleryNode::setFilename(const QString &value)
{
    filename = value;
}


QString GalleryNode::time_to_string(QString time)
{
    if(!time.contains('.'))
    {
        return "";
    }
    QStringList tmp = time.split('.');
    if(tmp.at(0).toInt()==1 && tmp.at(1).toInt()>1)
    {
        return tmp.at(0)+"/"+tmp.at(1);
    }
    else if(tmp.at(0).toInt()>1 && tmp.at(1).toInt()==10)
    {
        return QString::number(tmp.at(0).toInt()/tmp.at(1).toInt())+"\"";
    }
    else if(tmp.at(0).toInt()>1 && tmp.at(1).toInt()==1)
    {
        return tmp.at(0)+"\"";
    }
    else
    {
        return tmp.at(0)+"/"+tmp.at(1);
    }
}

QString GalleryNode::string_to_time(QString string)
{

}

void GalleryNode::on_pic_info(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&GalleryNode::on_pic_info);
    QJsonObject picinfo = QJsonDocument::fromJson(data).object();
    QString props;
    props.append(time_to_string(picinfo.value("tv").toString())+"\n");
    props.append("f/"+picinfo.value("av").toString()+"\n");
    props.append("ISO"+picinfo.value("sv").toString()+"\n");
    props.append(picinfo.value("xv").toString()+"EV\n");
    props.append(QDateTime::fromString(picinfo.value("datetime").toString(),"yy:MM:dd:hh:mm:ss").toString("dd.MM.yyyy hh:mm:ss")+"\n");
    setProperties(props);
    setText(properties);
    delete iface;
}

void GalleryNode::on_pic_thumb(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&GalleryNode::on_pic_thumb);
    QImage image;
    image.loadFromData(data);
    QIcon icon(QPixmap::fromImage(image));
    setPicture(icon);
    setIcon(picture);
    delete iface;
}


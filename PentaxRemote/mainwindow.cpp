#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    get_pics();
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadparams);
    params->get(QUrl("http://192.168.0.1/v1/props"),params);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadparams(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&MainWindow::loadparams);
    props = QJsonDocument::fromJson(data).object();
    QJsonArray array;

    bool oldstate = ui->wbcombo->blockSignals(true);
    array = props.value("WBModeList").toArray();
    ui->wbcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->wbcombo->addItem(array[i].toString());
    }
    ui->wbcombo->setCurrentText(props.value("WBMode").toString());
    ui->wbcombo->blockSignals(oldstate);

    oldstate = ui->sizecombo->blockSignals(true);
    array = props.value("stillSizeList").toArray();
    ui->sizecombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->sizecombo->addItem(array[i].toString());
    }
    ui->sizecombo->setCurrentText(props.value("stillSize").toString());
    ui->sizecombo->blockSignals(oldstate);

    oldstate = ui->shootmcombo->blockSignals(true);
    array = props.value("shootModeList").toArray();
    ui->shootmcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->shootmcombo->addItem(array[i].toString());
    }
    ui->shootmcombo->setCurrentText(props.value("shootMode").toString());
    ui->shootmcombo->blockSignals(oldstate);

    oldstate = ui->expmcombo->blockSignals(true);
    array = props.value("exposureModeList").toArray();
    ui->expmcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->expmcombo->addItem(array[i].toString());
    }
    ui->expmcombo->setCurrentText(props.value("exposureMode").toString());
    ui->expmcombo->blockSignals(oldstate);

    oldstate = ui->avcombo->blockSignals(true);
    array = props.value("avList").toArray();
    ui->avcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->avcombo->addItem(array[i].toString());
    }
    ui->avcombo->setCurrentText(props.value("av").toString());
    ui->avcombo->blockSignals(oldstate);

    oldstate = ui->tvcombo->blockSignals(true);
    array = props.value("tvList").toArray();
    ui->tvcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->tvcombo->addItem(array[i].toString());
    }
    ui->tvcombo->setCurrentText(props.value("tv").toString());
    ui->tvcombo->blockSignals(oldstate);

    oldstate = ui->svcombo->blockSignals(true);
    array = props.value("svList").toArray();
    ui->svcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->svcombo->addItem(array[i].toString());
    }
    ui->svcombo->setCurrentText(props.value("sv").toString());
    ui->svcombo->blockSignals(oldstate);

    oldstate = ui->expccombo->blockSignals(true);
    array = props.value("xvList").toArray();
    ui->expccombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->expccombo->addItem(array[i].toString());
    }
    ui->expccombo->setCurrentText(props.value("xv").toString());
    ui->expccombo->blockSignals(oldstate);

    delete iface;
}

void MainWindow::loadcameraparams(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    props = QJsonDocument::fromJson(data).object();
    QJsonArray array;

    bool oldstate = ui->wbcombo->blockSignals(true);
    ui->wbcombo->setCurrentText(props.value("WBMode").toString());
    ui->wbcombo->blockSignals(oldstate);

    oldstate = ui->sizecombo->blockSignals(true);
    ui->sizecombo->setCurrentText(props.value("stillSize").toString());
    ui->sizecombo->blockSignals(oldstate);

    oldstate = ui->shootmcombo->blockSignals(true);
    ui->shootmcombo->setCurrentText(props.value("shootMode").toString());
    ui->shootmcombo->blockSignals(oldstate);

    oldstate = ui->expmcombo->blockSignals(true);
    ui->expmcombo->setCurrentText(props.value("exposureMode").toString());
    ui->expmcombo->blockSignals(oldstate);

    oldstate = ui->avcombo->blockSignals(true);
    array = props.value("avList").toArray();
    ui->avcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->avcombo->addItem(array[i].toString());
    }
    ui->avcombo->setCurrentText(props.value("av").toString());
    ui->avcombo->blockSignals(oldstate);

    oldstate = ui->tvcombo->blockSignals(true);
    array = props.value("tvList").toArray();
    ui->tvcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->tvcombo->addItem(array[i].toString());
    }
    ui->tvcombo->setCurrentText(props.value("tv").toString());
    ui->tvcombo->blockSignals(oldstate);

    oldstate = ui->svcombo->blockSignals(true);
    array = props.value("svList").toArray();
    ui->svcombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->svcombo->addItem(array[i].toString());
    }
    ui->svcombo->setCurrentText(props.value("sv").toString());
    ui->svcombo->blockSignals(oldstate);

    oldstate = ui->expccombo->blockSignals(true);
    array = props.value("xvList").toArray();
    ui->expccombo->clear();
    for(int i=0;i<array.size();++i)
    {
        ui->expccombo->addItem(array[i].toString());
    }
    ui->expccombo->setCurrentText(props.value("xv").toString());
    ui->expccombo->blockSignals(oldstate);

    delete iface;
}

void MainWindow::on_wbcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("WBMode="+arg1).toUtf8(),params);
}

void MainWindow::on_sizecombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("stillSize="+arg1).toUtf8(),params);
}

void MainWindow::on_shootmcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("shootMode="+arg1).toUtf8(),params);
}

void MainWindow::on_expmcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("exposureMode="+arg1).toUtf8(),params);
}

void MainWindow::on_avcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("av="+arg1).toUtf8(),params);
}

void MainWindow::on_tvcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("tv="+arg1).toUtf8(),params);
}

void MainWindow::on_svcombo_currentIndexChanged(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("sv="+arg1).toUtf8(),params);
}

void MainWindow::on_expccombo_activated(const QString &arg1)
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QString("xv="+arg1).toUtf8(),params);
}

void MainWindow::on_pushgreen_clicked()
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->put(QUrl("http://192.168.0.1/v1/params/camera"),QByteArray(""),params);
}

void MainWindow::on_pushparams_clicked()
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::loadcameraparams);
    params->get(QUrl("http://192.168.0.1/v1/props"),params);
}

void MainWindow::on_pushshoot_clicked()
{
    QByteArray af;
    if(ui->radioafauto->isChecked())
    {
        af="af=auto";
    }
    if(ui->radioafon->isChecked())
    {
        af="af=on";
    }
    if(ui->radioafoff->isChecked())
    {
        af="af=off";
    }
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::on_shoot);
    params->post(QUrl("http://192.168.0.1/v1/camera/shoot"),af,params);
}

void MainWindow::on_shoot(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&MainWindow::on_shoot);

    delete iface;
}

void MainWindow::on_pics(QByteArray data, HttpInterface *iface)
{
    disconnect(iface,&HttpInterface::finished,this,&MainWindow::on_pics);
    QJsonObject picslist = QJsonDocument::fromJson(data).object();
    //qDebug() << "picslist\n\n" << picslist;
    QJsonArray dirs = picslist.value("dirs").toArray();
    //qDebug() << dirs;
    for(int i=0;i<dirs.size();++i)
    {
        QJsonValue name = dirs.at(i).toObject().value("name").toString();
        QJsonArray dir = dirs.at(i).toObject().value("files").toArray();
        for(int j=0;j<dir.size();++j)
        {
            pics.append(name.toString()+'/'+dir[i].toString());
        }
    }
    qDebug() << pics;
    delete iface;
}

void MainWindow::get_pics()
{
    HttpInterface *params = new HttpInterface();
    connect(params,&HttpInterface::finished,this,&MainWindow::on_pics);
    params->get(QUrl("http://192.168.0.1/v1/photos"),params);
}

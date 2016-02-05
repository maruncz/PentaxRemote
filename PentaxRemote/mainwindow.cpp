#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.get(QUrl("http://192.168.0.1/v1/props"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadparams(QByteArray data)
{
    disconnect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    props = QJsonDocument::fromJson(data).object();
    QJsonArray array;
    array = props.value("WBModeList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->wbcombo->addItem(array[i].toString());
    }
    array = props.value("stillSizeList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->sizecombo->addItem(array[i].toString());
    }
    array = props.value("shootModeList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->shootmcombo->addItem(array[i].toString());
    }
    array = props.value("exposureModeList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->expmcombo->addItem(array[i].toString());
    }
    array = props.value("avList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->avcombo->addItem(array[i].toString());
    }
    array = props.value("tvList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->tvcombo->addItem(array[i].toString());
    }
    array = props.value("svList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->svcombo->addItem(array[i].toString());
    }
    array = props.value("xvList").toArray();
    for(int i=0;i<array.size();++i)
    {
        ui->expccombo->addItem(array[i].toString());
    }


}

void MainWindow::on_wbcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("WBMode="+arg1).toUtf8());
}

void MainWindow::on_sizecombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("stillSize="+arg1).toUtf8());
}

void MainWindow::on_shootmcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("shootMode="+arg1).toUtf8());
}

void MainWindow::on_expmcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("exposureMode="+arg1).toUtf8());
}

void MainWindow::on_avcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("av="+arg1).toUtf8());
}

void MainWindow::on_tvcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("tv="+arg1).toUtf8());
}

void MainWindow::on_svcombo_currentIndexChanged(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("sv="+arg1).toUtf8());
}

void MainWindow::on_expccombo_activated(const QString &arg1)
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QString("xv="+arg1).toUtf8());
}

void MainWindow::on_pushgreen_clicked()
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.setparams(QByteArray(""));
}

void MainWindow::on_pushparams_clicked()
{
    connect(&interface,&HttpInterface::finished,this,&MainWindow::loadparams);
    interface.get(QUrl("http://192.168.0.1/v1/props"));
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
    connect(&interface,&HttpInterface::finished,this,&MainWindow::on_shoot);
    interface.shoot(af);
}

void MainWindow::on_shoot(QByteArray data)
{
    disconnect(&interface,&HttpInterface::finished,this,&MainWindow::on_shoot);

}

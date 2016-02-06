#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <functional>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QUrl>

#include "httpinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void loadparams(QByteArray data, HttpInterface *iface);

    void loadcameraparams(QByteArray data, HttpInterface *iface);

    void on_wbcombo_currentIndexChanged(const QString &arg1);

    void on_sizecombo_currentIndexChanged(const QString &arg1);

    void on_shootmcombo_currentIndexChanged(const QString &arg1);

    void on_expmcombo_currentIndexChanged(const QString &arg1);

    void on_avcombo_currentIndexChanged(const QString &arg1);

    void on_tvcombo_currentIndexChanged(const QString &arg1);

    void on_svcombo_currentIndexChanged(const QString &arg1);

    void on_expccombo_activated(const QString &arg1);

    void on_pushgreen_clicked();

    void on_pushparams_clicked();

    void on_pushshoot_clicked();

    void on_shoot(QByteArray data, HttpInterface *iface);

    void on_pics(QByteArray data, HttpInterface *iface);

signals:



private:
    Ui::MainWindow *ui;
    QJsonObject props;
    QStringList pics;

    void get_pics();

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httpinterface.h"


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

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

    void loadparams(QByteArray data);

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

    void on_shoot(QByteArray data);

private:
    Ui::MainWindow *ui;
    HttpInterface interface;
    QJsonObject props;


};

#endif // MAINWINDOW_H

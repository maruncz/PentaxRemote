#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QUrl>

#include <QTimer>
#include <QIcon>
#include <QDateTime>

#include <QList>

#include "httpinterface.h"
#include "gallerynode.h"

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

    void on_latest_info(QByteArray data, HttpInterface *iface);

    void on_pics(QByteArray data, HttpInterface *iface);

    void get_pics();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

signals:



private:
    Ui::MainWindow *ui;
    QJsonObject props;
    QStringList pics;

    QTimer *refresh;

    QList<GalleryNode*> gallery;


};

#endif // MAINWINDOW_H

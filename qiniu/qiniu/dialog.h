#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPoint>
#include <QRect>
#include "json.h"
#include <QProcess>
#include <QItemSelection>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString access_key;
    QString secret_key;
    QString bucket;
    QString src;
    void setparamwithedit();
    QString readFile(const QString &filename);
    QString getsubstring(QString str);

private slots:
    void on_saveconfig_clicked();
    void on_upload();


    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent * e);
    void dropEvent(QDropEvent *e);
};

#endif // DIALOG_H

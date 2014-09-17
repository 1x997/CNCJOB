#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPoint>
#include <QRect>
#include <QLabel>



#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setlablepic(QLabel * lable, Mat image);

    QString AVIfilename;

signals:
    void carSpeedFileNameSetSignal();

private slots:
    void carSpeedFileNameSetProcess();

private:
    Ui::Dialog *ui;

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
};

#endif // DIALOG_H

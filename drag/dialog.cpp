#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);

    setWindowTitle("drag dialog");
    //设置接受拖拽
    setAcceptDrops(true);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dragEnterEvent(QDragEnterEvent * e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }

}

void Dialog::dropEvent(QDropEvent *e)
{

    QPoint p= e->pos();
    QPoint lp= ui->label->pos();
    QRect r(lp.x(),lp.y(),ui->label->width(),ui->label->height());
    if(r.contains(p)){
        foreach (const QUrl &url, e->mimeData()->urls()) {
            const QString &fileName = url.toLocalFile();
            ui->message->setText(fileName);
        }


    }
}

#include "dialog.h"
#include "ui_dialog.h"
#include <QTextEdit>
#include <QFileInfo>
#include <QRegExp>
#include <QMessageBox>
#include <QStringListModel>
#include <QClipboard>
using QtJson::JsonObject;
using QtJson::JsonArray;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QString json = readFile("conf.json");
    if (json.isEmpty()) {
        qFatal("Could not read JSON file!");
        return ;
    }

    bool ok;
    JsonObject result = QtJson::parse(json, ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return ;
    }
    //    qDebug()<< result["src"].toString();
    //    qDebug()<< result["dest"].toString();
    //    qDebug()<< result["deletable"].toInt();
    //    qDebug()<< result["debug_level"].toInt();

    QString dest =result["dest"].toString();
    QStringList list= dest.split("&");
    ui->akEdit->setPlainText(getsubstring(list.at(0)));
    ui->skEdit->setPlainText(getsubstring(list.at(1)));
    ui->bucketEdit->setPlainText(getsubstring(list.at(2)));
    ui->srcEdit->setPlainText(result["src"].toString());

    this->src=result["src"].toString();





    ////    qDebug()<<list.at(0);
    //    qDebug()<<getsubstring(list.at(0));

    ////    qDebug()<<list.at(1);
    //    qDebug()<<getsubstring(list.at(1));

    ////    qDebug()<<list.at(2);
    //    qDebug()<<getsubstring(list.at(2));


}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::setparamwithedit()
{
    QString  ak= ui->akEdit->toPlainText();
    QString  editbucket= ui->bucketEdit->toPlainText();
    QString  sk= ui->skEdit->toPlainText();
    QString  editsrc= ui->srcEdit->toPlainText();

    this->access_key=ak;
    this->secret_key=sk;
    this->bucket=editbucket;
    this->src=editsrc;

}

QString Dialog::readFile(const QString &filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        return QString();
    } else {
        QTextStream in(&f);
        return in.readAll();
    }

}

QString Dialog::getsubstring(QString str)
{

    QString pattern("(.*)=(.*)");
    QRegExp rx(pattern);
    //    QString str("qiniu:access_key=aaaa");
    int pos = str.indexOf(rx);              // 0, position of the first match.
    // Returns -1 if str is not found.
    // You can also use rx.indexIn(str);
    //    qDebug() << pos;
    if ( pos >= 0 )
    {
        //        qDebug() << rx.matchedLength();     // 5, length of the last matched string
        //        // or -1 if there was no match
        //        qDebug() << rx.capturedTexts();     // QStringList(“a=100″, ”a”, ”100″),
        //        //   0: text matching pattern
        //        //   1: text captured by the 1st ()
        //        //   2: text captured by the 2nd ()

        //        qDebug() << rx.cap(0);              // a=100, text matching pattern
        //        qDebug() << rx.cap(1);              // a, text captured by the nth ()
        //        qDebug() << rx.cap(2);              // 100,
        return rx.cap(2);

        //        qDebug() << rx.pos(0);              // 0, position of the nth captured text
        //        qDebug() << rx.pos(1);              // 0
        //        qDebug() << rx.pos(2);              // 2
    }


}

void Dialog::on_saveconfig_clicked()
{
    setparamwithedit();
    //this->secret_key.toStdString().c_str();
    QtJson::JsonObject contributor;
    contributor["debug_level"] = 1;
    contributor["deletable"] = 0;
    contributor["dest"] = "qiniu:access_key="+this->access_key+"&secret_key="+ this->secret_key+"&bucket="+this->bucket;
    contributor["src"] = src.toStdString().c_str();

    QFile file("conf.json");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return ;

    QTextStream out(&file);
    out<<QtJson::serialize(contributor);;

}

void Dialog::on_upload()
{

    QProcess *pProces = (QProcess *)sender();
    QString result = pProces->readAll();
    //    QMessageBox::warning(NULL, "", result);
    qDebug()<<result;
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
    QPoint lp= ui->labeldrag->pos();
    QPoint lpupload= ui->labelupload->pos();
    QRect r(lp.x(),lp.y(),ui->labeldrag->width(),ui->labeldrag->height());
    QRect rupload(lpupload.x(),lpupload.y(),ui->labelupload->width(),ui->labelupload->height());
    if(r.contains(p)){
        foreach (const QUrl &url, e->mimeData()->urls()) {
            const QString &fileName = url.toLocalFile();
            qDebug()<<fileName;
            QFileInfo info(fileName);
            if(info.isDir()){
                qDebug()<<"is dir";
                //                this->src=fileName;
                ui->srcEdit->setPlainText(fileName);

            }
            if(info.isFile()){
                qDebug()<<"is file";
            }

        }
    }

    if(rupload.contains(p)){


        //        QStringList *stringList = new QStringList();
        //        QStringListModel* listModel = new QStringListModel(*stringList, NULL);
        //        ui->listView->setModel(listModel);

        foreach (const QUrl &url, e->mimeData()->urls()) {
            const QString &fileName = url.toLocalFile();
            QFile::copy(fileName, ui->srcEdit->toPlainText()+"/"+url.fileName());


            //            stringList->append(url.fileName());

            ui->listWidget->addItem(url.fileName());

        }







        QProcess *pProces = new QProcess(this);
        connect(pProces, SIGNAL(readyRead()),this, SLOT(on_upload()));
        QStringList  list;
        //list<<"conf.json";
        pProces->start("update.bat", list);
    }
}



void Dialog::on_pushButton_clicked()
{
    //    qDebug()<<ui->listWidget->currentItem()->text();
    QString outurl;
    outurl="http://"+ui->bucketEdit->toPlainText()+".qiniudn.com/"+ui->listWidget->currentItem()->text();

    if(outurl.length()==0){

        ui->lineEdit->setText("请选中文件");

    }
    ui->lineEdit->setText(outurl);

    QClipboard *clipboard = QApplication::clipboard();

    clipboard->setText(outurl);

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filethread.h"
#include <QtGui>
#include <QDebug>
#include <QFileDialog>

QStringList FileThread::existFileNameOpen;
//QString FileThread::existFileNameWrite;
int MainWindow::flag_computing; static QFuture<void> future;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::on_action_Write_triggered()
//{
//    FileThread::existFileNameWrite=QFileDialog::getOpenFileName(this,QString::fromUtf8("Open File"),QDir::currentPath(),"All files(*.*)");
//}

void MainWindow::on_actionOpen_triggered()
{

    FileThread::existFileNameOpen=QFileDialog::getOpenFileNames(this,QString::fromUtf8("Open File"),QDir::currentPath(),"All files(*.*)");

}

 void MainWindow::FileOpenReceive(QStringList filename){
   FileThread::existFileNameOpen=filename;
 }


void MainWindow::on_pushButton_clicked()
{
    int FilesNum=0;
    const int ThreadsNum=4;
    FileThread FileObj;
    QString Thr=ui->lineEdit->text();
    int ThrNum=Thr.toInt();
    int activeThreads=QThreadPool::globalInstance()->activeThreadCount();
    FilesNum=FileObj.existFileNameOpen.size();
    if (ThrNum>=10) ThrNum=10;
    if (ThrNum==0) ThrNum=4;
    if (FilesNum==0) ui->lineEdit_Error->setText("No choosed files, press File->Open");
    int Summary=0;
    qDebug() << ThrNum;
        for (int j=0;j<FilesNum;j++){
            FileObj.Files[j]=FileObj.existFileNameOpen.at(j);
        QThreadPool::globalInstance()->setMaxThreadCount(ThrNum);
       FileObj.future=QtConcurrent::run(FileObj.RFile_NumWords,FileObj.Files[j]);
        activeThreads=QThreadPool::globalInstance()->activeThreadCount();
        qDebug()<<"Active" <<activeThreads;
        }
       FileObj.future.waitForFinished();
      qDebug()<< "Summary Words"<<FileThread::SumWords;
}

void MainWindow::on_pushButton_2_clicked(){
    qDebug()<< "Summary Words"<<FileThread::SumWords;
    QString SumWordsString=QString::number(FileThread::SumWords);
    ui->lineEdit_2->setText(SumWordsString);
}

//void MainWindow::on_actionParams_triggered()
//{
//  Params_mat1 = new Params_mat;
//  Params_mat1->show();
//}

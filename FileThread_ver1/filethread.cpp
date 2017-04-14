#include "filethread.h"
int FileThread::SumWords=0,FileThread::Flag=0;

FileThread::FileThread()
{

}
FileThread::~FileThread()
{
}

int FileThread::RFile_NumWords(QString RFileName)
{
    int WordCount1,WordCount2,WordCount=0;
    int LineCount=1;
    QFile RFile(RFileName);
    if (!RFile.open(QFile::ReadOnly)) return 0;
    else
    {

        QTextStream RText(&RFile);
        QString TrimString,RString;
        for (int i=0;i<LineCount;++i){
            RString=RText.readLine();
            if (!RString.isNull()) ++LineCount;
        RString.remove(QChar(';'),Qt::CaseInsensitive);
        RString.remove(QChar('.'),Qt::CaseInsensitive);
        RString.remove(QChar(':'),Qt::CaseInsensitive);
        TrimString=RString.trimmed();
        WordCount1=TrimString.split(" ").count();
        WordCount2=TrimString.split("\n").count();
        if (WordCount1==WordCount2) WordCount1=0;
        WordCount=WordCount+WordCount1;
        qDebug() << WordCount <<" "<<RString;
        }
        RFile.close();
        SumWords=WordCount+SumWords;
        Flag=1;
    }
    return Flag;
}

void FileThread::process()
{
   qDebug() << FileThread::CurFile;
   FileThread::RFile_NumWords(FileThread::CurFile);
}
void FileThread::addThread(QString CFile)
{
    QThread* thread = new QThread;
    FileThread* filethread= new FileThread;
    filethread->CurFile=CFile;
    filethread->moveToThread(thread);
    connect(thread,SIGNAL(started()),filethread,SLOT(process()));
    connect(filethread,SIGNAL(finished()),thread,SLOT(quit()));
    connect(filethread,SIGNAL(finished()),filethread,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}


void FileThread::addThreadS(QStringList CFileList)
{
    QThread* thread = new QThread;
    FileThread* filethread= new FileThread;
    filethread->FileList=CFileList;
    filethread->moveToThread(thread);
    connect(thread,SIGNAL(started()),filethread,SLOT(process()));
    connect(filethread,SIGNAL(finished()),thread,SLOT(quit()));
    connect(filethread,SIGNAL(finished()),filethread,SLOT(deleteLater()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}

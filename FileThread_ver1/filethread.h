#ifndef FILETHREAD_H
#define FILETHREAD_H
#include <QThread>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QtConcurrent/QtConcurrentMap>
#include <QtConcurrent/QtConcurrentRun>
#include <math.h>
class FileThread: public QObject
{
    Q_OBJECT

public:
    FileThread();
    ~FileThread();
static int RFile_NumWords(QString RFileName);
void addThread(QString CFile);
void addThreadS(QStringList CFileList);
QString CurFile;
QString Files[20];
static QStringList existFileNameOpen;
QStringList FileList;
//static QString existFileNameWrite;
QFuture <int> future;
static int Flag;
static int SumWords;
public slots:
    void process();
   // void stop();


signals:
    void finished();
};

#endif // FILETHREAD_H

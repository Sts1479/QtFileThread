#ifndef SESSION_H
#define SESSION_H

#include <QThread>
#include <QStringList>

class Session: public QObject
{
    Q_OBJECT

public:
    //Session(QObject *parent, const QString &directory, const QVector<FileNum> &f_num);
   // ~Session();
    void buildReports();

private:
  //  void addThreads(FileNum f_num);
    void stopThreads();

    QStringList files;
signals:
    void stopAll();
};

#endif // SESSION_H

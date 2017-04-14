#ifndef WORDSCOUNTER_H
#define WORDSCOUNTER_H
#include <QString>
#include <QFile>
class WordsCounter
{
public:
    //void WordsCounter();
    static void RFile_Count(QString RFileName);
    void WriteFile(QString WFileName);
};

#endif // WORDSCOUNTER_H

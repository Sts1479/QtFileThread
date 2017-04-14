#include "wordscounter.h"
#include <QDebug>

void WordsCounter::RFile_Count(QString RFileName)
{
    int WordCount1,WordCount2,WordCount=0;
    int LineCount=1;
    QFile RFile(RFileName);
    if (!RFile.open(QFile::ReadOnly)) return;
    else
    {
//        QTextStream RText(&RFile);
//        QString RContent=RText.readAll();
//        //QStringList RList = RContent.split("\n");
//        QString TrimContent=RContent.trimmed();
//        int WordCount1=RContent.split(" ").count();
//        int WordCount2=RContent.split("\n").count();
//        qDebug() << WordCount1 <<" "<<WordCount2;
//        RFile.close();

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
    }

}

void WordsCounter::WriteFile(QString WFileName){

    const int data_size=100;
    QFile WFile(WFileName);
      if (!WFile.open(QFile::ReadOnly)){
        WFile.close();
        WFile.open(QFile::WriteOnly);
        QTextStream WText(&WFile);
        WText<<"\n";
        for (int i=0;i<data_size;i++)
        {
            WText<<"\n";
                         ;
            //WText<<G_file::kData[i];

        }

    }
    else{
        QTextStream WText(&WFile);
        //QStringList idList;
        QString WContent=WText.readAll();
        QStringList WList = WContent.split("\n");
        //currentid = idList.size();
        WFile.close();
        //WFile.open(QFile::Append|QFile::Text);
        WFile.open(QFile::Text|QFile::WriteOnly);
    //             WText<<"\n";
//                  for (int i=0;i<NDataSize;i++)
//                  {
//                      WText<<"\n";
//                      //OutText<<MathMethods::valIDFTData.IAmpl[i];
//                      //WText<<MathMethods::valIDFTData.IAmpl[i];
//                      WText<<ExtraMNK::PolData[i];
//                  }
    }
    WFile.close();

}

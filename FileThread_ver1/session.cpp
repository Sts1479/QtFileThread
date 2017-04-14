#include "session.h"



//void Session::allThreads()
//{
//    QThread* thread = new QThread;
//    proc->setFileList(files);
//    proc->moveToThread(thread);
//    connect (thread, SIGNAL(started()),proc, SLOT(process()));
//    connect (proc, SIGNAL(finished()),thread, SLOT(quit()));
//    connect (this, SIGNAL(stopAll()), proc, SLOT(stop()));
//    connect(proc, SIGNAL(finished()), proc, SLOT(deleteLater()));
//    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//    thread->start();
//    return;
//}

void Session::stopThreads()
{
    emit stopAll();
}

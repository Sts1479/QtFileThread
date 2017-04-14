#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int flag_computing;
    static QString OpenFileName;
private slots:
    //void on_action_Write_triggered();
    void on_actionOpen_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

   // void on_actionParams_triggered();

public slots:
    void FileOpenReceive(QStringList filename);
    //void DWriteFileReceive(QString filename);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

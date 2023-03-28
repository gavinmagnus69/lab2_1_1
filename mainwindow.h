#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "listcalls.h"
#include "listuser.h"
#include <QMessageBox>
#include "fromfile.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    fromfile bebra;
    bool chk = 0;
    listcalls calls;
    listuser users;
    QFile file1;
    int cntusers=0;
    int cntcalls=0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updatetable1();
    void updatetable2();
public slots:
    void on_selectfilebutton_clicked();
private slots:
    void on_adduserbutton_clicked();

    void on_addcallbutton_clicked();

    void on_findinforaboutnum_clicked();

    void on_canelbutton_clicked();

    void on_findcitybutton_clicked();

    void on_deleteuserbutton_clicked();

    void on_rewritefilebutton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

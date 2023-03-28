#ifndef FROMFILE_H
#define FROMFILE_H
#include <QFile>
#include "listcalls.h"
#include "listuser.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
class fromfile
{

public:
    fromfile( );
    bool importfile(listcalls &a, listuser &b, QFile &file,int &cntusers,int &cntcalls);
    void rewritefile(listcalls a, listuser b, QFile &file);
};

#endif // FROMFILE_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->callfromedit->setInputMask("+000000000000");
    ui->calltoedit->setInputMask("+000000000000");
    ui->phonenumberedit->setInputMask("+000000000000");
    ui->findnum->setInputMask("+000000000000");
    ui->deleteuserspin->setMinimum(1);
//    connect(ui->selectfilebutton,SIGNAL(pressed()),this,SLOT(on_selectfilebutton_clicked()));
//    connect(ui->adduserbutton,SIGNAL(pressed()),this,SLOT(on_adduserbutton_clicked()));
//    connect(ui->addcallbutton,SIGNAL(pressed()),this,SLOT(on_addcallbutton_clicked()));
//    connect(ui->findinforaboutnum,SIGNAL(pressed()),this,SLOT(on_findinforaboutnum_clicked()));
//    connect(ui->canelbutton,SIGNAL(pressed()),this,SLOT(on_canelbutton_clicked()));
//    connect(ui->findcitybutton,SIGNAL(pressed()),this,SLOT(on_findcitybutton_clicked()));
//    connect(ui->deleteuserbutton,SIGNAL(pressed()),this,SLOT(on_deleteuserbutton_clicked()));
//    connect(ui->rewritefilebutton,SIGNAL(pressed()),this,SLOT(on_rewritefilebutton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatetable1(){
    ui->userstable->setColumnCount(4);
    ui->userstable->setRowCount(cntusers);
    int cnt=0;
    for(node * ptr = users.head;ptr!=nullptr;ptr=ptr->next){
        qDebug()<<"person name: "<<ptr->person.name<<" midname : "<<ptr->person.midname<<" sur : "<<ptr->person.surname<<" phone num:"<<ptr->person.phonenumber<<"\n";
        QTableWidgetItem * itm = new QTableWidgetItem(ptr->person.name);
        ui->userstable->setItem(cnt,0,itm);
        QTableWidgetItem * itm2 = new QTableWidgetItem(ptr->person.midname);
        ui->userstable->setItem(cnt,1,itm2);
        QTableWidgetItem * itm3 = new QTableWidgetItem(ptr->person.surname);
        ui->userstable->setItem(cnt,2,itm3);
        QTableWidgetItem * itm4 = new QTableWidgetItem(ptr->person.phonenumber);
        ui->userstable->setItem(cnt,3,itm4);
        cnt++;
    }
    //ui->deleteuserspin->setMinimum(cntusers);
    qDebug()<<"we are here";
    updatetable2();

}
void MainWindow::updatetable2(){
    ui->callstable->setColumnCount(7);
    qDebug()<<cntcalls;
    ui->callstable->setRowCount(cntcalls);
    //date code city duration rate to from
    int cnt = 0;
    for(node2 * ptr = calls.head;ptr!=nullptr;ptr=ptr->next){
        if(cnt==cntcalls){
            break;
        }
        qDebug()<<cnt;
        qDebug()<<ptr->call.city<<" "<<ptr->call.myphonenumber<<" "<<ptr->call.code<<" "<<ptr->call.date<<" "<<ptr->call.duration<<" "<<ptr->call.rate<<" "<<ptr->call.tophonenumber;
        QTableWidgetItem * itm = new QTableWidgetItem(ptr->call.date);
        ui->callstable->setItem(cnt,0,itm);
        QTableWidgetItem * itm2 = new QTableWidgetItem(ptr->call.code);
        ui->callstable->setItem(cnt,1,itm2);
        QTableWidgetItem * itm3 = new QTableWidgetItem(ptr->call.city);
        ui->callstable->setItem(cnt,2,itm3);
        QTableWidgetItem * itm4 = new QTableWidgetItem(ptr->call.duration);
        ui->callstable->setItem(cnt,3,itm4);
        QTableWidgetItem * itm5 = new QTableWidgetItem(ptr->call.rate);
        ui->callstable->setItem(cnt,4,itm5);
        QTableWidgetItem * itm6 = new QTableWidgetItem(ptr->call.tophonenumber);
        ui->callstable->setItem(cnt,5,itm6);
        QTableWidgetItem * itm7 = new QTableWidgetItem(ptr->call.myphonenumber);
        ui->callstable->setItem(cnt,6,itm7);
        cnt++;
    }



}
void MainWindow::on_selectfilebutton_clicked()
{
    if(chk){

            QMessageBox bruh;
                   bruh.setWindowTitle("ti loh");
                           bruh.setInformativeText(
                           "error 228"            );
                           bruh.setText("you are already working with a file.");
                           bruh.exec();
                   return;

    }
    file1.setFileName(QFileDialog::getOpenFileName(this, tr("Open file")));
    chk = bebra.importfile(calls ,users, MainWindow::file1 , cntusers,cntcalls);
//    file.open(QIODeviceBase::ReadWrite);
//    QString txt = ".txt";
//    QString filename = file.fileName();
//    if(!filename.contains(txt)){
//        QMessageBox bruh;
//        bruh.setWindowTitle("ti loh");
//                bruh.setInformativeText(
//                "error 228"            );
//                bruh.setText("this wrong i can feel it.");
//                bruh.exec();
//        return;
//    }
//    if(filename == ""){
//        QMessageBox bruh;
//        bruh.setWindowTitle("ti loh");
//                bruh.setInformativeText(
//                "error 228"            );
//                bruh.setText("this wrong i can feel it.");
//                bruh.exec();
//        return;
//    }
//    QString s;
//    QString stemp;
//    Calls tempcall;
//    User tempuser;
//    int entercnt = 0;
//    while(!file.atEnd()){
//        entercnt=0;
//        s = file.readLine();
//        s.remove(s.length()-2,1);
//        qDebug()<<"fullstring: "<<s;

//        //text format
//        //name <-1 midname <-2 surname <-3 telephonenumber <-4 city <-5 code <-6 date <-7 duration <-8 price <-9 from <-10 to
//        if(s.length()>10){
//        for(int i = 0 ;i<s.length();++i){
//            if(s[i]==' '||s[i]=='\n'){
//                entercnt++;
//                if(entercnt==1){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c1: "<<stemp;
//                    tempuser.name =stemp;
//                    stemp="";
//                    continue;
//                }
//                if(entercnt==2){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c2: "<<stemp;
//                    tempuser.midname = stemp;
//                    stemp="";
//                    continue;
//                }
//                if(entercnt==3){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c3: "<<stemp;
//                    tempuser.surname = stemp;

//                    stemp="";
//                    continue;
//                }
//                if(entercnt==4){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c4: "<<stemp;
//                    tempuser.phonenumber = stemp;
//                    users.pushback(tempuser);
//                    cntusers++;
//                    stemp="";
//                    continue;
//                }
//                if(entercnt==5){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c5: "<<stemp;
//                    tempcall.city = stemp;
//                    stemp="";
//                    continue;

//                }
//                if(entercnt==6){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c6: "<<stemp;
//                    tempcall.code  = stemp;
//                    stemp="";
//                    continue;

//                }
//                if(entercnt==7){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c7: "<<stemp;
//                    tempcall.date = stemp;
//                    stemp="";
//                    continue;
//                }
//                if(entercnt==8){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c8: "<<stemp;
//                    tempcall.duration = stemp;
//                    stemp="";
//                    continue;

//                }
//                if(entercnt==9){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c9: "<<stemp;
//                    tempcall.rate = stemp;
//                    stemp="";
//                    continue;

//                }
//                if(entercnt==10){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                    qDebug()<<"c10: "<<stemp;
//                    tempcall.myphonenumber = stemp;
//                    stemp="";
//                    continue;
//                }
//                if(entercnt==11){
//                    if(stemp==""||stemp==" "){
//                        QMessageBox bruh;
//                        bruh.setWindowTitle("ti loh");
//                                bruh.setInformativeText(
//                                "error 228"            );
//                                bruh.setText("this wrong i can feel it.");
//                                bruh.exec();
//                        return;

//                    }
//                qDebug()<<"c11: "<<stemp;
//                tempcall.tophonenumber = stemp;
//                calls.pushback(tempcall);
//                cntcalls++;
//                stemp="";
//                continue;
//                }
//            }
//            stemp+=s[i];


//         }
//        }

//       }
//    file.close();
//    chk=1;
    if(chk){
    updatetable1();
    }
    }






void MainWindow::on_adduserbutton_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    qDebug()<<"adduser clicked";
   cntusers++;
   QString num =  ui->phonenumberedit->text();
   QString nam = ui->nameedit->text();
   QString mid = ui->midnameedit->text();
   QString sur = ui->surnameedit->text();
   User temp;
   temp.name = nam;
   temp.midname = mid;
   temp.surname = sur;
   temp.phonenumber = num;
   if(nam==""||mid==""||sur==""||num==""){
           QMessageBox bruh;
                  bruh.setWindowTitle("ti loh");
                          bruh.setInformativeText(
                          "error 228"            );
                          bruh.setText("this wrong i can feel it.");
                          bruh.exec();
                  return;

   }
   users.pushback(temp);
   updatetable1();
}


void MainWindow::on_addcallbutton_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    qDebug()<<"addcallbutton clicked";
    QString cit = ui->entercityedit->text();
    QString cod = ui->entercodeedit->text();
    int rate = ui->enterratespin->value();
    QString rat = QString::number(rate);
    QString dur =  QString::number(ui->enterdurationspin->value());
    QString dat = ui->dateEdit->text();
    //qDebug()<<dat;
    QString to = ui->calltoedit->text();
    QString from = ui->callfromedit->text();
    bool chk = 0;
    for(node * ptr = users.head;ptr!=nullptr;ptr=ptr->next){
        if(ptr->person.phonenumber == from){
            chk=1;
        }
        if(chk==1){
            break;
        }
    }

    if(chk==1){
        cntcalls++;
        qDebug()<<"this case228";

        Calls tmp;
        tmp.city = cit;
        tmp.code = cod;
        tmp.date = dat;
        tmp.duration = dur;
        tmp.rate = rat;
        tmp.myphonenumber = from;
        tmp.tophonenumber = to;
        qDebug()<<tmp.city<<" "<<tmp.myphonenumber<<" "<<tmp.tophonenumber<<" "<<tmp.code<<" "<<tmp.date<<" "<<tmp.duration<<" "<<tmp.rate;
        calls.pushback(tmp);
        updatetable2();
    }
    else{
        QMessageBox bruh;
        bruh.setWindowTitle("ti loh");
        bruh.setInformativeText(
        "error 228"            );
        bruh.setText("please, enter this user first");
        bruh.exec();
       return;
    }
}


void MainWindow::on_findinforaboutnum_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    QString s = ui->findnum->text();
    if(s==""){
        return;
    }
    else{
        int n1 = ui->userstable->rowCount();
        int n2 = ui->callstable->rowCount();
        for(int i = 0;i<n1;i++){
            QString tempnum = ui->userstable->item(i,3)->text();
            if(s!=tempnum){
                ui->userstable->hideRow(i);
            }
        }
        for(int i =0;i<n2;i++){
            QString tempnum2 = ui->callstable->item(i,6)->text();
            if(s!=tempnum2){
                ui->callstable->hideRow(i);
            }

        }

    }
}


void MainWindow::on_canelbutton_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    int n1 = ui->userstable->rowCount();
    for(int i = 0;i<n1;i++){
        ui->userstable->showRow(i);
    }
    n1 = ui->callstable->rowCount();
    for(int i = 0;i<n1;i++){
        ui->callstable->showRow(i);
    }
    updatetable1();
}


void MainWindow::on_findcitybutton_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    QString s = ui->findcityedit->text();
    int n = ui->callstable->rowCount();
    for(int i =0; i<n;i++){
     QString temp = ui->callstable->item(i,2)->text();
     if(s!=temp){
         ui->callstable->hideRow(i);
     }
    }

}


void MainWindow::on_deleteuserbutton_clicked()
{
    if(!chk){
        QMessageBox bruh;
               bruh.setWindowTitle("ti loh");
                       bruh.setInformativeText(
                       "error 228"            );
                       bruh.setText("this wrong i can feel it.");
                       bruh.exec();
               return;
    }
    if(cntusers==0){

            QMessageBox bruh;
                   bruh.setWindowTitle("ti loh");
                           bruh.setInformativeText(
                           "error 228"            );
                           bruh.setText("no users.");
                           bruh.exec();
                   return;

    }

    qDebug()<<"delete clicked";
    int n =1;
    n = ui->deleteuserspin->value();
    qDebug()<<"from spin :"<<n<<" actual users:"<<cntusers;

    if(n>cntusers){
        return;
    }
    QString num_to_delete = ui->userstable->item(n-1 ,3)->text();
    qDebug()<<num_to_delete;
    int count_of_calls = ui->callstable->rowCount();
    for(int i = 0;i<count_of_calls;i++){
        if(ui->callstable->item(i,6)->text()==num_to_delete){
            qDebug()<<"case inside cycle";
            qDebug()<<i;
            calls.erase(i);
            qDebug()<<"erased call";
            cntcalls--;
            qDebug()<<cntcalls<<" cntcalls amount";
            //count_of_calls--;
        }
        qDebug()<<"cycle 1";
    }
    qDebug()<<"out of cycle";
    users.erase(n-1);
    qDebug()<<"after erasing";
    cntusers--;
    qDebug()<<"cntusers: "<<cntusers;
    updatetable1();
}


void MainWindow::on_rewritefilebutton_clicked()
{
 bebra.rewritefile(calls,users,file1);
}


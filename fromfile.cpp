#include "fromfile.h"

fromfile::fromfile()
{

}
bool fromfile::importfile(listcalls &a, listuser &b,QFile &file,int &cntusers,int &cntcalls){
   file.open(QIODeviceBase::ReadWrite);
   QString txt = ".txt";
   QString filename = file.fileName();
   if(!filename.contains(txt)){
       QMessageBox bruh;
       bruh.setWindowTitle("ti loh");
               bruh.setInformativeText(
               "error 228"            );
               bruh.setText("this wrong i can feel it.");
               bruh.exec();
       return 0;
   }
   if(filename == ""){
       QMessageBox bruh;
       bruh.setWindowTitle("ti loh");
               bruh.setInformativeText(
               "error 228"            );
               bruh.setText("this wrong i can feel it.");
               bruh.exec();
       return 0;
   }
   QString s;
   QString stemp;
   Calls tempcall;
   User tempuser;
   int entercnt2 = 0;
   while(!file.atEnd()){
       entercnt2=0;
       s = file.readLine();
       s.remove(s.length()-2,1);
       qDebug()<<"fullstring: "<<s;
       for(int i =0;i<s.length();i++){
           if(s[i]==' '){
               entercnt2++;
           }
       }
       qDebug()<<entercnt2;
       if(entercnt2==3){
           int entercnt = 0;
           for(int i =0;i<s.length();i++){
               if(s[i]==' '||s[i]=='\n'){
                   entercnt++;
                   if(entercnt==1){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c1: "<<stemp;
                       tempuser.name =stemp;
                       stemp="";
                       continue;
                   }
                   if(entercnt==2){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c2: "<<stemp;
                       tempuser.midname = stemp;
                       stemp="";
                       continue;
                   }
                   if(entercnt==3){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c3: "<<stemp;
                       tempuser.surname = stemp;

                       stemp="";
                       continue;
                   }
                   if(entercnt==4){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c4: "<<stemp;
                       tempuser.phonenumber = stemp;
                       b.pushback(tempuser);
                       cntusers++;
                       stemp="";
                       break;
                   }



                }
               stemp+=s[i];


       }//for

       //text format
       //name <-1 midname <-2 surname <-3 telephonenumber <-4 city <-5 code <-6 date <-7 duration <-8 price <-9 from <-10 to






    }//if
       if(entercnt2==6){
           int entercnt = 0;
           for(int i =0;i<s.length();i++){
               if(s[i]==' '||s[i]=='\n'){
                   entercnt++;
                   if(entercnt==1){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c5: "<<stemp;
                       tempcall.city = stemp;
                       stemp="";
                       continue;

                   }
                   if(entercnt==2){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c6: "<<stemp;
                       tempcall.code  = stemp;
                       stemp="";
                       continue;

                   }
                   if(entercnt==3){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c7: "<<stemp;
                       tempcall.date = stemp;
                       stemp="";
                       continue;
                   }
                   if(entercnt==4){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c8: "<<stemp;
                       tempcall.duration = stemp;
                       stemp="";
                       continue;

                   }
                   if(entercnt==5){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c9: "<<stemp;
                       tempcall.rate = stemp;
                       stemp="";
                       continue;

                   }
                   if(entercnt==6){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                       qDebug()<<"c10: "<<stemp;
                       tempcall.myphonenumber = stemp;
                       stemp="";
                       continue;
                   }
                   if(entercnt==7){
                       if(stemp==""||stemp==" "){
                           QMessageBox bruh;
                           bruh.setWindowTitle("ti loh");
                                   bruh.setInformativeText(
                                   "error 228"            );
                                   bruh.setText("this wrong i can feel it.");
                                   bruh.exec();
                           return 0;

                       }
                   qDebug()<<"c11: "<<stemp;
                   tempcall.tophonenumber = stemp;
                   a.pushback(tempcall);
                   cntcalls++;
                   stemp="";
                   break;
                   }






               }
               stemp+=s[i];



           }//for




       }
       //if ==6
//       else{
//           QMessageBox bruh;
//           bruh.setWindowTitle("ti loh");
//                   bruh.setInformativeText(
//                   "error 228"            );
//                   bruh.setText("corrupted file.");
//                   bruh.exec();
//           return 0;


//       }





}//while
   file.close();
   return 1;
}
void fromfile::rewritefile(listcalls a, listuser b, QFile &file){
    file.open(QIODeviceBase::ReadWrite|QIODeviceBase::Truncate);
    for(node * ptr = b.head;ptr!=nullptr;ptr = ptr->next){
    QString temp = ptr->person.name+" " + ptr->person.midname+" "+ptr->person.surname+ " " + ptr->person.phonenumber+'\n';
    qDebug()<<temp;
    QTextStream bruh(&file);
    bruh<<temp;
    }
    //city <-5 code <-6 date <-7 duration <-8 price <-9 from <-10 to
    for(node2 * ptr = a.head;ptr!=nullptr;ptr = ptr->next){
    QString temp = ptr->call.city +" " + ptr->call.code+" "+ptr->call.date+ " " + ptr->call.duration+" "+ ptr->call.rate+ " " +ptr->call.myphonenumber + " " + ptr->call.tophonenumber + '\n';
    qDebug()<<"rewritung: "<<temp;
    QTextStream bruh(&file);
    bruh<<temp;
    }
    file.close();
};

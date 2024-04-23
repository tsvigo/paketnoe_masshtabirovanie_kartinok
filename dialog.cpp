#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <iostream>
#include <fstream>
using namespace std;
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// нужен сисок файлов в каталоге с полными путями.
/// 
void listDirectory(const QString &directoryPath, const QString &outputFilePath) {
    QDir dir(directoryPath);
    if (!dir.exists()) {
        qDebug() << "Directory does not exist:" << directoryPath;
        return;
    }

    QFile file(outputFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "Failed to open file for writing:" << outputFilePath;
        return;
    }

    QTextStream out(&file);
   // out << "Full path of files in directory:\n";

    for (const QFileInfo &fileInfo : dir.entryInfoList(QDir::Files)) {
        out << fileInfo.absoluteFilePath() << "\n";
    }

    file.close();
}
/// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// / 
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// convert путь-к-картинке -resize 10x10 -background White -gravity center -extent 10x10 путь-к-выходной-картинке
/// /mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   QString myString;
    const int len = 2832, strings =357;
    const char ch = '\n';
    char mass[len][strings];
    
    ifstream fs("/home/viktor/my_projects_qt_2/paketnoe_masshtabirovanie_kartinok/spisok.txt", ios::in | ios::binary);
    
    QString comanda1="convert \"";    
      QString puty;
    QString comanda3="\" -resize 10x10 -background White -gravity center -extent 10x10 \"";
    QString puty_vihod="/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/";
   QString comanda4=".bmp\"";
    QString comanda_vsia;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    for(int r = 0; r<strings; r++)
    {
        fs.getline(mass[r], len-1,ch); //Считываем строки в массив
        
        puty=mass[r];
        // subString = myString.mid(7,myString.size() - 1);
        comanda_vsia=comanda1+puty+comanda3+puty_vihod+QString::number(r)+comanda4;
        system (comanda_vsia.toStdString().c_str() );
     
    }

    fs.close(); //Закрываем файл 
/// 
/// 
///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// / 
         
     }

Dialog::~Dialog()
     {
          delete ui;
     }


void Dialog::on_pushButton_clicked()
{
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 listDirectory("/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/", 
 "/home/viktor/my_projects_qt_2/paketnoe_masshtabirovanie_kartinok/spisok.txt");
///  
}


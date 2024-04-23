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
 listDirectory("/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/", 
 "/home/viktor/my_projects_qt_2/paketnoe_masshtabirovanie_kartinok/spisok.txt");
///           
     }

Dialog::~Dialog()
     {
          delete ui;
     }


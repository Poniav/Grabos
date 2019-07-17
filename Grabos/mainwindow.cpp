#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TextEditeur");

    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(openAction()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(getFile()));
    connect(ui->pushButton_Save, SIGNAL(clicked()), this, SLOT(saveFileOpen()));
    connect(ui->pushButton_Quitter, SIGNAL(clicked()), this, SLOT(closeFileOpened()));
}

MainWindow::~MainWindow()
{
    delete fwindow;
    delete ui;
}

void MainWindow::openAction()
{
    fwindow = new Dialog(this);
    fwindow->setWindowTitle("A propos");
    fwindow->show();
}

void MainWindow::getFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, QString("Ouvrir un fichier"), QDir::homePath(), "Les fichiers (*.txt)");

    QFile file(fileName);

    this->setFileName(fileName);

    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            ui->plainTextEdit->setPlainText(file.readAll());
            file.close();
        }
    }

    if(!file.exists())
    {
        QMessageBox notif(this);
        notif.setText("Le fichier n'existe pas");
    }
}

void MainWindow::saveFileOpen()
{
//    QString fileName = QFileDialog::getSaveFileName(this, QString("Sauvegarder le fichier"), QDir::homePath(), "Les fichiers (*.txt)");

//    QFile file(fileName);

//    if (file.open(QIODevice::WriteOnly))
//    {

//    }

    qDebug() << this->fileName;

}

void MainWindow::closeFileOpened()
{
    ui->plainTextEdit->clear();
    this->setFileName("");
}

QString MainWindow::getFileName()
{
    return this->fileName;
}

void MainWindow::setFileName(QString file)
{
    this->fileName = file;
}

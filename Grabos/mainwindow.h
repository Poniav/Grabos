#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openAction();
    void getFile();
    void closeFileOpened();
    void saveFileOpen();
    void compareText();
private:
    Ui::MainWindow *ui;
    Dialog *fwindow;
    QString getFileName();
    void setFileName(QString File);
    QString fileName;
    QString getFileContent(const QString &filename);
};

#endif // MAINWINDOW_H

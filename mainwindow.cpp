#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QDebug>

bool isPracticeStarted = false;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuGitHub_triggered()
{
    QString link = "http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
    QApplication::quit();
}

void MainWindow::startPractice(language lang)
{
    qDebug() << ((QString) "run");

    if (lang == Java)
    {
        qDebug() << ((QString) "Java");
        isPracticeStarted = true;
    }

    if (lang == Cpp)
    {
        qDebug() << ((QString) "Cpp");
        isPracticeStarted = true;
    }

    if (isPracticeStarted)
    {
        qDebug() << ((QString) "true");
        ui->bStartJava->hide();
    }
}

void MainWindow::on_bStartJava_clicked()
{
    language lang = Java;
    startPractice(lang);
}

void MainWindow::on_bStartCpp_clicked()
{
    language lang = Cpp;
    startPractice(lang);
}

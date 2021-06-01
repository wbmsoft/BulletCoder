#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QDebug>
#include <QTimer>

#include <QPlainTextEdit>

using namespace std;

bool isPracticeStarted = false;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!isPracticeStarted)
    {
        ui->bStartCpp->setVisible(true);
        ui->bStartJava->setVisible(true);

        ui->plainLessonSource->setVisible(false);
        ui->bStartLesson->setVisible(false);
        ui->labelCountTime->setVisible(false);
        ui->bExitLesson->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

class Lesson : MainWindow
{

public:
    string name;
    int id;

    int time;

    int wpm;
    int lessonsAllChar;

    int accuracy;

    int correctTypedCharacters;
    int wrongTypedCharacters;

    void startLesson(language lang) {
        if (lang == Java)
        {

        }
    }

    int countWpm() {

        return ((lessonsAllChar/5) - wrongTypedCharacters) / time;

    }

    int countAccuracy() {
        return (correctTypedCharacters/lessonsAllChar);
    }
/*
    int countTime() {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);
        int allTime = 0;
        allTime = allTime + 1;
        qDebug() << ((QString) allTime);
    }
*/
};

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
        Lesson lesson;

        qDebug() << ((QString) "true");

        // If button was pushed we hide all elements
        ui->bStartJava->hide();
        ui->bStartCpp->setVisible(false);

        ui->plainLessonSource->setVisible(true);
        ui->bStartLesson->setVisible(true);
        ui->labelCountTime->setVisible(true);
        ui->bExitLesson->setVisible(true);

        lesson.startLesson(lang);
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

void MainWindow::on_bExitLesson_clicked()
{
    ui->bStartJava->setVisible(true);
    ui->bStartCpp->setVisible(true);

    ui->plainLessonSource->setVisible(false);
    ui->bStartLesson->setVisible(false);
    ui->labelCountTime->setVisible(false);
    ui->bExitLesson->setVisible(false);

    isPracticeStarted = false;
}





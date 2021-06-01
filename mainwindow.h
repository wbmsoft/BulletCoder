#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum language {
    Java,
    Cpp
};

enum status {
    newly_opened,
    practicing
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void startLesson(language lang);
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    ~MainWindow();

private slots:
    void startPractice(language lang);

    void on_menuGitHub_triggered();

    void on_bStartJava_clicked();

    void on_bStartCpp_clicked();

};
#endif // MAINWINDOW_H

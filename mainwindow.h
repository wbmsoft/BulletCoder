#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum language {
    Java,
    Cpp
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startPractice(language lang);

    void on_menuGitHub_triggered();

    void on_bStartJava_clicked();

    void on_bStartCpp_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

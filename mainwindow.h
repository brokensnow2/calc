#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum BtnType
{
    Num,
    Op,
    Dot,
    Equal,
    Clear,
    Back
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString num1;
    QString num2;
    QString op;
public slots:
    void OnClicked(BtnType _type,QString _btn);
};
#endif // MAINWINDOW_H

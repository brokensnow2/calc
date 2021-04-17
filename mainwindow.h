#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum BtnType
{
    Num,//数字
    Op,//运算
    Re,//倒数
    Dot,//点
    Sq,//平方
    Ra,//根号
    Eq,//等于
    Clear,//C
    Ch,// 正负号+/-
    Per,//百分号
    Back// 退格
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
    double a,b,result;
public slots:
    void OnClicked(BtnType _type,QString _btn);
};
#endif // MAINWINDOW_H

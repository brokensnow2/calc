#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //数字按钮绑定
    connect(ui->Zero,&QPushButton::clicked,[this](){
        OnClicked(Num,"0");
    });
    connect(ui->One,&QPushButton::clicked,[this](){
        OnClicked(Num,"1");
    });
    connect(ui->Two,&QPushButton::clicked,[this](){
        OnClicked(Num,"2");
    });
    connect(ui->Three,&QPushButton::clicked,[this](){
        OnClicked(Num,"3");
    });
    connect(ui->Four,&QPushButton::clicked,[this](){
        OnClicked(Num,"4");
    });
    connect(ui->Five,&QPushButton::clicked,[this](){
        OnClicked(Num,"5");
    });
    connect(ui->Six,&QPushButton::clicked,[this](){
        OnClicked(Num,"6");
    });
    connect(ui->Seven,&QPushButton::clicked,[this](){
        OnClicked(Num,"7");
    });
    connect(ui->Eight,&QPushButton::clicked,[this](){
        OnClicked(Num,"8");
    });
    connect(ui->Nine,&QPushButton::clicked,[this](){
        OnClicked(Num,"9");
    });

    //运算符号绑定
    connect(ui->Except,&QPushButton::clicked,[this](){
        OnClicked(Op,"/");
    });
    connect(ui->Sub,&QPushButton::clicked,[this](){
        OnClicked(Op,"+");
    });
    connect(ui->Reduce,&QPushButton::clicked,[this](){
        OnClicked(Op,"-");
    });
    connect(ui->Mul,&QPushButton::clicked,[this](){
        OnClicked(Op,"*");
    });
    connect(ui->Radical,&QPushButton::clicked,[this](){
        OnClicked(Op,"√");
    });
    connect(ui->Percent,&QPushButton::clicked,[this](){
        OnClicked(Op,"%");
    });
    connect(ui->One,&QPushButton::clicked,[this](){
        ui->lineEdit->setText("1");
    });
}
void MainWindow::OnClicked(BtnType _type,QString _btn)
{
    static QString str="";
    str += _btn;
    ui->lineEdit->setText(str);
}
MainWindow::~MainWindow()
{
    delete ui;
}


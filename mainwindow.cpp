#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //数字按钮绑定在line edit显示

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

    //运算符号绑定显示

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

    //其他

    connect(ui->Percent,&QPushButton::clicked,[this]()
    {
        OnClicked(Per,"");
    });
    connect(ui->Reciprocal,&QPushButton::clicked,[this]()
    {
        OnClicked(Re,"");
    });
    connect(ui->Point,&QPushButton::clicked,[this]()
    {
        OnClicked(Dot,"");
    });
    connect(ui->Square,&QPushButton::clicked,[this]()
    {
        OnClicked(Sq,"");
    });
    connect(ui->C,&QPushButton::clicked,[this]()
    {
        OnClicked(Clear,"");
    });
    connect(ui->Back,&QPushButton::clicked,[this]()
    {
        OnClicked(Back,"");
    });
    connect(ui->Change,&QPushButton::clicked,[this]()
    {
        OnClicked(Ch,"");
    });
}
void MainWindow::OnClicked(BtnType _type,QString _btn)
{
    switch(_type)
    {
    case Num:
    {
        if(op.isEmpty())//如果运算符为空
        {
            num1 += _btn;
        }
        else
        {
            num2 += _btn;
        }
        break;
    }
    case Op:
    {

    }
    }
    static QString str="";
    if(_type == Num || _type == Op)
    str += _btn;
    ui->lineEdit->setText(str);
}
MainWindow::~MainWindow()
{
    delete ui;
}


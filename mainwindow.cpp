#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include<QToolBar>
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
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
        OnClicked(Ra,"√");
    });
    connect(ui->Percent,&QPushButton::clicked,[this](){
        OnClicked(Per,"%");
    });
    connect(ui->Reciprocal,&QPushButton::clicked,[this](){
        OnClicked(Re,"");
    });
    connect(ui->Square,&QPushButton::clicked,[this](){
        OnClicked(Sq,"");
    });

    connect(ui->Point,&QPushButton::clicked,[this](){
        OnClicked(Dot,".");
    });


    //others
    connect(ui->C,&QPushButton::clicked,[this](){
        OnClicked(Clear,"");
    });
    connect(ui->Back,&QPushButton::clicked,[this](){
        OnClicked(Back,"");
    });
    connect(ui->Change,&QPushButton::clicked,[this](){
        OnClicked(Ch,"");
    });
    connect(ui->Equal,&QPushButton::clicked,[this](){
        OnClicked(Eq,"");
    });
}
void MainWindow::OnClicked(BtnType _type,const QString _btn)
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
        op = _btn;
        break;
    }
    case Clear:
    {
        num1.clear();
        num2.clear();
        op.clear();
        break;
    }
    case Dot:
    {
        if(op.isEmpty())
        {
            if(! num1.isEmpty() && ! num1.contains("."))//如果数字一不为空且不包含点，将点加到数字一上
            {
                num1 += _btn;
            }
        }
        else
        {
            if(! num2.isEmpty() && ! num2.contains("."))
            {
                num2 += _btn;
            }
        }
        break;
    }
    case Eq:
    {
        a = num1.toDouble();
        b = num2.toDouble();
        result = 0.0;
        if(op == "+")
        {
            result = a + b;
        }
        if(op == "-")
        {
            result = a - b;
        }
        if(op == "*")
        {
            result = a * b;
        }
        if(op == "√")
        {
            if(!num1.isEmpty() && op.isEmpty())
            {
                sqrt(a);
            }
        }
        if(op == "/")
        {
            if(b == 0.0)
            {
                ui->lineEdit->setText("error");
                return;
            }
            else
                result = a / b;
        }
        ui->lineEdit->setText(QString::number(result));
        break;
    }
    case Ch:
    {   a = num1.toDouble();
        b = num2.toDouble();
        if(!num1.isEmpty() && op.isEmpty())
        {
            a=a*-1;
            ui->lineEdit->setText(QString::number(a));
        }
        if(!num2.isEmpty())
        {
            b=b*-1;
            ui->lineEdit->setText(QString::number(b));
        }
        break;
    }
    case Back:
    {
        if(!num1.isEmpty() && !num2.isEmpty())
        {
            num2.chop(1);
        }
        if(!num1.isEmpty() && !op.isEmpty() && num2.isEmpty())
        {
            op.chop(1);
        }
        if(!num1.isEmpty() && op.isEmpty())
        {
            num1.chop(1);
        }
        break;
    }
    case Sq:
    {
        if(num2.isEmpty() && op.isEmpty())
        {
            a = num1.toDouble();
            pow(a,2);
            ui->lineEdit->setText(QString::number(a) + op);
        }
        break;
    }
    case Ra:
    {
        break;
    }
    case Per:
    {
        break;
    }
    case Re:
    {
        break;
    }
    }//switch
    ui->lineEdit->setText(num1 + op + num2);
}
MainWindow::~MainWindow()
{
    delete ui;
}


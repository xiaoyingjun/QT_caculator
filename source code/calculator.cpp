#include "calculator.h"
#include "ui_calculator.h"
#include<QString>
#include<QtCore>
#include<QSound>

Calculator::Calculator(QTabWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}
Calculator::~Calculator()
{
    delete ui;
}
QString str="0";
QString temp;
QString externstr;//用于储存括号外部的数字
float a;//str转成的浮点数
float b;
float c;//多位运算中用于储存b的值
int test=0;//检测各种符号的数量
int operate=0;//运算种类的代号
int lastoperate;//前一个运算符,以及用lastoperate=5实现无需多次清零按下一个数字即可开始新运算
int lastclicked;//用于检测删除一个数字还是一个操作/删除数字=0/删除操作=1
int op=0;//多位运算连乘或连除之前的符号
int externoperate=0;//括号外部的操作符号

//点击数字,显示整数和非整数
void Addnumber(QString &str,int number)
{
    if(str=="0")
        str.setNum(number);
    else
    {
        if(lastoperate==5)
        {
            str.setNum(number);
            lastoperate=0;
        }
        else
            {
            temp.setNum(number);
            str=str+temp;}
    }
}
void Calculator::on_pushButton_0_clicked()
{
    QSound::play("C:/soundeffcet/1.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,0);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_1_clicked()
{
    QSound::play("C:/soundeffcet/4.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,1);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_2_clicked()
{
    QSound::play("C:/soundeffcet/5.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,2);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_3_clicked()
{
    QSound::play("C:/soundeffcet/6.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,3);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_4_clicked()
{
    QSound::play("C:/soundeffcet/8.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,4);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_5_clicked()
{
    QSound::play("C:/soundeffcet/9.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,5);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_6_clicked()
{
    QSound::play("C:/soundeffcet/10.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,6);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_7_clicked()
{
    QSound::play("C:/soundeffcet/12.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,7);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_8_clicked()
{
    QSound::play("C:/soundeffcet/13.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,8);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_9_clicked()
{
    QSound::play("C:/soundeffcet/14.wav");
    if(str.length()>9)
    {
        cerror.exec();
        if(a!=0)
            str.setNum(a);
        else
            str="0";
    }
    else
        Addnumber(str,9);
    lastclicked=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_dot_clicked()
{
    QSound::play("C:/soundeffcet/2.wav");
    if(str.contains(".")>0)
    {
        ui->lcdNumber->display(str);
    }
    else
    {
        temp=".";
        str=str+temp;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
}


//清零
void Calculator::on_pushButton_clear_clicked()
{
    QSound::play("C:/soundeffcet/16.wav");
    str="0";
    test=0;
    a=b=0;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void getanswer()
{
        b=str.toFloat();
        switch (operate) {
        case 1:
            a=a+b;
            break;
        case 2:
            a=a-b;
            break;
        case 3:
            if(test>1)
            {
                switch(lastoperate){
                case 1:
                    a=a+b*c;
                    break;
                case 2:
                    a=a-b*c;
                    break;
                case 3:
                    a=a*b*c;
                    break;
                case 4:
                    a=a/c*b;
                    break;
                }
            }
            else
                a=a*b;
            break;
        case 4:
            if(test>1)
            {
                switch(lastoperate){
                case 1:
                    a=a+c/b;
                    break;
                case 2:
                    a=a-c/b;
                    break;
                case 3:
                    a=a*c/b;
                    break;
                case 4:
                    a=a/c/b;
                    break;
                }
            }
            else
                a=a/b;
            break;
        }
}
//选择运算
void Calculator::on_pushButton_plus_clicked()
{   
    QSound::play("C:/soundeffcet/7.wav");
    if(test!=0)
        getanswer();
    else
       a=str.toFloat();
    str="0";
    operate=1;
    test++;
    lastclicked=1;
}

void Calculator::on_pushButton_minus_clicked()
{
    QSound::play("C:/soundeffcet/11.wav");
    if(test!=0)
        getanswer();
    else
        a=str.toFloat();
    str="0";
    operate=2;
    test++;
    lastclicked=1;
}
/*
 * 多位运算原理
 * 可以将所有多位运算简化成
 * a+b*c
 * 也就是把所有带加减运算的看作是一个整体
 * 在按下一个“+”或“-”后，前面部分就成为一个整体
*/
void Calculator::on_pushButton_multi_clicked()
{
    QSound::play("C:/soundeffcet/15.wav");
    if(test!=0)
    {
        b=str.toFloat();
        lastoperate=operate;
        if((lastoperate==3||lastoperate==4)&&c!=0)
        {
            if(lastoperate==3)
                c=b*c;
            else
                c=c/b;
        }
        else
        {
            op=lastoperate;
            c=b;}
    }
    else
        a=str.toFloat();
    str="0";
    operate=3;
    test++;
    lastclicked=1;
}

void Calculator::on_pushButton_divide_clicked()
{
    QSound::play("C:/soundeffcet/19.wav");
    if(test!=0)
    {
        b=str.toFloat();
        lastoperate=operate;
        if((lastoperate==3||lastoperate==4)&&c!=0)
        {
            if(lastoperate==3)
                c=b*c;
            else
                c=c/b;
        }
        else
        {
            op=lastoperate;
            c=b;}
    }
    else
        a=str.toFloat();
    str="0";
    operate=4;
    test++;
    lastclicked=1;
}


//计算得数
void Calculator::on_pushButton_equal_clicked()
{
    QSound::play("C:/soundeffcet/3.wav");
    if(op!=0)
        lastoperate=op;
    getanswer();
    test=0;
    op=0;
    b=c=0;
    str.setNum(a);
    lastoperate=5;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}


//正负号
void Calculator::on_pushButton_sign_clicked()
{
    QSound::play("C:/soundeffcet/17.wav");
    if(str.contains("-")>0)
    {
        str.remove(QChar('-'));
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
    else
    {
        temp="-";
        str=temp+str;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
    lastoperate=5;
}


//百分号
void Calculator::on_pushButton_percent_clicked()
{
    QSound::play("C:/soundeffcet/18.wav");
    a=str.toFloat();
    a=a/100;
    str.setNum(a);
    lastoperate=5;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}


//函数运算
void Calculator::on_pushButton_reciprocal_clicked()
{
    QSound::play("C:/soundeffcet/20.wav");
    a=str.toFloat();
    if(a==0)
    {
        str="error";
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
        str="0";
    }
    else
    {
        a=1/a;
        str.setNum(a);
        lastoperate=5;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
}

void Calculator::on_pushButton_factorial_clicked()
{
    QSound::play("C:/soundeffcet/21.wav");
    int s=1;
    a=str.toFloat();
    if(a>0&&str.contains(".")==0){
        while(a>0)
        {
            s=s*a;
            a--;
        }
        str.setNum(s);
        lastoperate=5;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
    else{
        str="Error";
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
        str="0";
    }
}

void Calculator::on_pushButton_tan_clicked()
{
    QSound::play("C:/soundeffcet/24.wav");
    a=str.toFloat();
    a=qTan(a);
    str.setNum(a);
    lastoperate=5;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_sin_clicked()
{
    QSound::play("C:/soundeffcet/25.wav");
    a=str.toFloat();
    a=qSin(a);
    str.setNum(a);
    lastoperate=5;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_cos_clicked()
{
    QSound::play("C:/soundeffcet/26.wav");
    a=str.toFloat();
    a=qCos(a);
    str.setNum(a);
    lastoperate=5;
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
}

void Calculator::on_pushButton_ln_clicked()
{
    QSound::play("C:/soundeffcet/23.wav");
    a=str.toFloat();
    if(a>0){
        a=qLn(a);
        str.setNum(a);
        lastoperate=5;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
    else{
        str="Error";
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
        str="0";
    }
}

void Calculator::on_pushButton_sqrt_clicked()
{
    QSound::play("C:/soundeffcet/31.wav");
    a=str.toFloat();
    if(a>0){
        a=sqrt(a);
        str.setNum(a);
        lastoperate=5;
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
    else{
        str="Error";
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
        str="0";
    }
}


//调用数值π和e
void Calculator::on_pushButton_pai_clicked()
{
    QSound::play("C:/soundeffcet/22.wav");
    str="3.14159265";
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    lastoperate=5;
}

void Calculator::on_pushButton_e_clicked()
{
    QSound::play("C:/soundeffcet/27.wav");
    str="2.71828183";
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    lastoperate=5;
}


//进制转换
void Calculator::on_pushButton_binary_clicked()
{
    QSound::play("C:/soundeffcet/30.wav");
    int temp=str.toInt();
    str=QString::number(temp,2);
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    lastoperate=5;
}

void Calculator::on_pushButton_decimal_clicked()
{
    QSound::play("C:/soundeffcet/29.wav");
    int temp=str.toInt();
    str=QString::number(temp,10);
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    lastoperate=5;
}

void Calculator::on_pushButton_hex_clicked()
{
    QSound::play("C:/soundeffcet/28.wav");
    int temp=str.toInt();
    str=QString::number(temp,16);
    ui->lcdNumber->display(str);
    ui->lcdNumber_2->display(str);
    lastoperate=5;
}


//运算优先级
/*
 * 与前面a+b*c有相同原理
 * 但是需要检测括号
 * 需考虑括号内再次出现a+b*c的情况
 */
void Calculator::on_pushButton_left_clicked()
{
    lastclicked=3;
    if(a!=0)
    {
        if(a!=0&&operate!=0)
        {
            externstr.setNum(a);
            externoperate=operate;
        }
        else
        {
            str="error";
            ui->lcdNumber->display(str);
            ui->lcdNumber_2->display(str);
            str="0";
        }
    }
}

void Calculator::on_pushButton_right_clicked()
{
    if(lastclicked!=3)
        str="error";
    else
    {
        if(op!=0)
            lastoperate=op;
        getanswer();
        op=0;
        b=c=0;
        test=0;
        str.setNum(a);
        if(externoperate!=0)
        {
            c=a;
            b=externstr.toFloat();
            operate=externoperate;
        }
    }
}

void Calculator::on_pushButton_clicked()
{
    if(lastclicked!=0)
        operate=0;
    else
    {
        str.chop(1);
        ui->lcdNumber->display(str);
        ui->lcdNumber_2->display(str);
    }
}

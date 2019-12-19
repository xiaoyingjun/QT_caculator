#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QTabWidget>
#include <QLCDNumber>
#include<cerror.h>
namespace Ui
{
    class Calculator;
}
class Calculator:public QTabWidget
{
    Q_OBJECT
public:
   explicit Calculator(QTabWidget*parent=0);
    ~Calculator();
    CError cerror;
private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multi_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_sign_clicked();

    void on_pushButton_percent_clicked();

    void on_pushButton_reciprocal_clicked();

    void on_pushButton_factorial_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_pai_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_binary_clicked();

    void on_pushButton_decimal_clicked();

    void on_pushButton_hex_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_clicked();

private:
    Ui::Calculator*ui;
};

#endif // CALCULATOR_H

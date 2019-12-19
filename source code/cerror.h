#ifndef CERROR_H
#define CERROR_H

#include<QDialog>

namespace Ui {
    class CError;
}
class CError:public QDialog
{
    Q_OBJECT

public:
    explicit CError(QWidget*parent=0);
    ~CError();
private slots:
    void on_pushButton_clicked();

private:
    Ui::CError*ui;
};

#endif // CERROR_H

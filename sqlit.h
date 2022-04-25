#ifndef SQLIT_H
#define SQLIT_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "list.h"



QT_BEGIN_NAMESPACE
namespace Ui { class SQlit; }
QT_END_NAMESPACE

class SQlit : public QMainWindow
{
    Q_OBJECT

public:
    SQlit(QWidget *parent = nullptr);
    ~SQlit();

private slots:
    void on_btn_register_clicked();

    void on_btn_display_data_clicked();

private:
    Ui::SQlit *ui;
};
#endif // SQLIT_H

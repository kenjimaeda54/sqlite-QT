#ifndef LIST_H
#define LIST_H

#include <QDialog>
#include <QtSql>
#include <QDebug>

namespace Ui {
class List;
}

class List : public QDialog
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = nullptr);
    ~List();

private:
    Ui::List *ui;
};

#endif // LIST_H

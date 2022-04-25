#include "list.h"
#include "ui_list.h"

List::List(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);

    QSqlQuery query;
    QString consult = "SELECT * FROM personal";
    query.prepare(consult);

    if(query.exec()){
        int row = 0;
        ui->table_list->setColumnCount(2);


        while(query.next()){
            ui->table_list->insertRow(row);

            //row do banco de dados, coluna da tabale do tabe list( culna 0 corresponde a primerioa coluna 1 correponde ao 2 coluna), a classe  widget,value da couluna no banco(id,name ou second_name)
            ui->table_list->setItem(row,0,new QTableWidgetItem( query.value(1).toString()));
            ui->table_list->setItem(row,1,new QTableWidgetItem(query.value(2).toString()));
            ui->table_list->setRowHeight(row,30); //parte de estilo da coluna
            row ++ ;

        }


    }else {

        qDebug() << "I can`t get data";
    }



}

List::~List()
{
    delete ui;
}

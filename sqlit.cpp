#include "sqlit.h"
#include "ui_sqlit.h"

SQlit::SQlit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SQlit)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = getenv("HOME"); // variaveis de hambiente do linux, $HOME
    path += "/Documents/database/firstdb.db";
    db.setDatabaseName(path);
    if(!db.open()){
       qDebug() << "I can`t connection";
    }else {
       qDebug() << "Connection sucess";
    }


}

SQlit::~SQlit()
{
    delete ui;
}


void SQlit::on_btn_register_clicked()
{
    QString name = ui->input_name->text();
    QString secondName = ui->input_second_name->text();

    if(name.isEmpty()  || secondName.isEmpty() ){
       QMessageBox::warning(this,"Attention","Please insert filed name and second name");
       return;
    }

    QSqlQuery query;
    QString insertData = "INSERT INTO personal(name,second_name)  VALUES( '"+name+"','"+secondName+"')";
    query.prepare(insertData);

    if(query.exec()){

        QMessageBox::information(this,"Sucess","Data is set with sucess");
        ui->input_name->clear();
        ui->input_second_name->clear();
        ui->input_name->setFocus(); //precisa ser literalmente o campo, acima eu simplemente retribui o texto a varaivel e nao o campo


    }else {

        QMessageBox::critical(this,"Error","Can`t set data");
    }


}


void SQlit::on_btn_display_data_clicked()
{
    List list;
    list.exec();
}


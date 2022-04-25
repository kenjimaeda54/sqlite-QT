# SQLITE with QT
Pequena aplicação para entender os conceitos de sqlite com o QT

# Motivação
Aprofundar mais sobre QT e seus componentes disponiveis.

## Feature
- Para fazer a conexão do SQLITE no banco QT precisa no arquivo  .pro  colocar  dependência  SQL
- SQLITE  e um banco local escrito em C, no arch esta disponível neste link [SQL](https://aur.archlinux.org/packages/sqlite2)
- Usei “interface” gráfica do [sqlitestudio](https://aur.archlinux.org/packages/sqlitestudio) para consultar meus dados no banco salvo
- Antes de inciar o trabalho preciso primeiro realizar a conexão com o banco de dados sqlite, ele segue mesmo principio que outros bancos que implementa o sql
- Com getenv consigo pegar as variáveis de ambiente do linux como $HOME,PWD
- Usando o conceito de variáveis de ambiente garanto sempre vou estar dinamicamente com o caminho HOME do usuário



``` c++
//.pro
QT       += core gui  sql



//======================
//.cpp
  ui->setupUi(this);
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  QString path = getenv("HOME"); 
  path += "/Documents/database/firstdb.db";
  db.setDatabaseName(path);
  if(!db.open()){
       qDebug() << "I can`t connection";
    }else {
       qDebug() << "Connection sucess";
    }
```


## 
- Para inserção de dados no banco preciso usar os comandos tradicionais dos bancos que implementa sql, neste caso o INSERT INTO
- Precisa a coluna ter sido criada antes do banco,para  funcionar normalmente, caso a contrário não conseguira inserir
- Apos ter criado o comando, simplesmente preparo a string escrita com a palavra reservada prepare(). 
- Prepare e o comando sql que vai converter nossa string em um comando sql propriamente dita



``` c+=

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


```

##

- Para exibir os dados usei um componente QT QTableWidget
- O componente espera que setamos a quantidade de coluna, inserimos a quantidade de linhas e por fim os itens
- Para consultar o banco a lógica e mesma de inserir, escrevo o comando é preparo  query
- Apos executar a query, tem um comando next() do sql, usei o while, enquanto for verdadeiro o next permanece no laço
- SetItem do componente QTableWidget aguarda primeiro a row, depois a coluna da tabela a ser exibida, então  coluna 0 da tabela, sera exibido na tela 1, porque começa no index 0
- Por fim,para os valores,  usei  clase QTableWidgetItem no construtor desta classe  passei os valores da tabela do banco de dados.
- No caso no banco de dados estou consultando a coluna 1 e a coluna 2
- Banco de dados a coluna 1 representa o first name, 2 representa o second name
- Apos tudo pronto eu estilizo de forma dinâmica as colunas com  setRowHeight

``` c++

QSqlQuery query;
QString consult = "SELECT * FROM personal"; 
query.prepare(consult);

if(query.exec()){
   int row = 0;
   ui->table_list->setColumnCount(2);


   while(query.next()){
      ui->table_list->insertRow(row);

      //row do banco de dados, coluna da tabela da QTableWidget( culna 0 corresponde a primeira coluna 1,e 1 correponde  2 coluna), os valores QTableWidgetItem(value da couluna do banco(id,name ou second_name))
      //estou pegando o valor da primeira coluna no banco em QTableWidgetItem
      //e pegando valor da segunda coluna no banco em QtableWidgetItem
      ui->table_list->setItem(row,0,new QTableWidgetItem( query.value(1).toString()));
      ui->table_list->setItem(row,1,new QTableWidgetItem(query.value(2).toString()));
      ui->table_list->setRowHeight(row,30); //parte de estilo da coluna
      row ++ ;

  }

```

##

## ScreenShoot


![nameSe.jpeg](https://github.com/kenjimaeda54/sqlite-QT/blob/master/nameSe.jpeg)
![dataINser.jpeg](https://github.com/kenjimaeda54/sqlite-QT/blob/master/dataINser.jpeg)
![sucess.jpeg](https://github.com/kenjimaeda54/sqlite-QT/blob/master/sucess.jpeg)












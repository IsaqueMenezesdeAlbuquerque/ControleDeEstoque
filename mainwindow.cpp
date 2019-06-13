#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produto.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QVariant>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarDados(Produto a)
{



        int menorQuant = prod.getMenorQuant();
        int maiorQuant = prod.getMaiorQuant();
        int quantProd = prod.getquantProd();
        QString mes = prod.getmes(a);

       ui->label_5->setText(QString::number(menorQuant));
        ui->label_6->setText(QString::number(maiorQuant));
        ui->label_7->setText(QString::number(quantProd));
      if(a.getNum().size()>0 and a.getNome().size()>2)  ui->label_8->setText((mes));

}

void MainWindow::inserirProdutoNaTabela(Produto a, int linha){
    ui->tableWidget->setItem(linha,0,new QTableWidgetItem(a.getNome().toUpper()));
    ui->tableWidget->setItem(linha,2,new QTableWidgetItem(a.getNum()));
    ui->tableWidget->setItem(linha,1,new QTableWidgetItem(a.getDat()));
}


void MainWindow::on_pushButton_clicked()
{

    Produto pd;
    pd.setNum(ui->lineEdit_2->text());
    pd.setNome(ui->lineEdit->text());
    pd.setDat(ui->comboBox->currentText());

    if(pd.getNum().size()>0 and pd.getNome().size()>2){
        int linha = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(linha);

        inserirProdutoNaTabela(pd,linha);
    }





    ui->lineEdit_2->clear();
    ui->lineEdit->clear();


prod.inserirProduto(pd);
atualizarDados(pd);
}

void MainWindow::on_pushButton_2_clicked()
{
    prod.ordenarPorNome();
        atualizarTabela();
}
void MainWindow::atualizarTabela()
{
    ui->tableWidget->clearContents();
    for(int i=0; i<prod.size();i++){
        inserirProdutoNaTabela(prod[i],i);

    }

}

void MainWindow::on_pushButton_3_clicked()
{
    prod.ordenarPorDat();
    atualizarTabela();
}

void MainWindow::on_pushButton_4_clicked()
{
    prod.ordenarPorQuant();
    atualizarTabela();
}



void MainWindow::on_actionSalvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                          "Lista de produtos",
                                                          "",
                                                          "CSV(*.csv)");
       prod.salvarProduto(nomeArquivo);


       QMessageBox::information(this,"Salvar","Arquivo salvo com sucesso!");
}

void MainWindow::on_actionCarregar_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Produtos","","CSV(*.csv)");



      prod.carregarProduto(nomeArquivo);
      for(int i=0;i<prod.size();i++){


          ui->tableWidget->insertRow(i);
          inserirProdutoNaTabela(prod[i],i);
      }
}



void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    Produto a;
    if(column == 0){
            QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o nome do produto?");

            if(resp == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar Nome", "Nome", QLineEdit::Normal,"",&ok);
                if(ok and !txt.isEmpty()){
                    a.setNome(txt+"*");
                    a.setDat(prod[row].getDat());
                    a.setNum(prod[row].getNum());

                prod.inserirProduto(a);
                ui->tableWidget->setItem(row,0,new QTableWidgetItem (a.getNome().toUpper()));
            }}
    }
    else if(column == 1){
            QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o mes selecionado?");

            if(resp == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar mes", "Mes", QLineEdit::Normal,"",&ok);
                if(ok and !txt.isEmpty()){
                    a.setDat(txt.toUpper()+"*");
                    a.setNome(prod[row].getNome());
                    a.setNum(prod[row].getNum());
                }

                prod.inserirProduto(a);
               ui->tableWidget->setItem(row,1,new QTableWidgetItem (a.getDat()));
            }
    }
    else if(column == 2){
            QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar a quantidade selecionada?");

            if(resp == QMessageBox::Yes){
                bool ok;
                QString txt = QInputDialog::getText(this, "Alterar Quantidade de produto", "Quantidade", QLineEdit::Normal,"",&ok);
                if(ok and !txt.isEmpty()){
                    a.setNum(txt);
                    a.setDat(prod[row].getDat());
                    a.setNome(prod[row].getNome());

                prod.inserirProduto(a);
               ui->tableWidget->setItem(row,2,new QTableWidgetItem (a.getNum()));
}
            }

}


}




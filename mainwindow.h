#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produto.h"
#include "salvar.h"
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    salvar prod;
    void atualizarDados(Produto a);
    void atualizarTabela();
    void inserirProdutoNaTabela(Produto a, int linha);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_pushButton_5_clicked();

   void on_tableWidget_cellDoubleClicked(int row, int column,Produto a);

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

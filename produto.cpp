#include "produto.h"
#include "mainwindow.h"
#include <QMessageBox>
Produto::Produto()
{

}

void Produto::setNum(const QString b)
{
   if(b.toInt()) num =b;

}

void Produto::setDat(const QString c)
{
     data = c;
}

QString Produto::getNome() const
{
    return nome;
}

QString Produto::getNum() const
{
    return  num;
}

QString Produto::getDat() const
{

    return data;


}






void Produto::setNome(const QString a)
{

     nome = a;

}

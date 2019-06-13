#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>
#include <QDate>
class Produto
{
private:
    QString nome;
    QString num;
    QString data;



public:
    Produto();
    void setNome(const QString a);
    void setNum(const QString b);
    void setDat(const QString c);

    QString getNome() const;
    QString getNum()const ;
    QString getDat()const;
};

#endif // PRODUTO_H

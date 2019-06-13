#ifndef SALVAR_H
#define SALVAR_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QMap>
#include "produto.h"
class salvar
{
    protected:
    QVector<Produto> prod;

public:
    salvar();
    void inserirProduto(Produto a);
        Produto operator[](int i);
        int getMaiorQuant();
        int getMenorQuant();
        int getquantProd();
        QString getmes(Produto a);
        void ordenarPorNome();
        void ordenarPorQuant();
        void ordenarPorDat();
        bool salvarProduto(QString arquivo);
        bool carregarProduto(QString arquivo);
        int size();
        void clear1(int g);
};

bool compararPorQuant(Produto a, Produto b);
bool compararPorNome(Produto a, Produto b);
bool compararPorDat(Produto a, Produto b);
#endif // SALVAR_H

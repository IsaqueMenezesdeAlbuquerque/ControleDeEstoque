#include "salvar.h"

salvar::salvar()
{

}

void salvar::inserirProduto(Produto a)
{




   if(a.getNum().size()>0 and a.getNome().size()>2){

  prod.push_back(a) ;


   }
}

Produto salvar::operator[](int i)
{
    return prod[i];
}

int salvar::getMaiorQuant()
{
    Produto *menor = std::min_element(prod.begin(),prod.end(),compararPorQuant);
    return menor->getNum().toInt();
}


int salvar::getMenorQuant()
{
    Produto *maior  = std::max_element(prod.begin(),prod.end(),compararPorQuant);
    return maior -> getNum().toInt();
}

int salvar::getquantProd()
{
    int a1=0;
    for(int i =0;i<prod.size();i++){

        a1 = a1 +1;
    }
    return a1;
}

QString salvar::getmes(Produto a)
{
    int jan = 0;
    int fev = 0;
    int mar = 0;
    int abri = 0;
    int jun = 0;
    int jul = 0;
    int agos = 0;
    int set = 0;
    int out = 0;
    int nov = 0;
    int dez = 0;
    int mai = 0;


    for(int i  = 0;i<prod.size();i++){


        if(a.getDat()=="Janeiro"){
            jan =jan +1;
        }
        if(a.getDat()=="Fevereiro"){
            fev =fev +1;
        }
        if(a.getDat()=="Março"){
             mar=mar +1;
        }
        if(a.getDat()=="Abril"){
            abri = abri +1;
        }
        if(a.getDat()=="Maio"){
            mai =mai+1;
        }
        if(a.getDat()=="Junho"){
            jun = jun+1;
        }
        if(a.getDat()=="Julho"){
            jul =jul+1;
        }
        if(a.getDat()=="Agosto"){
            agos =agos +1;
        }
        if(a.getDat()=="Setembro"){
            set = set+1;
        }
        if(a.getDat()=="Outubro"){
            out =out+1;
        }
        if(a.getDat()=="Novembro"){
            nov =nov+1;
        }
        if(a.getDat()=="Dezembro"){
            dez =dez+1;
        }




    }

    QMap<int,QString> cont;

    cont[jan] = "Janeiro";
    cont[fev] = "Fevereiro";
    cont[mar] = "Março";
    cont[abri] = "Abril";
    cont[mai] = "Maio";
    cont[jun] = "Junho";
    cont[jul] = "Julho";
    cont[agos] = "Agosto";
    cont[set] = "Setembro";
    cont[out] = "Outubro";
    cont[nov] = "Novembro";
    cont[dez] = "Dezembro";

  return cont.last();






}


void salvar::ordenarPorNome()
{
    std::sort(prod.begin(),prod.end(),compararPorNome);

}

void salvar::ordenarPorQuant()
{
  std::sort(prod.begin(),prod.end(),compararPorQuant);
}

void salvar::ordenarPorDat()
{
    std::sort(prod.begin(),prod.end(),compararPorDat);
}

bool salvar::salvarProduto(QString arquivo)
{

    QFile file(arquivo);
        QString linha;
        if(!file.open(QIODevice::WriteOnly))
            return false;

        for(Produto a : prod){
            linha = a.getNome() + ',' + a.getDat() + ',' + a.getNum() + '\n';
            file.write(linha.toLocal8Bit());
        }
        linha = ".";
        return true;
}

bool salvar::carregarProduto(QString arquivo)
{
    QFile file(arquivo);
       if(!file.open(QIODevice::ReadOnly))
           return false;

       QString linha;
       Produto a;
       while(!file.atEnd()){
           linha = file.readLine();
           QStringList dados = linha.split(",");
           a.setNome(dados[0]);
           a.setNum(dados[2]);
           a.setDat(dados[1]);
           inserirProduto(a);
           if(dados == linha.split(".")) break;
       }
       return true;
}

int salvar::size()
{
    return prod.size();
}

void salvar::clear1(int g)
{
    prod.erase(prod.begin()+g);
}

bool compararPorNome(Produto a, Produto b)
{
    return a.getNome()<b.getNome();
}

bool compararPorQuant(Produto a, Produto b)
{
    return a.getNum().toInt()< b.getNum().toInt();
}

bool compararPorDat(Produto a, Produto b)

{
    int n;
    int m;
    if(a.getDat()=="Janeiro"){
        n =1;
    }
    if(a.getDat()=="Fevereiro"){
        n =2;
    }
    if(a.getDat()=="Março"){
        n =3;
    }
    if(a.getDat()=="Abril"){
        n =4;
    }
    if(a.getDat()=="Maio"){
        n =5;
    }
    if(a.getDat()=="Junho"){
        n =6;
    }
    if(a.getDat()=="Julho"){
        n =7;
    }
    if(a.getDat()=="Agosto"){
        n =8;
    }
    if(a.getDat()=="Setembro"){
        n =9;
    }
    if(a.getDat()=="Outubro"){
        n =10;
    }
    if(a.getDat()=="Novembro"){
        n =11;
    }
    if(a.getDat()=="Dezembro"){
        n =12;
    }
    //------------------------------------//
    if(b.getDat()=="Janeiro"){
        m =1;
    }
    if(b.getDat()=="Fevereiro"){
        m =2;
    }
    if(b.getDat()=="Março"){
        m =3;
    }
    if(b.getDat()=="Abril"){
        m =4;
    }
    if(b.getDat()=="Maio"){
        m =5;
    }
    if(b.getDat()=="Junho"){
        m =6;
    }
    if(b.getDat()=="Julho"){
        m =7;
    }
    if(b.getDat()=="Agosto"){
        m =8;
    }
    if(b.getDat()=="Setembro"){
        m =9;
    }
    if(b.getDat()=="Outubro"){
        m =10;
    }
    if(b.getDat()=="Novembro"){
        m =11;
    }
    if(b.getDat()=="Dezembro"){
        m =12;
    }

    //----------------------//

    return  n<m;

}

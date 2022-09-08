///ARRAY BIDIMENSIONAL CLASS

#ifndef ARRAYBIDIMENSIONALCLASS_H_INCLUDED
#define ARRAYBIDIMENSIONALCLASS_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

class arrayBidimensional{                                       ///A classe possibilidade criar arrays bidimensionais, bem conforme lhes fornecem ferramentas
    public:
        ///INTERFACE DA CLASSE
        ostream &operator<<( ostream& );                        ///OPERADOR DE DE DESLOCAMENTO A ESQUERDA SOBRECARREGADO PARA PRINTAR OS OBJETOS
        istream &operator>>( istream& );                        ///OPERADOR DE DE DESLOCAMENTO A DIRETA SOBRECARREGADO PARA PREENCHER OS OBJETOS
        arrayBidimensional( int = 2, int = 2 );                 ///CONSTRUTOR QUE CRIAR OS ARRAYS E INICIALIZA COM ZERO
        //~arrayBidimensional( );                               /*///DETRUIDOR //NÃO IMPLEMENTADO ainda POR PROBLEMAS COM DLLS
        bool operator==( arrayBidimensional& )const;            ///OPERADOR DE IGUALDADE SOBRECARREGADOR PARA COMPARAR OBJETOS
        bool operator!=( arrayBidimensional& )const;            ///OPERADOR DE DIFERENÇA SOBRECARREGADOR PARA COMPARAR OBJETOS
        const int &operator()( int, int )const;                 ///OPERADOR DE CHAMADA DE FUNÇÃO SOBRECARREGADO rvalue PARA DEVOLVER VALORES ESCALARES DO OBJETO
        int &operator()( int, int );                            ///OPERADOR DE CHAMADA DE FUNÇÃO SOBRECARREGADO lvalue PARA DEVOLVER VALORES ESCALARES DO OBJETO
        arrayBidimensional &operator=( arrayBidimensional& );   ///OPERADOR DE ATRIBUIÇÃO SOBRRECARREGADO PARA COPIAR UM OBJETO PARA OUTRO
        int operator[]( int );                                  ///OPERADOR DE SUBSCRITO SOBRECARREGADO PARA DEVOLVER OS MAIORES VALORES DO OBJETO;

    private:
        ///DADOS
        unsigned lines,                                         ///quantidade de linhas da matriz
                 columns;                                       ///quantidade de colunas da matriz

        int **ArrayB;                                           ///ponteiro para ponteiros no qual se desenvolverá a matriz

        ///FUNÇÕES UTILITÁRIAS
        bool creat_array( );                                    ///criar matriz 2x2
        void initialize_array( void );                          ///inicializa matriz 2x2 com zero
        void converte_array( int** );                           ///transforma a matriz 2x2 em um vetor n = lines*colums
        void insertionSort( int[], int );                       ///ordenada vetor n em ordem decrescente
};
#endif // ARRAYBIDIMENSIONALCLASS_H_INCLUDED



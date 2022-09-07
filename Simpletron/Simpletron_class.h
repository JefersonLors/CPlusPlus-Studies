///5.18-5.19 - SIMPLETRON PROJECT

#ifndef SIMPLETRON_CLASS_H_INCLUDED
#define SIMPLETRON_CLASS_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>

class simpletron{
    public:
        simpletron( );
        simpletron &launcher( );        ///Introduz o modo de uso do programa
        simpletron &command_list( );    ///Mostra a lista de comandos e como montar o código. Precisa ser alimentada caso haja alterações nos comandos da lista.
        simpletron &enter_commands( );  ///Recebe as instruções do usuário e armazena na memória.
        simpletron &run_debug( );       ///Mostra todos os espaços de memória e os demais registros.
        int run_program( );             ///Roda a próxima instrução da memória e retorna a quantidade de instruções que ainda faltam para ser executadas.

    private:
        int accumulator,         ///RECEBE UMA INSTRUÇÃO CARREGADA DA MEMÓRIA PELO USUÁRIO
            counter,             ///CONTA A QUANTIDADE DE INSTRUÇÕES INSERIDAS
            operationCode,       ///RECEBE, DA INSTRUÇÃO INSERIDA, O VALOR CORRESPONDENTE À AÇÃO A SER EXECUTADA
            operand,             ///RECEBE, DA INSTRUÇÃO INSERIDA, O VALOR CORRESPONDENTE AO LOCAL DA MEMÓRIA ONDE SERÁ EXECUTADA AÇÃO
            instructionRegister; ///RECEBE A INSTRUÇÃO ANTES DE SER CARREGADA PARA A MEMÓRIA

    std::string fullMemoryMessage = "     ^   FULL MEMORY\n",         ///EXIBE MENSAGEM DE MEMÓRIA CHEIA
                command_error_message = "     ^   INVALID COMMAND\n", ///EXIBE MENSAGEM DE ERRO PARA VALOR INSERIDO FORA DO FORMATO
                end_enter_command_message = "     ^   END ENTER\n";   ///EXIBE MENSAGEM DE FIM DE ENTRADA DE COMANDOS

    const int memorySize;
          int *const memory;     ///ARMAZENA AS INTRUÇÕES INSERIDAS PELO USUÁRIO

    ///LISTA DE COMANDOS
    enum IN_OUT{ READ = 10, WRITE = 11 };
    enum LOADS{ LOAD = 20, STORE = 21 };
    enum ARITIMETICS{ ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33 };
    enum CONTROL_TRANSFER{ BRANCH = 40, BRANCHNEG = 41, BANCHZERO = 42, HALT = 43 };
    ///-------------///

    enum EXCEPTION{ UNKNOW_COMMAND = 0, SENTINEL = -9999, WORD_SIZE = 4 };

    bool validate_command( const int)const;     ///VERIFICA SE O VALOR INSERIDO ESTÁ NO FORMATO CORRETO
    bool identifier_command( const int )const;  ///VERIFICA SE O VALOR INSERIDO É UM COMANDO
    bool memory_verifier( const int )const;     ///VERIFICA SE A MEMÓRIA ESTÁ OCUPADA
    bool isIt_sentinel( const int )const;       ///VERIFICA SE O VALOR INSERIDO É O "endlOfFile"

    int get_operationCode_from_instruction( const int );  ///EXTRAÍ INSTRUÇÃO DO COMANDO INSERIDO
    int get_operand_from_instruction( const int );        ///EXTRAÍ LOCAL DA MEMÓRIA ONDE A INTRUÇÃO SERÁ EXECUTADA

};
#endif // SIMPLETRON_CLASS_H_INCLUDED

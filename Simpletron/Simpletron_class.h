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
        simpletron &command_list( );    ///Mostra a lista de comandos e como montar o c�digo. Precisa ser alimentada caso haja altera��es nos comandos da lista.
        simpletron &enter_commands( );  ///Recebe as instru��es do usu�rio e armazena na mem�ria.
        simpletron &run_debug( );       ///Mostra todos os espa�os de mem�ria e os demais registros.
        int run_program( );             ///Roda a pr�xima instru��o da mem�ria e retorna a quantidade de instru��es que ainda faltam para ser executadas.

    private:
        int accumulator,         ///RECEBE UMA INSTRU��O CARREGADA DA MEM�RIA PELO USU�RIO
            counter,             ///CONTA A QUANTIDADE DE INSTRU��ES INSERIDAS
            operationCode,       ///RECEBE, DA INSTRU��O INSERIDA, O VALOR CORRESPONDENTE � A��O A SER EXECUTADA
            operand,             ///RECEBE, DA INSTRU��O INSERIDA, O VALOR CORRESPONDENTE AO LOCAL DA MEM�RIA ONDE SER� EXECUTADA A��O
            instructionRegister; ///RECEBE A INSTRU��O ANTES DE SER CARREGADA PARA A MEM�RIA

    std::string fullMemoryMessage = "     ^   FULL MEMORY\n",         ///EXIBE MENSAGEM DE MEM�RIA CHEIA
                command_error_message = "     ^   INVALID COMMAND\n", ///EXIBE MENSAGEM DE ERRO PARA VALOR INSERIDO FORA DO FORMATO
                end_enter_command_message = "     ^   END ENTER\n";   ///EXIBE MENSAGEM DE FIM DE ENTRADA DE COMANDOS

    const int memorySize;
          int *const memory;     ///ARMAZENA AS INTRU��ES INSERIDAS PELO USU�RIO

    ///LISTA DE COMANDOS
    enum IN_OUT{ READ = 10, WRITE = 11 };
    enum LOADS{ LOAD = 20, STORE = 21 };
    enum ARITIMETICS{ ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33 };
    enum CONTROL_TRANSFER{ BRANCH = 40, BRANCHNEG = 41, BANCHZERO = 42, HALT = 43 };
    ///-------------///

    enum EXCEPTION{ UNKNOW_COMMAND = 0, SENTINEL = -9999, WORD_SIZE = 4 };

    bool validate_command( const int)const;     ///VERIFICA SE O VALOR INSERIDO EST� NO FORMATO CORRETO
    bool identifier_command( const int )const;  ///VERIFICA SE O VALOR INSERIDO � UM COMANDO
    bool memory_verifier( const int )const;     ///VERIFICA SE A MEM�RIA EST� OCUPADA
    bool isIt_sentinel( const int )const;       ///VERIFICA SE O VALOR INSERIDO � O "endlOfFile"

    int get_operationCode_from_instruction( const int );  ///EXTRA� INSTRU��O DO COMANDO INSERIDO
    int get_operand_from_instruction( const int );        ///EXTRA� LOCAL DA MEM�RIA ONDE A INTRU��O SER� EXECUTADA

};
#endif // SIMPLETRON_CLASS_H_INCLUDED

///5.18-5.19 - SIMPLETRON PROJECT

#ifndef SIMPLETRON_INTERFACE_H_INCLUDED
#define SIMPLETRON_INTERFACE_H_INCLUDED

class simpletron;

class SIMPLETRON{
    public:
        SIMPLETRON(  );
        simpletron &launcher( );        ///Introduz o modo de uso do programa
        simpletron &command_list( );    ///Mostra a lista de comandos e como montar o código. Precisa ser alimentada caso haja alterações nos comandos da lista.
        simpletron &enter_commands( );  ///Recebe as instruções do usuário e armazena na memória.
        simpletron &run_debug( );       ///Mostra todos os espaços de memória e os demais registros.
        int run_program( );             ///Roda a próxima instrução da memória e retorna a quantidade de instruções que ainda faltam para ser executadas.

    private:
        simpletron *key;
};
#endif // SIMPLETRON_INTERFACE_H_INCLUDED

///5.18-5.19 - SIMPLETRON PROJECT

#ifndef SIMPLETRON_INTERFACE_H_INCLUDED
#define SIMPLETRON_INTERFACE_H_INCLUDED

class simpletron;

class SIMPLETRON{
    public:
        SIMPLETRON(  );
        simpletron &launcher( );        ///Introduz o modo de uso do programa
        simpletron &command_list( );    ///Mostra a lista de comandos e como montar o c�digo. Precisa ser alimentada caso haja altera��es nos comandos da lista.
        simpletron &enter_commands( );  ///Recebe as instru��es do usu�rio e armazena na mem�ria.
        simpletron &run_debug( );       ///Mostra todos os espa�os de mem�ria e os demais registros.
        int run_program( );             ///Roda a pr�xima instru��o da mem�ria e retorna a quantidade de instru��es que ainda faltam para ser executadas.

    private:
        simpletron *key;
};
#endif // SIMPLETRON_INTERFACE_H_INCLUDED

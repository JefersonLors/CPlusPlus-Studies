///5.18-5.19 - SIMPLETRON PROJECT

#include <iostream>
#include <cstdlib>

#include "Simpletron_interface.h"

using namespace std;

int main( ){
    unsigned answer( unsigned, unsigned );
    void menu( );

    unsigned instruction = 0;

    enum ACTIVITY{
         ON = 1,
         OFF = 0};
         ACTIVITY POWER = ON;
    enum MENU{
         LOAD = 1,
         RUN = 2,
         DEBUG = 3,
         INSTRUCTION = 4,
         OUT = 5};

    SIMPLETRON system;

    system.launcher( );

    do{
        menu( );
        switch( answer( LOAD, OUT ) ){
            case LOAD:
                cout << endl << "\tCARREGAMENTO INICIADO" << endl;
                system.enter_commands( );
                cout << endl << "\tCARREGAMENTO FINALIZADO" << endl;
                break;

            case RUN:
                cout << endl << "\tEXECUCAO INICIADA" << endl;
                system.run_program( );
                cout << endl << "\tEXECUCAO FINALIZADA" << endl;
                break;

            case DEBUG:
                cout << endl << "\tDEBUGANDO" << endl;
                do{
                    system.run_debug( );
                    instruction = system.run_program( );
                    system.run_debug( );
                }while( instruction > 0 );
                cout << endl << "\tDEBUG FINALIZADO" << endl;
                break;

            case INSTRUCTION:
                cout << endl << "\tLISTA DE COMANDOS" << endl;
                system.command_list();
                break;

            default:
                cout << endl << "\t    Deseja mesmo encerrar o simpletron?" << endl
                     << "\tIsso acarretara a perda das instrucoes carregadas." << endl << endl
                     << "\t    [1][SIM]                 [0][NAO]  " << endl;

                if( answer( OFF, ON )){
                    cout << endl << "\t <<<<< SIMPLETRON ENCERRADO >>>>> " << endl;
                    POWER = OFF;
                }
        }
    }while( POWER == ON );

    return 0;
}
unsigned answer( unsigned MIN, unsigned MAX ){
    int answer = 1;

    do{
        cout << ( (answer > MAX || answer < MIN ) ? ("\t    ^TENTE DE NOVO\n") : ("\n")) << "\t> [ ";
        cin  >> answer;
    }while( answer > MAX || answer < MIN );

    return answer;
}
void menu( ){
    cout << endl << "\t> MENU" << endl
         << "\t  [ 1 ] [ CARREGAR PROGRAMA ]" << endl
         << "\t  [ 2 ] [  RODAR PROGRAMA   ]" << endl
         << "\t  [ 3 ] [      DEBUGAR      ]" << endl
         << "\t  [ 4 ] [     INSTRUCOES    ]" << endl
         << "\t  [ 5 ] [        SAIR       ]" << endl;
}

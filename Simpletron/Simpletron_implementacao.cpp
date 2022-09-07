///5.18-5.19 - SIMPLETRON PROJECT

#include "Simpletron_class.h"

using namespace std;

///IMPLEMENTAÇÃO DA CLASSE-------------------------------------------------
simpletron::simpletron( )
    :memorySize(100), memory( new(nothrow) int[memorySize]) {

    if( memory ){
        for( int location = 0; location < memorySize; location++ )
        memory[ location ] = 0;

        accumulator = counter = operand = operationCode = instructionRegister = 0;
    }else{
        exit(EXIT_FAILURE);}
}
bool simpletron::identifier_command( const int command )const{
    switch( command ){
        case READ:
            return true;
        case WRITE:
            return true;
        case LOAD:
            return true;
        case STORE:
            return true;
        case ADD:
            return true;
        case SUBTRACT:
            return true;
        case DIVIDE:
            return true;
        case MULTIPLY:
            return true;
        case BRANCH:
            return true;
        case BRANCHNEG:
            return true;
        case BANCHZERO:
            return true;
        case HALT:
            return true;
        default:
            return UNKNOW_COMMAND;
    }
}
bool simpletron::isIt_sentinel ( const int instruction )const{
    return ( ( instruction == SENTINEL ) ? ( true ) : ( false ) );
}
bool simpletron::memory_verifier( const int location )const{
    return ( ( memory[ location ] != 0 ) ? ( true ) : ( false ) );
}
int simpletron::get_operationCode_from_instruction( const int instruction ){
    return instruction / 100;
}
int simpletron::get_operand_from_instruction( const int instruction ){
    return instruction % 100;
}
bool simpletron::validate_command( const int instruction )const{
    return ( ( instruction > 9999 || instruction < 1000 ) ? ( false ) : ( true ) );
}
simpletron &simpletron::command_list( ){
    cout << endl
         << "   > READ ------- 10 [ LE VALOR DO TECLADO                                                      ]" << endl
         << "   > WRITE ------ 11 [ LE VALOR DA MEMORIA                                                      ]" << endl
         << "   > LOAD ------- 20 [ CARREGA VALOR DA MEMORIA PARA O ACUMULADOR                               ]" << endl
         << "   > STORE ------ 21 [ CARREGA VALOR DO ACUMULADOR PARA A MEMORIA                               ]" << endl
         << "   > ADD -------- 30 [ SOMA PALAVRA DA MEMORIA A DO ACUMULADOR                                  ]" << endl
         << "   > SUBSTRACT -- 31 [ SUBTRAI PALAVRA DA MEMORIA DO ACUMULADOR                                 ]" << endl
         << "   > DIVIDE ----- 32 [ DIVIDE PALAVRA DA MEMORIA PELA DO ACUMULADOR                             ]" << endl
         << "   > MULTIPLY --- 33 [ MULTIPLICA PALAVRA DA MEMORIA PELA DO ACUMULADOR                         ]" << endl
         << "   > BRANCH ----- 40 [ PULA PARA UMA POSICAO ESPECIFICA DA MEMORIA                              ]" << endl
         << "   > BRANCHNEG -- 41 [ PULA PARA UMA POSICAO ESPECIFICA DA MEMORIA SE O ACUMULADOR FOR NEGATIVO ]" << endl
         << "   > BRANCHZERO - 42 [ PULA PARA UMA POSICAO ESPECIFICA DA MEMORIA SE O ACUMULADOR FOR ZERO     ]" << endl
         << "   > HALT ------- 43 [ EXIBE MENSAGEM DE ENCERRAMENTO DE PROGRAMA                               ]" << endl << endl
         << "-> MEMORY FOR USE 00 - " << memorySize - 1 << endl  << endl
         << "-> FORMATO: Os programas devem ser digitados "  << endl
         << "   > no seguinte formato CCMM onde CC e um "    << endl
         << "   > dos codigos acima, e MM e o local da "     << endl
         << "   > memoria onde o codigo deve ser executado." << endl
         << "   > Assim, o codigo 1024 indica que um valor " << endl
         << "   > deve ser lido do teclado para o espaco "   << endl
         << "   > de memoria com identificacao 24. "         << endl
         << "   > Digite -9999 para encerrar a entrada. "    << endl;
    return *this;
}
simpletron &simpletron::run_debug( ){
    const int lado = sqrt( memorySize );
          int linha = 0;

    cout << "\n\tREGISTRADORES:        " << endl
         << "\taccumulator --------- " << setw(WORD_SIZE)   << setfill('0') << accumulator         << endl
         << "\tcounter ------------- " << setw(WORD_SIZE/2) << setfill('0') << counter             << endl
         << "\tinstructionRegister - " << setw(WORD_SIZE)   << setfill('0') << instructionRegister << endl
         << "\toperationCode ------- " << setw(WORD_SIZE/2) << setfill('0') << operationCode       << endl
         << "\toperand ------------- " << setw(WORD_SIZE/2) << setfill('0') << operand             << endl;

    cout << endl << "\t    MEMORY: " << endl << endl;
    cout << "\t    ";

    for ( int coluna = 0; coluna < lado; coluna++ )
        cout << coluna << "       ";

    cout << endl << endl << "\t" << linha << "   ";

    for( int location = 0; location < memorySize; location++ ){
        cout << setw(WORD_SIZE) << setfill('0') << memory[ location ] << "    ";
        if( ( location + 1 ) % lado == 0 && ( location + 1 ) != memorySize )
            cout << "\n\n\t" << ++linha << "   ";
    }
    cout << endl << endl;
    return *this;
}

///INTERFACE PÚBLICAS DA CLASSE--------------------------------------------------------

simpletron &simpletron::enter_commands( ){
    if( counter < memorySize ){
        cout << endl << setw(WORD_SIZE/2) << setfill('0') << counter << " ? ";
        cin  >> instructionRegister;
        cin.ignore( numeric_limits<std::streamsize>::max(), '\n');

        if( validate_command( instructionRegister ) ){
            operationCode = get_operationCode_from_instruction( instructionRegister );
            operand = get_operand_from_instruction( instructionRegister );

            if( identifier_command( operationCode ) != UNKNOW_COMMAND ){
                memory[ counter ] = instructionRegister;
                counter++;
                enter_commands( );
            }else{
                cout << command_error_message;
                enter_commands( );}
        }else{
            if( !isIt_sentinel( instructionRegister ) ){
                cout << command_error_message;
                enter_commands( );
            }else{
                cout << end_enter_command_message;}}
    }else{
        cout << fullMemoryMessage; } ///verificar se há outros espaços vazios na memória para uso

    return *this;
}
int simpletron::run_program( ){
    static int run_control = 0;

    if( counter > 0 ){
        if( run_control <= counter ){
            instructionRegister = memory[ run_control ];
            operationCode = get_operationCode_from_instruction( memory[ run_control ] );
            operand = get_operand_from_instruction( memory[ run_control ] );

            switch( operationCode ){
                case READ:
                    cout << setw(WORD_SIZE/2) << setfill('0') << operand << " <- ";
                    cin  >> memory[ operand ];
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

                    if( !validate_command( memory[ operand ] ) ){
                        cout << command_error_message;
                        run_program();}
                    break;

                case WRITE:
                    cout << setw(WORD_SIZE/2) << setfill('0') << operand << " -> " << memory[ operand ] << endl;
                    break;

                case LOAD:
                    accumulator = memory[ operand ];
                    break;

                case STORE:
                    memory[ operand ] = accumulator;
                    break;

                case ADD:
                    accumulator += memory[ operand ];
                    break;
                case SUBTRACT:
                    accumulator -= memory[ operand ];
                    break;

                case DIVIDE:
                    if( memory[ operand ] ){
                        accumulator /= memory[ operand ];
                    }else{
                        cout << endl << "        >> ERRO << " << endl
                                     << "   --- Divisao por 0 --- " << endl;}
                    break;

                case MULTIPLY:
                    accumulator *= memory[ operand ];
                    break;

                case BRANCH:
                    counter = operand;
                    break;

                case BRANCHNEG:
                    counter = ( ( accumulator < 0 ) ? ( operand ) : ( counter ) );
                    break;

                case BANCHZERO:
                    counter = ( ( accumulator == 0 ) ? ( operand ) : ( counter ) );
                    break;

                case HALT:
                     cout << " <- Simpletron execution finished! " << endl;
                    break;
            }run_control++;
        }
    }return (counter - run_control);
}
simpletron &simpletron::launcher( ){
    cout << "\t >>>>>>      WELLCOME TO SIMPLETRON!!!    <<<<<<<" << endl
         << "\t >>>>>>                                   <<<<<<<" << endl
         << "\t >>>>>>  Please type your program one     <<<<<<<" << endl
         << "\t >>>>>>  intruction (or data words) at    <<<<<<<" << endl
         << "\t >>>>>>  a time. I will type the position <<<<<<<" << endl
         << "\t >>>>>>  number and '?'. So you enter the <<<<<<<" << endl
         << "\t >>>>>>  word for that position. Enter    <<<<<<<" << endl
         << "\t >>>>>>  the sentinela -9999 for finish   <<<<<<<" << endl
         << "\t >>>>>>  the your program instruction.    <<<<<<<" << endl;
    return *this;
}

///5.18-5.19 - SIMPLETRON PROJECT

#include "Simpletron_interface.h"
#include "Simpletron_class.h"

SIMPLETRON::SIMPLETRON( )
    :key( new simpletron( ) ){ }
simpletron &SIMPLETRON::launcher( ){
    return key->launcher( );
}
simpletron &SIMPLETRON::command_list( ){
    return key->command_list( );
}
simpletron &SIMPLETRON::enter_commands( ){
    return key->enter_commands( );
}
simpletron &SIMPLETRON::run_debug( ){
    return key->run_debug( );
}
int SIMPLETRON::run_program( ){
    return key->run_program( );
}

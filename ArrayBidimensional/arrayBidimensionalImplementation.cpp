///ARRAY BIDIMENSIONAL CLASS

#include "arrayBidimensionalClass.h"

arrayBidimensional::arrayBidimensional( int Qline, int Qcolumn )
{
    lines = ( ( Qline > 1 ? Qline : 2 ) );
    columns = ( ( Qcolumn > 1 ? Qcolumn : 2 ) );

    if( creat_array( ) ){
        initialize_array( );}
}
ostream &arrayBidimensional::operator<<( ostream &screen ){
    for( int x = 0; x < lines; x++ ){
        for( int y = 0; y < columns; y++ ){
            screen << ArrayB[x][y] << "\t";
        }screen << "\n";
    }return screen;
}
istream &arrayBidimensional::operator>>( istream &keyboard ){
    for( int x = 0; x < lines; x++ ){
        for( int y = 0; y < columns; y++ ){
            keyboard >> ArrayB[x][y];
        }
    }return keyboard;
}
bool arrayBidimensional::creat_array( ){
    ArrayB = new(nothrow) int *[lines];

    if( ArrayB ){
        for( int x = 0; x < lines; x++ ){
            ArrayB[x] = new(nothrow) int[columns];
            if( !ArrayB[x] ){ return false; }}
        return true;
    }return false;

}
void arrayBidimensional::initialize_array( ){
    for( int x = 0; x < lines; x++ ){
        for( int y = 0; y < columns; y++ ){
            ArrayB[x][y] = 0;}}

}
bool arrayBidimensional::operator==( arrayBidimensional &arrayB_2 )const{
    if( arrayB_2.columns == columns && arrayB_2.lines == lines ){
        for( int x = 0; x < lines; x++ ){
            for( int y = 0; y < columns; y++ ){
                if( ArrayB[x][y] != arrayB_2.ArrayB[x][y] ){
                   return false;}}}
        return true;
    }
    return false;
}
bool arrayBidimensional::operator!=( arrayBidimensional &arrayB_2 )const{
    if( arrayB_2.columns == columns && arrayB_2.lines == lines ){
        for( int x = 0; x < lines; x++ ){
            for( int y = 0; y < columns; y++ ){
                if( ArrayB[x][y] != arrayB_2.ArrayB[x][y] ){
                   return true;}}}
        return false;
    }else return true;
}
const int &arrayBidimensional::operator()( const int line, const int column )const{
    if( line > 1 && column > 1 ){
        if( line <= lines && column <= columns ){
            return ArrayB[line-1][column-1];
        }
    }
}
int &arrayBidimensional::operator()( const int line, const int column ){
    if( line > 1 && column > 1 ){
        if( line <= lines && column <= columns ){
            return ArrayB[line-1][column-1];
        }
    }
}
arrayBidimensional &arrayBidimensional::operator=( arrayBidimensional &arrayB_2 ){
    columns = arrayB_2.columns;
    lines = arrayB_2.lines;

    delete[] ArrayB;

    ArrayB = new int*[lines];

    if( ArrayB ){
        for( int x = 0; x < lines; x++ ){
            ArrayB[x] = new int[columns];}
        for( int x = 0; x < lines; x++ ){
            for( int y = 0; y < lines; y++ ){
                ArrayB[x][y] = arrayB_2.ArrayB[x][y];}}
    }return *this;
}
int arrayBidimensional::operator[]( const int posicao ){
    if( posicao > 0 && posicao <= columns*lines ){
        int *arrayUni;

        converte_array( &arrayUni );
        insertionSort( arrayUni, lines*columns );

        return arrayUni[posicao-1];
    }else{
        return -1;}
}
void arrayBidimensional::insertionSort( int arrayU[], int s ){
    for (int i = 1; i < s; i++) {
		int escolhido = arrayU[i];
		int j = i - 1;
		while ((j >= 0) && (arrayU[j] < escolhido)) {
			arrayU[j + 1] = arrayU[j];
			j--;}
		arrayU[j + 1] = escolhido;}
}
void arrayBidimensional::converte_array( int **newArrayU ){
    int *newArrayTemp;
    newArrayTemp = new(nothrow) int[lines*columns];

    if( newArrayTemp ){
        for( int i = 0; i < lines*columns; i++ ){
            newArrayTemp[i] = ArrayB[i/columns][i%columns ];}}
    *newArrayU = newArrayTemp;
}

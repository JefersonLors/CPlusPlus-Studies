///ARRAY BIDIMENSIONAL CLASS

#include <iostream>
#include <cstdlib>
#include "arrayBidimensionalClass.h"

using namespace std;

int main(){
    arrayBidimensional area_1( 2, 2 ),
                       area_2( 3, 3 );

    cout << "Area_1 2x2(vazia):\n\n";
    area_1 << cout << endl;

    cout << "Area_2 3x3 (vazia):\n\n";
    area_2 << cout << endl;

    cout << "Preenchendo Area_1:\n";
    area_1 >> cin;

    cout << endl << "Area_1(preenchida):\n\n";
    area_1 << cout << endl;

    cout << "Preenchendo Area_2:\n";
    area_2 >> cin;

    cout << endl << "Area_2(preenchida):\n\n";
    area_2 << cout << endl;

    cout << "Area_1 == Area_2 ? = " << ((area_1 == area_2)?("True\n"):(" False\n") );
    cout << "Area_1 != Area_2 ? = " << ((area_1 != area_2)?("True\n"):(" False\n") ) << endl;

    cout << "Area_1 = Area_2 ?" << endl << endl  ;
    area_1 = area_2;

    cout << "Nova Area_1  3x3:\n\n";
    area_1 << cout << endl;

    cout << "Area_2 3x3:\n\n";
    area_2 << cout << endl;

    cout << "Area_1 == Area_2 ? = " << ((area_1 == area_2)?("True\n"):(" False\n") );
    cout << "Area_1 ?= Area_2 ? = " << ((area_1 != area_2)?("True\n"):(" False\n") ) << endl;

    cout << "Preenchendo Area_2:\n";
    area_2 >> cin;

    cout << endl << "Nova area_2:\n\n";
    area_2 << cout << endl;

    cout << "Area_1 == Area_2 ? = " << ((area_1 == area_2)?("True\n"):(" False\n") );
    cout << "Area_1 != Area_2 ? = " << ((area_1 != area_2)?("True\n"):(" False\n") ) << endl;

    cout << "Esse e o maior elemento da Area_1 = " << area_1[1] << endl;
    cout << "Esse e o maior elemento da nova Area_2 = " << area_2[1] << endl << endl;

    cout << "Nessa coordenada (1,2) na Area_1 tem " << area_1(1,2) << endl;
    cout << "Nessa mesma coordenada (1,2) na Area_2 tem " << area_2(1,2) << endl << endl;

    area_1(1,2) = 90;
    area_2(1,2) = 13;

    cout << "Agora nessa coordenada (1,2) na Area_1 tem " << area_1(1,2) << endl;
    cout << "Agora nessa mesma coordenada (1,2) na Area_2 tem " << area_2(1,2) << endl << endl;

    cout << "Area_1 3x3:\n\n";
    area_1 << cout << endl;

    cout << "Area_2 3x3:\n\n";
    area_2 << cout << endl;

    return 0;
}

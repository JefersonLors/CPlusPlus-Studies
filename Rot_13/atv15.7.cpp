#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "Rot_13.h"

enum OPTIONS { 
	OUT = 0,
	ENCRYPT, 
	DECRYPT };

OPTIONS CHOOSEN;

string MENU();
void toLower(string&);

int main(){
	string nameFile,
		filesName_txt;

	do{
		filesName_txt = MENU();
		if( CHOOSEN != OUT ){
			cout << "\nthe new text is in: ";
			if (CHOOSEN == ENCRYPT)
				cout << Rot_13::encryptText(filesName_txt) << endl;
			if(CHOOSEN == DECRYPT)
				cout << Rot_13::decryptText(filesName_txt) << endl;
		}
	} while (CHOOSEN != OUT);
}
string MENU() {
	string inString,
		filesName_txt;
	
	int subs,
		length;

	do{
		cout << "\ntype OUT or DECRYPT/ENCRYPT + theFilesName.txt\n"
			"\tex: encrypt file.txt\n\n-> ";

		getline(cin, inString);
		toLower(inString);
		length = inString.length();
		
		subs = inString.find("out");
		if( !(0 <= subs && subs < length) ){

			subs = inString.find(".txt");
			if (0 <= subs && subs < length ) {
				int beg = inString.rfind(' ');

				subs = inString.find("encrypt");
				if (0 <= subs && subs < length) {
					CHOOSEN = ENCRYPT;
					filesName_txt = inString.substr(beg+1, inString.length() - 1);
					return filesName_txt;
				}
				subs = inString.find("decrypt");
				if (0 <= subs && subs < length) {
					CHOOSEN = DECRYPT;
					filesName_txt = inString.substr(beg+1, inString.length() - 1);
					return filesName_txt;
				}
				else
					cerr << "\ninvalid command\n";
			}
			else
				cerr << "\nplease insert an .txt file\n";
		}
		else 
			return " ";
	} while (true);
}
void toLower(string& text){
	string::iterator iter = text.begin();

	while ( iter != text.end() ) {
		*iter = tolower(*iter);
		iter++;
	}
}

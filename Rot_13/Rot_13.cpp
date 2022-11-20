#include "Rot_13.h"

#include <iostream>
using std::cout;
using std::endl;

//inicializa variáveis estáticas
string Rot_13::nameFile_txt;
string Rot_13::nameNewFile_txt;
string Rot_13::dencryptText;
string Rot_13::originalText;

//criptografa o texto utilizando a tecnologia rot13
string Rot_13::encryptText(string& nameFile) {
	string message("ops! found issues in the search file.\n");     //mensagem retornada, caso o arquivo não seja encontrado

	if( nameFileVerifier(nameFile) )
		if ( textRecover() ) {
			dencryptText = originalText;						  //copia texto original
			string::iterator iter = dencryptText.begin();         //inicializa um iterador para percorrer o texto

			while (iter != dencryptText.end()) {
				*iter = tolower(*iter);							  //deixa todas as letras minúsculas
				
				if( isalpha(*iter) ){							  //verifica se o caracter é alfabético e
					int newChar = (int)(*iter) + 13;			  //encontra o correspondente na codificação rot13

					if (newChar > 122) 
						*iter = (char)(newChar - 122 + 96);
					else 
						*iter = newChar;						  //atualiza o texto com o novo caracter 
				}
				else 
					*iter = *iter;								  //preserva o caracter não alfabético
				iter++;
			}
			if (textFileWriter())												
				return nameNewFile_txt;
		}
	return message;
}

//descriptografa um texto criptografado com rot13
string Rot_13::decryptText(string& nameFile) {
	string message("ops! found issues in the search file.\n");

	if (nameFileVerifier(nameFile))
		if (textRecover()) {
			dencryptText = originalText;
			string::iterator iter = dencryptText.begin();

			while (iter != dencryptText.end()) {
				*iter = tolower(*iter);

				if (isalpha(*iter)) {
					int newChar = (int)(*iter) - 13;

					if (newChar < 97) 
						*iter = (char)( - (97 - newChar) + 123);
					else 
						*iter = newChar;
				}
				else 
					*iter = *iter;
				iter++;
			}
			if (textFileWriter())
				return nameNewFile_txt;
		}
	return message;
}

//verifica se o arquivo possui extensão e se ela é .txt
bool Rot_13::nameFileVerifier(string& nameFile) {
	int subs = nameFile.find(".txt");

	if ( 0 <= subs && subs < nameFile.length() ) {
		ifstream fileText(nameFile);

		if (fileText){
			nameFile_txt = nameFile;
			fileText.close();
			return true;
		}
	}
	return false;
}

//recupera o texto do arquivo inserido
bool Rot_13::textRecover(){
	ifstream fileText(nameFile_txt);

	if (!fileText) {
		return false;
	}
	else {
		getline(fileText, originalText);
		fileText.close();
		return true;
	}
}

//escreve o texto processado( descriptografado ou
//criptografado ) num novo arquivo
bool Rot_13::textFileWriter() {
	nameNewFile_txt = nameFile_txt;

	int length = nameNewFile_txt.length();

	//cria novo nome para o novo arquivo
	//acrescentando "cript" ao final do nome original
	nameNewFile_txt.insert(length - 4, "(cript)" );

	ofstream newFileText(nameNewFile_txt);

	if (!newFileText) {
		return false;
	}
	else {
		newFileText << dencryptText;
		newFileText.close();
		return true;
	}
}

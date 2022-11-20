#pragma once

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;

class Rot_13{
public:
	//interface
	static string encryptText(string&);
	static string decryptText(string&);

private:
	//utilit�rias
	static bool nameFileVerifier(string&);
	static bool textRecover();
	static bool textFileWriter();

	//vari�veis
	static string nameFile_txt;
	static string nameNewFile_txt;
	static string dencryptText;
	static string originalText;

};


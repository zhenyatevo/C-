// LexAnalisator.cpp : Этот файл будет шаманить на лексемном

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Lexer(char c, char nc, bool& flag, bool& errorF, int& i, vector<char>& signs);

int main(){
	char c, nc;
	vector<char> signs;
	//string message;
	
	while (cin.get(c)) { //создаю вектор символов входной строки для дальнейшей работы
		if (c == '#') {  // тут # - символ конца ввода
			break;
		}
		else if(c == '\n') { //игнорируем \n и продолжаем считывание
		}
		else {          // считвание входных символов
			signs.push_back(c);
		}
	}
	signs.push_back('#');// дообавили символ в конец строки для подстраховки
	signs.push_back('#');// дообавили символ в конец строки для подстраховки
	
	
	int i = 0;
	bool flag = false;
	bool errorF = false;
	while (i < signs.size()-2) {
		Lexer(signs[i], signs[i + 1], flag, errorF, i, signs);
		if (flag != true) {
			i ++;
		}
		else {
			i += 2;
		}
		if (errorF == true) {
			break;
		}
	}
	cout << "eof";

}

	

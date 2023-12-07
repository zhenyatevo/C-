// LexAnalisator.cpp : Этот файл будет шаманить на лексемном

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Lexer(char c, char nc, bool &flag, bool &errorF, int &i, vector<char> &signs) {
	string message ="";
	switch (c)	{
	case ' ':
		cout << "whitespace" << " "; // state 0 - пробел
		flag = false;
		break;
	case '(':  // state 1 - (){},.;*>
		cout << "lpar" << " ";
		flag = false;
		break;
	case ')':
		cout << "rpar"<< " ";
		flag = false;
		break;
	case '{': 
		cout << "lbrace"<< " ";
		flag = false;
		break;
	case '}':
		cout << "rbrace" << " ";
		flag = false;
		break;
	case ';':
		cout << "semicolon" << " ";
		flag = false;
		break;
	case ',':
		cout << "comma" << " ";
		flag = false;
		break;
	case '.':
		cout << "colon" << " ";
		flag = false;
		break;
	case '>':
		cout << "opgt" << " ";
		flag = false;
		break;
	case '*':
		cout << "opmul" << " ";
		flag = false;
		break;
	case '<':
		if (nc!= '=') {// state 2
			cout << "oplt" << " ";
			flag = false;
		}
		else {// state 3
			cout << "ople" << " ";
			flag = true;
		}
		break;
	case '!':
		if (nc != '=') {// state 4
			cout << "opnot" << " ";
			flag = false;
		}
		else {// state 5
			cout << "opne" << " ";
			flag = true;
		}
		break;
	case '=':
		if (nc != '=') {// state 6
			cout << "opassign" << " ";
			flag = false;
		}
		else {// state 7
			cout << "opeq" << " ";
			flag = true;
		}
		break;
	case '+':
		if (nc != '+') {// state 8
			cout << "opplus" << " ";
			flag = false;
		}
		else {// state 9
			cout << "opinc" << " ";
			flag = true;
		}
		break;
	case '|':
		if (nc != '|') {// state 10
			cout << "error..." << " ";
			flag = false;
			errorF = true;
		}
		else {// state 11
			cout << "opor" << " ";
			flag = true;
		}
		break;
	case '&':
		if (nc != '&') {// state 12
			cout << "error..." << " ";
			flag = false;
			errorF = true;
		}
		else {// state 13
			cout << "opand" << " ";
			flag = true;
		}
		break;
	case '\'':// state 14
		if (nc == '\'') {// state 15
			cout << "error..." << " ";
			flag = false;
			errorF = true;
		}
		else if (signs[i + 2] != '\'') {// state 16, тут мы берес через символ от с, ищем там '
			cout << "error..." << " ";
			flag = false;
			errorF = true;
		}
		else {// state 17
			cout << "char(value)" << " ";
			flag = false;
			i += 2;
		}
		break;

	case '\"':// state 18
		for (int j = i+1; j < signs.size() - 1; j++) {// state 20, перебор от i+1 эл-та, до знака конца строки ввода #
			if (signs[j] == '\"') {
				cout << "str(value)" << " ";
				flag = false;
				i = i + (j - i);
				break;
			
			}
			else if (signs[j] == '#') {// state 19, перебор от i+1 эл-та, до знака конца строки ввода #, когда нет второго символа "
				cout << "error..." << " ";
				flag = false;
				errorF = true;
				break;
			}
		}
		break;
	case '-':// state 22
		if (nc !='0' && nc != '1' && nc != '2'&& nc != '3'&& nc != '4'&& nc != '5'&& nc != '6'&& nc != '7'&& nc != '8'&& nc != '9') {
			cout << "opminus" << " ";
			flag = false;
		
		
		}
		else {// state 23, цикл работает до первой не цифры
			for (int j = i + 1; j < signs.size() - 1; j++) {
				if (signs[j] != '0' && signs[j] != '1' && signs[j] != '2' && signs[j] != '3' 
					&& signs[j] != '4' && signs[j] != '5' && signs[j] != '6' && signs[j] != '7' && signs[j] != '8' && signs[j] != '9') {

					cout << "num(value)" << " ";
					flag = false;
					i = i + (j - i -1);
					break;

				}
			
			}
		
		}
		break;
	case '0'://state 23, для положительных чисел
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':// state 23, цикл работает до первой не цифры
		for (int j = i + 1; j < signs.size() - 1; j++) {
			if (signs[j] != '0' && signs[j] != '1' && signs[j] != '2' && signs[j] != '3'
				&& signs[j] != '4' && signs[j] != '5' && signs[j] != '6' && signs[j] != '7' && signs[j] != '8' && signs[j] != '9') {

				cout << "num(value)" << " ";
				flag = false;
				i = i + (j - i - 1);
				break;

			}

		}
		break;
	case 'a'://state 21, letter
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
		
		message += c;
		for (int j = i + 1; j < signs.size() - 2; j++) {
			if ((signs[j] >= 'a' && signs[j] <= 'z') || (signs[j] >= 'A' && signs[j] <= 'Z') || (signs[j] == '_') || (signs[j] >= '0' && signs[j] <= '9')) {
				message += signs[j];
			}
			else {
				break;

			}
		}
		if (message == "int" || message == "char" || message == "if" || message == "else" || message == "switch" || message == "case" || message == "while"
			|| message == "for" || message == "return" || message == "in" || message == "out") { //keyword

			cout << "keyword" << " ";
			flag = false;
			i = i + message.size() - 1;
		}
		else {									//id(value)
			cout << "id(value)" << " ";
			flag = false;
			i = i + message.size() - 1;
		}


		break;
	
	







		break;
	default: 0;
		
	}
	return 0;
}

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

	

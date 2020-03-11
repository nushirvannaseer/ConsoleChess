// chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <conio.h>
#include <Windows.h>
#include <cstring>
#include <fstream>

using namespace std;

void printarr(int arr[][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void printBoard(char board[][8])
{
	system("cls");
	cout << "       ";
	char j = 97;
	for (int i = 0; i < 8; i++) {
		cout << j++ << "   ";
	}
	cout << endl;
	cout << "     ---------------------------------" << endl;
	char a = '8';
	char b = '8';
	//cout << "   ";
	for (int i = 0; i < 8; i++) {
		cout << " " << a-- << "   | ";
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << " | ";
		}
		cout << "  " << b-- << "   " << endl;
		cout << "     ---------------------------------" << endl;
	}
	cout << "       ";
	j = 97;
	for (int i = 0; i < 8; i++) {
		cout << j++ << "   ";
	}
	//	cout<< "****************************************************************" << endl;
	/*	cout << "      | ";
		for (int i = 0, j = 0; i < 8; i++, j++) {
			cout << 'a' << "  |  ";
		}*/
	cout << endl << endl;
}

void initBoard(char board[][8], int &turn, bool &majwhile, bool &checkmove, bool &LOOP)
{
	bool mainloop = true;

	while (mainloop == true) {
		system("cls");
		cout << endl << endl << endl;
		cout << "Hello humans! Before you start playing, you might want to have a look at these instructions:" << endl << endl << endl <<
			"1. To make a move, enter the source and destination coordinates without any spaces" << endl <<
			"and then press ENTER. An example of a valid input is: a2a3" << endl << endl <<
			"2. Make sure to have the Caps Lock off while entering the coordinates" << endl << endl << endl << endl;

		cout << "Press: " << endl << "1 to Start a New Game" << endl << "2 to Resume your previously saved game" << endl << "Esc to Exit :(" << endl;

		char inp = _getch();
		if (inp == '1') {

			std::ifstream fin;
			std::string filepath = "C:\\Users\\Acer\\Desktop\\chessave1.txt";
			fin.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
			if (!fin.is_open() || fin.fail())
			{
				fin.close();
				printf("\nError : failed to erase file content !");
			}
			fin.close();


			turn = 1;
			system("cls");
			board[0][0] = 'r', board[0][1] = 'n', board[0][2] = 'b', board[0][3] = 'q', board[0][4] = 'k',
				board[0][5] = 'b', board[0][6] = 'n', board[0][7] = 'r', board[7][0] = 'R', board[7][1] = 'N',
				board[7][2] = 'B', board[7][3] = 'Q', board[7][4] = 'K', board[7][5] = 'B', board[7][6] = 'N', board[7][7] = 'R';

			for (int i = 0; i < 8; i++) {
				board[1][i] = 'p';
				board[6][i] = 'P';
			}

			for (int i = 2; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					board[i][j] = ' ';
				}
			}

			printBoard(board);
			mainloop = false;
		}

		else if (inp == 27) {//esc
			//cout << "Exiting now!" << endl;
			turn = 7;
			mainloop = false;
			majwhile = false;
			checkmove = false;
			LOOP = false;
		}

		//else if (inp == '2') {//
		//	turn = 4;
		//	mainloop = false;
		//	majwhile = false;
		//	checkmove = false;
		//	LOOP = false;
		//}
		else {
			turn = 7;
		}
	}


}

void Swapp(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;

}

void inputMove(char board[][8], char input[], int &turn)
{
	char inp;
	bool valinp = true;
	//int count = 0;

	while (valinp == true) {
		cin >> input[1];//count++;
		//input[1] = inp;
		cin >> input[0]; //count++;
		//input[0] = inp;
		cin >> input[3]; // count++;
		//input[3] = inp;
		cin >> input[2]; // count++;
		//input[2] = inp;

		if (input[1]<'a' || input[1]>'h') {
			cout << "Enter a valid input (alpha out of bounds 1)\r" << endl;

			valinp = true;
		}
		else if (input[0]<'1' || input[0]>'8') {
			cout << "Enter a valid input (num out of bounds 1)\r" << endl;
			valinp = true;
		}
		else if (input[1] == input[3] && input[0] == input[2]) {
			cout << "Enter a valid input (source and dest same)\r" << endl;
			valinp = true;
		}
		else if (input[3]<'a' || input[3]>'h') {
			cout << "Enter a valid input(alpha out of bounds 2)\r" << endl;
			valinp = true;
		}
		else if (input[2]<'1' || input[2]>'8') {
			cout << "Enter a valid input (num out of bounds 2)\r" << endl;
			valinp = true;
		}

		else {
			valinp = false;
		}
	}

	/*for (int i = 0; i < 4; i++) {
		cout << input[i] << " ";
	}

	cout << endl;*/
}
//print valid moves
void inputarr(char input[], int inpt[])
{
	//inpt[0] = input[0];
	inpt[1] = input[1] - 97;
	//inpt[2] = input[2];
	inpt[3] = input[3] - 97;
	//adjusting numerical coordinates
	if (input[0] == '1') {
		inpt[0] = 7;
	}
	if (input[0] == '2') {
		inpt[0] = 6;
	}
	if (input[0] == '3') {
		inpt[0] = 5;
	}
	if (input[0] == '4') {
		inpt[0] = 4;
	}
	if (input[0] == '5') {
		inpt[0] = 3;
	}
	if (input[0] == '6') {
		inpt[0] = 2;
	}
	if (input[0] == '7') {
		inpt[0] = 1;
	}
	if (input[0] == '8') {
		inpt[0] = 0;
	}
	//adjusting destination numerical coord
	if (input[2] == 49) {
		inpt[2] = 7;
	}
	if (input[2] == 50) {
		inpt[2] = 6;
	}
	if (input[2] == 51) {
		inpt[2] = 5;
	}
	if (input[2] == 52) {
		inpt[2] = 4;
	}
	if (input[2] == 53) {
		inpt[2] = 3;
	}
	if (input[2] == 54) {
		inpt[2] = 2;
	}
	if (input[2] == 55) {
		inpt[2] = 1;
	}
	if (input[2] == 56) {
		inpt[2] = 0;
	}


	/*	for(int i = 0; i < 4; i++) {
			cout << inpt[i] << " ";
		}*/


}

//functions for check. check for black or white pieces and their moves

bool WpawnCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };


	//black pieces
	//first move for black
	if (board[s1][s2] == 'p' && s1 == 1) {
		for (int i = s1 + 1; board[i][s2] == ' ' && i < 4; i++) {
			pm[i][s2] = 1;
		}
		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//any other move for black
	else if (board[s1][s2] == 'p' && s1 != 1) {
		if (board[s1 + 1][s2] == ' ')//I MADE A CHANGE HERE TO THE MINUS SIGN. MADE IT A PLUS
			pm[s1 + 1][s2] = 1;

		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 2 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;

}

bool BpawnCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };
	//first move for white
	if (board[s1][s2] == 'P' && s1 == 6) {
		for (int i = s1 - 1; board[i][s2] == ' ' && i >= 4; i--) {
			pm[i][s2] = 1;
		}

		//capturess
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//any other move for white
	else if (board[s1][s2] == 'P' && s1 != 6) {
		if (board[s1 - 1][s2] == ' ')
			pm[s1 - 1][s2] = 1;
		//captures
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 2 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;

}

bool WknightCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//black knight p moves
	if (board[s1][s2] == 'n') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'A' && board[s1 - 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'A' && board[s1 - 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'A' && board[s1 - 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'A' && board[s1 - 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'A' && board[s1 + 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'A' && board[s1 + 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'A' && board[s1 + 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'A' && board[s1 + 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool BknightCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };
	//white knight p moves
	if (board[s1][s2] == 'N') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'a' && board[s1 - 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'a' && board[s1 - 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'a' && board[s1 - 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 - 2 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'a' && board[s1 - 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'a' && board[s1 + 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 + 2 < 8)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'a' && board[s1 + 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'a' && board[s1 + 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'a' && board[s1 + 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool WbishopCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//black bishop's moves

	if (board[s1][s2] == 'b') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool BbishopCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//WHITE BISHOP'S MOVES

	if (board[s1][s2] == 'B') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool WrookCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//black piece possible positions
	if (board[s1][s2] == 'r') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;

}

bool BrookCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//white piece possible positions
	if (board[s1][s2] == 'R') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;

}

bool WqueenCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };
	//BLACK QUEEN'S POSSIBLE MOVES

	if (board[s1][s2] == 'q') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool BqueenCHECK(char board[][8], int s1, int s2)
{
	int pm[8][8] = { 0 };

	//white piece possible positions
	if (board[s1][s2] == 'Q') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool WkingCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//BLACK piece possible positions
	if (board[s1][s2] == 'k') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'A' && board[s1 - 1][s2] <= 'Z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'A' && board[s1 + 1][s2] <= 'Z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'A' && board[s1][s2 + 1] <= 'Z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'A' && board[s1][s2 - 1] <= 'Z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'A' && board[s1 - 1][s2 + 1] <= 'Z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'A' && board[s1 - 1][s2 - 1] <= 'Z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1 && (board[i][j] == 'K')) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool BkingCHECK(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };

	//WHITE piece possible moves
	if (board[s1][s2] == 'K') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'a' && board[s1 - 1][s2] <= 'z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'a' && board[s1 + 1][s2] <= 'z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'a' && board[s1][s2 + 1] <= 'z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'a' && board[s1][s2 - 1] <= 'z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'a' && board[s1 + 1][s2 + 1] <= 'z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'a' && board[s1 + 1][s2 - 1] <= 'z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 2 && (board[i][j] == 'k')) {
				return true;
				break;
			}
		}
	}
	return false;
}

//final check functions

//this checks if the white king is under check
bool whiteCHECK(char board[][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] >= 'a' && board[i][j] <= 'z') {
				if (WpawnCHECK(board, i, j) == true) {
					return true;
				}
				else if (WknightCHECK(board, i, j) == true) {
					return true;
				}
				else if (WbishopCHECK(board, i, j) == true) {
					return true;
				}
				else if (WrookCHECK(board, i, j) == true) {
					return true;
				}
				else if (WqueenCHECK(board, i, j) == true) {
					return true;
				}
				else if (WkingCHECK(board, i, j) == true) {
					return true;
				}
			}
		}
	}
	return false;
}
//this checks if the black king is under check
bool blackCHECK(char board[][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
				if (BpawnCHECK(board, i, j) == true) {
					return true;
				}
				else if (BknightCHECK(board, i, j) == true) {
					return true;
				}
				else if (BbishopCHECK(board, i, j) == true) {
					return true;
				}
				else if (BrookCHECK(board, i, j) == true) {
					return true;
				}
				else if (BqueenCHECK(board, i, j) == true) {
					return true;
				}
				else if (BkingCHECK(board, i, j) == true) {
					return true;
				}
			}
		}
	}
	return false;
}

//moving pieces AND checking if check removed. if the check is removed or no check after move, the piece is moved

bool rookArr(char board[][8], int s1, int s2, int d1, int d2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//black piece possible positions
	if (board[s1][s2] == 'r') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}

	//white piece possible positions
	else if (board[s1][s2] == 'R') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

	}


	//CASTLING

	//castling move for black king
		//queenside castling
	if (s1 == 0 && s2 == 0 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][4] == 'k' &&
		d1 == 0 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {
		Swapp(board[s1][s2], board[0][3]);
		Swapp(board[0][4], board[0][2]);

		if (blackCHECK(board) == true) {
			Swapp(board[s1][s2], board[0][3]);
			Swapp(board[0][4], board[0][2]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else {
			count = 1;
			rookcount = 1;
			system("cls");
			printBoard(board);
			return true;
		}

	}
	//kingside castling
	else if (s1 == 0 && s2 == 7 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][4] == 'k' && d1 == 0 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {
		Swapp(board[0][7], board[0][5]);
		Swapp(board[0][4], board[0][6]);

		if (blackCHECK(board) == true) {
			Swapp(board[0][4], board[0][6]);
			Swapp(board[0][7], board[0][5]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else {
			count = 1;
			rookcount = 1;
			system("cls");
			printBoard(board);
			return true;
		}

	}



	//castling move for white king
		//queenside castling
	else if (s1 == 7 && s2 == 0 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][4] == 'K' &&
		d1 == 7 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {
		Swapp(board[7][4], board[7][2]);
		Swapp(board[7][0], board[7][3]);

		if (whiteCHECK(board) == true) {
			Swapp(board[7][4], board[7][2]);
			Swapp(board[7][0], board[7][3]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else {
			count = 1;
			rookcount = 1;
			system("cls");
			printBoard(board);
			return true;
		}

	}

	//kingside castling
	else if (s1 == 7 && s2 == 7 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][4] == 'K' && d1 == 7 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {
		Swapp(board[7][4], board[7][6]);
		Swapp(board[7][7], board[7][5]);

		if (whiteCHECK(board) == true) {
			Swapp(board[7][4], board[7][6]);
			Swapp(board[7][7], board[7][5]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else {
			count = 1;
			rookcount = 1;
			system("cls");
			printBoard(board);
			return true;
		}

	}






	//moving the rooks

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'R') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'R';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'R';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'r') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'r';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'r';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'R') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'r') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;
}

bool pawnArr(char board[][8], int s1, int s2, int d1, int d2, int source1[], int source2[], int dest1[], int dest2[], int numofmoves)
{

	int pm[8][8] = { 0 };
	//first move for white
	if (board[s1][s2] == 'P' && s1 == 6) {
		for (int i = s1 - 1; board[i][s2] == ' ' && i >= 4; i--) {
			pm[i][s2] = 1;
		}

		//capturess
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//any other move for white
	else if (board[s1][s2] == 'P' && s1 != 6) {
		if (board[s1 - 1][s2] == ' ' && s1 - 1 >= 0)
			pm[s1 - 1][s2] = 1;
		//captures
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//black pieces
	//first move for black
	if (board[s1][s2] == 'p' && s1 == 1) {
		for (int i = s1 + 1; board[i][s2] == ' ' && i < 4; i++) {
			pm[i][s2] = 1;
		}
		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//any other move for black
	else if (board[s1][s2] == 'p' && s1 != 1) {
		if (board[s1 + 1][s2] == ' ' && s1 + 1 < 8)//I MADE A CHANGE HERE TO THE MINUS SIGN. MADE IT A PLUS
			pm[s1 + 1][s2] = 1;

		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}


	//EN PASSANT

	char killedpiece;
	//for a white piece capturing a black piece
	if (board[s1][s2] == 'P' && s1 == 3 && d1 == 2 && source1[numofmoves - 1] == 1 && dest1[numofmoves - 1] == 3) {
		//for a black piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'p' && d2 == s2 - 1) {
			killedpiece = board[s1][s2 - 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 - 1] = ' ';//capturing the pawn
			if (whiteCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				system("cls");
				printBoard(board);
				return true;
			}

		}
		//for a black piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'p' && d2 == s2 + 1) {
			killedpiece = board[s1][s2 + 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 + 1] = ' ';//capturing the pawn
			if (whiteCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				system("cls");
				printBoard(board);
				return true;
			}
		}
	}
	//for a black piece capturing a white piece
	if (board[s1][s2] == 'p' && s1 == 4 && d1 == 5 && source1[numofmoves - 1] == 6 && dest1[numofmoves - 1] == 4) {
		//for a white piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'P' && d2 == s2 - 1) {
			killedpiece = board[s1][s2 - 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 - 1] = ' ';//capturing the pawn
			if (blackCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				system("cls");
				printBoard(board);
				return true;
			}

		}
		//for a white piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'P' && d2 == s2 + 1) {
			killedpiece = board[s1][s2 + 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 + 1] = ' ';//capturing the pawn
			if (blackCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				system("cls");
				printBoard(board);
				return true;
			}
		}
	}






	//CHECKING MOVE VALIDITY AND MOVING

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 2) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'P') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'P';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'P';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'p') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'p';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'p';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
	}
	else if (pm[d1][d2] == 1) {
		Swapp(board[s1][s2], board[d1][d2]);
		if (whiteCHECK(board) == true && board[d1][d2] == 'P') {
			Swapp(board[d1][d2], board[s1][s2]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else if (blackCHECK(board) == true && board[d1][d2] == 'p') {
			Swapp(board[d1][d2], board[s1][s2]);
			cout << "Check not removed. Make a valid move!" << endl;
			return false;

		}
	}

	//PROMOTION
	char cmd = 'a';
	if (d1 == 0) {//promotion for white
		cout << "Your pawn has earned a promotion! Select any one of the pieces you want to promote your pawn to:" <<
			endl << "Press N for knight" << endl << "Press B for bishop" << endl << "Press R for rook" << endl <<
			"Press Q for queen" << endl;
		bool loop = true;
		while (loop == true) {
			cin >> cmd;
			if (cmd == 'N' || cmd == 'n') {
				board[d1][d2] = 'N';
				loop = false;
			}
			else if (cmd == 'B' || cmd == 'b') {
				board[d1][d2] = 'B';
				loop = false;
			}
			else if (cmd == 'R' || cmd == 'r') {
				board[d1][d2] = 'R';
				loop = false;
			}
			else if (cmd == 'Q' || cmd == 'q') {
				board[d1][d2] = 'Q';
				loop = false;
			}
			else {
				cout << "Enter a valid input" << endl;
				loop = true;
			}

		}
	}

	else if (d1 == 7) {//promotion for black
		cout << "Your pawn has earned a promotion! Select any one of the pieces you want to promote your pawn to:" <<
			endl << "Press N for knight" << endl << "Press B for bishop" << endl << "Press R for rook" << endl <<
			"Press Q for queen" << endl;
		bool loop = true;
		while (loop == true) {
			cin >> cmd;
			if (cmd == 'N' || cmd == 'n') {
				board[d1][d2] = 'n';
				loop = false;
			}
			else if (cmd == 'B' || cmd == 'b') {
				board[d1][d2] = 'b';
				loop = false;
			}
			else if (cmd == 'R' || cmd == 'r') {
				board[d1][d2] = 'r';
				loop = false;
			}
			else if (cmd == 'Q' || cmd == 'q') {
				board[d1][d2] = 'q';
				loop = false;
			}
			else {
				cout << "Enter a valid input" << endl;
				loop = true;
			}

		}
	}





	system("cls");
	printBoard(board);
	return true;


}

bool knightArr(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };
	if (board[s1][s2] == 'N') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'a' && board[s1 - 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'a' && board[s1 - 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'a' && board[s1 - 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 - 2 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'a' && board[s1 - 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'a' && board[s1 + 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 + 2 < 8)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'a' && board[s1 + 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'a' && board[s1 + 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 + 2 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'a' && board[s1 + 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//black knight p moves
	else if (board[s1][s2] == 'n') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'A' && board[s1 - 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'A' && board[s1 - 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'A' && board[s1 - 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0 && s1 - 2 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'A' && board[s1 - 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'A' && board[s1 + 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0 && s1 + 2 < 8)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'A' && board[s1 + 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'A' && board[s1 + 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 + 2 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'A' && board[s1 + 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//moving
	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'N') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'N';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'N';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'n') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'n';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'n';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'N') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'n') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;
}

bool bishopArr(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };


	//black bishop's moves


	if (board[s1][s2] == 'b') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//WHITE BISHOP'S MOVES

	else if (board[s1][s2] == 'B') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}


	//moving the bishops

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'B') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'B';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'B';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'b') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'b';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'b';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'B') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'b') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;

}

bool queenArr(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };

	//white piece possible positions
	if (board[s1][s2] == 'Q') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//BLACK QUEEN'S POSSIBLE MOVES


	else if (board[s1][s2] == 'q') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}


	//moving the QUEEN

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'Q') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'Q';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'Q';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'q') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'q';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'q';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'Q') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'q') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;


}

bool kingArr(char board[][8], int s1, int s2, int d1, int d2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//BLACK piece possible positions
	if (board[s1][s2] == 'k') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'A' && board[s1 - 1][s2] <= 'Z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'A' && board[s1 + 1][s2] <= 'Z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'A' && board[s1][s2 + 1] <= 'Z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'A' && board[s1][s2 - 1] <= 'Z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'A' && board[s1 - 1][s2 + 1] <= 'Z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'A' && board[s1 - 1][s2 - 1] <= 'Z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//WHITE piece possible moves
	if (board[s1][s2] == 'K') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'a' && board[s1 - 1][s2] <= 'z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'a' && board[s1 + 1][s2] <= 'z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'a' && board[s1][s2 + 1] <= 'z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'a' && board[s1][s2 - 1] <= 'z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'a' && board[s1 + 1][s2 + 1] <= 'z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'a' && board[s1 + 1][s2 - 1] <= 'z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//castling move for black king
	if (s1 == 0 && s2 == 4 && board[s1][s2] == 'k' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 0 && d2 == 2 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][0] == 'r') {
			
			
		//making amendments	
			Swapp(board[s1][s2], board[0][3]);
			//Swapp(board[0][0], board[0][3]);

			if (blackCHECK(board) == true) {
				Swapp(board[0][4], board[0][3]);
			//	Swapp(board[0][0], board[0][3]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				//reposition the king
				Swapp(board[0][4], board[0][3]);
				//swapping with the destination now
				Swapp(board[s1][s2], board[0][2]);
				Swapp(board[0][0], board[0][3]);

				if (blackCHECK(board) == true) {
					Swapp(board[0][4], board[0][2]);
					Swapp(board[0][0], board[0][3]);
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					count = 1;
					rookcount = 1;
					system("cls");
					printBoard(board);
					return true;
				}

			}
			
			//amendment ends
			
			
			

		}
		//kingside castling
		else if (d1 == 0 && d2 == 6 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 'r') {
			Swapp(board[0][4], board[0][5]);
			//Swapp(board[0][7], board[0][5]);

			if (blackCHECK(board) == true) {
				Swapp(board[0][4], board[0][5]);
				//Swapp(board[0][7], board[0][5]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				
				Swapp(board[0][4], board[0][5]);
				//Swapp(board[0][7], board[0][5]);
				Swapp(board[0][4], board[0][6]);
				Swapp(board[0][7], board[0][5]);

				if (blackCHECK(board) == true) {
					Swapp(board[0][4], board[0][6]);
					Swapp(board[0][7], board[0][5]);
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					count = 1;
					rookcount = 1;
					system("cls");
					printBoard(board);
					return true;
				}
			}

		}
	}


	//castling move for white king
	else if (s1 == 7 && s2 == 4 && board[s1][s2] == 'K' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 7 && d2 == 2 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][0] == 'R') {
			Swapp(board[7][4], board[7][3]);
			//Swapp(board[7][0], board[7][3]);

			if (whiteCHECK(board) == true) {
				Swapp(board[7][4], board[7][3]);
				//Swapp(board[7][0], board[7][3]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[7][4], board[7][3]);

				Swapp(board[7][4], board[7][2]);
				Swapp(board[7][0], board[7][3]);

				if (whiteCHECK(board) == true) {
					Swapp(board[7][4], board[7][2]);
					Swapp(board[7][0], board[7][3]);
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					count = 1;
					rookcount = 1;
					system("cls");
					printBoard(board);
					return true;
				}

			}

		}

		//kingside castling
		else if (d1 == 7 && d2 == 6 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'R') {
			Swapp(board[7][4], board[7][5]);
			//Swapp(board[7][7], board[7][5]);

			if (whiteCHECK(board) == true) {
				Swapp(board[7][4], board[7][5]);
				//Swapp(board[7][7], board[7][5]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {

				Swapp(board[7][4], board[7][5]);

				Swapp(board[7][4], board[7][6]);
				Swapp(board[7][7], board[7][5]);

				if (whiteCHECK(board) == true) {
					Swapp(board[7][4], board[7][6]);
					Swapp(board[7][7], board[7][5]);
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					count = 1;
					rookcount = 1;
					system("cls");
					printBoard(board);
					return true;
				}
				
			}
		}
	}



	//moving the king

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'K') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'K';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'K';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

			}
			else if (board[s1][s2] == 'k') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'k';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'k';
					board[d1][d2] = storpiece;
					cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'K') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'k') {
				Swapp(board[d1][d2], board[s1][s2]);
				cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;

}

//check if the move ENTERED by the user is a valid move
bool rook(char board[][8], int s1, int s2, int d1, int d2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//black piece possible positions
	if (board[s1][s2] == 'r') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}

	//white piece possible positions
	else if (board[s1][s2] == 'R') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

	}



	//castling move for black king
		//queenside castling
	if (s1 == 0 && s2 == 0 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][4] == 'k' &&
		d1 == 0 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {
		return true;

	}
	//kingside castling
	else if (s1 == 0 && s2 == 7 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][4] == 'k' && d1 == 0 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {

		return true;
	}

	//castling move for white king
		//queenside castling
	else if (s1 == 7 && s2 == 0 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][4] == 'K' &&
		d1 == 7 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {

		return true;


	}

	//kingside castling
	else if (s1 == 7 && s2 == 7 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][4] == 'K' && d1 == 7 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {

		return true;


	}


	if (pm[d1][d2] == 1) {
		return true;
	}

	else {
		return false;

	}
}

bool pawn(char board[][8], int s1, int s2, int d1, int d2, int source1[], int source2[], int dest1[], int dest2[], int numofmoves)
{

	int pm[8][8] = { 0 };
	//first move for white
	if (board[s1][s2] == 'P' && s1 == 6) {
		for (int i = s1 - 1; board[i][s2] == ' ' && i >= 4; i--) {
			pm[i][s2] = 1;
		}

		//capturess
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//any other move for white
	else if (board[s1][s2] == 'P' && s1 != 6) {
		if (board[s1 - 1][s2] == ' ' && s1 - 1 >= 0)
			pm[s1 - 1][s2] = 1;
		//captures
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//black pieces
	//first move for black
	if (board[s1][s2] == 'p' && s1 == 1) {
		for (int i = s1 + 1; board[i][s2] == ' ' && i < 4; i++) {
			pm[i][s2] = 1;
		}
		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//any other move for black
	else if (board[s1][s2] == 'p' && s1 != 1) {
		if (board[s1 + 1][s2] == ' ' && s1 + 1 < 8)//I MADE A CHANGE HERE TO THE MINUS SIGN. MADE IT A PLUS
			pm[s1 + 1][s2] = 1;

		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//EN PASSANT
	//for a white piece capturing a black piece
	if (board[s1][s2] == 'P' && s1 == 3 && d1 == 2 && source1[numofmoves - 1] == 1 && dest1[numofmoves - 1] == 3) {
		//for a black piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'p' && d2 == s2 - 1) {
			return true;
		}
		//for a black piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'p' && d2 == s2 + 1) {
			return true;
		}
	}
	//for a black piece capturing a white piece
	if (board[s1][s2] == 'p' && s1 == 4 && d1 == 5 && source1[numofmoves - 1] == 6 && dest1[numofmoves - 1] == 4) {
		//for a white piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'P' && d2 == s2 - 1) {
			return true;
		}
		//for a white piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'P' && d2 == s2 + 1) {
			return true;
		}
	}





	//MOVING THE PAWNS
	if (pm[d1][d2] == 1 || pm[d1][d2] == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool knight(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };
	//white knight p moves
	if (board[s1][s2] == 'N') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'a' && board[s1 - 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'a' && board[s1 - 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'a' && board[s1 - 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 - 2 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'a' && board[s1 - 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'a' && board[s1 + 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0 && s1 + 2 < 8)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'a' && board[s1 + 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'a' && board[s1 + 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 + 2 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'a' && board[s1 + 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//black knight p moves
	else if (board[s1][s2] == 'n') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'A' && board[s1 - 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'A' && board[s1 - 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'A' && board[s1 - 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0 && s1 - 2 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'A' && board[s1 - 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'A' && board[s1 + 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0 && s1 + 2 < 8)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'A' && board[s1 + 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'A' && board[s1 + 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 + 2 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'A' && board[s1 + 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//moving
	if (pm[d1][d2] == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool bishop(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };


	//black bishop's moves


	if (board[s1][s2] == 'b') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//WHITE BISHOP'S MOVES

	else if (board[s1][s2] == 'B') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}


	//moving the bishops

	if (pm[d1][d2] == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool queen(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };

	//white piece possible positions
	if (board[s1][s2] == 'Q') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//BLACK QUEEN'S POSSIBLE MOVES


	else if (board[s1][s2] == 'q') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}


	//moving the QUEEN

	if (pm[d1][d2] == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool king(char board[][8], int s1, int s2, int d1, int d2, int count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//BLACK piece possible positions
	if (board[s1][s2] == 'k') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'A' && board[s1 - 1][s2] <= 'Z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'A' && board[s1 + 1][s2] <= 'Z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'A' && board[s1][s2 + 1] <= 'Z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'A' && board[s1][s2 - 1] <= 'Z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'A' && board[s1 - 1][s2 + 1] <= 'Z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'A' && board[s1 - 1][s2 - 1] <= 'Z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//WHITE piece possible moves
	if (board[s1][s2] == 'K') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'a' && board[s1 - 1][s2] <= 'z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'a' && board[s1 + 1][s2] <= 'z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'a' && board[s1][s2 + 1] <= 'z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'a' && board[s1][s2 - 1] <= 'z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'a' && board[s1 + 1][s2 + 1] <= 'z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'a' && board[s1 + 1][s2 - 1] <= 'z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}

	//castling move for black king
	if (s1 == 0 && s2 == 4 && board[s1][s2] == 'k' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 0 && d2 == 2 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][0] == 'r') {
			return true;
		}
		//kingside castling
		else if (d1 == 0 && d2 == 6 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 'r') {
			return true;
		}
	}

	//castling move for white king
	else if (s1 == 7 && s2 == 4 && board[s1][s2] == 'K' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 7 && d2 == 2 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][0] == 'R') {
			return true;
		}
		//kingside castling
		else if (d1 == 7 && d2 == 6 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'R') {
			return true;
		}
	}

	   	  	//moving the king

	if (pm[d1][d2] == 1) {
		return true;
	}
	else {
		return false;
	}
}

// calculating any sort of mate...

//these functions calculate possible paths, move the pieces, determine if check removed or not
//these move pieces back to original positions after checking for a check

bool rookpathdet(char board[][8], int s1, int s2, int d1, int d2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//black piece possible positions
	if (board[s1][s2] == 'r') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}

	//white piece possible positions
	else if (board[s1][s2] == 'R') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

	}


	//CASTLING

	//castling move for black king
		//queenside castling
	if (s1 == 0 && s2 == 0 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][4] == 'k' &&
		d1 == 0 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {
		Swapp(board[s1][s2], board[0][3]);
		Swapp(board[0][4], board[0][2]);

		if (blackCHECK(board) == true) {
			Swapp(board[s1][s2], board[0][3]);
			Swapp(board[0][4], board[0][2]);

			return false;
		}
		else {
			Swapp(board[s1][s2], board[0][3]);
			Swapp(board[0][4], board[0][2]);
			return true;
		}

	}
	//kingside castling
	else if (s1 == 0 && s2 == 7 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][4] == 'k' && d1 == 0 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'r') {
		Swapp(board[0][7], board[0][5]);
		Swapp(board[0][4], board[0][6]);

		if (blackCHECK(board) == true) {
			Swapp(board[0][4], board[0][6]);
			Swapp(board[0][7], board[0][5]);

			return false;
		}
		else {
			Swapp(board[0][4], board[0][6]);
			Swapp(board[0][7], board[0][5]);
			return true;
		}

	}



	//castling move for white king
		//queenside castling
	else if (s1 == 7 && s2 == 0 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][4] == 'K' &&
		d1 == 7 && d2 == 3 && board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {
		Swapp(board[7][4], board[7][2]);
		Swapp(board[7][0], board[7][3]);

		if (whiteCHECK(board) == true) {
			Swapp(board[7][4], board[7][2]);
			Swapp(board[7][0], board[7][3]);

			return false;
		}
		else {
			Swapp(board[7][4], board[7][2]);
			Swapp(board[7][0], board[7][3]);
			return true;
		}

	}

	//kingside castling
	else if (s1 == 7 && s2 == 7 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][4] == 'K' && d1 == 7 && d2 == 5 &&
		board[d1][d2] == ' ' && count == 0 && rookcount == 0 && board[s1][s2] == 'R') {
		Swapp(board[7][4], board[7][6]);
		Swapp(board[7][7], board[7][5]);

		if (whiteCHECK(board) == true) {
			Swapp(board[7][4], board[7][6]);
			Swapp(board[7][7], board[7][5]);

			return false;
		}
		else {
			Swapp(board[7][4], board[7][6]);
			Swapp(board[7][7], board[7][5]);
			return true;
		}

	}


	//moving the rooks

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'R') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'R';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'R';
					board[d1][d2] = storpiece;

					return false;
				}
				else {
					board[s1][s2] = 'R';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'r') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'r';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'r';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'r';
					board[d1][d2] = storpiece;
					return true;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'R') {
				Swapp(board[d1][d2], board[s1][s2]);
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}

			else if (blackCHECK(board) == true && board[d1][d2] == 'r') {
				Swapp(board[d1][d2], board[s1][s2]);
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}

			else if (whiteCHECK(board) == false && board[d1][d2] == 'R') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
			else if (blackCHECK(board) == false && board[d1][d2] == 'r') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
		}
	}


	return true;
}

bool pawnpathdet(char board[][8], int s1, int s2, int d1, int d2, int source1[], int source2[], int dest1[], int dest2[], int numofmoves)
{

	int pm[8][8] = { 0 };
	//first move for white
	if (board[s1][s2] == 'P' && s1 == 6) {
		for (int i = s1 - 1; board[i][s2] == ' ' && i >= 4; i--) {
			pm[i][s2] = 1;
		}

		//capturess
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s1 - 1 >= 0)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s1 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//any other move for white
	else if (board[s1][s2] == 'P' && s1 != 6) {
		if (board[s1 - 1][s2] == ' ' && s1 - 1 >= 0)
			pm[s1 - 1][s2] = 1;
		//captures
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0 && s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//black pieces
	//first move for black
	if (board[s1][s2] == 'p' && s1 == 1) {
		for (int i = s1 + 1; board[i][s2] == ' ' && i < 4; i++) {
			pm[i][s2] = 1;
		}
		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//any other move for black
	else if (board[s1][s2] == 'p' && s1 != 1) {
		if (board[s1 + 1][s2] == ' ' && s1 + 1 < 8)//I MADE A CHANGE HERE TO THE MINUS SIGN. MADE IT A PLUS
			pm[s1 + 1][s2] = 1;

		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8 && s1 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0 && s1 + 1 < 8)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}


	//EN PASSANT

	char killedpiece;
	//for a white piece capturing a black piece
	if (board[s1][s2] == 'P' && s1 == 3 && d1 == 2 && source1[numofmoves - 1] == 1 && dest1[numofmoves - 1] == 3) {
		//for a black piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'p' && d2 == s2 - 1) {
			killedpiece = board[s1][s2 - 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 - 1] = ' ';//capturing the pawn
			if (whiteCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				//cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				return true;
			}

		}
		//for a black piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'p' && d2 == s2 + 1) {
			killedpiece = board[s1][s2 + 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 + 1] = ' ';//capturing the pawn
			if (whiteCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				return true;
			}
		}
	}
	//for a black piece capturing a white piece
	if (board[s1][s2] == 'p' && s1 == 4 && d1 == 5 && source1[numofmoves - 1] == 6 && dest1[numofmoves - 1] == 4) {
		//for a white piece of left side
		if (source2[numofmoves - 1] == s2 - 1 && s2 - 1 >= 0 && dest2[numofmoves - 1] == s2 - 1 && board[s1][s2 - 1] == 'P' && d2 == s2 - 1) {
			killedpiece = board[s1][s2 - 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 - 1] = ' ';//capturing the pawn
			if (blackCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 - 1] = killedpiece;
				return true;
			}

		}
		//for a white piece on right side
		else if (source2[numofmoves - 1] == s2 + 1 && s2 + 1 < 8 && dest2[numofmoves - 1] == s2 + 1 && board[s1][s2 + 1] == 'P' && d2 == s2 + 1) {
			killedpiece = board[s1][s2 + 1];
			Swapp(board[s1][s2], board[d1][d2]);
			board[s1][s2 + 1] = ' ';//capturing the pawn
			if (blackCHECK(board) == true) {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[d1][d2], board[s1][s2]);
				board[s1][s2 + 1] = killedpiece;
				return true;
			}
		}
	}






	//CHECKING MOVE VALIDITY AND MOVING

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 2) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'P') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'P';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'P';
					board[d1][d2] = storpiece;
					//			cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					board[s1][s2] = 'P';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'p') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'p';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'p';
					board[d1][d2] = storpiece;
					//			cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}

				else {
					board[s1][s2] = 'p';
					board[d1][d2] = storpiece;
					return true;
				}

			}
		}
	}
	else if (pm[d1][d2] == 1) {
		Swapp(board[s1][s2], board[d1][d2]);
		if (whiteCHECK(board) == true && board[d1][d2] == 'P') {
			Swapp(board[d1][d2], board[s1][s2]);
			//		cout << "Check not removed. Make a valid move!" << endl;
			return false;
		}
		else if (blackCHECK(board) == true && board[d1][d2] == 'p') {
			Swapp(board[d1][d2], board[s1][s2]);
			//		cout << "Check not removed. Make a valid move!" << endl;
			return false;

		}
		else if (whiteCHECK(board) == false && board[d1][d2] == 'P') {
			Swapp(board[d1][d2], board[s1][s2]);
			return true;
		}
		else if (blackCHECK(board) == false && board[d1][d2] == 'p') {
			Swapp(board[d1][d2], board[s1][s2]);
			return true;
		}
	}

	//PROMOTION
	char cmd = 'a';
	if (d1 == 0) {//promotion for white
		cout << "Your pawn has earned a promotion! Select any one of the pieces you want to promote your pawn to:" <<
			endl << "Press N for knight" << endl << "Press B for bishop" << endl << "Press R for rook" << endl <<
			"Press Q for queen" << endl;
		bool loop = true;
		while (loop == true) {
			cin >> cmd;
			if (cmd == 'N' || cmd == 'n') {
				board[d1][d2] = 'N';
				loop = false;
			}
			else if (cmd == 'B' || cmd == 'b') {
				board[d1][d2] = 'B';
				loop = false;
			}
			else if (cmd == 'R' || cmd == 'r') {
				board[d1][d2] = 'R';
				loop = false;
			}
			else if (cmd == 'Q' || cmd == 'q') {
				board[d1][d2] = 'Q';
				loop = false;
			}
			else {
				cout << "Enter a valid input" << endl;
				loop = true;
			}

		}
	}

	else if (d1 == 8) {//promotion for black
		cout << "Your pawn has earned a promotion! Select any one of the pieces you want to promote your pawn to:" <<
			endl << "Press N for knight" << endl << "Press B for bishop" << endl << "Press R for rook" << endl <<
			"Press Q for queen" << endl;
		bool loop = true;
		while (loop == true) {
			cin >> cmd;
			if (cmd == 'N' || cmd == 'n') {
				board[d1][d2] = 'n';
				loop = false;
			}
			else if (cmd == 'B' || cmd == 'b') {
				board[d1][d2] = 'b';
				loop = false;
			}
			else if (cmd == 'R' || cmd == 'r') {
				board[d1][d2] = 'r';
				loop = false;
			}
			else if (cmd == 'Q' || cmd == 'q') {
				board[d1][d2] = 'q';
				loop = false;
			}
			else {
				cout << "Enter a valid input" << endl;
				loop = true;
			}

		}
	}





	system("cls");
	printBoard(board);
	return true;


}

bool knightpathdet(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };
	//white knight p moves
	if (board[s1][s2] == 'N') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'a' && board[s1 - 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'a' && board[s1 - 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'a' && board[s1 - 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'a' && board[s1 - 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'a' && board[s1 + 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'a' && board[s1 + 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'a' && board[s1 + 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'a' && board[s1 + 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//black knight p moves
	else if (board[s1][s2] == 'n') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'A' && board[s1 - 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'A' && board[s1 - 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'A' && board[s1 - 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'A' && board[s1 - 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'A' && board[s1 + 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'A' && board[s1 + 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'A' && board[s1 + 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'A' && board[s1 + 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//moving
	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'N') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'N';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'N';
					board[d1][d2] = storpiece;
					//	cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					board[s1][s2] = 'N';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'n') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'n';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'n';
					board[d1][d2] = storpiece;
					//		cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					board[s1][s2] = 'n';
					board[d1][d2] = storpiece;
					return true;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'N') {
				Swapp(board[d1][d2], board[s1][s2]);
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'n') {
				Swapp(board[d1][d2], board[s1][s2]);
				//cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (whiteCHECK(board) == false && board[d1][d2] == 'N') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
			else if (blackCHECK(board) == false && board[d1][d2] == 'n') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;
}

bool bishoppathdet(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };


	//black bishop's moves


	if (board[s1][s2] == 'b') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//WHITE BISHOP'S MOVES

	else if (board[s1][s2] == 'B') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}


	//moving the bishops

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'B') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'B';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'B';
					board[d1][d2] = storpiece;
					//		cout << "Check not removed. Make a valid move!" << endl;
					return false;
				}
				else {
					board[s1][s2] = 'B';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'b') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'b';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'b';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'b';
					board[d1][d2] = storpiece;
					return true;
				}
			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'B') {
				Swapp(board[d1][d2], board[s1][s2]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'b') {
				Swapp(board[d1][d2], board[s1][s2]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (whiteCHECK(board) == false && board[d1][d2] == 'B') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
			else if (blackCHECK(board) == false && board[d1][d2] == 'b') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;

}

bool queenpathdet(char board[][8], int s1, int s2, int d1, int d2)
{

	int pm[8][8] = { 0 };

	//white piece possible positions
	if (board[s1][s2] == 'Q') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//BLACK QUEEN'S POSSIBLE MOVES


	else if (board[s1][s2] == 'q') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}


	//moving the QUEEN

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'Q') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'Q';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'Q';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'Q';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'q') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'q';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'q';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'q';
					board[d1][d2] = storpiece;
					return true;
				}

			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'Q') {
				Swapp(board[d1][d2], board[s1][s2]);
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'q') {
				Swapp(board[d1][d2], board[s1][s2]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (whiteCHECK(board) == false && board[d1][d2] == 'Q') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
			else if (blackCHECK(board) == false && board[d1][d2] == 'q') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;


}

bool kingpathdet(char board[][8], int s1, int s2, int d1, int d2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//BLACK piece possible positions
	if (board[s1][s2] == 'k') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'A' && board[s1 - 1][s2] <= 'Z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'A' && board[s1 + 1][s2] <= 'Z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'A' && board[s1][s2 + 1] <= 'Z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'A' && board[s1][s2 - 1] <= 'Z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'A' && board[s1 - 1][s2 + 1] <= 'Z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'A' && board[s1 - 1][s2 - 1] <= 'Z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//WHITE piece possible moves
	if (board[s1][s2] == 'K') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'a' && board[s1 - 1][s2] <= 'z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'a' && board[s1 + 1][s2] <= 'z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'a' && board[s1][s2 + 1] <= 'z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'a' && board[s1][s2 - 1] <= 'z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'a' && board[s1 + 1][s2 + 1] <= 'z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'a' && board[s1 + 1][s2 - 1] <= 'z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//castling move for black king
	if (s1 == 0 && s2 == 4 && board[s1][s2] == 'k' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 0 && d2 == 2 && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][0] == 'r') {
			Swapp(board[s1][s2], board[0][2]);
			Swapp(board[0][0], board[0][3]);

			if (blackCHECK(board) == true) {
				Swapp(board[0][4], board[0][2]);
				Swapp(board[0][0], board[0][3]);
				//	cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[0][4], board[0][2]);
				Swapp(board[0][0], board[0][3]);
				return true;
			}

		}
		//kingside castling
		else if (d1 == 0 && d2 == 6 && board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 'r') {
			Swapp(board[0][4], board[0][6]);
			Swapp(board[0][7], board[0][5]);

			if (blackCHECK(board) == true) {
				Swapp(board[0][4], board[0][6]);
				Swapp(board[0][7], board[0][5]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[0][4], board[0][6]);
				Swapp(board[0][7], board[0][5]);
				return true;
			}

		}
	}


	//castling move for white king
	else if (s1 == 7 && s2 == 4 && board[s1][s2] == 'K' && count == 0 && rookcount == 0) {
		//queenside castling
		if (d1 == 7 && d2 == 2 && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][0] == 'R') {
			Swapp(board[7][4], board[7][2]);
			Swapp(board[7][0], board[7][3]);

			if (whiteCHECK(board) == true) {
				Swapp(board[7][4], board[7][2]);
				Swapp(board[7][0], board[7][3]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[7][4], board[7][2]);
				Swapp(board[7][0], board[7][3]);
				return true;
			}

		}

		//kingside castling
		else if (d1 == 7 && d2 == 6 && board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'R') {
			Swapp(board[7][4], board[7][6]);
			Swapp(board[7][7], board[7][5]);

			if (whiteCHECK(board) == true) {
				Swapp(board[7][4], board[7][6]);
				Swapp(board[7][7], board[7][5]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else {
				Swapp(board[7][4], board[7][6]);
				Swapp(board[7][7], board[7][5]);
				return true;
			}

		}
	}



	//moving the king

	char storpiece = board[d1][d2];
	if (pm[d1][d2] == 1) {
		if ((board[d1][d2] >= 'a' && board[d1][d2] <= 'z') || (board[d1][d2] >= 'A' && board[d1][d2] <= 'Z')) {
			if (board[s1][s2] == 'K') {//for moving the white piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'K';

				if (whiteCHECK(board) == true) {
					board[s1][s2] = 'K';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'K';
					board[d1][d2] = storpiece;
					return true;
				}

			}
			else if (board[s1][s2] == 'k') {//for moving the black piece to capture
				board[s1][s2] = ' ';
				board[d1][d2] = 'k';

				if (blackCHECK(board) == true) {
					board[s1][s2] = 'k';
					board[d1][d2] = storpiece;
					return false;
				}
				else {
					board[s1][s2] = 'k';
					board[d1][d2] = storpiece;
					return true;
				}

			}
		}
		else if (board[d1][d2] == ' ') {
			Swapp(board[s1][s2], board[d1][d2]);
			if (whiteCHECK(board) == true && board[d1][d2] == 'K') {
				Swapp(board[d1][d2], board[s1][s2]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (blackCHECK(board) == true && board[d1][d2] == 'k') {
				Swapp(board[d1][d2], board[s1][s2]);
				//		cout << "Check not removed. Make a valid move!" << endl;
				return false;
			}
			else if (whiteCHECK(board) == false && board[d1][d2] == 'K') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
			else if (blackCHECK(board) == false && board[d1][d2] == 'k') {
				Swapp(board[d1][d2], board[s1][s2]);
				return true;
			}
		}
	}



	system("cls");
	printBoard(board);
	//printarr(pm);
	return true;

}

//these functions give coordinates to above functions for path testing
//these functions calculate all possible paths for the pieces it receives from the functions below. then stores the coordinates of desinations in two arrays.
// here pm is a temp array of 8 by 8 where possible paths are either 1 or 2(2 only for the pawn as 1 represents a straight path and 2 represents a capture move for the pawn only)
//retval is a counter that counts the number of return values. it is similar to retcnt used below
// by using pathdet functions for all pieces we check for the pieces and their destination coordinates we find. then we check whether check is removed when we move the
//pieces on those destinations. swapping or overwriting and the reverse occur there and it is seen if the check is returned true or not
bool pawnmate(char board[][8], int s1, int s2, int source1[], int source2[], int dest1[], int dest2[], int numofmoves)
{


	int pm[8][8] = { 0 };
	//first move for white
	if (board[s1][s2] == 'P' && s1 == 6) {
		for (int i = s1 - 1; board[i][s2] == ' ' && i >= 4; i--) {
			pm[i][s2] = 1;
		}

		//capturess
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//any other move for white
	else if (board[s1][s2] == 'P' && s1 != 6) {
		if (board[s1 - 1][s2] == ' ')
			pm[s1 - 1][s2] = 1;
		//captures
		if (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z') {
			if (s2 + 1 < 8)
				pm[s1 - 1][s2 + 1] = 2;
		}
		if (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z') {
			if (s2 - 1 >= 0)
				pm[s1 - 1][s2 - 1] = 2;
		}

	}


	//black pieces
	//first move for black
	if (board[s1][s2] == 'p' && s1 == 1) {
		for (int i = s1 + 1; board[i][s2] == ' ' && i < 4; i++) {
			pm[i][s2] = 1;
		}
		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//any other move for black
	else if (board[s1][s2] == 'p' && s1 != 1) {
		if (board[s1 + 1][s2] == ' ')//I MADE A CHANGE HERE TO THE MINUS SIGN. MADE IT A PLUS
			pm[s1 + 1][s2] = 1;

		//captures

		if (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z') {
			if (s2 + 1 < 8)
				pm[s1 + 1][s2 + 1] = 2;
		}
		if (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z') {
			if (s2 - 1 >= 0)
				pm[s1 + 1][s2 - 1] = 2;
		}

	}

	//storing destinations in an array
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((pm[i][j] == 1 || pm[i][j] == 2)) {
				count++;
			}
		}
	}

	if (count > 0) {
		int * moveX = new int[count];
		int * moveY = new int[count];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < count; i++) {
			if (pawnpathdet(board, s1, s2, moveX[i], moveY[i], source1, source2, dest1, dest2, numofmoves) == false) {
				retval++;
			}
			else {
				return true;
			}

		}

		if (retval == count) {
			return false;
		}
	}
	else {
		return false;
	}
}

bool knightmate(char board[][8], int s1, int s2)
{



	int pm[8][8] = { 0 };
	if (board[s1][s2] == 'N') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'a' && board[s1 - 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'a' && board[s1 - 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'a' && board[s1 - 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'a' && board[s1 - 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'a' && board[s1 + 2][s2 - 1] <= 'z')) {
			if (s2 - 1 >= 0)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'a' && board[s1 + 1][s2 - 2] <= 'z')) {
			if (s2 - 2 >= 0)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'a' && board[s1 + 2][s2 + 1] <= 'z')) {
			if (s2 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'a' && board[s1 + 1][s2 + 2] <= 'z')) {
			if (s2 + 2 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//black knight p moves
	else if (board[s1][s2] == 'n') {

		if (board[s1 - 2][s2 + 1] == ' ' || (board[s1 - 2][s2 + 1] >= 'A' && board[s1 - 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8 && s1 - 2 >= 0)
				pm[s1 - 2][s2 + 1] = 1;
		}
		if (board[s1 - 1][s2 + 2] == ' ' || (board[s1 - 1][s2 + 2] >= 'A' && board[s1 - 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 - 1][s2 + 2] = 1;
		}
		if (board[s1 - 2][s2 - 1] == ' ' || (board[s1 - 2][s2 - 1] >= 'A' && board[s1 - 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 - 2][s2 - 1] = 1;
		}
		if (board[s1 - 1][s2 - 2] == ' ' || (board[s1 - 1][s2 - 2] >= 'A' && board[s1 - 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 - 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 - 1] == ' ' || (board[s1 + 2][s2 - 1] >= 'A' && board[s1 + 2][s2 - 1] <= 'Z')) {
			if (s2 - 1 >= 0)
				pm[s1 + 2][s2 - 1] = 1;
		}
		if (board[s1 + 1][s2 - 2] == ' ' || (board[s1 + 1][s2 - 2] >= 'A' && board[s1 + 1][s2 - 2] <= 'Z')) {
			if (s2 - 2 >= 0)
				pm[s1 + 1][s2 - 2] = 1;
		}
		if (board[s1 + 2][s2 + 1] == ' ' || (board[s1 + 2][s2 + 1] >= 'A' && board[s1 + 2][s2 + 1] <= 'Z')) {
			if (s2 + 1 < 8)
				pm[s1 + 2][s2 + 1] = 1;
		}
		if (board[s1 + 1][s2 + 2] == ' ' || (board[s1 + 1][s2 + 2] >= 'A' && board[s1 + 1][s2 + 2] <= 'Z')) {
			if (s2 + 2 < 8)
				pm[s1 + 1][s2 + 2] = 1;
		}


	}

	//storing destinations in an array
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1) {
				count++;
			}
		}
	}

	if (count > 0) {

		int * moveX = new int[count];
		int * moveY = new int[count];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < count; i++) {
			if (knightpathdet(board, s1, s2, moveX[i], moveY[i]) == false) {
				retval++;
			}
			else {
				return true;
			}

		}

		if (retval == count) {
			return false;
		}
	}
	else {
		return false;
	}

}

bool bishopmate(char board[][8], int s1, int s2)
{


	int pm[8][8] = { 0 };


	//black bishop's moves


	if (board[s1][s2] == 'b') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//WHITE BISHOP'S MOVES

	else if (board[s1][s2] == 'B') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}


	//storing destinations in an array
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1) {
				count++;
			}
		}
	}

	if (count > 0) {
		int * moveX = new int[count];
		int * moveY = new int[count];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < count; i++) {
			if (bishoppathdet(board, s1, s2, moveX[i], moveY[i]) == false) {
				retval++;
			}
			else {
				return true;
			}

		}
		if (retval == count) {
			return false;
		}

	}
	else {
		return false;
	}



}

bool rookmate(char board[][8], int s1, int s2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//black piece possible positions
	if (board[s1][s2] == 'r') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}

	//white piece possible positions
	else if (board[s1][s2] == 'R') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

	}


	//storing destinations in an array
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1) {
				count++;
			}
		}
	}

	if (counter > 0) {
		int * moveX = new int[counter];
		int * moveY = new int[counter];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < counter; i++) {
			if (rookpathdet(board, s1, s2, moveX[i], moveY[i], count, rookcount) == false) {
				retval++;
			}
			else {

				return true;
			}

		}

		if (retval == counter) {
			return false;
		}
	}
	else {
		return false;
	}




}

bool queenmate(char board[][8], int s1, int s2)
{

	int pm[8][8] = { 0 };


	//white piece possible positions
	if (board[s1][s2] == 'Q') {
		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i--) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'a' && board[i][s2] <= 'z')); i++) {

			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}

		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i++) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'a' && board[s1][i] <= 'z')); i--) {

			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}

		}

		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'a' && board[i][j] <= 'z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

	}

	//BLACK QUEEN'S POSSIBLE MOVES


	else if (board[s1][s2] == 'q') {
		//diag up right
		for (int i = s1 - 1, j = s2 + 1; (i >= 0, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j++) {
			if (s1 - 1 >= 0 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}// if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z'))
		}

		//diag up left
		for (int i = s1 - 1, j = s2 - 1; (i >= 0, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i--, j--) {
			if (s1 - 1 >= 0 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down right
		for (int i = s1 + 1, j = s2 + 1; (i < 8, j < 8) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j++) {
			if (s1 + 1 < 8 && s2 + 1 < 8) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//diag down left
		for (int i = s1 + 1, j = s2 - 1; (i < 8, j >= 0) && (board[i][j] == ' ' || (board[i][j] >= 'A' && board[i][j] <= 'Z')); i++, j--) {
			if (s1 + 1 < 8 && s2 - 1 >= 0) {
				pm[i][j] = 1;
				if ((board[i][j] >= 'A' && board[i][j] <= 'Z') || (board[i][j] >= 'a' && board[i][j] <= 'z')) {
					break;
				}
			}
		}

		//vertUp
		for (int i = s1 - 1; i >= 0 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i--) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//vertDown
		for (int i = s1 + 1; i < 8 && (board[i][s2] == ' ' || (board[i][s2] >= 'A' && board[i][s2] <= 'Z')); i++) {
			pm[i][s2] = 1;
			if ((board[i][s2] >= 'A' && board[i][s2] <= 'Z') || (board[i][s2] >= 'a' && board[i][s2] <= 'z')) {
				break;
			}
		}
		//horRight
		for (int i = s2 + 1; i < 8 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i++) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}
		//horLeft
		for (int i = s2 - 1; i >= 0 && (board[s1][i] == ' ' || (board[s1][i] >= 'A' && board[s1][i] <= 'Z')); i--) {
			pm[s1][i] = 1;
			if ((board[s1][i] >= 'A' && board[s1][i] <= 'Z') || (board[s1][i] >= 'a' && board[s1][i] <= 'z')) {
				break;
			}
		}

	}


	//storing destinations in an array
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1) {
				count++;
			}
		}
	}
	if (count > 0) {
		int * moveX = new int[count];
		int * moveY = new int[count];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < count; i++) {
			if (queenpathdet(board, s1, s2, moveX[i], moveY[i]) == false) {
				retval++;
			}
			else {
				return true;
			}

		}
		if (retval == count) {
			return false;
		}
	}
	else {
		return false;
	}



}

bool kingmate(char board[][8], int s1, int s2, int &count, int &rookcount)
{

	int pm[8][8] = { 0 };

	//BLACK piece possible positions
	if (board[s1][s2] == 'k') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'A' && board[s1 - 1][s2] <= 'Z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'A' && board[s1 + 1][s2] <= 'Z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'A' && board[s1][s2 + 1] <= 'Z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'A' && board[s1][s2 - 1] <= 'Z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'A' && board[s1 - 1][s2 + 1] <= 'Z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'A' && board[s1 - 1][s2 - 1] <= 'Z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'A' && board[s1 + 1][s2 + 1] <= 'Z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'A' && board[s1 + 1][s2 - 1] <= 'Z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}


	//WHITE piece possible moves
	if (board[s1][s2] == 'K') {
		//vertUp
		if (s1 - 1 >= 0 && (board[s1 - 1][s2] == ' ' || (board[s1 - 1][s2] >= 'a' && board[s1 - 1][s2] <= 'z'))) {
			pm[s1 - 1][s2] = 1;
		}
		//vertdown
		if (s1 + 1 < 8 && (board[s1 + 1][s2] == ' ' || (board[s1 + 1][s2] >= 'a' && board[s1 + 1][s2] <= 'z'))) {
			pm[s1 + 1][s2] = 1;
		}
		//horRight
		if (s2 + 1 < 8 && (board[s1][s2 + 1] == ' ' || (board[s1][s2 + 1] >= 'a' && board[s1][s2 + 1] <= 'z'))) {
			pm[s1][s2 + 1] = 1;
		}
		//horLeft
		if (s2 - 1 >= 0 && (board[s1][s2 - 1] == ' ' || (board[s1][s2 - 1] >= 'a' && board[s1][s2 - 1] <= 'z'))) {
			pm[s1][s2 - 1] = 1;
		}
		//diagupright
		if ((s1 - 1 >= 0 && s2 + 1 < 8) && (board[s1 - 1][s2 + 1] == ' ' || (board[s1 - 1][s2 + 1] >= 'a' && board[s1 - 1][s2 + 1] <= 'z'))) {
			pm[s1 - 1][s2 + 1] = 1;
		}
		//diagupleft
		if ((s1 - 1 >= 0 && s2 - 1 >= 0) && (board[s1 - 1][s2 - 1] == ' ' || (board[s1 - 1][s2 - 1] >= 'a' && board[s1 - 1][s2 - 1] <= 'z'))) {
			pm[s1 - 1][s2 - 1] = 1;
		}
		//diagdownright
		if ((s1 + 1 < 8 && s2 + 1 < 8) && (board[s1 + 1][s2 + 1] == ' ' || (board[s1 + 1][s2 + 1] >= 'a' && board[s1 + 1][s2 + 1] <= 'z'))) {
			pm[s1 + 1][s2 + 1] = 1;
		}
		//diagdownleft
		if ((s1 + 1 < 8 && s2 - 1 >= 0) && (board[s1 + 1][s2 - 1] == ' ' || (board[s1 + 1][s2 - 1] >= 'a' && board[s1 + 1][s2 - 1] <= 'z'))) {
			pm[s1 + 1][s2 - 1] = 1;
		}

	}

	//storing destinations in an array
	int counter = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pm[i][j] == 1) {
				counter++;
			}
		}
	}
	if (counter > 0) {
		int * moveX = new int[counter];
		int * moveY = new int[counter];

		int m = 0, n = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((pm[i][j] == 1 || pm[i][j] == 2)) {
					moveX[m++] = i;//storing x coordinates of possible positions
					moveY[n++] = j;//storing y coordinates of possible positions
				}
			}
		}
		int retval = 0;
		for (int i = 0; i < counter; i++) {
			if (kingpathdet(board, s1, s2, moveX[i], moveY[i], count, rookcount) == false) {
				retval++;
			}
			else {

				return true;
			}

		}
		if (retval == counter) {
			return false;
		}

	}
	else {
		return false;
	}

}

//a false return from any of these functions means that NO LEGAL MOVE FOR ALL OF THE REsPECTIVE PIECES IS POSSIBLE
//// we use retcnt as a counter of the return values. if retcnt is equal to the number of pieces on board, then this means that all paths returned false and no
		//possible move for any piece
//numofpawns is a variable that calculates the number of pieces of a specific type on board

bool pawnforstale(char board[][8], int turn, int source1[], int source2[], int dest1[], int dest2[], int numofmoves)
{

	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's pawns here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'P') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'P') {
					n++;
					if (pawnmate(board, i, j, source1, source2, dest1, dest2, numofmoves) == false) {// this checks if the pawn at current location
						retcnt++;																//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}
					else {
						return true;
					}

				}
			}
		}

		if (retcnt == numofpawns) {
			return false;
		}



	}

	else if (turn == 2) {//black's turn. so you scan for black's pawns here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'p') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'p') {
					n++;
					if (pawnmate(board, i, j, source1, source2, dest1, dest2, numofmoves) == false) {// this checks if the pawn at current location
						retcnt++;																//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this pawn.

					else {
						return true;
					}
				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}


	return true;

	//a false return from this function means that NO LEGAL MOVE FOR ANY PAWN IS POSSIBLE
}

bool knightforstale(char board[][8], int turn)
{
	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's knights here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'N') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of kngihts
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'N') {
					n++;
					if (knightmate(board, i, j) == false) {// this checks if the knight at current location
						retcnt++;	//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight.

					else {
						return true;
					}
				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}

	else if (turn == 2) {//black's turn. so you scan for black's knights here

		int numofpawns = 0;//stores the number of knights on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'n') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'n') {
					n++;
					if (knightmate(board, i, j) == false) {// this checks if the knihgt at current location
						retcnt++;			//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight
					else {
						return true;
					}

				}
			}
		}

		if (retcnt == numofpawns) {
			return false;
		}


	}


	return true;
}

bool bishopforstale(char board[][8], int turn)
{
	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's knights here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'B') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of kngihts
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'B') {
					n++;
					if (bishopmate(board, i, j) == false) {// this checks if the knight at current location
						retcnt++;					//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight.
					else {
						return true;
					}
				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}

	else if (turn == 2) {//black's turn. so you scan for black's knights here

		int numofpawns = 0;//stores the number of knights on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'b') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'b') {
					n++;
					if (bishopmate(board, i, j) == false) {// this checks if the knihgt at current location
						retcnt++;				//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight
					else {
						return true;
					}

				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}


	return true;
}

bool rookforstale(char board[][8], int turn, int count, int rookcount)
{
	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's knights here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of kngihts
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					n++;
					if (rookmate(board, i, j, count, rookcount) == false) {// this checks if the knight at current location
						retcnt++;				//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight.
					else {
						return true;
					}
				}
			}
		}

		if (retcnt == numofpawns) {
			return false;
		}


	}

	else if (turn == 2) {//black's turn. so you scan for black's knights here

		int numofpawns = 0;//stores the number of knights on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'r') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'r') {
					n++;
					if (rookmate(board, i, j, count, rookcount) == false) {// this checks if the knihgt at current location
						retcnt++;			//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight
					else {
						return true;
					}

				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}


	return true;
}

bool queenforstale(char board[][8], int turn)
{
	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's knights here

		int numofpawns = 0;//stores the number of pawns on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'Q') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of kngihts
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'Q') {
					n++;
					if (queenmate(board, i, j) == false) {// this checks if the knight at current location
						retcnt++;					//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight.
					else {
						return true;
					}

				}
			}
		}

		if (retcnt == numofpawns) {
			return false;
		}


	}

	else if (turn == 2) {//black's turn. so you scan for black's knights here

		int numofpawns = 0;//stores the number of knights on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'q') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'q') {
					n++;
					if (queenmate(board, i, j) == false) {// this checks if the knihgt at current location
						retcnt++;				//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight
					else {
						return true;
					}

				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}


	return true;
}

bool kingforstale(char board[][8], int turn, int count, int rookcount)
{
	int retcnt = 0;
	if (turn == 1) {//white's turn. so you scan for white's kings here

		int numofpawns = 0;//stores the number of kings on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'K') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of kings
		int n = 0;// n is a counter
		// we use retcnt as a counter of the return values. if retcnt is equal to the number of pieces on board, then this means that all paths returned false and no
		//possible move for any piece
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'K') {
					n++;
					if (kingmate(board, i, j, count, rookcount) == false) {// this checks if the king at current location>>
						retcnt++;											//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight.
					else {
						return true;
					}

				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}

	else if (turn == 2) {//black's turn. so you scan for black's knights here

		int numofpawns = 0;//stores the number of knights on board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'k') {
					numofpawns++;
				}
			}
		}
		//now we have found the num of pawns
		int n = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'k') {
					n++;
					if (kingmate(board, i, j, count, rookcount) == false) {// this checks if the knihgt at current location
						retcnt++;					//has any legal moves or not. if legal present, then return true
						if (n == numofpawns) {
							break;
						}
					}//if this returns false, this means that there is no legal move for this knight
					else {
						return true;
					}

				}
			}
		}


		if (retcnt == numofpawns) {
			return false;
		}

	}


	return true;
}

//checks for both mates. If the mate is returned true while in check, it is a checkmate. else it is a stalemate....
bool mate(char board[][8], int turn, int source1[], int source2[], int dest1[], int dest2[], int numofmoves, int count, int rookcount)
{
	if (turn == 1) {//white's turn so we test for white's legal moves
		//if ALL paths return false, then this means no possible moves for any piece. so it is either in checkmate or stalemate condition
		if (pawnforstale(board, turn, source1, source2, dest1, dest2, numofmoves) == false && knightforstale(board, turn) == false && bishopforstale(board, turn) == false &&
			rookforstale(board, turn, count, rookcount) == false && queenforstale(board, turn) == false && kingforstale(board, turn, count, rookcount) == false) {
			return true;


		}
	}
	else if (turn == 2) {//black's turn so we test for black's legal moves
		//if ALL paths return false, then this means no possible moves for any piece. so it is either in checkmate or stalemate condition
		if (pawnforstale(board, turn, source1, source2, dest1, dest2, numofmoves) == false && knightforstale(board, turn) == false && bishopforstale(board, turn) == false &&
			rookforstale(board, turn, count, rookcount) == false && queenforstale(board, turn) == false && kingforstale(board, turn, count, rookcount) == false) {
			return true;
		}
	}

	return false;
}

int main()
{
	char board[8][8], input[4]; int inpt[4];
	//initBoard(board, turn);
	int source1[2000] = { 0 };
	int source2[2000] = { 0 };
	int dest1[2000] = { 0 };
	int dest2[2000] = { 0 };
	int replaymoves = 0;

	char option;

	bool checkmove = true;
	int numofmoves = 0;


	fstream fout("C:\\Users\\Acer\\Desktop\\chessave1.txt");


	int turn; bool majwhile = true;
	int wcount = 0, bcount = 0;//will keep count of both kings' moves
	int rookw = 0, rookb = 0;
	bool LOOP = true;


	int s1, s2, d1, d2;
	initBoard(board, turn, majwhile, checkmove, LOOP);
	if (turn == 1) {
		//This is where moves are executed
		while (majwhile == true) {//will work until one of the players doesnt enter esc or quit etc
			checkmove = true;

			if (turn == 1) {//for white
				if (whiteCHECK(board) == true) {
					cout << "White's King is Under check!\r" << endl;
					if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, wcount, rookw) == true) {
						cout << "CHECKMATE! Black wins 0 - 1" << endl;

						return 0;
						break;
					}
				}
				else {
					if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, wcount, rookw) == true) {
						cout << "STALEMATE! Both players get half a point  1/2 - 1/2" << endl;
						majwhile = false;
						checkmove = false;
						turn = 7;
						return 0;
						break;
					}
				}

				while (checkmove == true) {//checks if a valid move is being input. if yes, then move executed and loop
					cout << "White player, make your move!" << endl;
					inputMove(board, input, turn);

					inputarr(input, inpt);
					s1 = inpt[0]; s2 = inpt[1]; d1 = inpt[2]; d2 = inpt[3];
					source1[numofmoves] = s1; source2[numofmoves] = s2; dest1[numofmoves] = d1; dest2[numofmoves] = d2;
					if (board[inpt[0]][inpt[1]] >= 'A' && board[inpt[0]][inpt[1]] <= 'Z') {
						if (pawn(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
							if (pawnArr(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
								numofmoves++;
								checkmove = false;
							}
						}
						else if (knight(board, s1, s2, d1, d2) == true) {
							if (knightArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (bishop(board, s1, s2, d1, d2) == true) {
							if (bishopArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (rook(board, s1, s2, d1, d2, wcount, rookw) == true) {
							if (rookArr(board, s1, s2, d1, d2, wcount, rookw) == true) {
								numofmoves++;
								replaymoves++;
								rookw++;
								checkmove = false;
							}
						}
						else if (queen(board, s1, s2, d1, d2) == true) {
							if (queenArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (king(board, s1, s2, d1, d2, wcount, rookw) == true) {
							if (kingArr(board, s1, s2, d1, d2, wcount, rookw) == true) {
								numofmoves++;
								replaymoves++;
								wcount++;
								checkmove = false;
							}
						}
						else {
							cout << "Enter a valid move for white piece" << endl;
							checkmove = true;
						}
						turn = 2;

						for (int i = 0; i < 8; i++) {
							for (int j = 0; j < 8; j++) {
								fout << board[i][j];
							}

						}
						fout << endl;



					}
					else {
						cout << "You can only move a white player's piece" << endl;
						checkmove = true;
					}


				}

				checkmove = true;

				cout << "Press any key to continue to next move and ESC to save and exit!" << endl;
				_getch();
				option = _getch();


				if (option == 27) {
					majwhile = false;
					checkmove = false;
					turn = 7;
					return 0;
				}

			}

			if (turn == 2) {//for black
				if (blackCHECK(board) == true) {
					cout << "Black's King is Under check!" << endl;
					if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, bcount, rookb) == true) {//MATE(board, turn, bcount, rookb, source1, source2, dest1, dest2, numofmoves) == true) {
						cout << "CHECKMATE! White wins 1 - 0" << endl;

						return 0;
						break;
					}
				}
				else {
					if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, bcount, rookb) == true) {
						cout << "STALEMATE! Both players get half a point 1/2 - 1/2" << endl;

						return 0;
						break;
					}
				}
				while (checkmove == true) {//checks if a valid move is being inout. if yes, then move executed and loop
					cout << "Black player, make your move!" << endl;
					inputMove(board, input, turn);
					inputarr(input, inpt);
					s1 = inpt[0]; s2 = inpt[1]; d1 = inpt[2]; d2 = inpt[3];
					source1[numofmoves] = s1; source2[numofmoves] = s2; dest1[numofmoves] = d1; dest2[numofmoves] = d2;
					if (board[inpt[0]][inpt[1]] >= 'a' && board[inpt[0]][inpt[1]] <= 'z') {
						if (pawn(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
							if (pawnArr(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (knight(board, s1, s2, d1, d2) == true) {
							if (knightArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (bishop(board, s1, s2, d1, d2) == true) {
							if (bishopArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (rook(board, s1, s2, d1, d2, bcount, rookb) == true) {
							if (rookArr(board, s1, s2, d1, d2, bcount, rookb) == true) {
								numofmoves++;
								rookb++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (queen(board, s1, s2, d1, d2) == true) {
							if (queenArr(board, s1, s2, d1, d2) == true) {
								numofmoves++;
								replaymoves++;
								checkmove = false;
							}
						}
						else if (king(board, s1, s2, d1, d2, bcount, rookb) == true) {
							if (kingArr(board, s1, s2, d1, d2, bcount, rookb) == true) {
								numofmoves++;
								bcount++;
								replaymoves++;
								checkmove = false;
							}
						}
						else {
							cout << "Enter a valid move for black piece" << endl;
							checkmove = true;
						}
						turn = 1;

						for (int i = 0; i < 8; i++) {
							for (int j = 0; j < 8; j++) {
								fout << board[i][j];
							}

						}
						fout << endl;


					}
					else {
						cout << "You can only move a black player's piece" << endl;
						checkmove = true;
					}


				}

				cout << "Press any key to continue to next move and ESC to save and exit!" << endl;
				_getch();
				option = _getch();

				if (option == 27) {
					majwhile = false;
					checkmove = false;

					turn = 7;
					return 0;

				}




			}



		}
	}

	/*
	//int count = 0;
	//int movescounted = 0;
	//char buff[65];
	//bool nextmove = false;
	////TO LOAD A SAVED GAME FILE
	//if (turn == 4) {
	//	fstream fin("C:\\Users\\Acer\\Desktop\\chessave1.txt");

	//	if (fin.peek() == std::ifstream::traits_type::eof()) {
	//		cout << "NO previous saves" << endl;
	//		return 0;
	//	}

	//	while (!fin.eof()) {
	//		fin.getline(buff, 65);
	//		if (buff[0] == '\0') {
	//			nextmove = true;
	//			break;
	//		}
	//		int k = 0;

	//		for (int i = 0; i < 8; i++) {
	//			for (int j = 0; j < 8; j++) {
	//				board[i][j] = buff[k++];
	//			}
	//		}
	//		printBoard(board);
	//		count++;
	//		if (board[0][4] != 'k') {
	//			bcount = 1;
	//		}
	//		if (board[7][4] != 'K') {
	//			wcount = 1;
	//		}
	//		movescounted++;
	//		cout << endl << "Press any key to see the next move!" << endl;
	//		_getch();
	//		char next;
	//		next = _getch();
	//		nextmove = true;

	//	}


	//}

	//if (nextmove == true) {

	//	cout << "Now you may enter your next move. Press any key to continue..." << endl;
	//	_getch();

	//	system("cls");
	//	printBoard(board);
	//	if (movescounted % 2 == 0) {
	//		turn = 2; majwhile = true; checkmove = true;
	//	}
	//	else {
	//		turn = 1; majwhile = true; checkmove = true;
	//	}

	//	while (majwhile == true) {//will work until one of the players doesnt enter esc or quit etc
	//		checkmove = true;

	//		if (turn == 1) {//for white

	//			if (whiteCHECK(board) == true) {
	//				cout << "White's King is Under check!\r" << endl;
	//				if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, wcount, rookw) == true) {

	//					cout << "CHECKMATE! Black wins 0 - 1" << endl;
	//					majwhile = false;

	//					return 0;
	//				}
	//			}
	//			else {
	//				if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, wcount, rookw) == true) {
	//					cout << "STALEMATE! Both players get half a point  1/2 - 1/2" << endl;
	//					return 0;
	//				}
	//			}

	//			while (checkmove == true) {//checks if a valid move is being input. if yes, then move executed and loop
	//				cout << "White player, make your move!" << endl;
	//				inputMove(board, input, turn);
	//				inputarr(input, inpt);
	//				s1 = inpt[0]; s2 = inpt[1]; d1 = inpt[2]; d2 = inpt[3];
	//				source1[numofmoves] = s1; source2[numofmoves] = s2; dest1[numofmoves] = d1; dest2[numofmoves] = d2;
	//				if (board[inpt[0]][inpt[1]] >= 'A' && board[inpt[0]][inpt[1]] <= 'Z') {
	//					if (pawn(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
	//						if (pawnArr(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (knight(board, s1, s2, d1, d2) == true) {
	//						if (knightArr(board, s1, s2, d1, d2) == true) {
	//							count++;
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (bishop(board, s1, s2, d1, d2) == true) {
	//						if (bishopArr(board, s1, s2, d1, d2) == true) {
	//							count++;
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (rook(board, s1, s2, d1, d2, wcount, rookw) == true) {
	//						if (rookArr(board, s1, s2, d1, d2, wcount, rookw) == true) {
	//							count++;
	//							rookw++;
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (queen(board, s1, s2, d1, d2) == true) {
	//						if (queenArr(board, s1, s2, d1, d2) == true) {
	//							count++;
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (king(board, s1, s2, d1, d2, wcount, rookw) == true) {
	//						if (kingArr(board, s1, s2, d1, d2, wcount, rookw) == true) {
	//							count++;
	//							wcount++;
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else {
	//						cout << "Enter a valid move for white piece" << endl;
	//						checkmove = true;
	//					}
	//					turn = 2;


	//					for (int i = 0; i < 8; i++) {
	//						for (int j = 0; j < 8; j++) {
	//							fout << board[i][j];
	//						}

	//					}
	//					fout << endl;

	//				}
	//				else {
	//					cout << "You can only move a white player's piece" << endl;
	//					checkmove = true;
	//				}


	//			}

	//			checkmove = true;

	//			cout << "Press any key to continue to next move and ESC to save and exit!" << endl;
	//			_getch();
	//			option = _getch();


	//			if (option == 27) {

	//				cout << "Exiting the game!" << endl;
	//				return 0;
	//			}
	//		}

	//		if (turn == 2) {//for black

	//			if (blackCHECK(board) == true) {
	//				cout << "Black's King is Under check!" << endl;
	//				if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, bcount, rookb) == true) {//MATE(board, turn, bcount, rookb, source1, source2, dest1, dest2, numofmoves) == true) {
	//					cout << "CHECKMATE! White wins 1 - 0" << endl;
	//					majwhile = false;
	//					return 0;
	//				}
	//			}
	//			else {
	//				if (mate(board, turn, source1, source2, dest1, dest2, numofmoves, bcount, rookb) == true) {
	//					cout << "STALEMATE! Both players get half a point 1/2 - 1/2" << endl;
	//					return 0;
	//				}
	//			}
	//			while (checkmove == true) {//checks if a valid move is being inout. if yes, then move executed and loop
	//				cout << "Black player, make your move!" << endl;
	//				inputMove(board, input, turn);
	//				inputarr(input, inpt);
	//				s1 = inpt[0]; s2 = inpt[1]; d1 = inpt[2]; d2 = inpt[3];
	//				source1[numofmoves] = s1; source2[numofmoves] = s2; dest1[numofmoves] = d1; dest2[numofmoves] = d2;
	//				if (board[inpt[0]][inpt[1]] >= 'a' && board[inpt[0]][inpt[1]] <= 'z') {
	//					if (pawn(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
	//						if (pawnArr(board, s1, s2, d1, d2, source1, source2, dest1, dest2, numofmoves) == true) {
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (knight(board, s1, s2, d1, d2) == true) {
	//						if (knightArr(board, s1, s2, d1, d2) == true) {
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (bishop(board, s1, s2, d1, d2) == true) {
	//						if (bishopArr(board, s1, s2, d1, d2) == true) {
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (rook(board, s1, s2, d1, d2, bcount, rookb) == true) {
	//						if (rookArr(board, s1, s2, d1, d2, bcount, rookb) == true) {
	//							numofmoves++;
	//							rookb++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (queen(board, s1, s2, d1, d2) == true) {
	//						if (queenArr(board, s1, s2, d1, d2) == true) {
	//							numofmoves++;
	//							checkmove = false;
	//						}
	//					}
	//					else if (king(board, s1, s2, d1, d2, bcount, rookb) == true) {
	//						if (kingArr(board, s1, s2, d1, d2, bcount, rookb) == true) {
	//							numofmoves++;
	//							bcount++;
	//							checkmove = false;
	//						}
	//					}
	//					else {
	//						cout << "Enter a valid move for black piece" << endl;
	//						checkmove = true;
	//					}
	//					turn = 1;

	//					for (int i = 0; i < 8; i++) {
	//						for (int j = 0; j < 8; j++) {
	//							fout << board[i][j];
	//						}

	//					}
	//					fout << endl;
	//				}
	//				else {
	//					cout << "You can only move a black player's piece" << endl;
	//					checkmove = true;
	//				}


	//			}

	//			cout << "Press any key to continue to next move and ESC to save and exit!" << endl;
	//			_getch();
	//			option = _getch();

	//			if (option == 27) {

	//				cout << "Exiting the game!" << endl;
	//				return 0;
	//			}




	//		}



	//	}
	//}
	*/

	if (turn == 7) {
		cout << "Exiting now" << endl;
		return 0;
	}

	return 0;
}


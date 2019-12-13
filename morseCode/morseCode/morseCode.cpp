// morseCoder.cpp : Main Application that calls function from morseTree to allow for decoing and encoding of letters and morse code3
//
#include "stdafx.h"
#include "morseTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream istream; //initialization of text file
	istream.open("morse.txt"); //open the morse code text file
	if (!istream) { //throw error if there is no text file found
		throw std::exception("Text File not Found");
		return 0;
	}

	morseTree theTree; //initiallize the tree
	theTree.buildTree(istream); //build the tree
	theTree.encode("algorithms"); //convert letters to morse code
	theTree.decode(".... .._ ._ _..."); //convert morse code to letters
	system("pause"); //end the program
	return 0;
}

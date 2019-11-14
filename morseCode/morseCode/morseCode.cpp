// morseCoder.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "morseTree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream istream;
	istream.open("morse.txt");
	if (!istream) {
		throw std::exception("Book not found");
		return 0;
	}

	morseTree theTree;
	theTree.buildTree(istream);
	theTree.encode("algorithms");
	theTree.decode(".... ._._  .__. -.-.");
	system("pause");
	return 0;
}


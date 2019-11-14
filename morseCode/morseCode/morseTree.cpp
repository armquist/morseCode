#include "stdafx.h"
#include "morseTree.h"

using namespace std;

morseTree::morseTree() {
	root = new node();
}

morseTree::~morseTree() {

}

void morseTree::encode(string word) {

}

void morseTree::decode(string code) {

}

void morseTree::buildTree(ifstream& istream) {
	for (int i = 0; i < 26; i++) {
		string currentLine;
		node* curentNode = root;
		char letter;
		getline(istream, currentLine);
		letter = currentLine[0];
		for (int j = 1; j < currentLine.length(); j++) {
			if (currentLine[j] == '_') {
				if (curentNode->right == NULL) {
					curentNode->right = new node();
				}
				curentNode = curentNode->right;
			}
			else if (currentLine[j] == '.')
			{
				if (curentNode->left == NULL) {
					curentNode->left = new node();
				}
				curentNode = curentNode->left;
			}
			else {
				throw std::exception("Invalid Input");
			}
		}
		curentNode->data = letter;
	}
}

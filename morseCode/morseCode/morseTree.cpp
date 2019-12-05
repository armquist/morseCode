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

void morseTree::buildTree(ifstream& istream) { //actually builds the Huffman Tree for use with the other funtions O(n)
	for (int i = 0; i < 26; i++) { //traverse through all 26 lines
		string currentLine; //current line taken from tect file
		string datastring; //used to collect morse codes to get put in node->code
		datastring.resize(4); //resize string to prevent crashes
		node* curentNode = root; //set to root to begin traversal
		char letter; //the letter to put in node->data
		getline(istream, currentLine); //get the current line from text file to create the node
		letter = currentLine[0]; //the letter is always the first char of the line
		for (int j = 1; j < currentLine.length(); j++) { //keep travering until the end of the text file line
			if (currentLine[j] == '_') {  //traverse right for every _
				datastring += "_"; //add _ so morse code is recorded for node
				if (curentNode->right == NULL) { //make the node if there isn't already a node there
					curentNode->right = new node(); //make the node
				}
				curentNode = curentNode->right; //traverse right
			}
			else if (currentLine[j] == '.') {  //traverse left for every .
				datastring += "."; //add . so morse code is recorded for node
				if (curentNode->left == NULL) { //make the node if there isn't already a node there
					curentNode->left = new node(); //make the node
				}
				curentNode = curentNode->left; //traverse left
			}
			else { //odd characters will goof things up
				throw std::exception("Invalid Input");
			}
		}
		curentNode->data = letter; //set letter of current node
		curentNode->code = datastring; //set corresponsing sorce code for second line, code;
		datastring = ""; //reset datastring for next letter.
		datastring.resize(4); //resize string to prevent crashes
	}
	cout << "Tree built" << endl; //some feedback to know if things went well
	

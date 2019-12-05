#pragma once
#ifndef MORSETREE_H
#define MORSETREE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct node { //the node structure for the tree
	char data; //letter for node
	string code; //morse code that represents letter
	node *left; //node to the left
	node *right; //node to the right

	node() { //some defaults to prevents messups
		data = '0';
		code = "0000";
		left = NULL;
		right = NULL;
	}
};

class morseTree {
public:
	morseTree(); //Constructor
	~morseTree(); //Destructor
	void decode(string code);  //decodes morse code into alphanumeric letters: O(n)
	void decodeLetter(string code);  //Traverse tree to reach letter decoded morse string: O(n)
	void encode(string word); //encode letters to morse code O(n)
	void buildTree(ifstream& istream); //actually builds the Huffman Tree for use with the other funtions O(n)
	void recieveCode(node* curentNode, char letter); //searches through tree to find letter O(1)

private:
	node* root; //initial NULL node at the root

};

#endif

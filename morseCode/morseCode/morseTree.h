#pragma once
#ifndef MORSETREE_H
#define MORSETREE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;

	node() {
		data = '0';
		left = NULL;
		right = NULL;
	}
};

class morseTree {
public:
	morseTree();
	~morseTree();
	void decode(string code);
	void encode(string word);
	void buildTree(ifstream& istream);

private:
	node* root;
};

#endif
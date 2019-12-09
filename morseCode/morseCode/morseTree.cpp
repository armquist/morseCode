#include "stdafx.h"
#include "morseTree.h"

using namespace std;

morseTree::morseTree() {
	root = new node();
}

morseTree::~morseTree() {

}

void morseTree::encode(string word) { // endcode letters to morse code O(n)
	
	cout << "Encoded String: " << endl; // better formatting
	
	for(int i = 0; i < word.length(); i++) // loop for the length of the string to be encoded
	{
		node* currentNode = root; // reset to root every time a new letter is selected
		
		char letter = word[i]; // get current letter to be encoded
		
		receiveCode(currentNode->left , letter); // search left side of tree for letter
		receiveCode(currentNode->right, letter); //search right side of tree for letter
	}
	cout << endl; //end of Function
}

void morseTree::receiveCode(node* currentNode, char letter) // searches through the tree to find the lette O(1)
{
	if(currentNode == NULL) // exit if letter is not found
	{
		return;
	}
	
	if(currentNode->data == letter) { // print morsecode if letter node is found
		cout << currentNode->code;	
	}
	
	else {
		
		receiveCode(currentNode->left, letter) // recursively search the left subtree
		receiveCode(currentNode->right, letter) // recursively search the right subtree
	}
	
	
} // end of the receiveCode function
	
	
void morseTree::decode(string code) { //decodes morse code into alphanumeric letters: O(n)
	cout << "Decoded String: " << endl; //clean formatting
	string tempCode; //temporary string to push to decodeLetter rfunction
	tempCode.resize(code.size()); //resize strings to be equal to prevent crashes
	int c = 0; //extra counter to copy user input morse code to tempCode
	for (int i = 0; i < code.length(); i++) {  //read till the end of the string
		tempCode[c] += code[i]; //take each char from input string and put it into tempcode
		if (tempCode[c] == ' ') { //push tempcode to decodeLetter and clear out tempcode once string is decoded
			decodeLetter(tempCode); //actually traverse tree to get letter
			c = 0; //reset counter for next slew of morsecode chars
			tempCode = ""; //clear temcode
			tempCode.resize(code.size()); //resize strings to be equal to prevent crashes
		}
		if (i == code.length() - 1) { //special case for very last character as not to force user to add space at the end of code input
			tempCode += " "; //add a space to make decodeLetter's job easier
			decodeLetter(tempCode); //actually traverse tree to get letter
			c = 0; //reset counter for next slew of morsecode chars
			tempCode = ""; //clear temcode
		}
		c++; //increase counter to keep copying from input string
	}
	cout << endl; //end line for cleanliness
}

void morseTree::decodeLetter(string code) { //Traverse tree to reach letter decoded morse string: O(n)
	node* curentNode = root; //set root every time to ensure traversal consistancy
	string decodedMessage = ""; //translated letter
	for (int i = 0; i < code.length(); i++) { //will keep traversing for the length of the current morse code bit
		if (code[i] == '_') { //traverse right for every _
			if (curentNode->right != NULL) { //prevent freak accidents 
				curentNode = curentNode->right; //traverse right
			}
		}
		else if (code[i] == '.') { //traverse left for every .
			if (curentNode->left != NULL) { //prevent freak accidents 
				curentNode = curentNode->left; //traverse left
			}
		}
		else if (code[i] == ' ') { //space means stop traversing
			decodedMessage += curentNode->data; //set decodedMessage to current node
		}
	}
	cout << decodedMessage; //print out our decoded letter
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
	

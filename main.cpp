# Data-Structure-Tries
#include<iostream>
using namespace std;
#pragma once
#include <list>
#include <string>
#include "Trie.h"
//Noga Oren 206970519
//Shira Orbach 315234484

int main()
{
	char ch;
	string wrd;
	Trie tr;
	bool flag;
	//menu:
	cout << "\nTRIE PROGRAM" << endl;
	cout << "\nChoose one of the following" << endl;
	cout << "1: add a new item" << endl;
	cout << "2: delete an item" << endl;
	cout << "3: check if an item exists " << endl;
	cout << "4: complete the possible item name " << endl;
	cout << "5: exit " << endl;
	do
	{
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "Enter a word to insert " << endl;
			cin >> wrd;
			tr.insertWord(wrd);
			break;
		case '2':
			cout << "Enter a word to del " << endl; //delete
			cin >> wrd;
			if (!tr.deleteWord(wrd)) cout << "ERROR\n";
			break;
		case '3':
			cout << "Enter a word to search " << endl;
			cin >> wrd;
			if (tr.searchWord(wrd))
				cout << "exists\n";
			else
				cout << "does not exist\n";
			break;

		case '4':
			cout << "Enter a prefix to complete " << endl;
			cin >> wrd;
			flag = tr.printAllWordsFromPrefix(tr.pForEndOfWrd(wrd),wrd); //wrd=>pointer to the end of the prefix

			if (!flag)
				cout << "No string exist with this prefix\n";
			break;
		case '5':cout << "bye " << endl; break;
		default: cout << "ERROR " << endl;  break;
		}//switch
	} while (ch != '5');
	return 0;

}

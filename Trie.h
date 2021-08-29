# Data-Structure-Tries
#pragma once
#include <iostream>
#include <string>
using namespace std;
const int ALPHABET = 26;
//int charToInt(char ab) { return (int)ab - (int)'a'; };
static char intToCh(int i) { return (char)((int)'a' + i); }
static int charToInt(char c) { return (int)c - (int)'a'; }
class Trie
{
protected:
	class TrieNode
	{
		
	public:
		TrieNode* children[ALPHABET] = { 0 };
		TrieNode* father;
		bool isEndWord = false;
		int countChildren = 0;
	
	public:
		TrieNode() {};
		~TrieNode() { if (children != NULL) delete[] children; }
	};
	
public:
	TrieNode* root = new TrieNode();
	Trie()  //ctor - initialize root to be "root"
	{
		root->father = NULL;
		root->isEndWord = true;
	}
	//all functions
	void insertWord(string str);
	bool deleteWord(string str);
	bool searchWord(string str);
	bool printAllWordsFromPrefix(TrieNode* trie,string str);
	void printSub(string str, TrieNode* trie); //helper
	TrieNode* pForEndOfWrd(string pre); //helper:return pointer to the end of the prefix


};

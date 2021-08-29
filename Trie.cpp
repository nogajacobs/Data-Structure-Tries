# Data-Structure-Tries
#include "Trie.h"
#pragma once
void Trie::insertWord(string str)
{
	
	TrieNode* p = root; //pointer
	if (searchWord(str)) //the word is already exist
		return;
	for (int i = 0; i < str.length(); i++) //for each letter in the word
	{
		if (p->children[charToInt(str[i])] != 0)
		{
			if (i == str.length() - 1) //if the rout exist
				p->isEndWord = true;
			p = p->children[charToInt(str[i])];
		}
		else
		{
				p->children[charToInt(str[i])] = new TrieNode(/*p,i==str.length()-1*/);
				p->children[charToInt(str[i])]->father = p;
				//p = p->children[charToInt(str[i])];
				if (i == str.length() - 1)
				{
					p->isEndWord = true;
				}
				if (true)
				{

				}
				p->countChildren++;
				p = p->children[charToInt(str[i])];
			
		}

	}
	//p->isEndWord = true;
}
bool Trie::deleteWord(string str)
{
	TrieNode* p = root; //pointer
	if (!searchWord(str)) //the word doesn't exist
		return false;
	for (int i = 0; i < str.length()/*-1*/; i++) //bringing p to the last letter of the word
		p = p->children[charToInt(str[i])];
	p->isEndWord = false; //cancel the word
	if (p->children != NULL)
		for (int i = str.length() - 1; i >= 0; i--) //for each letter in the word
		{
			if (p->countChildren == 0 && p->isEndWord == false) //a leaf & not end of another word
			{
				p = p->father;
				(p->children[charToInt(str[i])])->~TrieNode(); //delete
				p->countChildren--;
			}
			else
				return true; //reached to a leaf
		}
	return true; //deleted
}
bool Trie::searchWord(string str)
{
	TrieNode* p = root; //pointer
	for (int i = 0; i < str.length(); i++) //for each letter in the word
	{
		if (p->children[charToInt(str[i])] != 0)
		{
			if (i == str.length() - 1) //the rout exist, checking the isEndWord flag
				return p->isEndWord;
			p = p->children[charToInt(str[i])];
		}
		else
			return false; //missing letter
	}
	//return false; //the rout exist, the word doesn't
}
bool Trie::printAllWordsFromPrefix(TrieNode* trie,string str)
{
	TrieNode* tmp = root;
	bool flag = true;
	for (int i = 0; i < str.length(); i++)
	{
		int n = str[i] - 'a';
		if (!(tmp->children[n]))
		{
			return 0;
		}
		tmp = tmp->children[n];
	}	
	if (tmp->isEndWord)
	{
		cout << str << endl;
	}
	for (int i = 0; i < ALPHABET; i++)
		{
			char c = i + 'a';
			printSub(str + c, tmp->children[i]);
		}
	return 1;
}
void Trie::printSub( string str, TrieNode* trie) //print all words with the 'str' prefix
{
		if (trie)
	{
		if (trie->isEndWord||trie->countChildren==0)
		{
			cout << str << endl;
		}
		for (int i = 0; i < ALPHABET; i++)
		{
			if (trie->children[i])
			{
				char c = i + 'a';
				printSub(str + c, trie->children[i]);
			}
		}
	}
}
Trie::TrieNode* Trie::pForEndOfWrd(string pre) //return pointer to the end of the prefix
{
	bool b = false;
	TrieNode* p = root; //pointer
	for (int i = 0; i < pre.length(); i++) //for each letter in the word
	{
		if (p->children[charToInt(pre[i])] != 0)
		{
			if (i == pre.length() - 1) //the rout exist, checking the isEndWord flag
				b = true;
			p = p->children[charToInt(pre[i])];
		}
	}
	if (!b)
	{
		return NULL;
	}
	p = root; //pointer
	for (int i = 0; i < pre.length(); i++) //for each letter in the word
	{
		if (p->children[charToInt(pre[i])] != 0)
		{
			//if (i == pre.length()-1) //the end of the prefix
			//{
			//	for (int i = 0; i < ALPHABET; i++)
			//	{
			//		if (pre[pre.length()] == intToCh(i))
			//		{
			//			return p->children[i];
			//		}
			//	}
			//}
			p = p->children[charToInt(pre[i])];
		}
	}

	return root; //default p
}

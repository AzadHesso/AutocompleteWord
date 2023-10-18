﻿#pragma once
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26; //Константа, определяющая размер алфавита (английский)

// Структура узла дерева

struct TrieNode {
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode* getNewTrieNode();
void addWord(TrieNode* root, const std::string& key);
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words);
bool isTrieEmpty(TrieNode* root);
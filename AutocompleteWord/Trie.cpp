﻿#include "Trie.h"


// Функция создания нового узла Trie
TrieNode* getNewTrieNode()
{
    TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = nullptr;
    }

    return pNode;
}

// Функция добавления слова в Trie
void addWord(TrieNode* root, const std::string& key)
{
    TrieNode* node = root;

    for (const auto& c : key) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = getNewTrieNode();
        }
        node = node->children[index];
    }

    node->isEndOfWord = true;
}

// Функция получения всех слов в Trie
void getAllWords(TrieNode* node, std::string prefix, std::vector<std::string>& words)
{
    if (node == nullptr) {
        return;
    }

    if (node->isEndOfWord) {
        words.push_back(prefix);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        int index = c - 'a';
        getAllWords(node->children[index], prefix + c, words);
    }
}

// Функция проверки, пуст ли Trie
bool isTrieEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if(root->children[i])
        return false;
    }
    return true;
}




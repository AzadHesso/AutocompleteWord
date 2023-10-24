#include "Trie.h"
#include <iostream>

int main() {

	setlocale(LC_ALL, "");
	TrieNode* root = getNewTrieNode();

	addWord(root, "sky");
	addWord(root, "tree");
	addWord(root, "window");
	addWord(root, "sound");
	addWord(root, "mount");
	addWord(root, "flag");
	addWord(root, "install");
	addWord(root, "shutdown");
	addWord(root, "search");
	addWord(root, "find");
	addWord(root, "war");
	addWord(root, "drive");

	std::vector<std::string> words;
	std::cout << "Словарь Английских слов: \n";
	getAllWords(root, "", words);
	for (const auto& word : words) {
		std::cout << "\t" << word << " " << "\n";
	   }

}
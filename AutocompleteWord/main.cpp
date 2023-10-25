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

	std::string word;
	std::cout << "Введите слово для добавления в словарь\n (Введите пустую строку для завершения ввода):\n";
		do {
			getline(std::cin, word);
			if (word.size() > 0) {
				addWord(root, word);
			}
		} while (word.size() > 0);
     
    std::cout << "\nВведите слово для удаления из словаря\n (Введите пустую строку для завершения ввода):\n";
	do {
		getline(std::cin, word);
		if (word.size() > 0) {
			removeWord(root, word);
		}
	} while (word.size() > 0);

	std::cout << "\nНаличие слов в словаре: \n";

	std::cout << "Введите слово для поиска в словаре\n (Введите пустую строку для завершения ввода):\n";
	do {
		getline(std::cin, word);
		if (word.size() > 0) {
			std::cout << word << ": " << (search(root, word) ? "Такое слово есть" : "Такое слово нет") << "\n";
		}
	} while (word.size() > 0);
		 
	std::string prefix;
	while (prefix != "q") {
	      std::cout << "Введите префикс слова для автодопление  (или введите 'q' для выхода): \n";
		  std::cin >> prefix;

		  if (prefix != "q") {
			  std::vector<std::string> words = getAllWordsByPrefix(root, prefix);
			  for (const std::string& word : words) {
				  std::cout << word << " ";
			  }
			  std::cout << std::endl;
		  }
	}

	return 0;
}


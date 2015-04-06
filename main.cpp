#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

void printAllPossibleWordsOfLength(char firstChar, char lastChar, int length) {
	char *word = new char[length];
	memset(word, firstChar, length);
	char *lastWord = new char[length];
	memset(lastWord, lastChar, length);
	int count = 0;

	std::cout << word << " -> " << lastWord << std::endl;

	while(true) {
		std::cout << word << std::endl;
		count += 1;
		if(memcmp(word, lastWord, length) == 0) {
			break;
		}
		if(word[length - 1] != lastChar) {
			word[length - 1] += 1;
		} else {
			for(int i=1; i<length; i++) {
				int index = length - i - 1;
				if(word[index] != lastChar) {
					word[index] += 1;
					memset(word+index+1, firstChar, length - index - 1);
					break;
				}
			}
		}
	}

	std::cout << "count: " << count << std::endl;

	delete[] word;
	delete[] lastWord;
}

int main(int argc, char* argv[]) {
	int length;
	if(argc > 1) {
		length = std::atoi(argv[1]);
		if(length == 0) {
			std::cout << "Please enter a valid length (i.e., greater than zero)" << std::endl;
			return 1;
		}
	} else {
		std::cout << "Usage: go <length>" << std::endl;
		return 1;
	}
	clock_t t = clock();
	printAllPossibleWordsOfLength('A', 'Z', length);
	t = clock() - t;
  	std:: cout << "Duration: " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds)" << std::endl;
    return 0;
}
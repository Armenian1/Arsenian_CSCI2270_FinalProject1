#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

struct DictionaryWords
{
    std::string word;
    std::string definition;
    DictionaryWords *next;
    DictionaryWords *previous;

    DictionaryWords(){};
	DictionaryWords(std::string in_word,std::string in_definition)
	{
		word = in_word;
		definition = in_definition;
		next = NULL;
		previous = NULL;
	}
};

class Dictionary
{
    public:
        Dictionary();
        ~Dictionary();
        void insertWord(std::string word);
        void defineWord(std::string word, std::string definition);
        void deleteWord(std::string word);
        void findDefinition(std::string word);
        void printAllWords();
        void insertSeveralWords(std::string sentence);
        void totalWordCount();
        void totalWordCountLetter(std::string letter);
        void dictionaryReset();
        void allWordDeleteLetter(std::string letter);
        void alphabetize();
    protected:
    private:
        DictionaryWords* findLetter(std::string letter);
        DictionaryWords* findWord(std::string letter);
        std::string seperateWords(std::string &sentence);
        int tableSize = 26;
		DictionaryWords* WordTable[26];
		std::string Letters[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
};
#endif // DICTIONARY_H


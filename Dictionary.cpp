#include "Dictionary.h"
#include <iostream>

using namespace std;

Dictionary::Dictionary()
{
    for (int x=0;x<tableSize;x++)
    {
        DictionaryWords *letter = new DictionaryWords(Letters[x],"");
        WordTable[x]=letter;
    }
}

Dictionary::~Dictionary()
{
    //dtor
}

void Dictionary::insertWord(std::string word)
{
    DictionaryWords *newWord = new DictionaryWords(word, "No definition inputted");
    DictionaryWords *tmp;
    DictionaryWords *ptr;

    ptr = findLetter(word);
    tmp = ptr;
    ptr = ptr->next;
    while (ptr!=NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    ptr = newWord;
    tmp->next = ptr;
    ptr->previous = tmp;
}

void Dictionary::defineWord(std::string word, std::string definition)
{
    DictionaryWords *tmp;
    tmp = findWord(word);
    if (tmp!=NULL)
        tmp->definition = definition;
    else
        cout<<"word not found"<<endl;

}

void Dictionary::deleteWord(std::string word)
{
    DictionaryWords *tmp;
    if (findWord(word)==NULL)
    {
        cout<<"word not found"<<endl;
        return;
    }
    tmp = findWord(word);
    if (tmp->next!=NULL)
    {
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        tmp->next = NULL;
    }
    else
        tmp->previous->next = NULL;
    tmp->previous = NULL;
}

void Dictionary::findDefinition(std::string word)
{
    DictionaryWords *tmp;
    tmp = findWord(word);
    if (tmp!=NULL)
        cout<<word<<" - "<<tmp->definition<<endl;
    else
        cout<<"word not found"<<endl;
}


void Dictionary::printAllWords()
{
    DictionaryWords *tmp;
    for (int x=0; x<tableSize; x++)
    {
        if (WordTable[x]->next!=NULL)
        {
            cout<<WordTable[x]->word<<" => ";WordTable[x]->next->word;
            if (WordTable[x]->next->next!=NULL)
            {
                cout<<WordTable[x]->next->word;
                tmp = WordTable[x]->next->next;
            }
            else
            {
                cout<<WordTable[x]->next->word<<endl;
                continue;
            }
            while (tmp->next!=NULL)
            {
                cout<<", "<<tmp->word;
                tmp = tmp->next;
            }
            cout<<", "<<tmp->word<<endl;
        }
        else
            cout<<WordTable[x]->word<<endl;
    }
}
/*
void Dictionary::insertSeveralWords(std::string sentence)
{
    while (seperateWords(sentence)!="")
        insertWord(seperateWords(sentence));
}
*/
void Dictionary::totalWordCount()
{
    int numWords=0;
    DictionaryWords *tmp;
    for (int x=0;x<tableSize;x++)
    {
        if (WordTable[x]->next!=NULL)
        {
            tmp = WordTable[x];
            while (tmp->next!=NULL)
            {
                tmp = tmp->next;
                numWords++;
            }
        }
    }
    cout<<"The total number of words in the dictionary is: "<<numWords<<endl;
}

void Dictionary::totalWordCountLetter(std::string letter)
{
    int numWords = 0;
    DictionaryWords *tmp;
    tmp = findLetter(letter);
    if (tmp==NULL)
    {
        cout<<"word not found"<<endl;
        return;
    }
    while (tmp->next!=NULL)
    {
        tmp = tmp->next;
        numWords++;
    }
    cout<<"The total number of words for the letter "<<letter<<" in the dictionary is: "<<numWords<<endl;
}

void Dictionary::dictionaryReset()
{
    for (int x=0; x<tableSize; x++)
        WordTable[x]->next = NULL;
}

void Dictionary::allWordDeleteLetter(std::string letter)
{
    findLetter(letter)->next=NULL;
}

void Dictionary::alphabetize()
{
  /*  DictionaryWords *tmp;
    DictionaryWords wordList[50];
    for (int x=0;)
        */
    return;
}

DictionaryWords* Dictionary::findWord(std::string word)
{
    DictionaryWords *tmp;
    tmp = findLetter(word);
    tmp=tmp->next;
    while(tmp!=NULL)
    {
        if (tmp->word==word)
            return tmp;
        else
            tmp = tmp->next;
    }
    return NULL;
}

DictionaryWords* Dictionary::findLetter(std::string letter)
{
    for (int x=0; x<tableSize; x++)
    {
        if (WordTable[x]->word[0] == letter[0])
            return WordTable[x];
    }
    return NULL;
}

string Dictionary::seperateWords(std::string &sentence)
{
    string result;
    int pos;
    pos = sentence.find(',');
    if (pos==-1)
        return "";
    result = sentence.substr(0,pos);
    sentence.erase(0,pos+2);
    cout<<result<<endl;
    return result;
}
void Dictionary::insertSeveralWords(std::string sentence)
{
    string word;
    while (true)
    {
        word = seperateWords(sentence);
        if (word=="")
        {
            insertWord(sentence);
            return;
        }
        insertWord(word);
    }
}


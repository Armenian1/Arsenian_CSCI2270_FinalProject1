#include "Dictionary.h"
#include <iostream>

using namespace std;

Dictionary::Dictionary()                        //Sets empty values to the array.
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

    ptr = findLetter(word);                                 //Finds the first letter from the word inputted.
    tmp = ptr;
    ptr = ptr->next;
    while (ptr!=NULL)                                       //Finds the last place in the linked list.
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    ptr = newWord;                                          //Sets the word to the linked list.
    tmp->next = ptr;                                        //Sets the previous and the next pointers.
    ptr->previous = tmp;
}

void Dictionary::defineWord(std::string word, std::string definition)
{
    DictionaryWords *tmp;
    tmp = findWord(word);
    if (tmp!=NULL)                                          //Makes sure the word was found
        tmp->definition = definition;                       //Updates definition to the word
    else
        cout<<"word not found"<<endl;

}

void Dictionary::deleteWord(std::string word)
{
    DictionaryWords *tmp;
    if (findWord(word)==NULL)                               //Makes sure the word is found.
    {
        cout<<"word not found"<<endl;
        return;
    }
    tmp = findWord(word);
    if (tmp->next!=NULL)                                    //Case when word to be deleted is not at the end of the linked list.
    {
        tmp->previous->next = tmp->next;                    //Update all the next and previous pointers
        tmp->next->previous = tmp->previous;
        tmp->next = NULL;                                   //Makes sure that the word being deleted doesn't point to anything.
    }
    else
        tmp->previous->next = NULL;
    tmp->previous = NULL;
}

void Dictionary::findDefinition(std::string word)
{
    DictionaryWords *tmp;
    tmp = findWord(word);
    if (tmp!=NULL)                                                      //Checks if the word was found.
        cout<<word<<" - "<<tmp->definition<<endl;
    else
        cout<<"word not found"<<endl;
}


void Dictionary::printAllWords()
{
    DictionaryWords *tmp;
    for (int x=0; x<tableSize; x++)                                         //Traverses through every letter of the alphabet.
    {
        if (WordTable[x]->next!=NULL)                                       //Checks if a linked list is attached to the letter
        {
            cout<<WordTable[x]->word<<" => ";WordTable[x]->next->word;      //Prints the word after the letter.
            if (WordTable[x]->next->next!=NULL)                             //Checks if the next of the next is NULL
            {
                cout<<WordTable[x]->next->word;                             //Just a heads up the reason this is super complicated was so I could get it to print in a specific format.
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

void Dictionary::totalWordCount()
{
    int numWords=0;                         //Goes through the entire table and every time it passes a word it adds one to numWords.
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
    int numWords = 0;                           //Goes through every word after a letter and adds one to numWords.
    DictionaryWords *tmp;
    tmp = findLetter(letter);
    if (tmp==NULL)                              //Checks if their is no word there.
    {
        cout<<"word not found"<<endl;
        return;
    }
    while (tmp->next!=NULL)                     //Traverses through the linked list
    {
        tmp = tmp->next;
        numWords++;
    }
    cout<<"The total number of words for the letter "<<letter<<" in the dictionary is: "<<numWords<<endl;
}

void Dictionary::dictionaryReset()
{
    for (int x=0; x<tableSize; x++)                         //Only makes every node point to NULL. Inefficient because the memory is not freed.
        WordTable[x]->next = NULL;
}

void Dictionary::allWordDeleteLetter(std::string letter)
{
    findLetter(letter)->next=NULL;                          //Changes the next variable for every word in a linked list of a specific letter to point to NULL.
}

void Dictionary::alphabetize()                              //Was unable to finish if anyone's up for the challenge.
{
  /*  DictionaryWords *tmp;                                 //Was going to assign every word to an array and use an algorithm to alphabetize it and then reinsert all the words at the correct alphabetical order.
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
        if (tmp->word==word)                                //Traversing through the array until it finds the word it wants and then returns that word as type DictionaryWords.
            return tmp;
        else
            tmp = tmp->next;
    }
    return NULL;                                            //Returns NULL if word not found.
}

DictionaryWords* Dictionary::findLetter(std::string letter)
{
    for (int x=0; x<tableSize; x++)
    {
        if (WordTable[x]->word[0] == letter[0])             //Compares the first letter of the word and the char value of the table.
            return WordTable[x];
    }
    return NULL;                                            //Returns NULL if letter wasn't found.
}

string Dictionary::seperateWords(std::string &sentence)
{
    string result;
    int pos;
    pos = sentence.find(',');                               //Searches for the next comma
    if (pos==-1)
        return "";                                          //If comma wasn't found returns nothing. 
    result = sentence.substr(0,pos);                        //Sets result to be everything before the next comma.
    sentence.erase(0,pos+2);                                //Deletes whatever result was set to and the comma. 
    cout<<result<<endl;
    return result;
}
void Dictionary::insertSeveralWords(std::string sentence)
{
    string word;
    while (true)
    {
        word = seperateWords(sentence);                     //Separates all the words
        if (word=="")                                       //Realizes that the word is the last word of the sentence. 
        {
            insertWord(sentence);                           //Inserts the last word in the sentence.
            return;
        }
        insertWord(word);                                   //Inserts the word.
    }
}


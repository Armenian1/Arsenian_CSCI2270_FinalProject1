#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

int main()
{
    string response;
    int numResponse;
    string word;
    string definition;
    Dictionary words;

    while (true)
    {
        cout << "======Main Menu======"<<endl;
        cout<<"1. Insert word"<<endl;
        cout<<"2. Define word"<<endl;
        cout<<"3. Delete word"<<endl;
        cout<<"4. Find Definition of a word"<<endl;
        cout<<"5. Print all contexts"<<endl;
        cout<<"6. Insert several words"<<endl;
        cout<<"7. Total word count"<<endl;
        cout<<"8. Total word count for specific letter"<<endl;
        cout<<"9. Reset entire dictionary"<<endl;
        cout<<"10. Delete all words for a specific letter"<<endl;
        cout<<"11. Quit"<<endl;

        getline (cin,response);
        numResponse = atoi(response.c_str());
        switch (numResponse)
        {
            case 1: cout<<"Enter word:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.insertWord(word);
                    break;

            case 2: cout<<"Enter word:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    cout<<"Enter definition:"<<endl;
                    getline (cin,definition);
                    words.defineWord(word,definition);
                    break;

            case 3: cout<<"Enter word:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.deleteWord(word);
                    break;

            case 4: cout<<"Enter word:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.findDefinition(word);
                    break;

            case 5: words.printAllWords();
                    break;

            case 6: cout<<"Enter words separated by commas:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.insertSeveralWords(word);
                    break;

            case 7: words.totalWordCount();
                    break;

            case 8: cout<<"Enter letter:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.totalWordCountLetter(word);
                    break;

            case 9: words.dictionaryReset();
                    break;

            case 10: cout<<"Enter letter:"<<endl;
                    getline (cin,word);
                    transform(word.begin(), word.end(),word.begin(), ::tolower);
                    words.allWordDeleteLetter(word);
                    break;

            case 11: cout<<"Goodbye!"<<endl;
                    return 0;
        }
    }
    return 0;
}

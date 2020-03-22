#include <iostream>
#include <string>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic
{
    
    string find(string text,string word)
    {
        string tempText=text;
        string returnStr;             
        if (text.find(word) != string::npos) { //locate word 
            cout << text.substr(text.find(word),word.length()) << '\n';
        }
        for(size_t i=0;i<word.length();i++) //word lower case
        {
            char c=word.at(i);
            word.at(i)=tolower(c);
        }
        for(size_t i=0;i<tempText.length();i++) //text lower case
        {
            char c=tempText.at(i);
            tempText.at(i)=tolower(c);
        }
        if (tempText.find(word) != string::npos) { //locate word again
            //cout << tempText.substr(tempText.find(word),word.length()) << '\n';
            returnStr=tempText.substr(tempText.find(word),word.length());
        }     
        return returnStr;    
    }
}



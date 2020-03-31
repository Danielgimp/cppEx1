#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic
{
        
    string replaceChar(string before,char from,char to)
    {
        replace( before.begin(), before.end(), from, to);
            int found = before.find(before);
            if (found != string::npos) 
            {
                
                string returnStr=before.substr(found,before.size()); 
                return returnStr;  
            }
    }

    string isFound(string Text,string Word)
    {
        int found=Text.find(Word);
        if (found != string::npos) 
        {
        string returnStr=Text.substr(found,Word.size()); 
        return returnStr;  
        }
        else return "-1";
    }
    string find(string text,string word)
    {
        string tmpText=text,tmpWord=word;
        for (int i = 0; i < text.length(); i++) 
        { 
                if (text.at(i) >= 'A' || text.at(i) <= 'Z')
                { 
                    tmpText.at(i)=tolower(text.at(i));
                }
                else
                {
                tmpText.at(i)=text.at(i);
                }
        }
        for (int i = 0; i < word.length(); i++) 
        { 
                if (word.at(i) >= 'A' || word.at(i) <= 'Z')
                { 
                    tmpWord.at(i)=tolower(word.at(i));
                }
                else
                {
                tmpWord.at(i)=word.at(i);
                }
        }
        if(isFound(tmpText,tmpWord).compare("-1")) return isFound(tmpText,tmpWord);
        string returnStr;                
        if(tmpWord.find('t')!=string::npos)
        {
            returnStr=replaceChar(tmpWord,'t','d');
            if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
        }
        if(tmpWord.find('d')!=string::npos)
        {
            returnStr=replaceChar(tmpWord,'d','t');
            if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
        }

         if(tmpWord.find('v')!=string::npos)
        {
           returnStr=replaceChar(tmpWord,'v','w');
           if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
        }
        if(tmpWord.find('w')!=string::npos)
        {
           returnStr=replaceChar(tmpWord,'w','v');
           if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
           
        }

         if(tmpWord.find('i')!=string::npos)
        {
            returnStr=replaceChar(tmpWord,'i','y');
            if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
        }
        if(tmpWord.find('y')!=string::npos)
        {
            
            returnStr=replaceChar(returnStr,'y','i');
            if(isFound(tmpText,returnStr).compare("-1") !=0) tmpText = isFound(tmpText,returnStr);
            
        }
                
        return tmpText;
          
    }
}



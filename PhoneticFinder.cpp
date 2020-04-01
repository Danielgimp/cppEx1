#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "PhoneticFinder.hpp"
using namespace std;
int wordIndex=-1;
namespace phonetic
{
    bool wordinText(vector<string> text,string word)
    {
        for(int i=0;i<text.size();i++)
        {             
             if(text[i].compare(word)==0)
             {
                 wordIndex=i;                 
                 return true;
             }
             
        }                  
        return false;
    }

    string returnWordfromText(vector<string> text,int i) { return text[i]; }        
    
    string find(string text,string word)
    {
        string returnStr="";
        if(word.length()>text.length() || text.length()==0 || word.length()==0) throw invalid_argument( "Criterias Aren't met!" );
        vector<string> regularTextVector; //regular text vector
        string regularTextTemp="";
        for(int i=0;i<text.length();i++) //put the regular case text to a vector
        {
            if(text.at(i)==' ')
            {                
                regularTextVector.push_back(regularTextTemp);
                regularTextTemp="";
            } 
            else regularTextTemp=regularTextTemp+text.at(i);
            if((i+1)==text.length())
            {                
                regularTextTemp+=text.at(i);
                regularTextVector.push_back(regularTextTemp);
            }
        }

        string lowercase=""; //lowercase text
        for(int i=0;i<text.length();i++) //lower case the text
        {
            char c=text.at(i);
            lowercase+=tolower(c);
            
        }
        

        string lowercaseWord=""; //lower case word
        for(int i=0;i<word.length();i++) //lower case the word
        {
            char c=word.at(i);
            lowercaseWord+=tolower(c);
            
        }

        vector<string> lowercaseTextVector; //lowercasevector
        string lowercaseText="";
        for(int i=0;i<lowercase.length();i++) //put the lower case text to a vector
        {
            if(lowercase.at(i)==' ')
            {                
                lowercaseTextVector.push_back(lowercaseText);
                lowercaseText="";
            } 
            else lowercaseText=lowercaseText+lowercase.at(i);
            if((i+1)==lowercase.length())
            {
                regularTextTemp+=text.at(i);
                regularTextVector.push_back(regularTextTemp);
            }
        }        
        bool ret=wordinText(lowercaseTextVector,lowercaseWord);        
        if(ret==1) returnStr=returnWordfromText(regularTextVector,wordIndex);
        wordIndex=-1;
        ret=0;

        



        return returnStr;
          
    }
}
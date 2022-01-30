//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  SpellChecker.cpp
//  ws05-part2

#include <iostream>
#include <fstream>
#include "SpellChecker.h"



namespace sdds {

SpellChecker::SpellChecker(const char* filename){
    std::ifstream file(filename);
    
    if(!file){
        throw "Bad file name!";
        
    }else{
        std::string lineTemp;
        do{
            getline(file, lineTemp);
            
            if(file){
                size_t positionI = 0;
                size_t posEnd = lineTemp.find(' ');
                
                this->m_badWords[counter] = lineTemp.substr(positionI, posEnd - positionI);
                lineTemp.erase(positionI, posEnd - positionI);
                for (size_t i = 0; i < lineTemp.length(); i++){
                    if(lineTemp[i] == ' ')
                        positionI = i;
                }
                this->m_goodWords[counter] = lineTemp.substr(positionI + 1);
                counter++;
            }
        }while(file);
    }
    
}
void SpellChecker::operator()(std::string& text) const{
    size_t textPlace = 0;

    for (size_t i = 0; i < counter; i++)
    {
        textPlace = text.find(m_badWords[i]);
        if (textPlace != text.npos)
        {
            while (textPlace != text.npos)
            {
                text.replace(textPlace, m_badWords[i].length(), m_goodWords[i]);
                textPlace = text.find(m_badWords[i]);
            }
        }
    }
    
}
}

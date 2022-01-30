//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/07/12
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  SongCollection.cpp
//  ws07-part1

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <numeric>
#include "SongCollection.h"
namespace sdds{
SongCollection::SongCollection(const char* in){
    std::ifstream file(in);
    if(!file){
        throw "File not found";
    }
    std::string temp;
    while(getline(file, temp)){
        Song theSong;
        
        std::string tempTitle;
        std::string tempArtist;
        std::string tempAlbum;
        std::string tempYear;
        std::string tempLength;
        std::string tempPrice;
        
        //TITLE
        tempTitle = temp.substr(0, 25);
        theSong.title = trim(tempTitle);
        temp.erase(0,25);
        
        //ARTISTI
        tempArtist = temp.substr(0, 25);
        theSong.artist = trim(tempArtist);
        temp.erase(0,25);
        
        //ALBUM
        tempAlbum = temp.substr(0, 25);
        theSong.album = trim(tempAlbum);
        temp.erase(0,25);
        
        //YEAR
        tempYear = temp.substr(0, 5);
        trim(tempYear);
        if(!tempYear.empty()){
            theSong.releaseYear = std::stoi(tempYear);
        }else{
            theSong.releaseYear = 0;
        }
        temp.erase(0,5);
        
        //LENGTH
        tempLength = temp.substr(0, 5);
        theSong.songLenght = std::stoi(trim(tempLength));
        temp.erase(0,5);
        
        //PRICE
        tempPrice = temp.substr(0, 5);
        theSong.m_price = std::stod(trim(tempPrice));
        temp.erase(0,5);
        
        songCollection.push_back(theSong);
    }
    
}
void SongCollection::display(std::ostream& out) const{
    int totalSec = std::accumulate(songCollection.begin(), songCollection.end(), 0, [](int sum, Song song) {return sum + song.songLenght;});
    int min = totalSec / 60;
    int hour = min / 60;
    int sec = totalSec % 60;
    
    std::for_each(songCollection.begin(), songCollection.end(), [](Song song){ std::cout << song << std::endl;});
    out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
    out << "| " << std::right << std::setw(77) << "Total Listening Time: " << hour << ":" << min % 60 << ":" << sec << " |" << std::endl;
    
}
void SongCollection::sort(std::string sortBy){
    if(sortBy == "title"){
        std::sort(songCollection.begin(), songCollection.end(), [] (Song i, Song j){return i.title < j.title;});
    }
    
    if(sortBy == "length"){
        std::sort(songCollection.begin(), songCollection.end(), [] (Song i, Song j){return i.songLenght < j.songLenght;});
    }
    
    if(sortBy == "album"){
        std::sort(songCollection.begin(), songCollection.end(), [] (Song i, Song j){return i.album < j.album;});
    }
}
void SongCollection::cleanAlbum(){
    std::for_each(songCollection.begin(), songCollection.end(),
                  [this](Song& i){ if(i.album == "[None]")  i.album = " " ;});
}
bool SongCollection::inCollection(std::string art) const{
    return std::any_of(songCollection.begin(), songCollection.end(), [art] (Song i){return i.artist == art;});
}
std::list<Song> SongCollection::getSongsForArtist(std::string art) const{
    std::list<Song> artistSong;
    std::copy_if(songCollection.begin(), songCollection.end(), back_inserter(artistSong), [art] (Song i){return i.artist == art;});
    
    return artistSong;
}

std::ostream& operator<<(std::ostream& out, const Song& theSong){
    int sec, min;
    sec = theSong.songLenght % 60;
    min = theSong.songLenght / 60;
    
    out << "| " << std::setw(20) << std::left << theSong.title;
    out << " | " << std::setw(15) << theSong.artist;
    out << " | " << std::setw(20) << theSong.album;
    if(theSong.releaseYear == 0){
        out << " | " << std::setw(6) << std::right << " ";
    }else{
        out << " | " << std::setw(6) << std::right << theSong.releaseYear;
    }
    out << " | " <<  min << ":" << std::setfill('0') << std::setw(2) << sec << std::setfill(' ');
    out << " | " << theSong.m_price << " |";
    
    return out;
}


std::string SongCollection::trim(std::string& str) const {
    size_t i = 0u;
    for (i = 0u; i < str.length() && str[i] == ' '; ++i);
    str = str.substr(i);
    for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
    str = str.substr(0, i);
    return str;
}


}

//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/07/12
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//  SongCollection.h
//  ws07-part1

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

namespace sdds{
struct Song{
    std::string artist;
    std::string title;
    std::string album;
    double m_price;
    int releaseYear;
    int songLenght;
};
class SongCollection{
    std::vector <Song> songCollection;
public:
    SongCollection(const char* in);
    void display(std::ostream& out) const;
    void sort(std::string);
    void cleanAlbum();
    bool inCollection(std::string) const;
    std::list<Song> getSongsForArtist(std::string) const;
    
    std::string trim(std::string& str) const;
    void setAlbum();
    
};
std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif /* SDDS_SONGCOLLECTION_H */

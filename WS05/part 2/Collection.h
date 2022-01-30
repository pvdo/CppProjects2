//
// Name: Pedro Vitor do Carmo Saraiva Teixeira
// Email: pvdo-carmo-sariava-t@myseneca.ca
// Student ID: 100036193
// Last Version: 2020/06/28

//  Collection.h
//  ws05-part2

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <stdio.h>
#include <iostream>

namespace sdds{
template<typename T>
class Collection{
    std::string m_name{""};
    T* m_items{nullptr};
    size_t counter{0};
    
    void (*m_observer) (const Collection<T>&, const T&) = nullptr;
    
public:
    Collection(std::string name){
        m_name = name;
        
    }
    Collection(const Collection&) = delete;
    Collection& operator=(const Collection&) = delete;
    ~Collection(){
        delete [] m_items;
        m_items = nullptr;
    }
    const std::string& name() const{
        return m_name;
    }
    size_t size() const{
        return counter;
    }
    void setObserver(void (*observer)(const Collection<T>&, const T&)){
        m_observer = observer;
    }
    Collection<T>& operator+=(const T& item){
        
        bool findTitle = false;
        for(size_t i = 0; i < counter; i++){
            if(m_items != nullptr && m_items[i].title() == item.title()){
                findTitle = true;
            }
        }
        
        if(!findTitle){
            T* tempItems = new T[counter];

            for (size_t i = 0; i < counter; ++i){
                tempItems[i] = m_items[i];
            }
            
            
            delete[]m_items;
            m_items = new T[counter + 1];
            for (size_t i = 0; i < counter; ++i){
                m_items[i] = tempItems[i];
            }
            m_items[counter] = item;
            ++counter;
            
            if (m_observer != nullptr)
                m_observer(*this, m_items[counter - 1]);
            delete [] tempItems;
        }
        return *this;
    }
    
    T& operator[](size_t idx) const{
        
        if(idx >= counter){
            throw std::out_of_range("Bad index [" +
                                    std::to_string(idx) +
                                    "]. Collection has [" +
                                    std::to_string(counter) +
                                    "] items.");
        }
        return m_items[idx];
    }
    T* operator[](std::string title) const{
        size_t i;
        bool findTitle = false;
        for(i = 0; i < counter && findTitle == false; i++){
            if(m_items != nullptr && m_items[i].title() == title){
                findTitle = true;
            }
        }
        
        return findTitle == true? &(m_items[i - 1]) : nullptr;
    }

    
};
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& items){
        for (size_t i = 0; i < items.size(); i++){
            os << items[i];
        }
    return os;
    };
}

#endif /* SDDS_COLLECTION_H */

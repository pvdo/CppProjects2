//
//  PairSummable.hpp
//  ws3-part2
//
//  Created by Pedro Do Carmo on 2020-06-10.
//  Copyright © 2020 Pedro Do Carmo. All rights reserved.
//

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <stdio.h>
#include <iomanip>
#include "Pair.h"

namespace sdds{

template <class K, class V>
class PairSummable : public Pair<K, V>{
        
    static V initialValue;
    static size_t width;
    
public:
    static const V& getInitialValue(){
        return initialValue;
    }
    PairSummable(){}
    PairSummable(const K& key, const V& value) : Pair<K, V>(key, value){
        int size = key.size();
        if(size != width){
            width = size;
        }
    }
    
    V sum(const K& key, const V& val) const;
//        V value;
//        if(key == Pair<K, V>::key()){
//            value = Pair<K, V>::value() + val;
//        }else{
//            value = val;
//        }
//
//        return value;
//    }
    
//    std::string sum(const std::string key, const std::string val) const{
//        V value;
//        if(key == Pair<K, V>::key()){
//            value = Pair<K, V>::value() + val;
//        }else{
//            value = val;
//        }
//
//        return value;
//    }
    void display(std::ostream& os) const{
        os << std::setw(width) << std::left;
        Pair<K, V>::display(os);
        os << std::right;
        
    }
    
};




size_t width = 0;
template <typename K, typename V>
const V& getInitialValue(){
    return PairSummable<K,V>::initialValue;
}
template<>
std::string PairSummable<std::string, std::string>::initialValue = "";

template<>
int PairSummable<std::string, int>::initialValue = 0;




template<typename K, typename V>
V PairSummable<K,V>::sum(const K& key, const V& val) const{
    V value;
    if(key == Pair<K, V>::key()){
        value = Pair<K, V>::value() + val;
    }else{
        value = val;
    }
    
    return value;
}

template<>
std::string PairSummable<std::string, std::string>::sum<std::string, std::string>(const std::string key, const std::string val) const{
        std::string value;
        if(key == Pair<std::string, std::string>::key()){
            value = Pair<std::string, std::string>::value() + val;
        }else{
            value = val;
        }
        
        return value;
    }




template<typename K, typename V>
V PairSummable<K,V>::sum(const K& key, const V& val) const{
    V value;
    if(key == Pair<K, V>::key()){
        value = Pair<K, V>::value() + val;
    }else{
        value = val;
    }
    
    return value;
}

template<>
std::string PairSummable<std::string, std::string>::sum<std::string, std::string>(const std::string key, const std::string val) const{
        std::string value;
        if(key == Pair<std::string, std::string>::key()){
            value = Pair<std::string, std::string>::value() + val;
        }else{
            value = val;
        }
        
        return value;
    }
}

#endif /* SDDS_PAIRSUMMABLE_H */

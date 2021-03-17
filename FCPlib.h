// FunctionalCompetitive.h
#include <bits/stdc++.h>
#include <iostream>
#pragma once

namespace FCP
{
    //single var print
    template <typename T>
    void print(const T &target) {
        std::cout << target << std::endl;
    }
    //labeled print
    template <typename O,typename T>
    void print(const O label, const T &target) {
        std::cout << label << ": " << target << std::endl;
    }
    //vector print
    template <typename T>
    void print(const std::vector<T>& target) {
        std::cout << "[ ";
        for(auto i: target){
            std::cout << i << " ";
        }
        std::cout << "]" <<std::endl;
    }
    //labeled vector print
    template <typename O,typename T>
    void print(const O label,const std::vector<T>& target) {
        std:: cout << label << ":[ ";
        for(auto i: target){
            std::cout << i << " ";
        }
    std::cout << "]"<<std::endl;
    }

    // functional functions
    template <typename T, typename R, typename L>
    void fmap(const T& target, R& result, L lambda ){
        transform(target.cbegin(),target.cend(),result.begin(),lambda);
    }
    template <typename T, typename B, typename L>
    auto foldl(const T& target, const B base, L lambda ){
        return accumulate(target.cbegin(),target.cend(),base,lambda);
    }

    template <typename T, typename B, typename L>
    auto foldr(const T& target, const B base, L lambda ){
        return accumulate(target.crbegin(),target.crend(),base,lambda);
    }

    template <typename T>
    std::vector<T> tail(std::vector<T> target){
        if(target.size() == 0 || target.size() == 1){
            return std::vector<T>(target.begin(),target.begin());
        }
        return std::vector<T>(target.begin()+1,target.end());    
    }

}
//end of namespace 

//overloading + operator of vector class
template <typename T>
std::vector<T> operator+(std::vector<T> Fst,std::vector<T> Snd ){
    Fst.insert(Fst.end(),Snd.begin(),Snd.end());
    return Fst;
}

template <typename T>
std::vector<T> operator+(std::vector<T> Fst,T Snd ){
    Fst.insert(Fst.end(),Snd);
    return Fst;
}

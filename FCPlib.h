// FunctionalCompetitive.h
#include <bits/stdc++.h>
#include <iostream>
#pragma once

namespace FCP
{
    template <typename T>
    void print(const T &t) {
        std::cout << t << std::endl;
    }
    template <typename O,typename T>
    void print(const O label, const T &t) {
        std::cout << label << ": " << t << std::endl;
    }
    template <typename T>
    void print(const std::vector<T>& t) {
        for(auto i: t){
            std::cout << i << " ";
        }
    std::cout <<std::endl;
    }
    template <typename O,typename T>
    void print(const O label,const std::vector<T>& t) {
        std:: cout << label << ": ";
        for(auto i: t){
            std::cout << i << " ";
        }
    std::cout <<std::endl;
    }
    template <typename T, typename R, typename L>
    void fmap(const T& t, R& result, L lambda ){
        transform(t.cbegin(),t.cend(),result.begin(),lambda);
    }
    template <typename T, typename B, typename L>
    auto foldl(const T& t, const B base, L lambda ){
        return accumulate(t.cbegin(),t.cend(),base,lambda);
    }

    template <typename T, typename B, typename L>
    auto foldr(const T& t, const B base, L lambda ){
        return accumulate(t.crbegin(),t.crend(),base,lambda);
    }

    //functional format instead of  int maxd(){}, we  do auto maxd()-> int{}
    auto maxd(int a, int b) -> int{
        return 5;
    }
}

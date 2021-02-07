#include <bits/stdc++.h>
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

using namespace std;
int main(){    
//--------------------------------------------------------
    //lambda  
    auto lambdaX = [](int x){return x + 9;};
    print("lambda applied to 8",lambdaX(8)); 
    print("lambda type", typeid(lambdaX).name()); //type of lambda

    //lambda expression  = (lambda a: a + 9)(8)
    int pp = [](int x){return x + 9;}(8);
    print(pp);
//--------------------------------------------------------
    vector<int> intlst = {1,2,3,4};
    vector<int> results(intlst.size());
    //cbegin and begin are iterators
    //cbegin is constant, begin is not, begin iterator can change the value pointing to
    //fmap is a template for transform
    transform(intlst.cbegin(),intlst.cend(),results.begin(),[](int x){return x + 3;});
    fmap(intlst,results,[](int x){return x + 3;});
    print("transform",results);
//--------------------------------------------------------   
    //accumulate is foldl, the state transition fold
    auto Sum = accumulate(intlst.cbegin(),intlst.cend(),0,[](int x, int y){return x + y;});
    auto Sum2 = foldl(intlst,0,[](int x, int y){return x + y;});
    print("accumulate",Sum2);
    print("foldl",Sum);

    auto Largest = accumulate(intlst.cbegin(),intlst.cend(),0,[](int x, int y){ return x > y ? x : y;});
    print(Largest);
    
//--------------------------------------------------------
    //foldl works from left inner parenthesis outwards
    string InStr = "MSFT";
    string k = "|";
    auto paren = foldl(InStr,k,
        [](auto IH, auto nextStep){
            string v = "(" + IH + nextStep + ")";
            return v;
            }
                );

    print(paren);
    //outputs ((((|M)S)F)T) for foldl
    //(((|M)S)F) is IH,   
    // T is nextStep


//--------------------------------------------------------

    auto parenR = foldr(InStr,k,
    [](auto IH, auto x){
        string v = "(" + IH + x + ")";
        return v;
        }
            );

    print(parenR);
    //outputs ((((|T)F)S)M) for foldr
    // can also be rewritten as (M(S(F(|T))))
    // (S(F(|T))) is IH
    // M is x
    // in haskell list x:xs, x operates on IH(xs).


    auto Reverse = foldr(InStr,k,
    //input MSFT
    [](auto IH, auto x){
        string v = IH + x ;
        //IH represents reverse(SFT)
        //x represents "M"
        return v;
        }
            );

    print(Reverse);
    return 0;

}

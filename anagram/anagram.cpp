#include <iostream>
#include <algorithm>

int main(){
    std::string verb;

    std::cin>>verb;
    
    while (std::next_permutation(verb.begin(), verb.end())){
        std::cout<<verb<<std::endl;
    }
    std::cout<<verb; // last permutation 
    
    return 0;
}
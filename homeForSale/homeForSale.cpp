#include <iostream>
#include <vector>
#include <algorithm>

int solve(){
    int houses,budget;
    int houseBought=0;
    std::cin>>houses>>budget;
    std::vector<int> housesPrice;
    
    int housePrice;
    for(int i=0; i<houses; i++){   
        std::cin>>housePrice;
        housesPrice.push_back(housePrice);
    }

    std::sort(housesPrice.begin(), housesPrice.end());
 
    for(auto& house : housesPrice){
        if(budget-house>=0){
            houseBought++;
            budget-=house;
        }
        else{
            break;
        }
   }

    return houseBought;
}

int main(){

    int caseNumber;
    std::vector<int> samples;
    std::cin>>caseNumber;

    while (caseNumber--)
    {
        samples.push_back(solve());
    }
      std::cout<<std::endl;
    for(int a = 0; a<samples.size(); a++){
        std::cout<<"CASE: "<<a+1<<" "<< samples.at(a)<<std::endl;
    }

    return 0;
}
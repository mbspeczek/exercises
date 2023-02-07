#include <iostream>
#include <vector>
#include <algorithm>

int winRound(std::vector<int> player1, std::vector<int>player2){
    std::sort(player1.begin(), player1.end(),[](int a, int b){return a>b;});
    std::sort(player2.begin(), player2.end(),[](int a, int b){return a>b;});

    int player1Sum = player1.at(0)+player1.at(1);
    int player2Sum = player2.at(0)+player2.at(1);

    if(player1Sum>player2Sum){
        return 1;
    }
    return 0;
}

int main(){

    std::cout<<winRound({2, 5, 2, 6, 9}, {3, 7, 3, 1, 2});
    std::cout<<winRound({1, 2, 3, 4, 5}, {9, 8, 7, 6, 5});
    std::cout<<winRound({4, 3, 4, 4, 5}, {3, 2, 5, 4, 1});
    return 0;
}
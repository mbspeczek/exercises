#include <iostream>
#include <vector>

template<typename T>
int BinarySearch(T target, std::vector<T> &vec, int startID, int endID){
    if(startID<=endID){
        int pivot = (startID+endID)/2;

        if( vec.at(pivot) == target){
            return pivot;
        }

        if( vec.at(pivot) > target){
           return BinarySearch(target, vec, startID, pivot-1);
        }
        else{
           return BinarySearch(target, vec, pivot+1, endID);
        }
    }
    else{
        return -1;
    }

}

int main(){
// array must be sorted 
std::vector<int> vec = {1,2,3,4,5,6,7,8,9};

// type deduction from 5 -> int
std::cout<<BinarySearch(5, vec, 0, (vec.size()-1));

return 0;
}
#include <iostream>
// 0 - 10
std::string digits0_10[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
// 11 - 20 
std::string tens11_19[] = {"eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen","nineteen"};
// 20 - 90
std::string tens20_90[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
// scale x100
std::string scaleX100[] = {""," thousand, ", " million, ", " billion, " };

std::string numberToText(int number){
    std::string tmp;

    if(number/100>0){
        tmp+=digits0_10[(number/100)];
        tmp+=" houndred ";
        number-=(number/100)*100;
    }

    if(number/10>1){
        tmp+=tens20_90[(number/10)-2];
        number-=(number/10)*10;
        tmp+="-";
    }
    
    if(number>0){
        tmp+=digits0_10[(number)];
    }
   
   return tmp;
}

void solve(int number){
    std::string parsedNumberToText;
    int step=0;
    
    while (number!=0)
    {
        if(number%1000>0){
            int tmp_number = number%1000;
            parsedNumberToText=scaleX100[step]+parsedNumberToText;
            parsedNumberToText=numberToText(tmp_number)+parsedNumberToText;
            step++;
        }
        else{
            step++;
        }
        number/=1000;        
    }
    std::cout<<parsedNumberToText;
}

int main(){
    int number;

    std::cin>>number;
    
    std::cout<<"the number: "<<number<<std::endl;
    
    solve(number);
   
    return 0;
}
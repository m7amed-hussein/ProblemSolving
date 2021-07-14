#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> numbers;
int nsize;
map<int, vector<int>> memo;



vector<int> HowSum(int targeSum ) {

    if (memo.find(targeSum) != memo.end()) return memo[targeSum];


    vector<int> arr;
    if (targeSum == 0) {
        arr.push_back(0);
        return arr;
    }


    for (int i = 0; i < nsize; i++) {
        int reminder = targeSum - numbers[i];
        if (reminder >= 0) {
            vector<int> Result = HowSum(reminder);
            if (!Result.empty()) {
                if(Result.back()==0)
                    Result.pop_back();
                Result.push_back(numbers[i]);
                memo[targeSum] = Result;
                return Result;
            }
        }
           
    }
    memo[targeSum] = arr;
    return arr;
}



int main()
{
    
    numbers = { 7,14 };
    nsize = numbers.size() ;
    vector<int > result = HowSum(300);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i]<<" ,";
    }
    

}
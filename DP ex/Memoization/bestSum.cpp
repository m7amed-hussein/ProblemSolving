#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> numbers;
map<int, vector<int>> memo;

vector<int> bestSum(int targetSum) {


    if (memo.find(targetSum) != memo.end()) return memo[targetSum];

    vector<int> temp;
    if (targetSum == 0) {
        temp.push_back(0);
        return temp;
    }



    vector<int> shortest;
    for (int i = 0; i < numbers.size(); i++) {
        int reminder = targetSum - numbers[i];
        if (reminder >= 0) {
            vector<int> Result = bestSum(reminder);
            if (!Result.empty()) {
                if (Result.back() == 0) Result.pop_back();
                Result.push_back(numbers[i]);
                if (Result.size() < shortest.size()|| shortest.size()==0) {
                    shortest.clear();
                    shortest = Result;
                }
            }
        }
    }
    memo[targetSum] = shortest;

    return shortest;
}


int main()
{
    numbers = { 1,2,5,25 };
    vector<int> ans = bestSum(100);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    

}
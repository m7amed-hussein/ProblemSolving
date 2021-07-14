#include <iostream>
#include <bits/stdc++.h>
using namespace std;


map<int, bool> memo;
map<int, bool> :: iterator it;
bool CanSum(int targetSum,int nums[]) {
    it = memo.find(targetSum);
    if (it!= memo.end()) return memo[targetSum];
    if (targetSum == 0)return true;
    for (int i = 0; i < 2; i++) {
        int reminder = targetSum - nums[i];
        if (reminder >= 0) {
            if (CanSum(reminder, nums)) return  true;
        }
            
    }
    return memo[targetSum] = false;
}


int main()
{
    int nums[]  { 7,14 };
    cout << CanSum(300,nums);

}



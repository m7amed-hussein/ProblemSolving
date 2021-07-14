#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordBank;
map<string, bool> memo;

bool CanConstruct(string target) {

    //memoization check
    if (memo.find(target) != memo.end())return memo[target];

    //base case
    if (target == "") return true;
    
    //Itrate over all wordBank

    for (int i = 0; i < wordBank.size(); i++) {
        string pref = wordBank[i];
        if (pref.length() > target.length()) continue;
        auto res = std::mismatch(pref.begin(), pref.end(), target.begin());

        if (res.first == pref.end())
        {
            string newTarget = target;
            newTarget.erase(0, pref.length());
            memo[target] = CanConstruct(newTarget);
            if(memo[target]) return true;
        }
    }
    return false;
    
}


int main()
{
    wordBank = { "e","ee","eee","eeee","eeeee","eeeeeee","eeeeeeeeee"};
    cout << CanConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef");
    

}
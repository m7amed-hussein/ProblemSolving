#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordBank;
map<string, int> memo;

int CountConstruct(string target) {

    //memoization check
    if (memo.find(target) != memo.end())return memo[target];

    //base case
    if (target == "") return 1;
    
    //Itrate over all wordBank
    for (int i = 0; i < wordBank.size(); i++) {
        string pref = wordBank[i];
        if (pref.length() > target.length()) continue;
        auto res = std::mismatch(pref.begin(), pref.end(), target.begin());

        if (res.first == pref.end())
        {
            string newTarget = target;
            newTarget.erase(0, pref.length());
            memo[target] += CountConstruct(newTarget);
            
        }
    }
    return memo[target];
    
}


int main()
{
    wordBank = { "purp","P","ur","le","purple" };
    cout << CountConstruct("purple");


    wordBank = { "e","ee","eee","eeee","eeeee","eeeeeee","eeeeeeeeee"};
    cout << endl<< CountConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef");


    wordBank = { "a","p","ent","enter","ot","o","t"};
    cout << endl << CountConstruct("enterapotentpot");

    

}
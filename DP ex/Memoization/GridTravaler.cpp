#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, long long> memo;
map<pair<int, int>, long long >::iterator it;


long long GridTravaler(int n, int m) {

    it= memo.find({ n,m });
    //Base case
    if (it != memo.end()) return memo[{n, m }];
   // if (memo[{n, m}] != NULL) return memo[{n, m}];
    if (m == 0 || n == 0)return 0;
    if (m == 1 && n == 1) return 1;
    memo[{n,m}] = GridTravaler(n - 1, m) + GridTravaler(n, m - 1);
    return memo[{n, m}];
}


int main()
{
    cout << GridTravaler(18, 18);

}



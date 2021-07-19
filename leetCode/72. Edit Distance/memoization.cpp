#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, int> memo;
int minDistance(string word1, string word2) {

	if (memo.find({ word1,word2 }) != memo.end()) return memo[{ word1, word2}];

	int D = INT_MAX, I = INT_MAX, U=INT_MAX;
    //base case 
	if (word1.size() ==0&& word2.size()==0) return 0;

	if (word1[0] == word2[0]) return minDistance(word1.substr(1), word2.substr(1));
	if (word2.size() != 0) {
		D = minDistance(word1, word2.substr(1));
	}
	if (word1.size() != 0 && word2.size() != 0) {
		U = minDistance(word1.substr(1), word2.substr(1));
	}
	if(word1.size()!=0){
		I = minDistance(word1.substr(1), word2);
	}
	memo[{word1,word2}] = min(min(D, U), I) + 1;

	return memo[{word1, word2}];

}
int main()
{
	//cout << minDistance("horse", "ros");
	cout << minDistance("intention", "execution");
}
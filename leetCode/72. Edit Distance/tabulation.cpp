#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int minDistance(string word1, string word2) {

	int h = word1.size()+1; int w = word2.size()+1;
	
	//creating the grid
	vector<vector<int>> dp(h, vector<int>(w));

	//iterate over the grid
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			if (i == 0) { dp[i][j] = j;  continue; }
			if (j == 0) { dp[i][j] = i; continue; }
			if (word1[i-1] == word2[j-1]) {
				dp[i][j] =  dp[i - 1][j - 1];
				continue;
			}
			dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);

		}
	}
	
	return dp[h - 1][w - 1];
}
int main()
{
	//cout << minDistance("horse", "ros"); //2
	cout << minDistance("intention", "execution");
}
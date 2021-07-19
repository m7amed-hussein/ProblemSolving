#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordBank;

//string longestPal(string s)
vector<vector<int>> longestPal(string s)
{
	int n = s.length();

	int maxl = 1;
	int start = 0;

	//inithialize the table
	vector<vector<int>> grid(n,vector<int>(n,false));

	//base case for 1 character string
	for (int i = 0; i < n; i++) 
	{
		grid[i][i] = true;
	}

	//bese for 2 character string 
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i + 1]) {
			grid[i][i + 1] = true;
			start = i;
			maxl = 2;
		}
	}
	

	//iterate over the grid
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j < n -i+1; j++) {
			int k = j + i - 1;

			if(s[k]==s[j]&&grid[j+1][k-1]){
				grid[j][k] = true;
				if (i > maxl) {
					maxl = i;
					start = j;
				}
			}
		}
	}
	cout << maxl << endl;
	cout<<s.substr(start,maxl)<<endl;
	return grid;

}

int main()
{
	//cout << longestPal("babad");
	auto res = longestPal("ac");
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size() ; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
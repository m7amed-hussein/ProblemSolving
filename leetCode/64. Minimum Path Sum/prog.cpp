#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> table(n,vector<int>(m,0) );

	table[0][0] = grid[0][0];
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (i + 1 < n) {
				if (table[i + 1][j] == 0 || table[i][j]+grid[i+1][j]<table[i+1][j])
					table[i + 1][j] = table[i][j] + grid[i+1][j];
			}
				
			if (j + 1 < m)
				if (table[i ][j + 1] == 0 || table[i][j] + grid[i ][j + 1 ] < table[i ][j + 1])
					table[i ][j + 1] = table[i][j] + grid[i][j + 1];
		}
	}
	return table[n - 1][m - 1];
}
int main()
{
	//vector<vector<int>> temp = { {0,0,0} ,{0,1,0},{0,0,0} };
	//vector<vector<int>> temp = { {0,1} ,{0,0} };
	//vector<vector<int>> temp = { {1,3,1} ,{1,5,1},{4,2,1} };
	vector<vector<int>> temp = { {1,2,3} ,{4,5,6} };

	cout << minPathSum(temp);
}
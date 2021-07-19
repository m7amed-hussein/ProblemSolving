#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int n = obstacleGrid.size();
	int m = obstacleGrid[0].size();
	vector<vector<int>> grid(n, vector<int>(m, 0));
	if (obstacleGrid[0][0] == 0) {
		grid[0][0] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < obstacleGrid[i].size(); j++) {

			if (grid[i][j] == 0 || obstacleGrid[i][j] == 1) continue;

			if (i + 1 < n)
				if (obstacleGrid[i + 1][j] == 0)
					grid[i + 1][j] += grid[i][j];
			if (j + 1 < m)
				if (obstacleGrid[i][j + 1] == 0)
					grid[i][j + 1] += grid[i][j];
		}
	}
	return grid[n - 1][m - 1];
} 
int main()
{
	//vector<vector<int>> temp = { {0,0,0} ,{0,1,0},{0,0,0} };
	//vector<vector<int>> temp = { {0,1} ,{0,0} };
	vector<vector<int>> temp = { {0,1} };
	cout << uniquePathsWithObstacles(temp);
}
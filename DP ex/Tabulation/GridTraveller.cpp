#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GridTraveller(int n) {
	vector < vector<int> > Grid(n+1, vector<int>(n+1, 0));
	Grid[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + 1 <= n)Grid[i + 1][j] += Grid[i][j];
			if (j + 1 <= n)Grid[i ][j + 1] += Grid[i][j];
		}
	}
	return Grid[n][n];
}


int main()
{
	cout << GridTraveller(3);
}
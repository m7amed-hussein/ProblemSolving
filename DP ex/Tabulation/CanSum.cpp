#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> numbers;

bool CanSum(int targetSum) {
	//making the table
	vector<bool> grid(targetSum+1,false);
	//	My starting point
	grid[0] = true;
	//Iteration over the grid
	for (int i = 0; i < targetSum; i++) {
		if(grid[i])
		for (int j = 0; j < numbers.size(); j++) {
			if (i + numbers[j] <= targetSum)grid[i + numbers[j]] = true;
		}
	}

	return grid[targetSum];
}


int main()
{
	numbers = {7, 14};
	cout << CanSum(300);
	//numbers = { 5,3,4,7};
	//cout << CanSum(7);

	/*numbers = { 2,4 };
	cout << CanSum(7);*/
}
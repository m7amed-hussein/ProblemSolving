#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> numbers;

vector<int> HowSum(int target) {
	//making the grid
	vector<vector<int>> grid(target + 1, vector<int>());

	//inithialize first vector 
	grid[0] = { 0 };

	//iterate over the grid 
	for (int i = 0; i <= target; i++) {
		if (grid[i].size() > 0) {
			for (int j = 0; j < numbers.size(); j++)
			{
				//temp vector to map to other grid elements vectors
				vector<int> temp;
				temp = grid[i];
				temp.push_back(numbers[j]);
				if(i + numbers[j]<=target)
				grid[i + numbers[j]] = temp;
			}
		}
	}
	return grid[target];
}


int main()
{
	numbers = { 3,4,5};

	vector<int > result = HowSum(7);
	for (int i = 0; i < (int)result.size(); i++) {
		cout << result[i] << " ";
	}
}
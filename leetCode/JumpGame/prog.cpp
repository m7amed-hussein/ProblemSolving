#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> nums) {
	//create tabel for the tabulation
	vector<int> grid(nums.size()+1, 0);

	//inithialize the first element
	grid[0] = 0;

	for (int i = 0; i < nums.size(); i++) {

		for (int j = 1; j <= nums[i]; j++) {
			
			if (grid[i + j] == 0 || grid[i + j]> grid[i] + 1)
				grid[i + j] = grid[i] + 1;
			if (grid[nums.size() - 1] != 0) return grid[nums.size() - 1];
		}
	}
	return grid[nums.size() - 1];
}

int main()
{
	vector<int> nums = { 1,2,1,1,1 };
	cout << jump(nums);
	
}
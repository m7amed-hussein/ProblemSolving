#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxSunArray(vector<int> nums) {
	int max_SoFar = nums[0];
	int result = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		max_SoFar = max(nums[i], max_SoFar+ nums[i]);
		result = max(max_SoFar, result);
	}
	return result;
}

int main()
{
	vector<int> temp = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << maxSunArray(temp);
}
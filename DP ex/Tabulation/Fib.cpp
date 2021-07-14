#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	vector<int> arr (n+1,0);

	arr[1] = 1;
	for (int i = 1; i <= n; i++) {
		if(i + 1 <= n)arr[i + 1] += arr[i];
		if(i + 2 <= n)arr[i + 2] += arr[i];
	}
	return arr[n];

}


int main()
{
	cout << fib(6);
}
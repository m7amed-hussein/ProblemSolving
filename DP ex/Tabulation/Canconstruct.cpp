#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordBank;

bool CanConstruct(string target) {
	//create grid
	vector < bool> grid(target.length() + 1, false);

	//Inithialize first in grid
	grid[0] = true;


	//iterate over the grid
	for (int i = 0; i <= target.length(); i++) {
		//substring from the i to the end of the target
		string temp = target.substr(0 , target.length() - i);
		//cheking if the grid[i] is reachable if not do nothing
		if (grid[i]) {
			for (int j = 0; j < wordBank.size(); j++)
			{
				string pref = wordBank[j];
				if (pref <= temp) {
					auto res = mismatch(pref.begin(), pref.end(), temp.begin());
					//check if it is a prefix of the target
					if (res.first == pref.end()) {
						if(i + pref.length()<=target.length())
						grid[i + pref.length()] = true;
					}
				}
			}
		}
	}
	return grid[target.length()];
}


int main()
{
	wordBank = { "purp","P","ur","le","purple" };
	cout << CanConstruct("purple");
}
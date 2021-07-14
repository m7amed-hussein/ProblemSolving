#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> wordBank;
map<string, vector<vector<string>>> memo;

vector<vector<string>> allConstruct(string target) {

	//check for memoization first
	if (memo.find(target) != memo.end()) return memo[target];

	//Data
	vector <vector<string>> temp;

	//Base Case
	if (target == "") {
		temp.push_back({ "0" });
		return temp;
	}

	//reult vector
	vector<vector<string>> Result;

	//iterate over WordBank and call countCounstruct
	for (int i = 0; i < wordBank.size(); i++) {
		string prf = wordBank[i];
		if (wordBank[i].length() > target.length()) continue;

		//check if the wordBank[i] is a prefix of the target of not
		auto res = mismatch(prf.begin(), prf.end(), target.begin());


		//if true if prf is a prefix of the target
		if (res.first == prf.end()) {
			string newtarget = target;
			newtarget.erase(0, prf.length());
			temp = allConstruct(newtarget);
			if (temp.size() > 0) {
				for (int j = 0; j < temp.size(); j++) {
					if (temp[j].back() == "0") {
						temp[j].pop_back();
					}
					temp[j].push_back(wordBank[i]);
					Result.push_back(temp[j]);
				}
				
			}
		}


	}
	memo[target] = Result;
	return Result;

}


int main()
{
	/*wordBank = { "a","p","ent","enter","ot","o","t" };
	auto result =  allConstruct("enterapotentpot");*/

	/*wordBank = { "purp","P","ur","le","purple" };
	auto result = allConstruct("purple");*/

	/*wordBank = { "ab","abc","cd","def","abcd","ef","c"};
	auto result = allConstruct("abcdef");*/

	wordBank = { "e","ee","eee","eeee","eeeee","eeeeeee","eeeeeeeeee" };
	auto result = allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeez");

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << endl;
		}
		cout << endl;
	}
}
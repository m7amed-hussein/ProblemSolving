// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;



    bool isAnagram(string S, string T) {
        int frs[26] = { 0 };
        int frt[26] = { 0 };
        for (int i = 0;i < (int)S.size();i++) {
            if (!islower(S[i]))return false;
            frs[S[i] - 'a']++;
        }
           
        for (int i = 0;i < (int)T.size();i++) {
            if (!islower(T[i]))return false;
            frt[T[i] - 'a']++;
        }
            
        for (int i = 0;i < 26;i++) {
            if (frs[i] > frt[i])return 0;

        }
        return 1;
    }
    string solution(string& S, string& T) {
        // write your code in C++14 (g++ 6.2.0)
        int Sn = S.size();
        string sTemplate = "";
        string maxLex = "";
        for (int i = 0;i <= (int)T.size()-Sn;i++)
        {
            
            sTemplate = T.substr(i, Sn);
            if (isAnagram(S, sTemplate)) {
                if (maxLex == "") maxLex = sTemplate;
                else {
                    maxLex = max(maxLex, sTemplate);
                }
            }
            


        }
            
        return maxLex;

    }



int main()
{
    string s = "abz", t = "ddsj m,abz baz fkl aetsd eatjfteajsdzbalkfj";
    string str = solution(s, t);


    cout << solution(s,t);
}



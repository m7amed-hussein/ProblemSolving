// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;



  
    int reverse(int x) {
        
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = (rev * 10) + pop;
        }
        return rev;


    }



int main()
{
    

    cout<<reverse(2147483641);
}



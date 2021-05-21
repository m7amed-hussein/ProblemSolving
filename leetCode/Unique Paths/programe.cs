using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        private int[,] ways;
        private int x, y;
        public int DP(int m,int n)
        {
            if (m >= x || n >= x) return 0;
            if (m == x - 1 && n == y - 1) return ways[m, n]; 
            ways[m, n] += UniquePaths(m + 1, n) + UniquePaths(m, n + 1);
            return ways[m , n ];
        }
        public int UniquePaths(int m , int n)
        {
            //validation
            if (n <= 0 || m <= 0) return 0;
            ways = new int[m, n];
            Array.Clear(ways,1,ways.Length);
            x = m;
            y = n;
            return DP(0,0);
            

        }
        static void Main(string[] args)
        {
            
            
            
        }
        

    }
}
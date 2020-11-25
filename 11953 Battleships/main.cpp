#include <bits/stdc++.h>

//"#include "boost"

using namespace std;


#define all(v)                ((v).begin()), ((v).end())
#define sz(v)                ((int)((v).size()))
#define clr(v, d)            memset(v, d, sizeof(v))
#define rep(i, v)        for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;

const double EPS = (1e-7);
int dcmp(double x, double y) {    return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;    }

#define pb                    push_back
#define MP                    make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double         ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;



ll t ;
const int MAX  =101;
ll  n = 0 ;
char maze[MAX][MAX];
bool vis[MAX][MAX];

typedef char ch;
void fast()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}


bool isvalid(int r , int c){
    if (r>=0&&c>=0&&r<n&&c<n){
        return 1;
    }
    return 0;
}


int shipcounter = 0;
void cnt(int r, int c){
    if(!isvalid(r , c)||maze[r][c]=='.'||vis[r][c])
        return;
    vis[r][c]= 1;
    cnt(r, c-1);
    cnt(r, c+1);
    cnt(r-1, c);
    cnt(r+1, c);
   
}

void solve(){
    shipcounter = 0;
    lp(i, 101){
        clr(vis[i],0);
    }
    cin>>n;
    lp(i, n){
        lp(j, n){
            cin>>maze[i][j];
            
        }
    }
    
    lp(i, n){
        lp(j, n){
            if(maze[i][j]=='x'&&!vis[i][j]){
                cnt(i, j);
                shipcounter++;
            }
        }
    }



    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //freopen("game.in", "r", stdin);
    
    fast();
    cin>>t;
    lp(i, t)
    {
        solve();
       
            cout<<"Case "<<i + 1<<": "<<shipcounter<<endl;
        
        
        
    }
    
    
  
    return 0;
}

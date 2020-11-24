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
const int MAX  =10;
ll m = 0 , n = 0 ;
char maze[MAX][MAX];
char v[]={'@','I','E','H','O','V','A','#'};
bool vis[MAX][MAX];
vector<string>vstring;
int r , c;

typedef char ch;
void fast()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}


bool isvalid(int r , int c){
    if (r>=0&&c>=0&&r<m&&c<n){
        return 1;
    }
    return 0;
}



int icount = 0;
void cnt(int r, int c,string s){
    if(!isvalid(r , c)||maze[r][c]!=v[icount])
        return;
        if(s.size()>0)
    vstring.pb(s);
    icount++;
    cnt(r, c-1, "left");
    cnt(r, c+1, "right");
    cnt(r-1, c, "forth");
}

void solve(){
    icount = 0;
    cin>>m>>n;
    lp(i, m){
        lp(j, n){
            cin>>maze[i][j];
            if(maze[i][j]=='@'){
                r = i ;
                c = j;
            }
        }
    }
    cnt(r, c, "");



    cout<<vstring[0];
    for(int i = 1;i<vstring.size();i++){
        cout<<" "<<vstring[i];
    }
  
    cout<<endl;
    vstring.clear();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //freopen("game.in", "r", stdin);
    
    fast();
    cin>>t;
    while (t--) {
        solve();
      
        
    }
    
    
  
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
int n,m;
const int MAX_N = 1000,MAX_M = 1000;
char s[MAX_N], t[MAX_M];

int dp[MAX_N+1][MAX_M+1];
void solve(){
    FOR(i,0,n){
        FOR(j,0,m){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            } else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%s",&s);
    scanf("%s",&t);
    solve();
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int n,limit_W;
const int MAX_N = 100, MAX_W = 1000;
int weight[MAX_N], value[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j){
    if (dp[i][j] >= 0){
        return dp[i][j];
    }
    int res;
    if(i==n){
        res = 0;
    }else if (j < weight[i]){
        res = rec(i+1, j);
    }else{
        res = max(rec(i+1, j), rec (i+1, j - weight[i]) + value[i]);
    }
    return dp[i][j] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    printf("%d\n",rec(0,limit_W));
}

int main(){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d %d",&weight[i],&value[i]);
    scanf("%d",&limit_W);
    solve();
}
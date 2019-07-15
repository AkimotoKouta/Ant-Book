#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int n,limit_W;
const int MAX_N = 100, MAX_W = 1000;
int weight[MAX_N], value[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<limit_W;j++){
            if(j < weight[j]){
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i+1][j-weight[i]] + value[i]);
            }
        }
    }
    printf("%d\n",dp[n][limit_W]);
}

int main(){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d %d",&weight[i],&value[i]);
    scanf("%d",&limit_W);
    solve();
}
//部分和問題 P34
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
int n,a[20],k;

bool dfs(int depth, int sum){
    if(depth==n) return sum==k;
    return dfs(depth+1, sum+a[depth]) || dfs(depth+1, sum);
}

void solve(){
    if(dfs(0, 0)) puts("Yes");
    else puts("No");
}
int main(){
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    scanf("%d",&k);
    solve();
}
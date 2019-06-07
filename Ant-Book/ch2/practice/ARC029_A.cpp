#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 4;
int N;
int t[MAX_N];

int dfs(int a, int b, int depth){
    if(depth==N){
        return max(a, b);
    }
    return min(dfs(a+t[depth],b,depth+1),dfs(a,b+t[depth],depth+1));
}

void solve(){
    int ans = dfs(0, 0, 0);
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&N);
    REP(i,N) scanf("%d",&t[i]);
    solve();
}
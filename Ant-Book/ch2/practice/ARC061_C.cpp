/* Many Formulas
   部分和の問題*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

long long int S, n;

long long int dfs(long long int s, int digit, int depth){
    if(depth == n) return s;
    long long int a = s/pow(10,digit+1);
    long long int b = s - a*pow(10,digit+1);
    return dfs(s,digit+1,depth+1) + dfs(a,0,depth+1) + b*pow(2, n-depth-1);
}

void solve(){
    long long int ans = dfs(S, 0, 0);
    printf("%lld",ans);
}

int main(){
    scanf("%lld",&S);
    n = log10(S);
    solve();
}
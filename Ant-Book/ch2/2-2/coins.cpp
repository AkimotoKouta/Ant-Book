#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int c[6], A;
const int V[6] = {1, 5, 10, 50, 100, 500};

void solve(){
    int ans = 0;
    for(int i=5;i>=0;i--){
        int t = min(A / V[i], c[i]);
        A -= t * V[i];
        ans += t;
    }

    printf("%d\n", ans);
}

int main(){
    REP(i, 6) scanf("%d",&c[i]);
    scanf("%d",&A);
    solve();
}
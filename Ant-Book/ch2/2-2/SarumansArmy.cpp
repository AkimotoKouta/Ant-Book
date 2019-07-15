#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
const int MAX_N = 1000;
int N, R;
int X[MAX_N];
void solve(){
    sort(X, X + N);
    int i = 0, ans = 0;
    while(i < N){

        int s = X[i++];
        
        while (i<N && X[i] <= s+R) i++;

        int p = X[i-1];
        while (i<N && X[i] <= p+R) i++;
        ans++;
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d",&N);
    scanf("%d",&R);
    FOR(i,0,N) scanf("%d",&X[i]);
    solve();
}
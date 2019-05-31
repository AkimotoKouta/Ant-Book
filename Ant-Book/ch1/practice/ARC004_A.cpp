// https://atcoder.jp/contests/arc004/tasks/arc004_1

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int N,x[100],y[100];
void solve(){
    double maxL = 0;
    FOR(i,0,N){
        FOR(j,i+1,N){
            maxL = max(maxL, sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)));
        }
    }
    printf("%f",maxL);
}
int main(){
    scanf("%d",&N);
    REP(i,N) scanf("%d %d",&x[i], &y[i]);
    solve();
}
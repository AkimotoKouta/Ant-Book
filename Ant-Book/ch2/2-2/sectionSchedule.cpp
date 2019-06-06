#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 100000;
int n;
int s[MAX_N],t[MAX_N];
pair<int,int> itv[MAX_N];

void solve(){
    REP(i,n){
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv+n);
    int ans = 0, t= 0;
    REP(i,n){
        if(t<itv[i].second){
            t = itv[i].first;
            ans++;
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&n);
    REP(i,n) scanf("%d",&s[i]);
    REP(i,n) scanf("%d",&t[i]);
    solve();
}
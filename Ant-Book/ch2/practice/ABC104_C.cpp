#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_D = 10;
int D, G;
int p[MAX_D], c[MAX_D];

int dfs(int nokori, int num, int depth, int max_i){
    if(depth==D){
        if(nokori <= 0){
            return num;
        }else if(nokori > p[max_i]*100*(max_i+1)){
            return 1000;
        }else{
            return num + (nokori+100*(max_i+1)-1)/(100*(max_i+1));
        }
    }
    return min(dfs(nokori - p[depth]*100*(depth+1)-c[depth],num + p[depth],depth+1,max_i),
               dfs(nokori,num,depth+1,depth));
}

void solve(){
    int ans = dfs(G, 0, 0, 0);
    printf("%d",ans);
}

int main(){
    scanf("%d",&D);
    scanf("%d",&G);
    REP(i,D) scanf("%d %d",&p[i], &c[i]);
    solve();
}
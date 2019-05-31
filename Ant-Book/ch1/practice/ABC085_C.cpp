#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int N, Y;

void solve(){
   REP(man,N+1){
       REP(gosen,N+1-man){
           int nokori = Y-man*10000-gosen*5000;
           if(nokori%1000==0 && nokori/1000==N-man-gosen){
               printf("%d %d %d",man, gosen, nokori/1000);
               return;
           }
       }
   }
    printf("-1 -1 -1");
    return ;
}

int main(){
    scanf("%d",&N);
    scanf("%d",&Y);
    solve();
}
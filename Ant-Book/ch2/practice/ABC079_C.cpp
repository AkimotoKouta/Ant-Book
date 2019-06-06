#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int Num[4];
char op[3];
void solve(){
    for (int bit = 0; bit < (1 << 3); bit++){
        int sum = Num[0];
        for (int i = 0; i < 3; i++){
            if(bit & (1<<i)){
                op[i] = '+';
                sum += Num[i+1];
            }else{
                op[i] = '-';
                sum -= Num[i+1];
            }
        }
        if(sum==7){
            break;
        }
    }
    printf("%d%c%d%c%d%c%d=7",Num[0],op[0],Num[1],op[1],Num[2],op[2],Num[3]);
}

int main(){
    int S;
    scanf("%d",&S);
    Num[0] = S/1000;
    Num[1] = S%1000/100;
    Num[2] = S%100/10;
    Num[3] = S%10;
    solve();
}
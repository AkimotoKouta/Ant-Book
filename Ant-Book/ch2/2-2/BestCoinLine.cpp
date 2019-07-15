#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
const int MAX_N = 2000;
int N;
char S[MAX_N + 1];
void solve(){
    int a = 0, b = N - 1;

    while(a <= b){
        bool left = false;
        for(int i = 0;a + i <= b; i++){
            if(S[a + i] < S[b - i]){
                left = true;
                break;
            }
            else if (S[a + i] > S[b - i]){
                left = false;
                break;
            }
            //もし同じ文字だったら，次の文字を見る．
        }
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
}

int main(){
    scanf("%d",&N);
    scanf("%s",&S);
    solve();
}
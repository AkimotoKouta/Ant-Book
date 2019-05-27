#include <bits/stdc++.h>
using namespace std;

int L,n,x[1000000];

void solve(){
    int minT = 0;
    int maxT = 0;
    for(int i=0;i<n;i++){
        minT = max(minT, min(L-x[i],x[i]));
        maxT = max(maxT, max(L-x[i],x[i]));
    }
    printf("%d %d\n", minT, maxT);
}

int main(){
    scanf("%d",&L);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    solve();
}

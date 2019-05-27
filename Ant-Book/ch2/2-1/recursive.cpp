#include <bits/stdc++.h>
using namespace std;
int n;
int fact(int x){
    if(x==0){
        return 1;
    }
    return fact(x-1) * x;
}
int main(){
    scanf("%d",&n);
    int ans = fact(n);
    printf("%d",ans);
}

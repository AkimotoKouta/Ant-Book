#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 10000;
int heap[MAX_N], size = 0;

void push(int x){
    //自分のノード番号
    int index = size++;

    while(index > 0){
        //親のノード番号
        int parent = (index - 1) / 2;
        //親の方が小さいなら，終了
        if(heap[parent]<=x) break;
        //自分のノード番号の所に親の値を入れ，自分のノード番号は親のノード番号へ
        heap[index] = heap[parent];
        index = parent;
    }
    //最終的な自分の場所に値を入れる．
    heap[index] = x;
}

int pop(){
    //最小値
    int min = heap[0];
    //最後尾のノードの値
    int x = heap[--size];

    //根からスタート
    int index = 0;
    while(index*2+1<size){
        //今いる節の，子のノード番号
        int a = index * 2 + 1, b = index * 2 + 2;
        //子のノードのうち小さい方が親より小さかったら交換
        if(b<size && heap[b] < heap[a]) a = b;

        if(heap[a] >= x) break;

        heap[index] = heap[a];
        index = a;
    }
    //最後尾だったノードの値が根からあるべき場所へ移動させる
    heap[index] = x;

    return min;
}

int main(){
    push(5);
    push(1);
    push(6);
    push(3);
    printf("%d",pop());
    printf("%d",pop());
    printf("%d",pop());
    printf("%d",pop());
}
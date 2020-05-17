#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int tab[2][505][505];
const int MAX=500;
int main(){
    int now=0,pre=1;
    FOR1(i,33){
    FOR(j,i+1){
int a=j,b=i-j;
    FOR(k,MAX+1){
    FOR(l,MAX+1){
        tab[now][k][l]=tab[pre][k][l];
        if(k-a>=0&&l-b>=0)tab[now][k][l]=max(tab[now][k][l],tab[pre][k-a][l-b]+1);
    }
    }
    swap(now,pre);
    }
    }

    int q;
    cin>>q;
    while(q--){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",tab[pre][a][b]);
    }
}

//33*32/2

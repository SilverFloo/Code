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
int tab[1005];
int n;
void in(int i){
    if(i==n)return;
    scanf("%d",&tab[i]);
    in(i+1);
}
void sort2(int ed,int i){
    if(i==ed)return;
    if(tab[i-1]>tab[i])swap(tab[i],tab[i-1]);
    sort2(ed,i-1);
}
void sort1(int i){
    if(i==n)return;
    sort2(i,n-1);
    sort1(i+1);
}
void print(int i){
    if(i==n)return;
    printf("%d\n",tab[i]);
    print(i+1);
}
int main(){
    cin>>n;
    in(0);
    sort1(0);
    print(0);
}

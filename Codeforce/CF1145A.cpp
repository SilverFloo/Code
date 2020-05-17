#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
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
int tab[20];
int ans=1;
void search(int st,int ed){
  //  printf("%d %d/",st,ed);
    if(ed<=st)return;
    int ch=0;
    for(int i=st+1;i<=ed;i++){
        if(tab[i]<tab[i-1])ch=1;
    }
    if(ch==0)ans=max(ed-st+1,ans);
    int m=(st+ed)/2;
    search(st,m);
    search(m+1,ed);
}
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d",&tab[i]);
    search(0,n-1);
    printf("%d",ans);
}

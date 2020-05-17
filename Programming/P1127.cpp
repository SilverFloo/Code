#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
int main(){
    int n;
    cin>>n;
    int tab[9];
    vector<int> q;
    FOR(i,0,9){
    scanf("%d",&tab[i]);
    }
    while(1){
        int a;
        int mx=0;
        FOR(i,0,9)if(n/tab[i]>=mx){mx=n/tab[i];a=i;}
        if(mx==0)break;
        n-=tab[a];
        q.pb(a+1);
       // printf("%d %d\n",a,n);
    }
    sort(all(q),greater<int>());
    for(auto i:q)printf("%d",i);
}

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
int tab[3005];
int main(){
    int n;int cnt=0;
    cin>>n;
    FOR(i,n)scanf("%d",&tab[i]);
    FOR(i,n){
    int mn=INF,mx=-1;
        for(int j=i;j<n;j++){

            mn=min(mn,tab[j]);
            mx=max(mx,tab[j]);
            //printf("%d %d %d %d\n",i,j,mx,mn);
            if(mx-mn==j-i){cnt++;}
        }
    }
    printf("%d",cnt);
}

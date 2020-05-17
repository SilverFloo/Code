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
int tab[1000006],s[1000006];

int main(){
    int n,k,p;
    cin>>n>>k>>p;
    FOR(i,n)scanf("%d",&tab[i]),s[i]=tab[i];
    sort(s,s+n);
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r)/2;
        int ed=0;
        int cnt=0;
        FOR(i,n){
            if(tab[i]>s[m]){
                cnt++;i+=p-1;
                if(cnt>k)break;
            }
        }
         if(cnt>k)l=m+1;
            else r=m;
    } printf("%d",s[r]);
}

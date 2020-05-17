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
int main(){
    int n,k;
    cin>>n>>k;
    int l=1,r=n;
    string s;
    int ans=-1;
    cin>>s;
    while(l<=r){
        map<string,int> M;
        int m=(l+r)/2;
        int mx=-1;
        for(int i=0;i<=n-m;i++){
            mx=max(++M[s.substr(i,m)],mx);
        }
        //printf("%d ",mx);
        if(mx>=k)ans=m,l=m+1;
        else r=m-1;
    }
    printf("%d",ans);
}

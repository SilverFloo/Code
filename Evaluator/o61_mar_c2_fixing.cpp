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
    int n,m,k;
    cin>>n>>m>>k;
    int bf;
    cin>>bf;
    vector<int> tab;
    FOR(i,m-1){
        int x;
        scanf("%d",&x);
        tab.pb(x-bf-1);
        bf=x;
    }
    sort(all(tab),greater<int>());
    int ans=0;
    int cnt=0;
    for(auto a:tab){
        cnt++;
        if(cnt>=k)ans+=a;
    }
    printf("%d",ans);
}

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
int cr[100005];
int main(){
    int n,w,p;
    cin>>n>>w>>p;p*=2;
    FOR(i,n){
        scanf("%d",&cr[i]);
    }
    sort(cr,cr+n);
    int l=0,r=w;
    while(l<=r){
         deque<int> q;
         int m=(l+r)/2;
         int cnt=0;
         FOR(i,p)q.pb(0);
         int ch=1;
         FOR(i,n){
            if(cr[i]-q.front()<=m){
            cnt++;
            q.pop_front();
            q.pb(cr[i]);
            }
            else {ch=0;break;}
         }
         if(ch){
            FOR(i,p)if(w-q.front()>m){ch=0;break;}
         }
         if(ch){r=m-1;}
         else l=m+1;
    }
    printf("%lld",(ll)l*l);
}

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
int tab[(int)1e5+5];
int ans[(int)1e5+5];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        FOR(i,n)scanf("%d",&tab[i]);
        deque<int> q;
        FOR(i,n){
        while(!q.empty()&&tab[q.back()]<=tab[i])q.pop_back();
        q.push_back(i);
        }
        FOR(i,n){
        while(!q.empty()&&tab[q.back()]<=tab[i])q.pop_back();

        if(q.empty()){ans[i]=0;}
        else ans[i]=i-q.back();
        if(ans[i]<=0)ans[i]+=n;
        //printf("%d ",ans[i]);
        q.push_back(i);
        }

        while(!q.empty())q.pop_back();
        for(int i=n-1;i>=0;i--){
        while(!q.empty()&&tab[q.back()]<=tab[i])q.pop_back();
        q.push_back(i);
        }
         for(int i=n-1;i>=0;i--){
        while(!q.empty()&&tab[q.back()]<=tab[i])q.pop_back();
        int l;
        if(q.empty())l=n;
        else l=q.back()-i;
        if(l<=0)l+=n;
        ans[i]=min(l,ans[i]);
        //printf("<%d>%d ",q.back(),l);
        q.push_back(i);
        }

        FOR(i,n)printf("%d ",ans[i]-1>(n-1)>>1?(n-1)>>1:ans[i]-1);printf("\n");
    }
}

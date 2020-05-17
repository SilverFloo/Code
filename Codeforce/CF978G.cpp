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
vector<int> s[105];
int day[105];
int e[105];
int ans[105];
int main(){
    int d,n;
    cin>>d>>n;
    FOR(i,n){
        int a;
        cin>>a>>e[i]>>day[i];
        s[a].pb(i);
        ans[e[i]]=n+1;
    }
    priority_queue<ii,vector<ii>,greater<ii>> q;
    FOR1(i,d){
        for(auto j:s[i])q.p(e[j],j);
        if(ans[i]==0){
            if(q.empty())continue;

//                printf("%d %d %d\n",i,q.top().f,day[q.top().s]);
            if(q.top().f<i){printf("-1");return 0;}
            ans[i]=q.top().s+1;
            if(--day[q.top().s]==0)q.pop();
        }
    }//printf("aaa");
    if(!q.empty()){printf("-1");return 0;}
    FOR1(i,d)printf("%d ",ans[i]);
}

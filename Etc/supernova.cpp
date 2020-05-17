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
vector<int> e[100005];
int deg[100005];
int ch[100005];
ll ans[100005];
ii path[100005];
int main(){
	int n,m;
	cin>>n>>m;
	FOR(i,m){
		int a,b;
		scanf("%d %d",&a,&b);
		deg[a]++;deg[b]++;
		e[a].pb(b);
		e[b].pb(a);
		path[i].f=a;
		path[i].s=b;
	}
	queue<int> q;
	FOR1(i,n){if(deg[i]==1)q.p(i);}
	while(!q.empty()){

			ch[q.front()]++;
		for(auto i:e[q.front()]){

			if(deg[i]>1)ch[i]+=ch[q.front()];
			deg[i]--;
			if(deg[i]==1)q.p(i);
		}
		ans[q.front()]=(ll)ch[q.front()]*(n-ch[q.front()]);
   // printf("%d %lld -> ",q.front(),ans[q.front()]);
		q.pop();
	}
	FOR(i,m){
	   // printf("<%lld %lld %d %d>",ans[path[i].f],ans[path[i].s],ch[path[i].f],ch[path[i].s]);
	if(deg[path[i].f]>1&&deg[path[i].s]>1){
	printf("0 ");
	}
    else if(deg[path[i].f]>1)printf("%lld ",ans[path[i].s]);
    else if(deg[path[i].s]>1)printf("%lld ",ans[path[i].f]);
	else if(ch[path[i].f]<ch[path[i].s]) printf("%lld ",ans[path[i].f]);
	else printf("%lld ",ans[path[i].s]);
	}
}

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
const int MAX=262144;
int t[MAX<<1];
void update(int x,int v,int p,int l,int r){
    if(l==r){
    t[p]=v;
    return;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,p<<1,l,m);
    else update(x,v,(p<<1)|1,m+1,r);
    t[p]=max(t[p<<1],t[(p<<1)|1]);
}
int query(int x,int y,int p,int l,int r){
    if(x<=l&&y>=r)return t[p];
    else if(y<l||x>r)return -INF;
    int m=(l+r)/2;
    return max(query(x,y,p<<1,l,m),query(x,y,(p<<1)|1,m+1,r));
}
int main(){
    int n,q;
	scanf("%d %d",&n,&q);
	while(q--){
		int a,b;
		char c;
		scanf(" %c %d %d",&c,&a,&b);
		if(c=='U'){
		update(a,b,1,1,n);
		}
		else{
		printf("%d\n",query(a,b,1,1,n));
		}
	}
}

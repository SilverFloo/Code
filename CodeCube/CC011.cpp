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
const int MAX=1005;
bool tab[MAX][MAX];
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	FOR(i,n)FOR(j,m)scanf("%d",&tab[i][j]);
	int y=0;

	int cnt=0;
	for(int i=n-1;i>=0;i--){
        int x=0;
        deque<int> q;
	FOR(j,m){
	if(!tab[i][j]){x++;q.push_back(j);}
	if(!q.empty()&&q.front()<=j-k)q.pop_front();
	if(y+q.size()>=k){printf("%d",i+1);return 0;}
	}
	y+=x;
	}
}
/*

3 5 3
1 1 1 0 1
0 1 1 1 0
0 1 1 1 1

*/

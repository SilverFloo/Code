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
char tab[205][205];
bool visit[205][205][130][6];
typedef struct state{
int i,j,st,num,gem,l;
state(int i,int j,int st,int gem,int num,int l):i(i),j(j),st(st),gem(gem),num(num),l(l){}
}state;
queue<state> q;
map<ii,int> M;
int n,m;
void add(state a){
if(!visit[a.i][a.j][a.st][a.num]){
	visit[a.i][a.j][a.st][a.num]=1;
	q.p(a);
}
}
void check(int i,int j,state a){
	if(i<0||j<0||i==n||j==m)return;
	a.i=i;
	a.j=j;
	a.num++;
	a.num%=6;
	a.l++;
	if(tab[i][j]=='.'||tab[i][j]=='S'){
			//printf("IN");
		add(a);
	}
	else if(tab[i][j]=='G'){
		if((a.st&(1<<M[mp(i,j)]))==0){
				a.gem++;
				a.st|=1<<M[mp(i,j)];
			if(a.gem==7){
				printf("%d",a.l);
				exit(0);
			}
			else add(a);
		}
		else add(a);
	}
	else if(tab[i][j]!='#'){
		if(tab[i][j]-'0'<=a.gem||tab[i][j]-'0'==a.num+1)add(a);
	}
}
main(){
	cin>>n>>m;
	int c=0;
	FOR(i,n){
	FOR(j,m){
	scanf(" %c",&tab[i][j]);
	if(tab[i][j]=='G')M[mp(i,j)]=c++;
	if(tab[i][j]=='S')q.p(i,j,0,0,0,0);
	}
	}
	while(!q.empty()){
		state a=q.front();
	   // printf("%d %d %d %d\n",a.i,a.j,a.st,a.num);
		check(a.i,a.j,a);
		check(a.i,a.j-1,a);
		check(a.i,a.j+1,a);
		check(a.i+1,a.j,a);
		check(a.i-1,a.j,a);
		q.pop();
	}
	printf("-1");
}

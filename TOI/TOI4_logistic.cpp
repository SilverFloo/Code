#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
//#define p emplace
using namespace std;
const int INF=1e9;
int p[27];vector<int> l[27];
float sum=0;
float find(int a){
sort(all(l[a]));
if(l[a].size()%2==0)return (float)(l[a][l[a].size()/2-1]+l[a][l[a].size()/2])/2;
else return l[a][l[a].size()/2];
}

void  go(int a){
if(a==27)return;
int b=p[a];
if(a==0)printf("X ");
else printf("%c ",a+'a'-1);
if(b==27)printf("Y ");
else printf("%c ",b+'a'-1);
sum+=find(a);
printf("%.1f\n",find(a));
go(b);
}

bool ch(int n){
   // printf("->%d ",n);
    if(p[n]==0)return 0;
    if(p[n]==27)return 1;
return ch(p[n]);
}
int main(){
int n;
cin>>n;

FOR(i,n){

char a,b;int c;
scanf(" %c %c %d",&a,&b,&c);
if(islower(a)){a-='a'-1;}
else if(a=='X')a=0;
else a=27;

if(islower(b)){b-='a'-1;}
else if(b=='X')b=0;
else b=27;

if(a>b)swap(a,b);
p[a]=b;
l[a].pb(c);
}

FOR(i,27)printf("%d ",p[i]);
if(!ch(0)){printf("broken");exit(0);}

//printf("dsfsdfsd");
go(0);
printf("%.1f",sum);
}

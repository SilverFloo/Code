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
int tab[100005];
int main(){
int n;
cin>>n;
queue<int> q;
FOR(i,n){
char c;
scanf(" %c",&c);
if(c=='B'||c=='W')q.p(i);
if(c=='B')tab[i]=1;
else if(c=='W')tab[i]=2;
}
if(q.empty())q.p(0),tab[0]=1;
while(!q.empty()){
int i=q.front();
q.pop();
int ch;
if(tab[i]==1)ch=2;
else ch=1;
//printf("/%d %d/",i,ch);
if(i>0){
if(tab[i-1]!=tab[i]){if(tab[i-1]==0){tab[i-1]=ch;q.p(i-1);}}
else tab[i-1]=3;}
if(i<n-1){
if(tab[i+1]!=tab[i]){if(tab[i+1]==0){tab[i+1]=ch;q.p(i+1);}}
else tab[i+1]=3;
}

}
FOR(i,n){
if(tab[i]==1)printf("B");
else if(tab[i]==2)printf("W");
else printf("G");
}
}

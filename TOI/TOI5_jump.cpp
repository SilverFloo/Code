#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
int main(){
int n,k;
cin>>n>>k;
deque<int> q;
int tab[n];
FOR(i,n)scanf("%d",&tab[i]);
int f=0,s=0;
int mx=0;
FOR(i,n){
if(q.empty()&&f<n-1){q.push_back(f);f++;}
while(f<n&&tab[f]<=tab[q.front()]+k){q.push_back(f);f++;}
q.pop_front();
if(mx<q.size())mx=q.size();//printf("%d/",mx);
}
printf("%d",mx);
}

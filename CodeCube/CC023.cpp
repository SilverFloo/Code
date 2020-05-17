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
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    int cnt=0;
    cin>>a>>b;
    auto p=a.find(b);
    while(p!=-1){
       // printf("%d>",p);
    cnt++;
    p=a.find(b,p+1);
    }
    printf("%d",cnt);
}

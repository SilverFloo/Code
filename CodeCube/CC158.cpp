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
bool prime[1005];
int main(){
    prime[0]=prime[1]=1;
    for(int i=2;i<1005;i++){
    if(!prime[i]){
    for(int j=i+i;j<1005;j+=i){
    prime[j]=1;
    }
    }
    }
    int cnt=0;
    int a,b;
    cin>>a>>b;
    for(int i=ceil(sqrt(a));i<=sqrt(b);i++){
    if(!prime[i])printf("%d ",i*i),cnt++;
    }
    if(cnt==0)printf("-1");
}

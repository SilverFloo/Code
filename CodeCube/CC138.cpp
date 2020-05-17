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
int cnt[5000];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    int x;
    scanf("%d",&x);
    cnt[x]++;
    }
    for(int i=0;i<=2017;i++){
    if(cnt[2017-i]==1){printf("%d",2017-i);return 0;}
    if(cnt[2017+i]==1){printf("%d",2017+i);return 0;}
    }
    printf("-1");
}

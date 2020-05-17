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
int a[(int)1e5+5],b[(int)1e5+5];
int main(){
    int t;
    cin>>t;
    while(t--){
    deque<int> q;
    int n;cin>>n;
    int cnt=0;
    FOR(i,n)scanf("%d",&a[i]);
    FOR(i,n)scanf("%d",&b[i]);
    FOR(i,n){
        while(!q.empty()&&q.back()<b[i])q.pop_back();
        if(a[i]^b[i])if(q.empty()||q.back()!=b[i]){cnt++;q.push_back(b[i]);}
    }
    printf("%d\n",cnt);
    }
}

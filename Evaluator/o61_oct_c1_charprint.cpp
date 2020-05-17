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
queue<int> pos[26];
const int MAX=300005;
int t[MAX];
void update(int p,int v){
    for(int i=p;i<MAX;i+=i&-i){
        t[i]+=v;
    }
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
 char a[300005],b[100005];
int main(){
    int st,m,n;
    cin>>st;

    scanf(" %s %s",a,b);
    int l1=strlen(a),l2=strlen(b);
    FOR1(i,l1)update(i,1);
    FOR(i,l1){
        char c=a[i];
        pos[a[i]-'a'].p(i+1);
    }
    ll ans=0;
    FOR(i,l2){
        if(pos[b[i]-'a'].empty()){printf("-1");return 0;}
        ans+=(ll)query(pos[b[i]-'a'].front());
        if(st)update(pos[b[i]-'a'].front(),-1);
        pos[b[i]-'a'].pop();
    }
    printf("%lld",ans);
}
/*
    idea : use fenwick tree

    13 min 0%
        add case -1
    15 min 10%
        fix strlen in loop condition make program very slow
    25 min 10%
        change ans to long long
    30 min 100%
*/

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
bool ans[(int)1e5+5];
int main(){
    int n,k;
    cin>>k;
    vector<ii> v;
    FOR1(i,n){
    int a,b;
    scanf("%d %d",&a,&b);
    v.pb(a,i);
    v.pb(b,-i);
    }
    sort(all(b));
    int cnt=0;
    for(auto i:v){
    if(i.s>0){
    if(cnt<k){
    cnt++;
    ans[i.s]=1;
    }
    }
    else{
    if(ans[-i.s]){
    cnt--;
    }
    }

    }
FOR1(i,n)printf("%s\n",ans[i]?"yes":"no");
}

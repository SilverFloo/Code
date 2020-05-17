#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
ii tab[100005];
int main(){
    //rf();
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        FOR(i,n){
            scanf("%d %d",&tab[i].f,&tab[i].s);
        }
        sort(tab,tab+n);
        deque<int> mn,mx;
        int ans=INF+5;
        FOR(i,n){
            while(!mx.empty()&&tab[mx.back()].s<tab[i].s)mx.pop_back();
            while(!mn.empty()&&tab[mn.back()].s>tab[i].s)mn.pop_back();
            while(!mn.empty()&&tab[i].s-tab[mn.front()].s>=k){ans=min(ans,tab[i].f-tab[mn.front()].f);mn.pop_front();}
            mx.pb(i);
            while(!mx.empty()&&tab[mx.front()].s-tab[i].s>=k){ans=min(ans,tab[i].f-tab[mx.front()].f);mx.pop_front();}
            mn.pb(i);
        }
        printf("%d\n",ans==INF+5?-1:ans);
    }
}

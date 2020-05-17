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
int val[120005];
int tab[120005];
vector<int> c[120005];
vector<int> s[120005];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int mx=0;
    FOR1(i,m){
        int x;
        scanf("%d",&x);
        mx=max(mx,x);
        while(x--){
            int a;
            scanf("%d",&a);
            c[i].pb(a);
            s[a].pb(i);
        }
    }

    if(mx<=5||(q<=1000&&m<=1000&&n<=1000)){
    while(q--){
        int a;
        scanf("%d",&a);
        if(a==1){
        int b,x;
        scanf("%d %d",&b,&x);
            for(auto i:c[b])val[i]+=x-tab[b];
            tab[b]=x;
        }
        else{
            int b;
            scanf("%d",&b);
            printf("%d\n",val[b]);
        }
    }
    return 0;
    }


    while(q--){
        int a;
        scanf("%d",&a);
        if(a==1){
        int b,x;
        scanf("%d %d",&b,&x);
            tab[b]=x;
        }
        else{
            int b;
            int ans=0;
            scanf("%d",&b);
            for(auto i:s[b]){
                ans+=tab[i];
            }
            printf("%d\n",ans);
        }
    }

}

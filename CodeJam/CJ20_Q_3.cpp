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
pair<ii,int> tab[1005];
int ans[1005];
int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        int n;
        cin>>n;
        FOR(i,n){scanf("%d %d",&tab[i].f.f,&tab[i].f.s);tab[i].s=i;}
        sort(tab,tab+n);
        int a=0,b=0;
        int x=0;
        FOR(i,n){
            if(tab[i].f.f>=a){
                a=tab[i].f.s;
                ans[tab[i].s]=0;
            }
            else if(tab[i].f.f>=b){
                b=tab[i].f.s;
                ans[tab[i].s]=1;
            }
            else{
                x=1;break;
            }
        }
        printf("Case #%d: ",k);
        if(x==1){printf("IMPOSSIBLE\n");}
        else{
            FOR(i,n)printf("%c",ans[i]?'C':'J');
            cout<<endl;
        }
    }
}

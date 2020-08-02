#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_bajck
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
ii tab[100005];
bool cmp(ii a,ii b){
    return a.s<b.s;
}
int main(){
    // rf();
    // pf();
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w+",stdout);
    int n;
    cin>>n;
    stack<ii> t;
    stack<ii> tmp;
    FOR(i,n){
        scanf("%d %d",&tab[i].f,&tab[i].s);
    }
    int cnt = 0;
    int ans = 0;
    sort(tab,tab+n,cmp);
    t.p(tab[0].f,0);//printf("%d %d\n",tab[0].f,tab[0].s);
    FOR1(i,n-1){
        //printf("<%d>\n",tab[i].s-tab[i-1].s);
        while(!t.empty()&&tab[i].s-tab[t.top().s].s>t.top().f){
            t.pop();
        }
        
        
        if(t.empty()){
            while(!tmp.empty()){tmp.pop();}
        }
        else{
            tmp.p(tab[i].s-tab[i-1].s,t.top().s);
            while(!tmp.empty()&&tab[i].s-tab[tmp.top().s].s<=tab[i].f){
                //printf("<+%d %d>\n",tmp.top().f,tmp.top().s);
                ans+=tmp.top().f;
                int x = tmp.top().s;
                tmp.pop();
                if(!tmp.empty())tmp.top().s = min(tmp.top().s,x);
                while(!tmp.empty()&&tab[i].s-tab[tmp.top().s].s>tab[tmp.top().s].f){
                    tmp.top().s = tmp.top().s-1;
                    if(tmp.top().s==-1)break;
                }
                if(!tmp.empty()&&tmp.top().s==-1){
                    while(!tmp.empty()){tmp.pop();}
                }


            }

        }
        t.p(tab[i].f,i);
        //printf("(%d)\n%d %d\n",tab[i].s-tab[i-1].s,tab[i].f,tab[i].s);
        //printf("<%d>",cnt);
        //printf("<%d>\n",ans);
    }
    printf("%d",ans);
}
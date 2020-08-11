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
int st[150005];
ii ans[150005];
ii nx[150005];
int n,m;
int cmp(pair<float,ii> a, pair<float,ii> b){
    if(a.f==b.f)return a.s>b.s;
    return a.f<b.f;
}
set<pair<float,ii>,decltype(cmp)*> s(cmp);
float dist(int x,int y){
    ii a,b;
    a.f = x;
    a.s = st[x];
    b.f = y;
    b.s = st[y];
    
    if(a.f==0&&b.f==n+1){
        return 0;
    }
    if(b.f-a.f==1&&a.s==3)return -1;
    else if(b.f-a.f==1)return 1;
    if(a.f==0){
        if(b.s == 3)return b.f-1;
        else return b.f-0.5;
    }
    if(b.f==n+1){
        if(a.s == 3)return b.f-a.f-1;
        else return b.f-a.f-0.5;
    }
    if((b.f-a.f)%2==1){
        if(a.s==3&&b.s==3){
            return (b.f-a.f)/2;
        }
        else return (b.f-a.f)/2+0.5;
    }
    else {
        if(a.s!=3&&a.s==b.s){
            return (b.f-a.f)/2+0.5;
        }
        else return (b.f-a.f)/2;
    }
}
ii get(int x,int y){
    ii a,b;
    a.f = x;
    a.s = st[x];
    b.f = y;
    b.s = st[y];
    if(a.f==0&&b.f==n+1){
        return {1,1};
    }
    if(b.f-a.f==1&&a.s!=3){
        return {a.f,a.s==2?1:2};
    }
    if(a.f==0){
        if(b.s == 3)return {1,1};
        else return {1,b.s==1?2:1};
    }
    if(b.f==n+1){
        if(a.s == 3)return {n,1};
        else return {n,a.s==1?2:1};
    }
    if(b.f-a.f==2&&a.s!=3&&a.s!=b.s){
        return {a.f,a.s==2?1:2};
    }
    if((b.f-a.f)%2==1){
        if(a.s==3&&b.s==3){
            return {(a.f+b.f)/2,1};
        }
        else if(a.s==3){
            return {(a.f+b.f)/2+1,b.s==1?2:1};
        }
        else return {(a.f+b.f)/2,a.s==1?2:1};
    }
    else {
        if(a.s!=3&&a.s==b.s){
            return {(a.f+b.f)/2,a.s==1?2:1};
        }
        else return {(b.f+a.f)/2,1};
    }
}
int main(){
//  rf();
//  pf();
    cin>>n>>m;
    s.emplace(dist(0,n+1),mp(0,n+1));
    nx[0]={-1,n+1};
    nx[n+1]={0,-1};
    st[0]=3;
    st[n+1]=3;
    FOR1(i,m){
        char c;
        cin>>c;
        if(c == 'E'){
            auto x = *s.rbegin();
            auto y = get(x.s.f,x.s.s); 
            //printf("%d <%.1f|[%d %d] [%d %d]>",i,x.f,x.s.f,st[x.s.f],x.s.s,st[x.s.s]);
            printf("%d %d\n",y.f,y.s);
            s.erase(*s.rbegin());
            if(st[y.f]==0)st[y.f] = y.s;
            else st[y.f]=3;
            s.emplace(dist(x.s.f,y.f),mp(x.s.f,y.f));
            s.emplace(dist(y.f,x.s.s),mp(y.f,x.s.s));
            ans[i] = y;
            if(x.s.f!=y.f){  
                nx[x.s.f].s=y.f;
                nx[y.f]=x.s;
                nx[x.s.s].f=y.f;
            }
        }
        else{
            int x; 
            scanf("%d",&x);
            int now = ans[x].f;
            int bf = nx[now].f;
            int nxt = nx[now].s;
            
            s.erase(mp(dist(bf,now),mp(bf,now)));
            s.erase(mp(dist(now,nxt),mp(now,nxt)));
            
           // printf("Erase [%d %d] ",ans[x].f,ans[x].s);
            if(st[now]==3)st[now]=ans[x].s==1?2:1;
            else st[now]=0; 
            if(st[now]==0){
                //printf("add[%d %d/%d %d]\n",bf,st[bf],nxt,st[nxt]);
                s.emplace(dist(bf,nxt),mp(bf,nxt));
                nx[bf].s=nxt;
                nx[nxt].f=bf;
                nx[now]={0,0};
            }
            else{
                //printf("add[%d %d/%d %d] [%d %d/%d %d]\n",bf,st[bf],now,st[now],now,st[now],nxt,st[nxt]);
                s.emplace(dist(bf,now),mp(bf,now));
                s.emplace(dist(now,nxt),mp(now,nxt));
            }
        }
    }
}
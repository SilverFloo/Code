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
using namespace std;
const int INF=1e9;
bool visit[31][31][31][31];
bool tab[31][31];
typedef struct e{
    ii a,b;
    int l;
    e(ii a,ii b,int l):a(a),b(b),l(l){}
}e;
int main(){
   int n,m;
   cin>>m>>n;
   ii sa,sb;
   FOR(i,n){
        FOR(j,m){
            char a;
            scanf(" %c",&a);
            switch(a){
                case 'A': sa.f=i;sa.s=j;break;
                case 'B': sb.f=i;sb.s=j;break;
                case '#': tab[i][j]=1;break;
            }
        }
   }
   visit[sa.f][sa.s][sb.f][sb.s]=1;
   queue<e> q;
   int ans=-1;
   int ans2=-1;
   q.p(sa,sb,0);
   while(!q.empty()){
        ii a=q.front().a;
        ii b=q.front().b;
        int l=q.front().l;
        q.pop();
       // printf("%d %d %d %d\n",a.f,a.s,b.f,b.s);
        if(a==b){printf("0 %d",l);return 0;}
        if(abs((a.f-b.f)+(a.s-b.s))==1&&ans==-1){ans=l;}
        if(abs(a.f-b.f)==1&&abs(a.s-b.s)==1&&!tab[a.f][b.s]&&!tab[b.f][a.s]&&ans2==-1){ans2=l;}
        ii ta=a,tb=b;
        if(a.f-1>=0&&!tab[a.f-1][a.s])ta.f=a.f-1;
        if(b.f+1<n&&!tab[b.f+1][b.s])tb.f=b.f+1;
        if(!visit[ta.f][ta.s][tb.f][tb.s]){
            q.p(ta,tb,l+1);
            visit[ta.f][ta.s][tb.f][tb.s]=1;
        }

        ta=a,tb=b;
        if(a.f+1<n&&!tab[a.f+1][a.s])ta.f=a.f+1;
        if(b.f-1>=0&&!tab[b.f-1][b.s])tb.f=b.f-1;
        if(!visit[ta.f][ta.s][tb.f][tb.s]){
            q.p(ta,tb,l+1);
            visit[ta.f][ta.s][tb.f][tb.s]=1;
        }

        ta=a,tb=b;
        if(a.s-1>=0&&!tab[a.f][a.s-1])ta.s=a.s-1;
        if(b.s+1<m&&!tab[b.f][b.s+1])tb.s=b.s+1;
        if(!visit[ta.f][ta.s][tb.f][tb.s]){
            q.p(ta,tb,l+1);
            visit[ta.f][ta.s][tb.f][tb.s]=1;
        }

        ta=a,tb=b;
        if(a.s+1<m&&!tab[a.f][a.s+1])ta.s=a.s+1;
        if(b.s-1>=0&&!tab[b.f][b.s-1])tb.s=b.s-1;
        if(!visit[ta.f][ta.s][tb.f][tb.s]){
            q.p(ta,tb,l+1);
            visit[ta.f][ta.s][tb.f][tb.s]=1;
        }
   }
   if(ans!=-1)printf("1 %d",ans);
   else if(ans2!=-1)printf("2 %d",ans2);
   else printf("-1 0");
}

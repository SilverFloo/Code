#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int par[100000];
struct edge{
    int u,v,x;
    float w;
    edge(int u,int v,float w,int x):u(u),v(v),w(w),x(x){}
    bool operator < (const edge &ot)const{return w<ot.w;}
};
int root(int i){
while(par[par[i]]!=i){
par[i]=par[par[i]];
i=par[par[i]];
}
return i;
}
void merge(int a,int b){
par[root(b)]=root(a);
}
vector <edge> e;
main(){
int n,i,m;float ans=0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++){par[i]=i;}

for(i=0;i<m;i++){
    int u,v;float w;
    scanf("%d %d %f",&u,&v,&w);
    e.push_back(edge(u,v,w,i));
}
vector<int> line;
sort(e.begin(),e.end());
for(i=0;i<e.size();i++){
if(root(e[i].u)!=root(e[i].v)){
merge(e[i].u,e[i].v);
ans+=e[i].w;
line.push_back(e[i].x);
}
//printf("%f %f>",ans,e[i].w);

}

printf("%f\n",ans);
for(auto i:line)printf("%d\n",i);
}

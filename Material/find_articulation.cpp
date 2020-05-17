int num[10005],low[10005],art[10005];
vector<int> e[10005];
int ptr=1;
void findart(int u,int p=0){
    num[u]=low[u]=ptr++;
    int cnt=0;
    for(auto v:e[u]){
        if(num[v]==0){
            findart(v,u);
            low[u]=min(low[u],low[v]);
            cnt++;
            if(p==0&&cnt>1)art[u]=1;
            if(p!=0&&low[v]>=num[u])art[u]=1;
        }
        else if(v!=p)low[u]=min(num[v],low[u]);
    }
}

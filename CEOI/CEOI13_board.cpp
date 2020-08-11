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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int a[300005],b[300005];
int x[300005];
int st;
int eda,edb;
void dist(){
    int tmp = 0;
    for(int i=eda-1;i>=0;i--){
        x[i] = a[i]-b[i]+tmp;
        tmp=0;
        if(x[i]<0&&i>0)tmp--,x[i]+=2;
    }st=eda;
    for(int i=0;i<eda;i++){
        if(x[i]!=0){st=i;break;}
    }
    if(x[st]<0){
        tmp=0;
        for(int i=eda-1;i>=0;i--){
            x[i] = b[i]-a[i]+tmp;
            tmp=0;
            if(x[i]<0&&i>0)tmp--,x[i]+=2;
        }st=eda;
        for(int i=0;i<eda;i++){
            if(x[i]!=0){st=i;break;}
        }
    }
}
string sa,sb;
void push(int a[],int pos){
    while(a[pos]>1){
        a[pos]-=2;
        a[pos-1]++;
    }
    while(a[pos]<0){
        a[pos]+=2;
        a[pos-1]--;
    }
}
int main(){
    //rf();
    eda=1;
    edb=1;
    a[0]=1;
    b[0]=1;
    cin>>sa>>sb;
    for(auto i:sa){
        if(i=='1')a[eda++]=0;
        if(i=='2')a[eda++]=1;
        if(i=='U')push(a,--eda);
        if(i=='L')a[eda-1]--;
        if(i=='R')a[eda-1]++;
    }
    for(auto i:sb){
        if(i=='1')b[edb++]=0;
        if(i=='2')b[edb++]=1;
        if(i=='U')push(b,--edb);
        if(i=='L')b[edb-1]--;
        if(i=='R')b[edb-1]++;
       
    }
    for(int i=eda-1;i>=0;i--)push(a,i);
    //for(int i=0;i<eda;i++)printf("%d",a[i]);
    //cout<<endl;
    for(int i=edb-1;i>=0;i--)push(b,i);
    //for(int i=0;i<edb;i++)printf("%d",b[i]);
    int ans = abs(edb-eda);
    edb = min(edb,eda);
    eda = edb;  
    dist();
    //cout<<endl;
    
       // for(int i=st;i<eda;i++)printf("%d",x[i]);
    while(eda-st>2){
        int xx = eda-st;
        //printf("<%d>",xx);
        eda-=xx-2;
        edb-=xx-2;
        ans+=2*(xx-2);
        dist();
    }
   // cout<<endl;for(int i=st;i<eda;i++)printf("%d",x[i]);cout<<endl;
    if(eda-st==2){
        if(x[eda-1]==0)ans+=2;
        else ans+=3;
    }
    if(eda-st==1)ans++;
    printf("%d",ans);
    
}
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
int ans[105];
void pl(){
    ans[0]++;
    for(int i=0;i<102;i++){
        if(ans[i]==10)ans[i]=0,ans[i+1]++;
    }
}
void mul(){
    for(int i=0;i<102;i++){
        ans[i]*=2;
        if(i>0&&ans[i-1]>=10)ans[i-1]-=10,ans[i]++;
    }
}
void print(){
    int st=0;
    for(int i=102;i>=0;i--){
        if(ans[i]!=0)st=1;
        if(st)printf("%d",ans[i]);
    }
}
pair<string,string> get(string s){
    pair<string,string> tmp;
    cout<<s;
    cout<<endl;
    fflush(stdout);
    cin>>tmp.f;
    cin>>tmp.s;
    return tmp;
}
int main(){
    ans[0]=1;
    string tmp = "1";
    int depth = 1;
    while(1){
        tmp = get(tmp).f;
        if(tmp=="0")break;
        depth++;
    }
    tmp = "1";
    //db(depth);
    for(int i=1;i<depth;i++){
        //cout<<'<'<<tmp<<'>'<<endl;
        string walk = tmp;
        int d = i+1;
        walk = get(walk).s;
        while(d<depth){
            walk = get(walk).f;
            d++;
        }
        mul();
        if(walk=="0"){
            tmp = get(tmp).f;
        }
        else {
            tmp = get(tmp).s;
            pl();
        }
    }
    print();
}
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
vector<int> ans;
int main(){
    int x;
    cin>>x;
    int i=0;
    while(x>>i!=0)i++;
    int a=i;
    i--;
    int cnt=0;
    while(i!=0){
        while(i>=0&&(x>>i)%2!=0)i--;
        if(i<0)break;
        //printf("%d",i);
        ans.pb(i+1);
        x^=(1<<(i+1))-1;
        cnt++;
        if(x==(1<<a)-1)break;
        x++;
        cnt++;//printf("%d ",x);
        if(x==(1<<a)-1)break;
    }
    printf("%d\n",cnt);
    for(auto i:ans)printf("%d ",i);
}

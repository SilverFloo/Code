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
int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        string s;
        cin>>s;
        int cnt=0;
        printf("Case #%d: ",k);
        for(auto i:s){
            while(i-'0'>cnt)printf("("),cnt++;
            while(i-'0'<cnt)printf(")"),cnt--;
            printf("%d",i-'0');
        }
        while(cnt>0)printf(")"),cnt--;
        cout<<endl;
    }
}

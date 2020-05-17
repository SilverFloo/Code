#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
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
int main(){
    string s;
    string s2;
    cin>>s;
    string k="sipa";
    FOR(i,s.size()){
    s2.push_back(tolower(s[i]));
    }
    auto p=s2.find("sipa");

    int cnt=0;
    queue<int> q;
    while(p!=-1){
    cnt++;
    q.p(p);
    q.p(p+4);
    p=s2.find("sipa",p+1);
    }

    FOR(i,s.size()){
    while(!q.empty()&&q.front()==i){q.pop();printf("\"");}
    printf("%c",s[i]);
    }
    if(!q.empty())printf("\"");
        printf("\n%d",cnt);
}

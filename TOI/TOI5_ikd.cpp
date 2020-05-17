#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define mp make_pair
#define f first
#define s second
using namespace std;
pair<int,int> st[4][2][2];
int main(){
vector<int> real;
//FOR(i,4)FOR(j,2)FOR(k,2)st[i][j][k]=-1;
st[0][0][0]=mp(0,0);
st[0][1][1]=mp(0,2);
st[1][0][0]=mp(1,2);
st[1][1][1]=mp(1,0);
st[2][0][1]=mp(0,3);
st[2][1][0]=mp(0,1);
st[3][1][0]=mp(1,3);
st[3][0][1]=mp(1,1);
int n;
cin>>n;
int state=0;
string s[n];FOR(i,n)cin>>s[i];
for(int i=n-1;i>=0;i--){
vector<int> ans;
for(int j=s[i].size()-1;j>=0;j-=2){
ans.push_back(st[state][s[i][j-1]-'0'][s[i][j]-'0'].f);//printf("/%d",st[state][s[i][j-1]-'0'][s[i][j]-'0'].f);
state=st[state][s[i][j-1]-'0'][s[i][j]-'0'].s;
}
if(ans.size()==8){
int x=0;
for(int j=7;j>=0;j--){//printf("%d",ans[j]);

x*=2;x+=ans[j];}
real.push_back(x);
}

}
for(int i=real.size()-1;i>=0;i--)printf("%c",real[i]);

}
//1 0100101100111011

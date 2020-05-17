#include<bits/stdc++.h>
using namespace std;
int c[26];
main(){
int n,m;scanf("%d %d",&m,&n);
vector<string> st[26];
for(int i=0;i<m;i++){
string c;
cin>>c;
st[c[0]-'a'].push_back(c);
}
for(int i=0;i<26;i++){sort(st[i].begin(),st[i].end());}
for(int i=0;i<n;i++){
char x;
scanf(" %c",&x);x-='a';
cout<<st[x][c[x]%st[x].size()]<<endl;
c[x]++;
}

}

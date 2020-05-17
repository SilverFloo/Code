#include<bits/stdc++.h>
using namespace std;
vector< pair<pair<int,int >,string> > friends;
int m[26];
bool myfunction (pair<pair<int,int >,string> i,pair<pair<int,int >,string> j) {
     if(i.first.first==j.first.first)return (i.first.second<j.first.second);
     return i.first.first>j.first.first;
}

int main(){
    string myname;
cin>>myname;
int n;
cin>>n;

for(int i=0;i<myname.size();i++){m[myname[i]-'A']++;}
for(int j=0;j<n;j++){
string fr;
cin>>fr;
int f[26];
for(int i=0;i<26;i++)f[i]=0;
for(int i=0;i<fr.size();i++){f[fr[i]-'A']++;}
int p=0;
for(int i=0;i<26;i++)p+=f[i]*m[i];
friends.push_back(make_pair(make_pair(p,j),fr));
}
sort(friends.begin(), friends.end(), myfunction);

for(int i=0;i<friends.size();i++)cout<<friends[i].second<<endl;
}

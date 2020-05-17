#include<bits/stdc++.h>
using namespace std;
vector<int> q;
void dom(int n){
if(n==0){
for(auto i:q){
if(i==1)printf("--\n");
else printf("||\n");
}
printf("E\n");
}
if(n>0){
q.push_back(1);dom(n-1);q.pop_back();
q.push_back(2);dom(n-2);q.pop_back();
}

}
int main(){
int n;
cin>>n;
dom(n);
}

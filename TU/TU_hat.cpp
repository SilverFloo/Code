#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void b2(int x){
if(x!=0){
int a=x%2;
x/=2;
b2(x);
ans.push_back(a);
}

}
main(){
int n;
scanf("%d",&n);
int M=0;
for(int i=0;i<n;i++){
int x;
scanf("%d",&x);
if(x>M)M=x;
}
b2(M);
for(int i=0;i<ans.size();i++){
printf("%d",ans[i]);
}


}

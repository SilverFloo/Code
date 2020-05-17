#include<bits/stdc++.h>
using namespace std;
main(){
int n;
scanf("%d",&n);
if(n<6)printf("no");
else{
vector<int> ans;
for(int i=0;i<=n/6;i++){
    for(int j=0;j<=n/9;j++){
        for(int k=0;k<=n/20;k++){
            if(6*i+9*j+20*k<=n&&6*i+9*j+20*k!=0){ans.push_back(6*i+9*j+20*k);}
        }
    }
}
sort(ans.begin(),ans.end());
printf("%d\n",ans[0]);
for(int i=1;i<ans.size();i++){if(ans[i]!=ans[i-1])printf("%d\n",ans[i]);}}
}

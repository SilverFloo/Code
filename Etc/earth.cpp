#include <bits/stdc++.h>

using namespace std;

main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = -1;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            continue;
        }else if(a[i]>a[i+1]){
            ans = max(ans,a[i+1]);
        }else{
            ans = max(ans,a[i]);
        }
    }
    printf("%d",ans);
}


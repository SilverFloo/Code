#include "boxes.h"
#include "boxes.cpp"
#include <bits/stdc++.h>

int main() {
    int N, K, L, i;
    cin>>N>>K>>L;
    int *p = (int*)malloc(sizeof(int) * (unsigned int)N);

    for (i = 0; i < N; i++) {
        cin>>p[i];
    }

    printf("%lld\n", delivery(N, K, L, p));
    return 0;
}
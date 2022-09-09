#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long int k;
    int number=0;
    scanf("%d %ld",&n,&k);
    int elements[n];
    for (int s = 0; s < n; ++s) {
        scanf("%d",&elements[s]);
    }
    for (int i = 0; i < n; ++i) {
        long int sum=0;
        for (int j = i; j < n ; ++j) {
            sum+=elements[j];
            if (sum<=k)++number;
        }
    }
    cout << number;
    return 0;
}

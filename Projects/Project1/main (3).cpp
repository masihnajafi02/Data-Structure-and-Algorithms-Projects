#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    long long int k;
    long long int number = 0;
    scanf("%lld %lld", &n, &k);
    long long int elements[n];
    for (int s = 0; s < n; ++s) {
        scanf("%lld", &elements[s]);
    }
    long long int end = 0;
    long long int beginning = 0;
    long long int sum = elements[0];
    while (end < n) {
        if (sum <= k) {
            ++end;
            number += end - beginning;
            sum += elements[end];
        } else {
            sum -= elements[beginning];
            ++beginning;
        }
    }

    cout << number;
    return 0;
}

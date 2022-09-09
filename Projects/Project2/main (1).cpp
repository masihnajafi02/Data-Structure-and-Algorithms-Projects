#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int answer;

int main() {
    vector<int> numbers;
    stack<int> sequence;
    stack<int> attempts;
    int input;
    int size;
    cin >> size;
    for (int k = 0; k < size; ++k) {
        cin >> input;
        numbers.push_back(input);
    }
    int max = 0;
    int results[size];
    for (int j = 0; j < size; ++j) {
        results[j] = 0;
    }
    sequence.push(numbers[0]);
    attempts.push(-1);
    for (int i = 1; i < size; ++i) {
        max = 0;
        while (!sequence.empty() && numbers[i] > sequence.top()) {
            sequence.pop();
            if (attempts.top() > max) {
                max = attempts.top();
            }
            attempts.pop();
        }
        if (!sequence.empty() && numbers[i] < sequence.top()) {
            attempts.push(max + 1);
            if (max + 1 > answer)answer = max + 1;
        } else {
            attempts.push(-1);
        }
        sequence.push(numbers[i]);
    }

    cout << answer;

    return 0;
}


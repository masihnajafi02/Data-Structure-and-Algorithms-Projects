#include <iostream>

using namespace std;

int find(string str);


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        cout << find(str) << endl;
    }
    return 0;
}

int find(string str) {
    int i = 0;
    int start_pointer = 0;
    int move=0;
    int counter = 0;
    while (i < str.size() / 2) {
        start_pointer+=str[i]-str[str.size()-i-1];
        if (start_pointer==0){
            if(str.substr(move,i-move+1)==str.substr(str.size()-i-1,i-move+1)){
                counter+=2;
                move=i+1;
            }
        }
        ++i;
    }
    if (start_pointer!=0 || str.size()%2==1)++counter;

    return counter;
}

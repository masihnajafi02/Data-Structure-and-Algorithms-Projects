#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, char> blocks;
    int m, n;
    scanf("%d %d", &n, &m);
    map<int, int> saved;
    for (int j = 0; j < m; ++j) {
        int x, y;
        char direction;
        int final = 0;
        scanf("%d %d %c", &x, &y, &direction);
        if (blocks.find(x)->second != 0) {
            final = 0;
        } else {
            if (direction == 'L') {
                blocks.insert({x, direction});
                auto lowerBound = blocks.lower_bound(x);
                if (lowerBound == blocks.begin()) {
                    final = x;
                } else {
                    lowerBound--;
                    if ((*lowerBound).second == 'U') {
                        final = x - (*lowerBound).first;
                    } else if ((*lowerBound).second == 'L') {
                        final = x + saved.find((*lowerBound).first)->second - (*lowerBound).first;
                    }
                }
            } else if (direction == 'U') {
                auto upperBound = blocks.upper_bound(x);
                if ((*upperBound).second == 0) {
                    final = y;
                } else {
                    if ((*upperBound).second == 'L') {
                        final = (*upperBound).first - x;
                    } else if ((*upperBound).second == 'U') {
                        final = (*upperBound).first + saved.find((*upperBound).first)->second - x;
                    }
                }
                blocks.insert({x, direction});
            }
            saved.insert({x, final});
        }
        printf("%d\n", final);
    }
}

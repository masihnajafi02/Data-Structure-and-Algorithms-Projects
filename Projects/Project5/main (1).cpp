#include <bits/stdc++.h>

using namespace std;

int total_edges = 0, current = 0, answer = 0;

class Graph {
    unordered_map<int, vector<int>> adjacency_list;

public:
    int edges = 0, k = 0, element_max = 0, element_second_max = 0;


    void process_answer(int i) {
        if (element_max < i) {
            element_second_max = element_max;
            element_max = i;
        } else if (element_max != i && element_second_max < i)
            element_second_max = i;
        ++k;
    }

    int BFS(unordered_map<int, int> &convert_to_index, vector<pair<int, vector<int>>> &adjacency_array,
    vector<bool> &marked) {

        for (int i = 0; i < adjacency_array.size(); i++) {
            if (!marked[i]) {
                stack<int> visit;
                marked[i] = true;
                total_edges = 0;
                visit.push(i);
                Graph component;
                while (!visit.empty()) {
                    int top = visit.top();
                    visit.pop();
                    for (const auto &n : adjacency_array[top].second) {
                        int index = convert_to_index[n];
                        if (!marked[index]) {
                            marked[index] = true;
                            visit.push(index);
                        }
                    }
                    total_edges += adjacency_array[top].second.size();
                    component.process_answer(adjacency_array[top].first);
                }
                total_edges = total_edges / 2;
                if (component.k == total_edges) {
                    current = component.element_max;
                } else if (component.k - 1 == total_edges) {
                    current = component.element_second_max;
                } else {
                    return -1;
                }
                answer = max(answer, current);
            }
        }
        return answer;
    }


    void add_edge(int a, int b) {
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    int finalize() {
        if (edges > adjacency_list.size())
            return -1;
        unordered_map<int, int> convert_to_index(adjacency_list.size());
        int i = 0;
        vector<pair<int, vector<int>>> adjacency_array(adjacency_list.size());
        for (auto &j : adjacency_list) {
            convert_to_index[j.first] = i;
            adjacency_array[i].second = j.second;
            adjacency_array[i].first = j.first;
            ++i;
        }
        vector<bool> marked(adjacency_array.size());
        return BFS(convert_to_index, adjacency_array, marked);
    }
};

int main() {
    int n, first, second;
    Graph graph;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first >> second;
        graph.add_edge(first, second);
        ++graph.edges;
    }
    cout << graph.finalize();
    return 0;
}
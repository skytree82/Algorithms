#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <sstream>
#include <istream>
#include <string>
#include <cctype>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
#include <unordered_map>
#include <set>
#include <functional>
#include <limits>
#include <tuple>
#include <ctime>

using namespace std;

int v, e;
int graph[101][101][101];

void InitializeGraph(int k) {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) graph[k][i][j] = 0;
            else graph[k][i][j] = 15000000;
        }
    }
}

void FloydWarshall() {
    for (int k = 1; k <= v; k++) {
        InitializeGraph(k);
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                graph[k][i][j] = min(graph[k - 1][i][j], graph[k - 1][i][k] + graph[k - 1][k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> v;
    cin >> e;
    InitializeGraph(0);

    for (int i = 0; i < e; i++) {
        int st, ed, w; cin >> st >> ed >> w;
        if (graph[0][st][ed] > w) graph[0][st][ed] = w;
    }
    
    FloydWarshall();

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            (graph[v][i][j] < 15000000) ? cout << graph[v][i][j] : cout << 0; cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

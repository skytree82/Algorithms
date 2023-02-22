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
struct Vertex {
    int idx;
    int dist;
    Vertex* prev;
    vector<pair<Vertex*, int>> adj;
};

int v, e;
int start, dest;
vector<Vertex*> vertexArr;
vector<Vertex*> pq;

bool cmp(Vertex* a, Vertex* b) {
    return a->idx < b->idx;
}

void Relax(Vertex* u, Vertex* v, int w) {
    if (v->dist > u->dist + w) {
        v->dist = u->dist + w;
        v->prev = u;
    }
}

int minVertex() // Priotity Queue 대체용{
    int minDist = numeric_limits<int>::max();
    int minIdx = 0;
    for (int i = 0; i < pq.size(); i++) {
        if (pq[i]->dist < minDist) {
            minIdx = i;
            minDist = pq[i]->dist;
        }
    }
    return minIdx;
}

void Dijkstra(int start) {

    while (!pq.empty()) {
        int minIdx = minVertex();
        Vertex* u = pq[minIdx];
        pq.erase(pq.begin() + minIdx);

        vertexArr.push_back(u);
        for (pair<Vertex*, int> v : u->adj) {
            Relax(u, v.first, v.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> v;
    cin >> e;

    for (int i = 1; i <= v; i++) {
        Vertex* tmpVertex;
        tmpVertex = new Vertex{ i, 150000000, NULL };
        pq.push_back(tmpVertex);
    }

    for (int i = 0; i < e; i++) {
        int s, e, w; cin >> s >> e >> w;
        pq[s - 1]->adj.push_back(make_pair(pq[e - 1], w));
    }

    cin >> start >> dest;

    for (int i = 0; i < pq.size(); i++) {
        if (start == pq[i]->idx) {
            pq[i]->dist = 0;
            break;
        }
    }

    Dijkstra(start);

    deque<int> route;
    sort(vertexArr.begin(), vertexArr.end(), cmp);

    cout << vertexArr[dest - 1]->dist << '\n';
    int cur = dest - 1;

    while (true) {
        if (vertexArr[cur]->prev->idx == start) {
            route.push_front(vertexArr[cur]->idx);
            route.push_front(vertexArr[cur]->prev->idx);
            break;
        }
        route.push_front(vertexArr[cur]->idx);
        cur = vertexArr[cur]->prev->idx - 1;
    }

    cout << route.size() << '\n';

    while (!route.empty()) {
        cout << route.front() << ' ';
        route.pop_front();
    }

    return 0;
}

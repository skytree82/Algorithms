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
    vector<pair<Vertex*, int>> adj;
};

int v, e;
int start, dest;
vector<Vertex*> vertexArr;
vector<Vertex*> pq;
vector<tuple<int, int, int>> routeData;

bool cmp(Vertex* a, Vertex* b) {
    return a->idx < b->idx;
}

void InitializeSingleSource(int start) {
    for (int i = 1; i <= v; i++) {
        Vertex* tmpVertex;
        if (i == start) tmpVertex = new Vertex{ i, 0 };
        else tmpVertex = new Vertex{ i, 150000000 };
        pq.push_back(tmpVertex);
    }
    for (auto e: routeData) {
        pq[get<0>(e) - 1]->adj.push_back(make_pair(pq[get<1>(e) - 1], get<2>(e)));
        pq[get<1>(e) - 1]->adj.push_back(make_pair(pq[get<0>(e) - 1], get<2>(e)));
    }
    vertexArr.clear();
}

void Relax(Vertex* u, Vertex* v, int w) {
    if (v->dist > u->dist + w) {
        v->dist = u->dist + w;
    }
}

int minVertex() {
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
    InitializeSingleSource(start);

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

    for (int i = 0; i < e; i++) {
        int s, e, w; cin >> s >> e >> w;
        routeData.push_back(make_tuple(s, e, w));
    }

    cin >> start >> dest;

    Dijkstra(start);
    sort(vertexArr.begin(), vertexArr.end(), cmp);
    
    vertexArr[dest - 1]->dist < 150000000 ? cout << vertexArr[dest - 1]->dist : cout << -1;

    return 0;
}

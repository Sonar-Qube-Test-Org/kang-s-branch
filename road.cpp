#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
 
#define  V_MAX 100005
#define INF 0x3f3f3f3f3f3f3f3f
 
using namespace std;
 
typedef long long ll;
 
struct Edge {
    int to;
    ll w;
};
 
struct Node {
    ll dis;
    int u;
    bool operator>(const Node &b) const {return dis > b.dis; }
};
 
vector<Edge> e[V_MAX];
 
void addEdge(int u, int v, ll w) {
    e[u].push_back({v, w});
}
 
vector<ll> dijkstra(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    vector<ll> dis(V_MAX);
    fill(dis.begin(),  dis.end(), INF);
    vector<bool> vis(V_MAX);
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()){
        int u = q.top().u;
        q.pop();
        if(vis[u])continue;
        vis[u] = true;
        for (auto ed : e[u]){
            int v = ed.to;
            ll w = ed.w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    return dis;
}
 
int main() {
    int n, m;
    int s;
    cin >> n >> m >> s;
    int x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        addEdge(x, y, w);
    }
    vector<ll> dis = dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    return 0;
}

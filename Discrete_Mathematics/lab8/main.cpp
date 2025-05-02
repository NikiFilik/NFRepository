#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

struct Edge {
public:
    int to;
    int capacity;
    int flow;
    Edge* rev;

    Edge(int t, int c) : to(t), capacity(c), flow(0), rev(nullptr) {}
};

class Graph {
private:
    int n;
    std::vector<std::vector<Edge*>> adj;
    std::vector<int> level;
    std::vector<int> ptr;
    int S, T;

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        q.push(S);
        level[S] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge* e : adj[u]) {
                if (level[e->to] == -1 && e->flow < e->capacity) {
                    level[e->to] = level[u] + 1;
                    q.push(e->to);
                }
            }
        }
        return level[T] != -1;
    }

    int dfs(int u, int current_flow) {
        if (u == T || current_flow == 0)
            return current_flow;
        for (; ptr[u] < adj[u].size(); ptr[u]++) {
            Edge* e = adj[u][ptr[u]];
            if (level[e->to] == level[u] + 1) {
                int pushed = dfs(e->to, std::min(current_flow, e->capacity - e->flow));
                if (pushed > 0) {
                    e->flow += pushed;
                    e->rev->flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

public:
    Graph(int nodes, int source, int sink) : n(nodes), S(source), T(sink) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    ~Graph() {
        for (auto& edges : adj) {
            for (Edge* e : edges) {
                delete e;
            }
        }
    }

    void printAdjacencyList() const {
        for (int u = 0; u < n; ++u) {
            std::cout << "Vertex " << u << " -> [";
            bool first = true;
            for (Edge* e : adj[u]) {
                if (e->capacity > 0) {
                    if (!first) std::cout << ", ";
                    std::cout << e->to << " (cap " << e->capacity << ")";
                    first = false;
                }
            }
            std::cout << "]" << std::endl;
        }
    }

    void addEdge(int from, int to, int capacity) {
        Edge* forward = new Edge(to, capacity);
        Edge* backward = new Edge(from, 0);
        forward->rev = backward;
        backward->rev = forward;
        adj[from].push_back(forward);
        adj[to].push_back(backward);
    }

    int dinic() {
        int max_flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(S, INT_MAX)) {
                max_flow += pushed;
            }
        }
        return max_flow;
    }

    std::vector<bool> minCut() {
        std::vector<bool> visited(n, false);
        std::queue<int> q;
        q.push(S);
        visited[S] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge* e : adj[u]) {
                if (e->capacity > e->flow && !visited[e->to]) {
                    visited[e->to] = true;
                    q.push(e->to);
                }
            }
        }
        return visited;
    }

    const std::vector<std::vector<Edge*>>& getAdj() const {
        return adj;
    }
};

int main() {
    std::srand(time(NULL));

    int n = 11;
    int S = 0, T = 10;

    Graph Graph(n, S, T);

    Graph.addEdge(0, 1, 3);
    Graph.addEdge(0, 2, 7);
    Graph.addEdge(0, 3, 5);
    Graph.addEdge(1, 2, 6);
    Graph.addEdge(1, 5, 5);
    Graph.addEdge(2, 6, 10);
    Graph.addEdge(3, 2, 3);
    Graph.addEdge(3, 4, 4);
    Graph.addEdge(4, 2, 2);
    Graph.addEdge(4, 7, 8);
    Graph.addEdge(5, 2, 9);
    Graph.addEdge(5, 6, 3);
    Graph.addEdge(5, 8, 3);
    Graph.addEdge(6, 8, 4);
    Graph.addEdge(7, 2, 7);
    Graph.addEdge(7, 6, 5);
    Graph.addEdge(7, 9, 5);
    Graph.addEdge(7, 10, 7);
    Graph.addEdge(8, 10, 9);
    Graph.addEdge(9, 10, 9);

    /*Graph.addEdge(0, 1, (std::rand() % 901) + 100);
    Graph.addEdge(0, 2, (std::rand() % 901) + 100);
    Graph.addEdge(0, 3, (std::rand() % 901) + 100);
    Graph.addEdge(1, 2, (std::rand() % 901) + 100);
    Graph.addEdge(1, 5, (std::rand() % 901) + 100);
    Graph.addEdge(2, 6, (std::rand() % 901) + 100);
    Graph.addEdge(3, 2, (std::rand() % 901) + 100);
    Graph.addEdge(3, 4, (std::rand() % 901) + 100);
    Graph.addEdge(4, 2, (std::rand() % 901) + 100);
    Graph.addEdge(4, 7, (std::rand() % 901) + 100);
    Graph.addEdge(5, 2, (std::rand() % 901) + 100);
    Graph.addEdge(5, 6, (std::rand() % 901) + 100);
    Graph.addEdge(5, 8, (std::rand() % 901) + 100);
    Graph.addEdge(6, 8, (std::rand() % 901) + 100);
    Graph.addEdge(7, 2, (std::rand() % 901) + 100);
    Graph.addEdge(7, 6, (std::rand() % 901) + 100);
    Graph.addEdge(7, 9, (std::rand() % 901) + 100);
    Graph.addEdge(7, 10, (std::rand() % 901) + 100);
    Graph.addEdge(8, 10, (std::rand() % 901) + 100);
    Graph.addEdge(9, 10, (std::rand() % 901) + 100);*/

    std::cout << "\nAdjacency List:\n";
    Graph.printAdjacencyList();
    std::cout << std::endl;

    int max_flow = Graph.dinic();
    std::cout << "Maximum flow: " << max_flow << std::endl;

    std::vector<bool> cut = Graph.minCut();
    std::cout << "Edges in the min cut:" << std::endl;
    for (int u = 0; u < n; ++u) {
        if (cut[u]) {
            for (Edge* e : Graph.getAdj()[u]) {
                if (e->capacity > 0 && !cut[e->to]) {
                    std::cout << u << " -> " << e->to << " (capacity " << e->capacity << ")" << std::endl;
                }
            }
        }
    }

    return 0;
}
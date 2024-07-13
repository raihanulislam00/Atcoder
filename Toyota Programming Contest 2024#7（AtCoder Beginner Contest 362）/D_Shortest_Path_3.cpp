#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Edge
{
    int to;
    ll weight;
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<ll> A(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int U, V;
        ll B;
        cin >> U >> V >> B;
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    vector<ll> dist(N + 1, INF);
    dist[1] = A[1];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({A[1], 1});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.to;
            ll weight = edge.weight;
            ll new_dist = dist[u] + weight + A[v];
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        cout << dist[i] << (i == N ? '\n' : ' ');
    }

    return 0;
}

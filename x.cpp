#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 2e5 + 5; // Maximum number of nodes

vector<int> adj[N];
vector<int> a(N);
vector<int> preorder;
vector<int> prefix(N);
vector<int> query_result;
int query[N][2];

// Perform DFS in preorder and calculate the longest alternating prefix
void dfs(int node, int parent, int length) {
    int current_value = a[node];
    if (length % 2 == 1) {
        current_value = 1 - current_value;
    }

    prefix[node] = (node == 1) ? current_value : (prefix[parent] + current_value);

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, length + 1);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Read node values
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Read tree edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform DFS to calculate the alternating prefix
    dfs(1, 0, 0);

    // Read and process queries
    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            a[x] = 1 - a[x]; // Flip the value of node x
        }
        query[i][0] = type;
        query[i][1] = x;

        // Calculate the longest alternating subarray in the preorder traversal
        int longest = prefix[x];
        if (longest == 0) {
            longest = -1;
        }
        query_result.push_back(longest);
    }

    // Output the results
    for (int i = 0; i < q; ++i) {
        if (query[i][0] == 1) {
            cout << query_result[i] << endl;
        } else {
            cout << max(query_result[i], query_result[i - 1]) << endl;
        }
    }

    return 0;
}
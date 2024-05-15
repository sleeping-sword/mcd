#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define MAX 1005
#define INF INT_MAX

int mat[MAX][MAX], dist[MAX][MAX];
bool visited[MAX][MAX], used[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
vector<PII> path;
vector<PII> parent[MAX][MAX];

bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    if(visited[x][y] || mat[x][y] == 1) return false;

    return true;
}

void bfs(PII src, PII dest) {
    queue<PII> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
            used[i][j] = false;
        }
    }
    q.push(src);
    visited[src.first][src.second] = true;
    dist[src.first][src.second] = 0;

    while(!q.empty()) {
        PII u = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];

            if(isValid(vx, vy)) {
                visited[vx][vy] = true;
                dist[vx][vy] = dist[u.first][u.second] + 1;

                parent[vx][vy].push_back(u);
                q.push(make_pair(vx, vy));
            } else if(vx >= 0 && vy >= 0 && vx < n && vy < n && mat[vx][vy] != 1) {
                if(dist[u.first][u.second] + 1 == dist[vx][vy]) {
                    parent[vx][vy].push_back(u);
                }
            }
        }
    }
}

// void printPath(PII u) {
//     for(auto v : parent[u.first][u.second]) {
//         mat[v.first][v.second] = 2;
//         if (!used[v.first][v.second]) {
//             used[v.first][v.second] = true;
//             printPath(v);
//         }
//     }
// }

void printPath(PII u, PII src) {
    for(auto v : parent[u.first][u.second]) {
        if (!(v.first == src.first && v.second == src.second)) { // Add this condition to exclude the starting point.
            mat[v.first][v.second] = 2;
        }
        if (!used[v.first][v.second]) {
            used[v.first][v.second] = true;
            printPath(v, src);
        }
    }
}

int main()
{
    while(cin>>n){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
                dist[i][j] = INF;
                parent[i][j].clear();
            }
        }

        PII src, dest;
        cin >> src.first >> src.second >> dest.first >> dest.second;

        bfs(src, dest);
        printPath(dest,src);
        
        int m; // number of coordinates to check
        cin >> m;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout <<mat[i][j]<< " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            if(mat[x][y] == 2) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << endl;
    }
    return 0;
}
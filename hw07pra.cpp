#include<bits/stdc++.h>
using namespace std;

#define MAX 1005
struct PII{
    int first;
    int second;
};

//int mat[MAX][MAX],distance[MAX][MAX];
bool visited[MAX][MAX],used[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n;
vector<PII> path;
vector<PII> parent[MAX][MAX];


int main(){
    while(cin>>n){
        int mat[n][n],distance[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
                distance[i][j]=10000000000000;
                parent[i][j].clear();
            }
        }
        PII src, dest;
        cin >> src.first >> src.second >> dest.first >> dest.second;
        bfs(src,dest);
        printPath(src,dest);
    }
    return 0;
}

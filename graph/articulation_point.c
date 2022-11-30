#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 100
int n;
int time=0;
int graph[N+1][N+1];
char color[N+1];
int parent[N+1], d[N+1], f[N+1], low[N+1];
void dfs(int graph[N+1][N+1]);
void dfs_visit(int node);
int art[N+1], ap=0;

int min(int a,int b) {
    return (a<b? a:b);
}

void init() {
    for(int i=1;i<=n;i++) {
        color[i]='w';
        parent[i]=-1;
        d[i]=f[i]=INT_MAX;
        low[i]=INT_MAX;
    }
}


int main() {
    //freopen("inputDFS.txt","r",stdin);
    int m; scanf("%d %d", &n,&m);
    init();
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    //int source; scanf("%d", &source);
    dfs(graph);
    printf("\n");
    for(int i=1;i<=n;i++) {
        printf("%d %d %d %d\n", i,d[i],f[i],low[i]);
    }
    printf("%d\n", ap);
    for(int i=1;i<=n;i++)
        if(art[i]) printf("%d ", i);
}


void dfs(int graph[N+1][N+1]) {
    for(int i=1;i<=n;i++) {
        if(color[i]=='w') dfs_visit(i);
    }
}

void dfs_visit(int node) {
    //printf("%d ", node);
    
    color[node]='g';
    low[node]=d[node]=++time;
    int child=0;
    for(int j=1;j<=n;j++) {
        if(graph[node][j]==1 && color[j]=='w') {
            child++;
            parent[j]=node;
            dfs_visit(j);
            low[node]=min(low[node],low[j]);
            if(low[j]>=d[node] && parent[node]!=-1) art[node]=1,ap++;//for bridge low[j]>d[node]
            if(child>1 && parent[node]==-1) art[node]=1,ap++;
        }
        else low[node]=min(low[node],d[j]); //back edge
    }
    color[node]='b';
    f[node]=++time;
}




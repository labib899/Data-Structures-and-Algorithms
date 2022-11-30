#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//graph
#define N 100
int graph[N+1][N+1];
char color[N+1];
int parent[N+1], level[N+1];
void bfs(int node);
void path(int graph[][N+1],int s,int v);

//queue
int queue[N+1];
int start=1,end=1;


int main() {
    freopen("inputBFS.txt","r",stdin);
    for(int i=1;i<=N;i++) {
        color[i]='w';
        parent[i]=-1;
        level[i]=0;
    }
    int n,m; scanf("%d %d", &n,&m);
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=1;
        //graph[b][a]=1;
    }
    int source; scanf("%d", &source);
    bfs(source);
    for(int i=1;i<=n;i++) {
        if(color[i]=='b') printf("color[%d]=%c\n", i,color[i]);
        if(parent[i]!=-1 || i==source) printf("parent[%d]=%d\n", i,parent[i]);
        if(level[i]!=-1 || i==source) printf("level[%d]=%d\n", i,level[i]);
    }
    int s,v; scanf("%d %d", &s,&v);
    path(graph,s,v);
}


void bfs(int node) {
    queue[end++]=node;
    color[node]='g';
    while(end>=start) {
        int p=queue[start];
        //printf("%d ", p);
        for(int j=1;j<=N;j++) {
            if(graph[p][j]==1 && color[j]=='w') {
                //printf("   %d ", j);
                queue[end++]=j;
                color[j]='g';
                level[j]=level[p]+1;
                parent[j]=p;
            }
        }
        start++;
        color[p]='b';
        //printf("\n");
    }
}

void path(int graph[][N+1],int s,int v) {
    if(v==s) printf("%d ", s);
    else if(parent[v]==-1) printf("No path...");
    else {
        path(graph,s,parent[v]);
        printf("%d ", v);
    }
}

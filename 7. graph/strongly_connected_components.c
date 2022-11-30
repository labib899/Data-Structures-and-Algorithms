#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define N 100
int n; //number of vertices
int time=0;
int graph[N+1][N+1], trans[N+1][N+1];
char color[N+1];
int parent[N+1], d[N+1], f[N+1];
void dfs(int g[][N+1]);
void dfs_visit1(int node), dfs_visit2(int node);

//stack
int stack[N+1], t=0;
void push(int x) {
    stack[++t]=x;
}


int main() {
    //freopen("inputDFS.txt","r",stdin);
    int m; scanf("%d %d", &n,&m);
    for(int i=1;i<=n;i++) {
        color[i]='w';
        parent[i]=-1;
        d[i]=f[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++) {
        int a,b; scanf("%d %d", &a,&b);
        graph[a][b]=1;
    }
    dfs(graph);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            trans[j][i]=graph[i][j];
        }
    }
    for(int i=1;i<=n;i++) color[i]='w';
    int comp=0;
    for(int i=1;i<=n;i++) {
        int x=stack[t--];
        if(color[x]=='w') {
            dfs_visit2(x);
            comp++;
            printf("\n");
        }
    }
    printf("Total components: %d\n", comp);
    //for(int i=1;i<=n;i++) printf("\n%d ",stack[i]);
    //for(int i=1;i<=n;i++) printf("\n%d %d %d\n",i,d[i],f[i]);
}


void dfs(int g[][N+1]) {
    for(int i=1;i<=n;i++) {
        if(color[i]=='w') dfs_visit1(i);
    }
}

void dfs_visit1(int node) {
    color[node]='g';
    d[node]=++time;
    for(int j=1;j<=n;j++) {
        if(graph[node][j]==1 && color[j]=='w') {
            parent[j]=node;
            dfs_visit1(j);
        }
    }
    color[node]='b';
    f[node]=++time;
    push(node); //pishing nodes in the stack
}

void dfs_visit2(int node) {
    printf("%d ", node);
    color[node]='g';
    for(int j=1;j<=n;j++) {
        if(trans[node][j]==1 && color[j]=='w') {
            parent[j]=node;
            dfs_visit2(j);
        }
    }
    color[node]='b';
}

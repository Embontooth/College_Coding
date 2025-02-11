#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void prims(int ** , int );
int mindist(int *, int *, int);
void print(int *, int **, int);
int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    int ** arr = (int **)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++){
        arr[i]=(int *)calloc(v,sizeof(int));
    }
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        arr[u][v]=w;
        arr[v][u]=w;
    }
    prims(arr,v);
}
int mindist(int * dist, int * visited, int vert){
    int mind = INT_MAX;
    int mini;
    for(int i=0;i<vert;i++){
        if(!visited[i] && dist[i]<mind){
            mind=dist[i];
            mini=i;
        }
    }
    return mini;
}
void print(int * parent, int ** graph, int vert){
    for(int i=1;i<vert;i++){
        printf("%d -> %d    %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
void prims(int ** arr, int v){
    int visited[v],distances[v],parents[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
        distances[i]=INT_MAX;
    }
    parents[0]=-1;
    distances[0]=0;
    for(int i=0;i<v-1;i++){
        int u = mindist(distances,visited,v);
        visited[u]=1;
        for(int j=0;j<v;j++){
            if(arr[u][j] && !visited[j] && arr[u][j]<distances[j]){
                distances[j]=arr[u][j];
                parents[j]=u;
            }
        }
    }
    print(parents,arr,v);
}
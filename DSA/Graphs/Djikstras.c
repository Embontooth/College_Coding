#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int mindist(int *, int *, int);
void print(int *, int , int);
void dijikstras(int **, int, int, int);
int main(){
    int v,e;
    scanf(" %d %d",&v,&e);
    int ** arr = (int **)malloc(v*sizeof(int *));
    for(int i=0;i<v;i++){
        arr[i] = (int *)calloc(v,sizeof(int));
    }
    for(int i=0;i<e;i++){
        int val1,val2,w;
        scanf("%d %d %d",&val1,&val2,&w);
        arr[val1][val2]=w;
    }
    int source,dest;
    scanf("%d %d",&source, &dest);
    dijikstras(arr,v,source, dest);
}
void print(int * parent, int dest){
    if(parent[dest]==-1){
        printf("%d",dest);
        return;
    }
    print(parent, parent[dest]);
    printf(" -> %d",dest);
}
int mindist(int * dist, int * visited, int v){
    int mind = INT_MAX;
    int mini;
    for(int i=0;i<v;i++){
        if(dist[i]<mind && visited[i]==0){
            mind = dist[i];
            mini = i;
        }
    }
    return mini;
}
void dijikstras (int ** arr, int vertices, int src, int dest){
    int distances[vertices],visited[vertices],parent[vertices];
    for(int i=0;i<vertices;i++){
        distances[i]=INT_MAX;
        visited[i]=0;
        parent[i]=-1;
    }
    distances[src]=0;
    for(int i=0;i<vertices-1;i++){
        int u = mindist(distances, visited, vertices);
        visited[u]=1;
        for(int v=0;v<vertices;v++){
            if(arr[u][v]&&!visited[v]&&distances[u]!=INT_MAX && (distances[u]+arr[u][v]<distances[v])){
                distances[v]=distances[u]+arr[u][v];
                parent[v]=u;
            }
        }
    }
    if(distances[dest]==INT_MAX){
        printf("No path found");
        return;
    }
    printf("Shortest path: ");
    print(parent, dest);
    printf("\nShortest distance: %d",distances[dest]);
}
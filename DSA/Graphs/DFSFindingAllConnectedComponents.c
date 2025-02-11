#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void dfs(int ** graph, int source, int * visited, int vertices){
    visited[source]=1;
    printf("%d ",source);
    for(int i=0;i<vertices;i++){
        if(graph[source][i] && !visited[i]){
            visited[i]=1;
            dfs(graph, i, visited, vertices);
        }
    }
}
int main(){
    int v;
    scanf(" %d",&v);
    int ** graph = (int **)malloc(v*sizeof(int *));
    for(int i=0;i<v;i++){
        graph[i]=(int*)calloc(v,sizeof(int));
    }
    while(true){
        int val1,val2;
        scanf("%d %d",&val1,&val2);
        if(val1<0 && val2<0){
            break;
        }
        graph[val1][val2]=graph[val2][val1]=1;
    }
    printf("Following are connected components:\n");
    int * visited = (int *)calloc(v,sizeof(int));
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(graph,i,visited,v);
            printf("\n");
        }
    }
}
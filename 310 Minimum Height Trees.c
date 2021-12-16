
#define N 50001

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int i,j,u,v;
	int deg[N]={0};
	bool quiteedge[N]={false};
    int degwait[N]={0};bool visited[N]={false};
    for(i=0;i<edgesSize;i++){
		u=edges[i][0];
        v=edges[i][1];
        quiteedge[i]=false;
		deg[u]++;
        deg[v]++;
	}
    int nb=n;
	while(nb>2){
		for(i=0;i<edgesSize;i++){
            degwait[i]=0;
        }
        for(i=0;i<edgesSize;i++){
			if(!quiteedge[i]){
				u=edges[i][0]
                    ;v=edges[i][1];
				if(deg[u]==1){
                    quiteedge[i]=true;
                    ++degwait[u];
                    ++degwait[v];
                    nb--;
                    visited[u]=true;
                }
				else if(deg[v]==1){
                    quiteedge[i]=true;
                    ++degwait[u];
                    ++degwait[v];
                    nb--;
                    visited[v]=true;
                }
			}
		}
        for(i=0;i<n;i++){
            deg[i]-=degwait[i];                        }
	}
	int *returned=malloc(sizeof(*returned));
    *returnSize=0;
	for(i=0;i<n;i++){
		if(!visited[i]){
			returned=realloc(returned,++*returnSize*sizeof(*returned));
			returned[*returnSize-1]=i;
		}
	}
	return returned;
}

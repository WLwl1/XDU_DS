void ShortestPath_DIJ(MGraph G,int v0, Patharc *P,ShortPathTable *D)
{    
    int final[MAXVEX];
    D[0]=0;final[0]=TRUE;//V0到自己的路径权值为0，令final[0]=TRUE，初始化将V0加入S
    for(int i=1;i<G.vexnum;i++)
    {
        final[i]=FALSE;//初始化，FALSE代表尚未寻找到最短路径
        D[i]=G.arcs[0][i];//存在弧的话即为弧上的权值，无弧则置值为无穷大
        for(int j=0;j<G.vexnum;j++)  P[i][j]=FALSE;//初始化为空路径
        if(D[i]<INFINITY){//如果存在弧，即权值D[i]小于无穷，则说明必定存在从V0到Vi的最短路径
            P[i][0]=TRUE;//V0必定在该路径中
            P[i][i]=TURE;//Vi也在该路径中
        }//如果为暂时为无穷大不代表不存在最短路径
    }//开始主循环，找到V0到剩下n-1个顶点的最短路径，分别加入S中，并令final[i]=TRUE
    for(int i=1;i<G.vexnum;i++)
    {
        int min=INFINITY;int k=0;//设最短路径为INFINITY,k为该顶点位置
        for(int j=0;j<G.vexnum;j++)
            if(!final[j]&&D[j]<min){//顶点j在V-S中，且路径权值和小于Min
                k=j;//用k标记顶点位置
                min=D[j];
            }
        final[k]=TRUE;//将顶点k加入到S,表示已经找到V0到顶点Vk的最短路径
        for(int j=0;j<G.vexnum;j++)//更新权值代价分量,看通过经顶点k的路径能否减少路径代价
            if(!final[j]&&(min+G.arcs[k][j]<D[j])){ //顶点j必须还未找到路径
                D[j]=min+G.arcs[k][j];//如果可以经过顶点k减少路径，那么更新代价
                P[j]=P[k];P[j][j]=TRUE;//将V0到Vk的路径纳入V0到Vj的路径
            }//并且P[j][j]=TRUE,原先可能值为无穷无法判断有路径，现在可以确定有V0到Vj的路径
        }
    }
}

typedef int Pathmatrix[MAXVEX][MAXVEX]
typedef int ShortPathTable[MAXVEX][MAXVEX]
void ShortestPath_Floyd(MGraph G,Pathmatrix *P,ShortPathTable *D)
{   //初始化矩阵D和P
    for(int v=0;v<G.numVertexes;v++)
    {
        for(int w=0;w<G.numVertexes;w++)
        {
            (*D)[v][w]=G.matrix[v][w];//初始时就是邻接矩阵
            (*P)[v][w]=w;//无中间结点，有v到w的下一落脚顶点就是w
        }
    }
    for(int k=0;k<G.numVertexes;++k)//外层循环，寻找所有顶点经过顶点k到其他顶点的最短路径，更新D和P
    {   
        for(int v=0;v<G.numVertexes;++v)
        {
            for(int w=0;w<G.numVertexes;++w)
            {
                if( (*D)[v][w]>(*D)[v][k]+(*D)[k][w] )
                {
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];//如果经过顶点k距离更小，则更新权值
                    (*P)[v][w]=(*P)[v][k];//将由v到k的最短路径纳入v到w的最短路径
                }
            }
        }
    }
    return;
}//这代码是真的简洁优美

//打印最短路径的代码为：
for(int v=0;v<G.numVertexes;v++)
{    
    for(int w=v+1;w<G.numVertexes;w++)
    {
        printf("V%d——>V%d weight:%d",v,w,D[v][w]);//打印源点和终点以及路径权值和
        int k=P[v][w];//获取第一个路径顶点下标
        printf(" Path:%d",v);//打印源点
        while(k!=w){
            printf("-->%d",k);//打印路径中间顶点
            k=P[k][w];//寻找到下一个路径终点顶点
        }
        printf("-->%d\n",w);//打印终点
    }
    printf("\n");
}

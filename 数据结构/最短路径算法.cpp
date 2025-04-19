void ShortestPath_DIJ(MGraph G,int v0, Patharc *P,ShortPathTable *D)
{    
    int final[MAXVEX];
    D[0]=0;final[0]=TRUE;//V0���Լ���·��ȨֵΪ0����final[0]=TRUE����ʼ����V0����S
    for(int i=1;i<G.vexnum;i++)
    {
        final[i]=FALSE;//��ʼ����FALSE������δѰ�ҵ����·��
        D[i]=G.arcs[0][i];//���ڻ��Ļ���Ϊ���ϵ�Ȩֵ���޻�����ֵΪ�����
        for(int j=0;j<G.vexnum;j++)  P[i][j]=FALSE;//��ʼ��Ϊ��·��
        if(D[i]<INFINITY){//������ڻ�����ȨֵD[i]С�������˵���ض����ڴ�V0��Vi�����·��
            P[i][0]=TRUE;//V0�ض��ڸ�·����
            P[i][i]=TURE;//ViҲ�ڸ�·����
        }//���Ϊ��ʱΪ����󲻴����������·��
    }//��ʼ��ѭ�����ҵ�V0��ʣ��n-1����������·�����ֱ����S�У�����final[i]=TRUE
    for(int i=1;i<G.vexnum;i++)
    {
        int min=INFINITY;int k=0;//�����·��ΪINFINITY,kΪ�ö���λ��
        for(int j=0;j<G.vexnum;j++)
            if(!final[j]&&D[j]<min){//����j��V-S�У���·��Ȩֵ��С��Min
                k=j;//��k��Ƕ���λ��
                min=D[j];
            }
        final[k]=TRUE;//������k���뵽S,��ʾ�Ѿ��ҵ�V0������Vk�����·��
        for(int j=0;j<G.vexnum;j++)//����Ȩֵ���۷���,��ͨ��������k��·���ܷ����·������
            if(!final[j]&&(min+G.arcs[k][j]<D[j])){ //����j���뻹δ�ҵ�·��
                D[j]=min+G.arcs[k][j];//������Ծ�������k����·������ô���´���
                P[j]=P[k];P[j][j]=TRUE;//��V0��Vk��·������V0��Vj��·��
            }//����P[j][j]=TRUE,ԭ�ȿ���ֵΪ�����޷��ж���·�������ڿ���ȷ����V0��Vj��·��
        }
    }
}

typedef int Pathmatrix[MAXVEX][MAXVEX]
typedef int ShortPathTable[MAXVEX][MAXVEX]
void ShortestPath_Floyd(MGraph G,Pathmatrix *P,ShortPathTable *D)
{   //��ʼ������D��P
    for(int v=0;v<G.numVertexes;v++)
    {
        for(int w=0;w<G.numVertexes;w++)
        {
            (*D)[v][w]=G.matrix[v][w];//��ʼʱ�����ڽӾ���
            (*P)[v][w]=w;//���м��㣬��v��w����һ��Ŷ������w
        }
    }
    for(int k=0;k<G.numVertexes;++k)//���ѭ����Ѱ�����ж��㾭������k��������������·��������D��P
    {   
        for(int v=0;v<G.numVertexes;++v)
        {
            for(int w=0;w<G.numVertexes;++w)
            {
                if( (*D)[v][w]>(*D)[v][k]+(*D)[k][w] )
                {
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];//�����������k�����С�������Ȩֵ
                    (*P)[v][w]=(*P)[v][k];//����v��k�����·������v��w�����·��
                }
            }
        }
    }
    return;
}//���������ļ������

//��ӡ���·���Ĵ���Ϊ��
for(int v=0;v<G.numVertexes;v++)
{    
    for(int w=v+1;w<G.numVertexes;w++)
    {
        printf("V%d����>V%d weight:%d",v,w,D[v][w]);//��ӡԴ����յ��Լ�·��Ȩֵ��
        int k=P[v][w];//��ȡ��һ��·�������±�
        printf(" Path:%d",v);//��ӡԴ��
        while(k!=w){
            printf("-->%d",k);//��ӡ·���м䶥��
            k=P[k][w];//Ѱ�ҵ���һ��·���յ㶥��
        }
        printf("-->%d\n",w);//��ӡ�յ�
    }
    printf("\n");
}

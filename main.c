#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main(int argc, char* argv[])
{
    FILE *f1=fopen(argv[1],"rt"),*f2=fopen(argv[2],"rt"), *f3=fopen(argv[3],"wt+");
    testfis(f1);
    testfis(f2);
    testfis(f3);
    int v[5],i,nrech;
    for(i=0; i<5; i++)
        fscanf(f1,"%d",&v[i]);
    NodeEch *headech=NULL,*headcpy,*castig=NULL,*invins=NULL,*ult8=NULL;
    Queue *q;
    citfis(f2,&q,&nrech,&headech);
    if(v[3]==1)
    {
        elimina(&headech,&nrech);
        task3(f3,&castig,&ult8,&nrech,&invins,&q,headech);
        NodeGraph *root=NULL;
        BST(f3,&ult8,&root);
    }
    else if(v[2]==1)
    {
        elimina(&headech,&nrech);
        task3(f3,&castig,&ult8,&nrech,&invins,&q,headech);
    }
    else if(v[1]==1)
    {
        elimina(&headech,&nrech);
        task1(f3,headech);
    }
    else if(v[0]==1)
        task1(f3,headech);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}

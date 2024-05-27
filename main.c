#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main(int argc, char* argv[])
{
    FILE *f1=fopen(argv[1],"rt"),*f2=fopen(argv[2],"rt"), *f3=fopen(argv[3],"wt+");
    if(f1==NULL)
    {
        printf("Fisierul f1 nu a putut fi deschis!");
        exit(1);
    }
    if(f2==NULL)
    {
        printf("Fisierul f2 nu a putut fi deschis!");
        exit(1);
    }
    if(f3==NULL)
    {
        printf("Fisierul f3 nu a putut fi deschis!");
        exit(1);
    }
    int v[5],i,nrech,n=1;
    char a;
    for(i=0; i<5; i++)
        fscanf(f1,"%d",&v[i]);
    NodeEch *headech=NULL,*headcpy,*castig=NULL,*invins=NULL,*ult8=NULL;
    fscanf(f2,"%d",&nrech);
    fscanf(f2,"%c",&a);
    citire(f2,&headech,&nrech);
    headcpy=headech;
    Queue *q;
    q=createQueue();
    if(v[3]==1)
    {
        elimina(&headech,&nrech);
        while(nrech>1)
        {
            if(nrech==8)
            {
                headcpy=castig;
                while(headcpy!=NULL)
                {addAtBeginning8(&ult8,headcpy);
                headcpy=headcpy->next;
                }
            }

            if(n==1)
            adaugqueue(q,&headech,n);
            else
            adaugqueue(q,&castig,n);
            printqueue(f3,q->front,n);
            printround(f3,q->front,n,&castig,&invins);
            deleteinvins(&invins);
            printcastig(f3,castig,n);
            while(!isEmpty(q))
                deQueue(q);
            n++;
            nrech=nrech/2;
        }
        NodeGraph *root=NULL;
        headcpy=ult8;
        while(headcpy!=NULL)
        {
            root=insertg(root,headcpy);
            headcpy=headcpy->next;
        }
        fprintf(f3,"\n");
        fprintf(f3,"TOP 8 TEAMS:\n");
        descresc(f3,root);
    }
    else if(v[2]==1)
    {
        elimina(&headech,&nrech);
        while(nrech>1)
        {
            if(nrech==8)
            {
                headcpy=castig;
                while(headcpy!=NULL)
                {addAtBeginning8(&ult8,headcpy);
                headcpy=headcpy->next;
                }
            }

            if(n==1)
            adaugqueue(q,&headech,n);
            else
            adaugqueue(q,&castig,n);
            printqueue(f3,q->front,n);
            printround(f3,q->front,n,&castig,&invins);
            deleteinvins(&invins);
            printcastig(f3,castig,n);
            while(!isEmpty(q))
                deQueue(q);
            n++;
            nrech=nrech/2;
        }
    }
    else if(v[1]==1)
    {
        elimina(&headech,&nrech);
        headcpy=headech;
        while(headcpy!=NULL)
        {
            fprintf(f3,"%s\n",headcpy->numech);
            headcpy=headcpy->next;
        }
    }
    else if(v[0]==1)
    {
        headcpy=headech;
        while(headcpy!=NULL)
        {
            fprintf(f3,"%s\n",headcpy->numech);
            headcpy=headcpy->next;
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}


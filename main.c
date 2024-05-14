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
    int v[5],i;
    for(i=0;i<5;i++)
        fscanf(f1,"%d",&v[i]);
    NodeEch *headech=NULL,*headcpy;
    citire(f2,&headech);
    if(v[0]==1)
    {
    headcpy=headech;
    while(headcpy!=NULL)
    {
        fprintf(f3,"%s\n",headcpy->numech);
        headcpy=headcpy->next;
    }
    }
    fclose(f2);
    fclose(f3);
    return 0;
}


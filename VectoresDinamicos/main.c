#include <stdio.h>
#include <stdlib.h>
#define T 5


int main()
{
    int* pVec,aux;

    /*pVec =(int*)malloc(sizeof(int)*T);malloc memoria dinamica recibe un sizeof*/
    pVec =(int*)calloc(sizeof(int),T);///Calloc inicializa la cosa en 0 recibe 2 tamaños

    int i;
    for(i = 0; i<T; i++)
    {
        ///*(pVec+i) = i+1;
        printf("Ingrese un numero: ");
        scanf("%d", pVec+i);
    }
    for(i = 0; i<T; i++)
    {
        printf("%d\n", *(pVec+i));
    }

    aux = (int*)realloc(pVec, sizeof(int)*10);
    if(aux != NULL)
    {
        pVec = aux;
        for(i = 0; i<10; i++)
        {
            ///*(pVec+i) = i+1;
            printf("Ingrese un numero: ");
            scanf("%d", pVec+i);
        }
        for(i = T; i<10; i++)
        {
            printf("%d\n", *(pVec+i));
        }
    }


    return 0;

}

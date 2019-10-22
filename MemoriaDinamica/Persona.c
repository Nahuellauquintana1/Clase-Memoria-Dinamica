#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

ePersona* new_Persona()
{
    ePersona* puntero;
    puntero = (ePersona*)malloc(sizeof(ePersona));
    return puntero;
}

void delete_Persona(ePersona* unaPersona)
{
    free(unaPersona);
}
void mostrarPersona(ePersona* unaPersona)
{
    if(unaPersona != NULL)
    {
        printf("La persona es:\n");
        printf("%d--%c--%.2f", unaPersona->legajo,unaPersona->sexo,unaPersona->altura);
    }
}
ePersona* new_Persona_Con_Valores(int legajo, char sexo, float altura)
{
    ePersona* unaPersona;

    unaPersona = new_Persona();
    if(unaPersona != NULL)
    {
        unaPersona->altura = altura;
        unaPersona->legajo = legajo;
        unaPersona->sexo = sexo;
    }

    return unaPersona;
}

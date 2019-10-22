#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    ePersona* puntero = new_Persona_Con_Valores(15,'m',1.78);

    mostrarPersona(puntero);

    delete_Persona(puntero);


    /*free(puntero);///Libera el puntero desreferencia
    puntero = NULL; ///Es optimo hacerlo abajo del free para no poder usar los datos por error*/


    return 0;
}

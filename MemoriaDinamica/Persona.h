typedef struct
{
    int legajo;
    char sexo;
    float altura;
} ePersona;

ePersona* new_Persona();//Constructor por defecto
void delete_Persona(ePersona*);
void mostrarPersona(ePersona* unaPersona);
ePersona* new_Persona_Con_Valores(int, char,float);

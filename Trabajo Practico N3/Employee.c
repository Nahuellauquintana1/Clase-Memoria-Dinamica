#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validar.h"

int employee_setId(Employee* this,int id)
{

    int todoOk = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;

    if( this != NULL && id != NULL )
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL && strlen(nombre) > 3)
    {

        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;

    if( this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {


                    this->id = atoi(idStr);

                    strcpy(this->nombre,nombreStr);

                    this->horasTrabajadas = atoi(horasTrabajadasStr);

                    this->sueldo = atoi(sueldoStr);

        }
    }

    return this;
}


void mostrarEmpleado(Employee* emp)
{
    if(emp != NULL)
    {
        printf("%10d %20s %10d %10d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

int sortEmpleadoId(void* e1,void* e2)
{
    int retorno = -1;
    int id,id2;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;
    employee_getId(empleado1, &id);
    employee_getId(empleado2,&id2);
    if( id > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id == id2)
        {
            retorno = 0;
        }

    }

    return retorno;
}

int sortEmpleadoName(void* e1,void* e2)
{
    int retorno = -1;
    int comparacion;

    Employee* empleado1 = (Employee*)e1;
    Employee* empleado2 = (Employee*)e2;

    char n1[50];
    employee_getNombre(e1, n1);
    char n2[50];
    employee_getNombre(e2, n2);

    comparacion = strcmp(n1,n2);

    return comparacion;
}

int mostrarLista(Employee* lista)
{
    int i, tam;
    tam = ll_len(lista);

    Employee* aux;
    printf("ID\tNombre\t    Horas\t    Sueldo\n");
    for(i= 0; i<tam ; i++)
    {
        aux = (Employee*)ll_get(lista,i);
        mostrarEmpleado(aux);

    }


    return 0;
}

Employee* altaEmpleado ()
{

   Employee* unEmpleado = employee_new();
   char auxNombre[50];
   int auxHoras[50];
   int auxSueldo[50];

   //employee_setId();
   getValidString("Ingrese el nombre del Empleado: ","\nIngrese un Nombre",0,51,auxNombre);
   employee_setNombre(unEmpleado,auxNombre);
   getValidInt("Ingrese las Horas trabajadas:","\nIngrese numeros",0,168,auxHoras);
   employee_setHorasTrabajadas(unEmpleado,auxHoras);
   getValidInt("Ingrese el sueldo del Empleado: ","\nIngrese un numero",0,100000,auxSueldo);
   employee_setSueldo(unEmpleado,auxSueldo);

   return unEmpleado;

   }
///W.I.P
/*int buscarIndice(Employee* lista,int id)
{
    int i, tam,auxId;
    tam = ll_len(lista);
    printf("hola");
    for(i = 0; i < tam; i++)
    {
        if( == id)
        {
            return i;

        }
    }

return -1;

}*/

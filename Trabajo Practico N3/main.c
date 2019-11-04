#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validar.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

///Falta ID automatico
int main()
{
    FILE* dArchivo;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* aux;
    Employee* auxGet;
    int auxId, auxIndice;
    int opcion;
    char auxRemove;
    do
    {
        getValidInt("1. Cargar Datos Textos\n2. Cargar Datos Binario\n3. Alta Epleado\n4. Modificar Empleado\n5. Baja Empleado\n6. Listar Empleados\n7. Ordenar\n8. Guardar modo Texto\n9. Guardar modo Binario\n10. Salir\nOpcion: ","Error Por favor Ingrese numeros Validos",0,11,&opcion);

        switch(opcion)
        {
        case 1:
            parser_EmployeeFromText(dArchivo,listaEmpleados);
            break;
        case 2:
            parser_EmployeeFromBinary(dArchivo,listaEmpleados);
            break;
        case 3:
            aux = (Employee*)altaEmpleado();
            ll_add(listaEmpleados,aux);
            break;
        case 4:
            ///Modif Empleado
            break;
        case 5:
            mostrarLista(listaEmpleados);
            getValidInt("Ingrese id del Empleado a Eliminar: ","\nIngerse un Numero valido",0,1000,&auxId);
            auxGet = (Employee*)ll_get(listaEmpleados,auxId);
            mostrarEmpleado(auxGet);
            auxRemove = getChar("Esta seguro que desea Eliminar este empleado? (s/n)");
            if(auxRemove == 's')
            {
                ll_remove(listaEmpleados,auxId);
                printf("Empleado Eliminado");
            }
            break;
        case 6:
            mostrarLista(listaEmpleados);
            break;
        case 7:
            printf("Ordenano Espere\n");
            ll_sort(listaEmpleados,sortEmpleadoId,0);///lista, funcion SOLO nombre sin parentesis, orden 1 --- 0
            break;
        case 8:
            ///Guardar Texto
            break;
        case 9:
            ///Guardar Binario
            break;
        case 10:
            opcion = 10;
            break;
        }
        system("pause");
        system("cls");


    }
    while(opcion!=10);

    return 0;
}

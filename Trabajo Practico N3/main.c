#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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


int main()
{
    ///int option = 0;
    int tam;

    FILE* dArchivo;
    LinkedList* listaEmpleados = ll_newLinkedList();
    parser_EmployeeFromText(dArchivo,listaEmpleados);

    //Employee* e1 = employee_newParametros("5","Maria","10","5000");
    //Employee* e2 = employee_newParametros("2","Jose","20","6000");
    ///Employee* e3 = employee_newParametros("6","Pedro","15","7000");
   /// Employee* e4 = employee_newParametros("8","Juan","24","8450");

    //ll_add(listaEmpleados, e1);
    //ll_add(listaEmpleados, e2);
   /// ll_add(listaEmpleados, e3);
  ///  ll_push(listaEmpleados,1, e4);
    ///ll_set(listaEmpleados,2,e4);
    ll_sort(listaEmpleados,sortEmpleadoId,1);///lista, funcion SOLO nombre sin parentesis, orden 1 --- 0
    ///ll_sort(listaEmpleados,sortEmpleadoName,1);

    tam = ll_len(listaEmpleados);
    int i;
    Employee* aux;
    printf("ID\tNombre\t    Horas\t    Sueldo\n");
    for(i= 0; i<tam ; i++)
    {
        aux = (Employee*)ll_get(listaEmpleados,i);
        mostrarEmpleado(aux);

    }



    /**ll_clear(listaEmpleados);
    tam = ll_len(listaEmpleados);
    printf("\nTam lista despues de ll_clear: %d",tam);
    **/
    ///ll_deleteLinkedList(listaEmpleados); borra la lista entera.


    return 0;
}

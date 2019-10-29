#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
     char id [50];
     char nombre [50];
     char horasTrabajadas[50];
     char sueldo[50];
int i=0;
     pFile = fopen("data.csv","r");
      fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
     while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        Employee* unEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee, unEmpleado);
 //ll_get(pArrayListEmployee,i));


    }

    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

     char id [50];
     char nombre [50];
     char horasTrabajadas[50];
     char sueldo[50];

     pFile = fopen("data.csv","rb");
     while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        Employee* unEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
        ll_add(pArrayListEmployee, unEmpleado);

    }

    fclose(pFile);

    return 1;
}

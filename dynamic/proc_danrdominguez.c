//Estudiante: Alain Daniel Rodr'iguez Dom'inguez.

#include "../rpc.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    reportable_t parent;

    int n;//Grado de la potencia de 2 hasta la cual se sumar'a.
    long unsigned int acc; //Esta variable acumular'a la suma de las potencias de 2 hasta el grado indicado por "n".
} students_struct_t;//El nombre de la estructura fue cambiado a "students_struct".

void *parse_parameters(void *data)
{
    const char *buf = (const char *)(data);

    my_struct_t *d = (students_struct_t *)(malloc(sizeof(students_struct_t)));

    if (d)
    {
        sscanf(buf, "%d", &d->n);//Lee por consola el valor de d->n.    
    }

    return (void *)d;
}

void *do_work(void *data)//Esta funci'on halla la suma de las potencias de 2 hasta el grado indicado por d->n y lo guarda en d->acc.
{
    students_struct_t *d = (students_struct_t *)(data);

    int n=d->n;
    long unsigned int acumulador=0;

    int i=0;
    int power_of_two=1;
    while(i<=n){
        acumulador+=power_of_two;
        power_of_two*=power_of_two;
        i++;
    }
    d->acc=acumulador;
    return data;
}

reportable_t *report(void *data)
{
    students_struct_t *d = (students_struct_t *)(data);

    d->parent.data = (char *)(malloc(255 * sizeof(char)));

    snprintf(d->parent.data, 255, "La suma de potencias de 2 hasta el grado %d = %ld\n", d->n, d->acc);//Imprime la informaci'on correspondiente.
    d->parent.len = strlen(d->parent.data);

    return (reportable_t *)(data);
}

void clean_up(void *params, void *result, reportable_t *report)
{
    if (report && report->data)
    {
        free(report->data);
    }

    if (params)
    {
        free(params);
    }
}

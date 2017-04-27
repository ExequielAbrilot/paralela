#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datos
{
    char ip[20];
    int dia;
    char mes[10];
    int anio;
};

int main()
{

    char texto[1];
    char fecha[26];

    FILE *puntero;
    FILE *nuevo;

    int i;

    struct datos los_datos;

    if ((puntero =fopen("clientes.txt","r"))==NULL )
    {
        printf("El archivo no se pudo abrir!!");
    }
    else
    {


       while(!feof(puntero))
       {

            fread(texto,sizeof(char),1,puntero);
            if (*texto=='[')
            {
                fread(fecha,sizeof(char)*26,1,puntero);
                //printf("\n\n%s\n",&fecha);

                if ((nuevo =fopen("fechas.txt","a"))==NULL )
                {
                    printf("El archivo no se pudo abrir!!");
                }
                else
                {

                    fwrite(fecha,sizeof(char)*27,1,nuevo);

                    char *otra_fecha= fecha;
                    char vacio1[]="";
                    char hora[2];
                    char *creoqeno,*creoqeno2;
                    strcpy(hora,vacio1);

                    creoqeno=otra_fecha[12];
                    creoqeno2=otra_fecha[13];
                    //printf("%c\n",*creoqeno);
                    strcat(hora,&creoqeno);
                    strcat(hora,&creoqeno2);

                    printf("%d\n",atoi (hora));
                    //strcat(hora,&otra_fecha[13]);
                    //printf("%c\n",otra_fecha[12]);
                    //printf("%s",hora);
                    //funcion_hora(fecha,nuevo);


                }
            }

       }

       fclose(puntero);

    }
    return 0;

}

/*void funcion_hora(*char fecha[26], FILE *posicion)
{
    int i, hora;

    for(i=0; i<strlen(fecha); i++)
    {
        if(fecha[i]==':')
        {

        }
    }

    fread(hora,sizeof(char)*2,1,posicion);


}*/




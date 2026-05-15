#include <stdlib.h>

void mostrarMenuPrincipal() {
    printf("\n// IMPOSTOR //  Creado por ShinyDitto10\n");
    printf("Usa los numeros para navegar por el menu\n");
    if(partidaConfigurada == false){
        printf("*Atencion* No has configurado todavia la partida!\n");
    }
    printf("[1] Configuracion\n");
    printf("[2] Comenzar la partida\n");
    printf("[3] Creditos\n");
    printf("[4] Salir\n");
}

int elegirMenuPrincipal() {
    fgets(inputBufferMenu, 3, stdin);
    limpiarBufferStdin();
    switch(atoi(inputBufferMenu)){
        case 1:
          return 1;
        case 2:
          return 2;
        case 3:
          return 3;
        case 4:
          return 4;
        default:
          return 0;
    }
}

void mostrarCreditos() {
    printf("\n\nCREDITOS\n");
    printf("Programado por: ShinyDitto10\n");
    printf("Colabora con el proyecto en gitHub! https://github.com/ShinyDitto10/Impostor\n\n");
}
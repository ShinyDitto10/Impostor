#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mostrarMenuOpciones() {
    printf("CONFIGURACION\n");
    printf("Usa los numeros para navegar por el menu\n");
    printf("[1] Numero de jugadores: %d\n", numJugadores);
    printf("[2] Numero de impostores: %d\n", numImpostores);
    if(opcionPista == true){
        printf("[3] Pista para el impostor: [Si] No\n");
    } else{
        printf("[3] Pista para el impostor: Si [No]\n");
    }
    if(opcionConocer == true){
        printf("[4] Los impostores se conocen entre si: [Si] No\n");
    } else{
        printf("[4] Los impostores se conocen entre si: Si [No]\n");
    }
    printf("[5] Volver al menu principal\n");
}

int elegirOpciones() {
    fgets(inputBufferOpciones, 3, stdin);
    limpiarBufferStdin();
    switch(atoi(inputBufferOpciones)){
        case 1:
          return 1;
        case 2:
          return 2;
        case 3:
          return 3;
        case 4:
          return 4;
        case 5:
          return 5;
        default:
          return 0;
    }
}

int elegirNumJugadores() {
    printf("\nSelecciona el numero de jugadores (entre 3 y 12):\n");
    fgets(bufferJugadores, 3, stdin);
    limpiarBufferStdin();
    if(atoi(bufferJugadores) < 3){
        printf("Debe haber al menos 3 jugadores");
        return 1;
    } else if(atoi(bufferJugadores) > 12){
        printf("No puede haber mas de 12 jugadores");
        return 1;
    } else {
        numJugadores = atoi(bufferJugadores);
        return 0;
    }
}

int elegirNumImpostores() {
    printf("\nSelecciona el numero de impostores:\n");
    fgets(bufferImpostores, 3, stdin);
    limpiarBufferStdin();
    if(atoi(bufferImpostores) < 1){
        printf("Debe haber al menos un impostor");
        return 1;
    } else if(atoi(bufferImpostores) > numJugadores){
        printf("No puede haber tantos impostores");
        return 1;
    } else {
        numImpostores = atoi(bufferImpostores);
        return 0;
    }
}

int elegirBoolPista() {
    printf("Selecciona una opcion:\n");
    printf("[1] Activar pista para el impostor\n");
    printf("[2] Desactivar pista para el impostor\n");
    fgets(bufferBoolPista, 3, stdin);
    limpiarBufferStdin();
    if(atoi(bufferBoolPista) == 1){
        opcionPista = true;
        return 0;
    } else if(atoi(bufferBoolPista) == 2){
        opcionPista = false;
        return 0;
    } else {
        return 1;
    }
}

int elegirBoolConocer() {
    printf("Selecciona una opcion:\n");
    printf("[1] Activar que los impostores se conozcan\n");
    printf("[2] Desactivar que los impostores se conozcan\n");
    fgets(bufferBoolConocer, 3, stdin);
    limpiarBufferStdin();
    if(atoi(bufferBoolConocer) == 1){
        opcionConocer = true;
        return 0;
    } else if(atoi(bufferBoolConocer) == 2){
        opcionConocer = false;
        return 0;
    } else {
        return 1;
    }
}
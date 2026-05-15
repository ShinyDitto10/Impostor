#include <stdio.h>
#include <time.h>
#include <stdlib.h>

FILE * palabrasTXT;

int abrirPalabrasTXT() {
    palabrasTXT = fopen("palabras_impostor.txt", "r");
    if(palabrasTXT == NULL){
        printf("Ha habido un error al leer palabras_impostor.txt\n");
        return 1;
    } else{
        printf("palabras_impostor.txt se abrio correctamente\n\n");
        return 0;
    }
}

int comprNumPalabrasArchivo() {
    fgets(palabrasArchivo, 7, palabrasTXT);
    numPalabrasArchivo = atoi(palabrasArchivo);
    if(numPalabrasArchivo <= 0){
        printf("Ha habido un error al leer la primera linea de palabras_impostor.txt\n");
        return 1;
    } else{
        return 0;
    }
}

void crearPalabraGameplay() {
    srand(time(NULL));
    palabraElegida = rand() % numPalabrasArchivo;
    for(int i = 0; i < 5*palabraElegida + 1; i++){
        fgets(buffer, 99, palabrasTXT);
        //printf("%s", buffer);
    }
    fgets(palabraGameplay, 29, palabrasTXT);
    //printf("La palabra es %s\n", palabraGameplay);
}

void crearPistaGameplay() {
    srand(time(NULL));
    pistaGameplayID = rand() % 3;
    for(int i = 0; i < pistaGameplayID; i++){
        fgets(buffer, 99, palabrasTXT);
        //printf("%s", buffer);
    }
    fgets(pistaGameplay, 29, palabrasTXT);
    //printf("La pista es %s\n", pistaGameplay);
}

int cerrarPalabrasTXT() {
    if(fclose(palabrasTXT) != 0){
        printf("Ha habido un error al cerrar palabras_impostor.txt");
        return 1;
    } else {
        return 0;
    }
}

void crearImpostores() {
    srand(time(NULL));
    do{
    for(int i = 0; i < numImpostores; i++){
        impostoresJ[i] = rand() % numJugadores;
    }
    //Que línea más preciosa, por dios. (Ya arreglaré esto, supongo)
    } while(impostoresJ[0] == impostoresJ[1] || impostoresJ[0] == impostoresJ[2] || impostoresJ[0] == impostoresJ[3] || impostoresJ[1] == impostoresJ[2] || impostoresJ[1] == impostoresJ[3] || impostoresJ[2] == impostoresJ[3]); 
    //printf("Los impostores son: %d, %d, %d, %d\n", impostoresJ[0], impostoresJ[1], impostoresJ[2], impostoresJ[3]);
}

void mostrarPalabras() {
    char bufferInputGameplay[100];
    for(int i = 0; i < numJugadores; i++){
    limpiarPantalla();
    printf("Jugador %d, pulsa enter para ver tu palabra\n", i + 1);
    fgets(bufferInputGameplay, 99, stdin);
    limpiarBufferStdin();
    bufferInputGameplay[0] = '\0';
    bufferInputGameplay[1] = '\0';
    limpiarPantalla();
    if(i == impostoresJ[0] || i == impostoresJ[1] || i == impostoresJ[2] || i == impostoresJ[3]){
        if(opcionPista == true){
        printf("Jugador %d, eres un IMPOSTOR, tu pista es %s\n", i + 1, pistaGameplay);
        } else {
            printf("Jugador %d, eres un IMPOSTOR, buena suerte!", i + 1);
        }
    } else {
        printf("Jugador %d, la palabra es %s\n", i + 1, palabraGameplay);
    }
    printf("Presiona enter 1 VEZ para continuar, jugador %d\n", i + 1);
    limpiarBufferStdin();
    }
}

void seleccionarPrimerJugador() {
    srand(time(NULL));
    int jugadorComienza = rand() % numJugadores;
    limpiarPantalla();
    printf("Empieza el jugador %d\n", jugadorComienza + 1);
    printf("Pulsa enter para revelar la palabra y a los impostores\n");
}

void revelarImpostores() {
    printf("La palabra era %s\n\n", palabraGameplay);
    if (numImpostores == 1){
        printf("El impostor era el jugador %d\n", impostoresJ[0] + 1);
    } else {
        printf("Los impostores eran:\n");
        for(int i = 0; i < numImpostores; i++){
            printf("Jugador %d\n", impostoresJ[i] + 1);
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void reset(void){
    //Limpia el buffer de entrada para que fgets() funcione bien (sigue habiendo
    //algún bug pero no sé como arreglarlo)
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear(void){
    //Imprime montones de saltos de línea para limpiar la pantalla
    for(int s = 0; s < 100; s++){
        printf("\n");
    }
}

int main(){

    srand(time(NULL));
    char buffer[100];

    //Abre el archivo "palabras_impostor.txt"
    //Si no existe, el programa se cierra con un error
    FILE * palabrasTXT;
    palabrasTXT = fopen("palabras_impostor.txt", "r");
    if(palabrasTXT == NULL){
        printf("Ha habido un error al leer palabras_impostor.txt\n");
        return 1;
    } else{
        printf("palabras_impostor.txt se abrio correctamente\n\n");
    }

    //Lee la primera línea de "palabras_impostor.txt", que contiene el número total de
    //grupos de palabras con sus pistas que hay en el archivo
    char palabrasArchivo[8];
    fgets(palabrasArchivo, 7, palabrasTXT);
    int numPalabrasArchivo = atoi(palabrasArchivo);
    if(numPalabrasArchivo <= 0){
        printf("Ha habido un error al leer la primera linea de palabras_impostor.txt\n");
        return 1;
    }

    //Selecciona la palabra que se usará en la partida al azar
    int palabraElegida;
    palabraElegida = rand() % numPalabrasArchivo;
    for(int i = 0; i < 5*palabraElegida + 1; i++){
        fgets(buffer, 99, palabrasTXT);
        //printf("%s", buffer);
    }
    char palabraGameplay[30];
    fgets(palabraGameplay, 29, palabrasTXT);
    //printf("La palabra es %s\n", palabraGameplay);
    char pistaGameplay[30];
    int pistaGameplayID = rand() % 3;
    for(int b = 0; b < pistaGameplayID; b++){
        fgets(buffer, 99, palabrasTXT);
        //printf("%s", buffer);
    }
    fgets(pistaGameplay, 29, palabrasTXT);
    //printf("La pista es %s\n", pistaGameplay);

    if(fclose(palabrasTXT) != 0){
        printf("Ha habido un error al cerrar palabras_impostor.txt");
        return 1;
    }


    //Seleccionar el número de jugadores
    char jugadores[4];
    printf("Cuantos van a jugar? (entre 2 y 12)\n");
    fgets(jugadores, 3, stdin);
    int numJugadores = atoi(jugadores);
    if (numJugadores < 2 || numJugadores > 12){
        printf("Numero no valido");
        return 1;
    }
    
    reset();

    //Seleccionar el número de impostores
    char impostores[3];
    printf("Cuantos impostores va a haber? (entre 1 y 4)\n");
    fgets(impostores, 2, stdin);
    int numImpostores = atoi(impostores);
    if (numImpostores < 1 || numImpostores > 4 || numImpostores > numJugadores){
        printf("No puede haber ese numero de impostores");
        return 1;
    }
    printf("La partida de %d jugadores con %d impostores va a empezar\n", numJugadores, numImpostores);

    //Crea a los jugadores y a los impostores
    int impostoresJ[4] = {13, 14, 15, 16};
    do{
        for(int j = 0; j < numImpostores; j++){
            impostoresJ[j] = rand() % numJugadores;
        }
    //Que línea más preciosa, por dios. (Ya arreglaré esto, supongo)
    } while(impostoresJ[0] == impostoresJ[1] || impostoresJ[0] == impostoresJ[2] || impostoresJ[0] == impostoresJ[3] || impostoresJ[1] == impostoresJ[2] || impostoresJ[1] == impostoresJ[3] || impostoresJ[2] == impostoresJ[3]); 
    //printf("Los impostores son: %d, %d, %d, %d\n", impostoresJ[0], impostoresJ[1], impostoresJ[2], impostoresJ[3]);
    
    //Gameplay
    char placeHold[3];
    for(int k = 0; k < numJugadores; k++){
        clear();
        printf("Jugador %d, pulsa enter para ver tu palabra\n", k + 1);
        fgets(placeHold, 2, stdin);
        reset();
        placeHold[0] = '\0';
        placeHold[1] = '\0';
        clear();
        if(k == impostoresJ[0] || k == impostoresJ[1] || k == impostoresJ[2] || k == impostoresJ[3]){
            printf("Jugador %d, eres un IMPOSTOR, tu pista es %s\n", k + 1, pistaGameplay);
        } else {
            printf("Jugador %d, la palabra es %s\n", k + 1, palabraGameplay);
        }
        printf("Presiona enter 1 VEZ para continuar, jugador %d\n", k + 1);
        reset();
    }
    int jugadorComienza = rand() % numJugadores;
    clear();
    printf("Empieza el jugador %d\n", jugadorComienza + 1);
    printf("Pulsa enter para revelar la palabra y a los impostores\n");
    reset();
    clear();
    printf("La palabra era %s\n\n", palabraGameplay);
    if (numImpostores == 1){
        printf("El impostor era el jugador %d\n", impostoresJ[0] + 1);
    } else {
        printf("Los impostores eran:\n");
        for(int l = 0; l < numImpostores; l++){
            printf("Jugador %d\n", impostoresJ[l] + 1);
        }
    }
    reset();

    printf("\nAdios!");
    return 0;

}
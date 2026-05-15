#include <stdbool.h>
#include <stdio.h>

char bufferJugadores[4];
int numJugadores = 6;
char bufferImpostores[4];
int numImpostores = 2;
char inputBufferOpciones[4];
char bufferBoolPista[3];
bool opcionPista = true;
char bufferBoolConocer[3];
bool opcionConocer = false;
char palabrasArchivo[8];
int numPalabrasArchivo;
char buffer[100];
int palabraElegida;
char palabraGameplay[30];
char pistaGameplay[30];
int pistaGameplayID;
int impostoresJ[4] = {13, 14, 15, 16};
bool partidaConfigurada = false;
char inputBufferMenu[4];

void limpiarBufferStdin() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void limpiarPantalla() {
    for(int i = 0; i < 100; i++){
        printf("\n");
    }
}
#include "impostor.h"
#include "opciones.h"
#include "gameplay.h"
#include "menu_principal.h"

int main() {

    if(abrirPalabrasTXT() == 1){
        return 1;
    }
    if(comprNumPalabrasArchivo() == 1){
        return 1;
    }
    int m = 4;
    do{
    mostrarMenuPrincipal();
    m = elegirMenuPrincipal();
    switch(m){
        case 1:
           int b;
           do{
           mostrarMenuOpciones();
           b = elegirOpciones();
           switch(b){
              case 1:
                 int a = 1;
                 do{
                     a = elegirNumJugadores();
                 } while(a == 1);
                 break;
              case 2:
                 a = 1;
                 do{
                     a = elegirNumImpostores();
                 } while(a == 1);
                 break;
              case 3:
                 a = 1;
                 do{
                 a = elegirBoolPista();
                 } while(a == 1);
                 break;
              case 4:
                 a = 1;
                 do{
                 a = elegirBoolConocer();
                 } while(a == 1);
                 break;
              case 0:
                 printf("Inserta un numero valido\n\n");
                 break;        
           }
           } while (b != 5);
           partidaConfigurada = true;
           break;
        case 2:
           crearPalabraGameplay();
           crearPistaGameplay();
           crearImpostores();
           mostrarPalabras();
           seleccionarPrimerJugador();
           limpiarBufferStdin();
           revelarImpostores();
           cerrarPalabrasTXT();
           abrirPalabrasTXT();
           comprNumPalabrasArchivo();
           break;
        case 3:
           mostrarCreditos();
           break;
        case 4:
           break;
        default:
           printf("Inserta un numero valido\n\n");
           break;
        }
    } while (m != 4);

    cerrarPalabrasTXT();
    printf("Adios! :)\n");
    return 0;
}
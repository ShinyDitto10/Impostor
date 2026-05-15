#include "impostor.h"
#include "opciones.h"
#include "gameplay.h"
#include "menu_principal.h"

int main() {

    abrirPalabrasTXT();
    comprNumPalabrasArchivo();
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
                 printf("Inserta un numero valido");
                 break;        
           }
           } while (b != 5);
           partidaConfigurada = true;
           break;
        case 2:
           crearPalabraGameplay();
           crearPistaGameplay();
           if(cerrarPalabrasTXT() == 1){
            return 1;
           }
           crearImpostores();
           mostrarPalabras();
           seleccionarPrimerJugador();
           limpiarBufferStdin();
           revelarImpostores();
           break;
        case 3:
           mostrarCreditos();
           break;
        case 4:
           break;
        default:
           printf("Inserta un numero valido");
           break;
        }
    } while (m != 4);

    printf("Adios! :)\n");
    return 0;
}
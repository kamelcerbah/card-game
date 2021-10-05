#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <Allegro.h>
#include "menuDeJeu.h"

int main()
{


    allegro_init();
    //install_int_ex(Increment,BPS_TO_TIMER(100));
    ///initialisation de program Allegro 4
    set_window_title("Luck card game"); // nom de program
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    /// taille de l'écran avec 640 en largeur et 480 en hauteur
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);

    /// -> menuDeJeu.h
    menuDeJeu();


    readkey();

    return 0 ;
}
END_OF_MAIN();



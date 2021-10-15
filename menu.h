#include"Headers/play_cards.h"
#include "Headers/hidden_cards.h"
#include "Headers/cards_to_play.h"
#include "Headers/player.h"
#include "Headers/party.h"


//#include "menu.h"
#include "aid.h"
#include "scorescreen.h"

#include "board.h"
//#include "Headers/nomdejoueurs.h"


///exit button
volatile bool Fermer = false ;
void Handler ()
{
    Fermer = true;
}


void menuDeJeu(void)
{
    Partie partie ;


    ///exit si il tape sur x
    LOCK_FUNCTION(Handler);

    int w = 800;
    int h = 600;
    /// counter to select from menu
    int counter =0;


    /// double buffering screen
    BITMAP *menuScreen = create_bitmap(w,h);

    /// background image
    BITMAP *BackGroundImage = malloc(sizeof(BITMAP));

    /// fermer le program
    set_close_button_callback(Handler);

    /// ne pas quitter tant que esc n'est pas pressé
    while(!Fermer)
    {
        /// Logic de selection

        if(key[KEY_DOWN])
            counter++;

        if(key[KEY_UP])
            counter--;

        if(counter>4 )
            counter=0;

        if(counter<0)
            counter=4;

        switch(counter)
        {
        case 1:
            BackGroundImage = load_bitmap("assets/menu_screen/menu_screen2.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_bitmap(menuScreen);
                /// -> partie.h
                Partie newPartie ;
                initPartie(&newPartie,1,0);


                /// -> nomDeJoueurs.h
                //nomDeJoueurs(w,h,2,&newPartie);

                strcpy(newPartie.joueurs[0].nom,"Lucky Player");

                /// plateauDeJeu.h
                plateauDeJeu(&newPartie);
                rest(40);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,w,h,0,0);

                /*
                clear_bitmap(menuScreen);
                menu(w,h,1); //prv :    menu(w,h,nb+1);    use nb+1 when  u finish the "work on this later"  Line 39
                rest(50);
                */
            }


            break;
        case 2:// partie saved
            BackGroundImage = load_bitmap("assets/menu_screen/menu_screen3.bmp",NULL);
            if(key[KEY_ENTER])
            {
                partie = readPartieData();

                clear_bitmap(menuScreen);

                plateauDeJeu(&partie);

                rest(40);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,w,h,0,0);

            }

            break;
        case 3:
            BackGroundImage = load_bitmap("assets/menu_screen/menu_screen4.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_bitmap(menuScreen);
                aideMenu(w,h);
                rest(50);
            }
            break;

        case 4:
            BackGroundImage = load_bitmap("assets/menu_screen/menu_screen5.bmp",NULL);
            if(key[KEY_ENTER])
                Handler();
            break;
        default:
            BackGroundImage = load_bitmap("assets/menu_screen/menu_screen1.bmp",NULL);
            break;

        }

        ///set background image for menu
        blit(BackGroundImage,menuScreen,0,0,0,0,w,h);

        //texte à afficher dans l'application
       // textout_ex (menuScreen,font,"Appuyer sur ESC pour quitter",0,h-10,makecol(32,29,240),makecol(109,158,235));

        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);
        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }



}


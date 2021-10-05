#include "plateauDeJeu.h"
#include "Headers/nomdejoueurs.h"

/// <- menuDeJeu.h
void menu(int w,int h,int nbDePartie)
{
    // Use current time as seed for random generator
    srand(time(0));

/// counter to select from menu
    int counter =0;

    ///configuration de la police à partir du dossier source
    //FONT *font1 =load_font("font1.pcx",NULL,NULL);

    /// double buffering screen
    BITMAP *menuScreen = create_bitmap(w,h);
    /// background image
    BITMAP *menuImg = load_bitmap("assets/player_menu/menu_screen1.bmp",NULL);

    //text to display for test
    //textout_ex (backGroundImage,font1,"Hello World",round(w/2) -150 ,round(h/2),makecol(32,29,240),makecol(0,0,0)); //texte à afficher dans l'application


    /// not exiting till esc is pressed

    bool isDone= false;
    while(!isDone)
    {


        /// menu functionlity
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        /// logic de selection


        if(key[KEY_DOWN])
            counter++;

        if(key[KEY_UP])
            counter--;
        if(counter>3 )
            counter=1;

        if(counter<0)
            counter=3;

        /// anim les screen
        switch(counter)
        {
        case 1:
            menuImg = load_bitmap("assets/player_menu/menu_screen2.bmp",NULL);
            if(key[KEY_ENTER])
            {
                /// -> partie.h
                Partie newPartie ;
                initPartie(&newPartie,2,nbDePartie);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,2,&newPartie);

                /// plateauDeJeu.h
                plateauDeJeu(&newPartie);
                rest(40);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,w,h,0,0);

                isDone=true;

            }


            break;
        case 2:
            menuImg = load_bitmap("assets/player_menu/menu_screen3.bmp",NULL);
            if(key[KEY_ENTER])
            {

                Partie newPartie ;
                initPartie(&newPartie,3,nbDePartie);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,3,&newPartie);

                /// plateauDeJeu.h
                plateauDeJeu(&newPartie);
                rest(40);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

                isDone=true;

            }
            break;
        case 3:
            menuImg = load_bitmap("assets/player_menu/menu_screen4.bmp",NULL);
            if(key[KEY_ENTER])
            {
                Partie newPartie ;
                initPartie(&newPartie,4,nbDePartie);

                clear_bitmap(menuScreen);

                /// -> nomDeJoueurs.h
                nomDeJoueurs(w,h,4,&newPartie);

                /// plateauDeJeu.h
                plateauDeJeu(&newPartie);
                rest(40);
                set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

                isDone=true;
            }
            break;
        default:
            menuImg = load_bitmap("assets/player_menu/menu_screen1.bmp",NULL);
            break;

        }
        ///set background image for menu
        blit(menuImg,menuScreen,0,0,0,0,w,h);

        //texte à afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(32,29,240),makecol(109,158,235));

        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }


}


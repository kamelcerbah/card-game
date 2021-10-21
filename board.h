#include <stdio.h>
#include <stdlib.h>
#include "Headers/board_mouse_logic.h"
#include "Headers/board_logic.h"
#include "win_screen.h"
#include "lose_screen.h"
//const int partiesMax = 30 ;
// timer
long int timer  ;
void Increment()
{
    timer++;
}
END_OF_FUNCTION(Increment);
/// <- nomDeJoueurs
void plateauDeJeu(Partie *partie)
{
    install_timer();

    /// taille de l'écran
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,900,0,0);

    /// double buffering screen
    BITMAP *plateau = create_bitmap(1024,900);

    /// background image
    BITMAP *backGround = load_bitmap("assets/plateau/cardGamePlateau.bmp",NULL);

    ///game timer
    timer = partie->prvTimer;
    LOCK_VARIABLE(timer);
    LOCK_FUNCTION(Increment);
    install_int_ex(Increment, MSEC_TO_TIMER(1000));




    // maybbe put it in the joueur init in joueur.h ??
    setJoueursCartesPos(partie->joueurs,partie->nbJoueurs);
    //clear_to_color(plateau,makecol(68,85,90)); //Couleur de l'arrière plan en RGB
    //int indexDeJoueur ;
    bool chercheurDorAGagne = false;
    bool isDone= false;
    while(!isDone)
    {
        /// draw backGround
        blit(backGround,plateau,0,0,0,0,1024,900);
        ///Logic

        // save partie si p est touche
        if(key[KEY_P]){
            partie->prvTimer = timer;
            writePartieData(partie);
        }

        if(timer>60)
            resetOrCartes(partie->orCartes);




        // drag and drop logic
        dragAndDrop(partie,&partie->joueurs[partie->indexjEnTour],partie->indexjEnTour);

        //changment de joueur en tour si il joue 3 carte (setting the timer to 60 will change the player with changementDeTour func)
        if(partie->joueurs[partie->indexjEnTour].trois >= 3 ){
            timer =60;
            partie->joueurs[partie->indexjEnTour].trois =0;
        }
        // si le temp de joueur en tour a fini le indew de joueur en tour changee
        partie->indexjEnTour = changementDeTour( partie->joueurs,&timer,partie->nbJoueurs);

        if(key[KEY_ESC] && keypressed()){
            isDone=true;
        }


        //display saboteur win  screen
        if(isEmpty(partie->pioche) || timer>59 || key[KEY_L]){
                for(int i=0;i<partie->nbJoueurs;i++)
                    if(partie->joueurs[i].role == saboteur)
                            partie->joueurs[i].score = 6;
            writePartieData(partie);
                lossScreen();
        return;


        }

        // check if miners r the winers
        chercheurDorAGagne = chercheurDorGagne(partie);
        if( chercheurDorAGagne || key[KEY_W] ){
            writePartieData(partie);
            winScreen();
            return;
        }






        //si le joueur passe son tour et tape sur D
        /*
        if(key[KEY_D]){
                int temp_x,temp_y;
                for(int i=3;i>partie->joueurs[partie->indexjEnTour].trois;i--){
                    temp_x =partie->joueurs[ partie->indexjEnTour ].cartes[i].x;
                    temp_y =partie->joueurs[ partie->indexjEnTour ].cartes[i].y;
                    partie->joueurs[ partie->indexjEnTour ].cartes[i]= pop(&partie->pioche);
                     partie->joueurs[ partie->indexjEnTour ].cartes[i].x=temp_x;
                     partie->joueurs[ partie->indexjEnTour ].cartes[i].y=temp_y;
                }

                    timer =60;
                    partie->joueurs[ partie->indexjEnTour ].trois =0;

        }
        */

        ///Draw

        /// draw Or cartes
        animerOrCartes(plateau,partie->orCartes);
        drawPlateauCartes(plateau,*partie);
        animerJoueurs(plateau,partie->joueurs,partie->nbJoueurs);


        //texte à afficher dans l'application
        textout_ex (plateau,font,"Appuyer sur P pour sauvegarder ",0,890,makecol(32,29,240),makecol(109,158,235));
        //textout_ex (plateau,font,"Appuyer sur D pour passe ",300,890,makecol(32,29,240),makecol(109,158,235));

        textprintf_ex(plateau, font,814, 13, makecol(32,29,240),makecol(164,194,244), "Temps reste : %ld ", 60 -timer );
        textprintf_ex(plateau, font,814,25, makecol(32,29,240),makecol(164,194,244), "reste : %d tour ", 3 -partie->joueurs[partie->indexjEnTour].trois );


        /// blit final
        blit(plateau,screen,0,0,0,0,1024,900);
        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(plateau);
    }



}


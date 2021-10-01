void scoresScreen(Partie partie)
{
    int w = 640;
    int h = 480;
        FONT *font1 =load_font("font1.pcx",NULL,NULL);
    /// background image
    BITMAP *BackGroundImage = load_bitmap("assets/score_screen/scoreScreen.bmp",NULL);
    BITMAP * menuScreen = create_bitmap(w,h);
    int x,y;
    x=150;
    y = 100;
    bool printed=false;
    /// not exiting till esc is pressed
    bool isDone= false;
    while(!isDone)
    {
                /// menu functionlity
        if(key[KEY_ESC])
        {
            isDone=true;
        }
        /// Logic de selection

        ///set background image for menu
        blit(BackGroundImage,menuScreen,0,0,0,0,w,h);
        if(!printed){
        for(int i=0;i<partie.nbJoueurs;i++){

        textprintf_ex(BackGroundImage, font1,x, y, makecol(32,29,240),makecol(164,194,244), "  Nom De joueur : %s   |  Score : %d    ", partie.joueurs[i].nom ,partie.joueurs[i].score   );
            y+= 50;
            if(i==partie.nbJoueurs-1)
                printed = true;
        }
        }
        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);
        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }



}


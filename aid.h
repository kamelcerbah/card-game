

/// <- menuDeJeu.h
void aideMenu(int w,int h){

 /// counter to select from menu
    int counter =0;

    /// double buffering screen
    BITMAP *menuScreen = create_bitmap(w,h);
    /// background image
    BITMAP *menuImg = load_bitmap("assets/aide/aide1.bmp",NULL);


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
        if(counter>3 )
            counter=1;
        if(counter<0)
            counter=3;

        if(key[KEY_RIGHT])
            counter++;

        if(key[KEY_LEFT])
            counter--;

        /// anim les screen
        switch(counter)
        {
        case 1:
            menuImg = load_bitmap("assets/aide/aide1.bmp",NULL);
            break;
        case 2:
            menuImg = load_bitmap("assets/aide/aide2.bmp",NULL);

            break;
        case 3:
            menuImg = load_bitmap("assets/aide/aide3.bmp",NULL);

            break;
        default:
            menuImg = load_bitmap("assets/aide/aide1.bmp",NULL);
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



void saboteurWinscreen(void)
{
                    set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

    int w = 640;
    int h = 480;
    /// background image
    BITMAP *BackGroundImage = load_bitmap("assets/saboteur_winscreen/saboteur_winscreen.bmp",NULL);
    BITMAP * menuScreen = create_bitmap(w,h);

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

        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);
        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);


    }



}


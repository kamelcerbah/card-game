

void minerWinScreen(long int *timer)
{
        set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);

    *timer = 0;

    int w = 640;
    int h = 480;

    /// double buffering screen
    BITMAP *menuScreen = create_bitmap(w,h);

    BITMAP *bgImg = load_bitmap("assets/miner_winscreen/minerwin_s_bg.bmp",NULL);
    BITMAP * miner = load_bitmap("assets/miner_winscreen/miner.bmp",NULL);
    BITMAP * chariot = load_bitmap("assets/miner_winscreen/chariot.bmp",NULL);
    BITMAP * or1 = load_bitmap("assets/miner_winscreen/or1.bmp",NULL);
    BITMAP * or2 = load_bitmap("assets/miner_winscreen/or2.bmp",NULL);
    BITMAP * or3 = load_bitmap("assets/miner_winscreen/or3.bmp",NULL);

    int orIndex = 0;
    int or_y = 0 ;
    int temp_c = 0;
    /// background image

        while(1){
        if(orIndex >2)
                orIndex=0;
        or_y+=8;
        if(key[KEY_ESC] || *timer>=10)
            return;

        if(or_y > 360)
            or_y =0;

        if(*timer > temp_c+3){
            temp_c+=2;

            orIndex++;
        }


        ///set background image for menu
        blit(bgImg,menuScreen,0,0,0,0,w,h);
        masked_blit(miner,menuScreen,0,0,225,236,128,256);
        masked_blit(chariot,menuScreen,0,0,325,300,183,206);

        switch(orIndex){
        case 0:
            masked_blit(or1,menuScreen,0,0,420,or_y,32,32);
            break;
        case 1:
            masked_blit(or2,menuScreen,0,0,420,or_y,32,32);
            break;
        case 2:
            masked_blit(or3,menuScreen,0,0,420,or_y,32,32);
            break;
            default:break;

        }


        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner ",0,470,makecol(32,29,240),makecol(109,158,235));

        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);
        ///show mouse
        show_mouse(screen);
        rest (50);
        clear_bitmap(menuScreen);
        }






}


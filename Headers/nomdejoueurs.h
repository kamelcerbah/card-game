#define ERR_MESSAGE__NO_MEM "Not enough memory!"
#define allocator(element, type) _allocator(element, sizeof(type))

/// pour alloc espce de le nom
void *_allocator(size_t element, size_t typeSize)
{
    void *ptr = NULL;
    /* check alloc */
    if( (ptr = calloc(element, typeSize)) == NULL)
    {
        printf(ERR_MESSAGE__NO_MEM);
        exit(1);
    }
    /* return pointer */
    return ptr;
}

/// ajouter un caracter dans le nom avec chaque keypress
char *append( char *input, const char c)
{
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||c == '6' || c == '7'|| c == '8' ||c == '9' || c == '\x0D'  ) // \x0D
        return input;

    char *newString, *ptr;

    /* alloc */
    newString = allocator((strlen(input) + 2), char);
    /* Copy old string in new (with pointer) */
    ptr = newString;
    for(; *input; input++)
    {
        *ptr = *input;
        ptr++;
    }
    /* Copy char at end */

    *ptr = c;
    /* return new string (for dealloc use free().) */
    return newString;
}



/// saisir les  noms
void saisieLesNoms(int w,int h,int nbj, Partie * partie,BITMAP* menuScreen )
{
    FONT *font1 =load_font("font1.pcx",NULL,NULL);

    blit(menuScreen,screen,0,0,0,0,w,h);

    int x = 250;
    int y = 100; //add 80 every next name

    /// Les noms des joueurs
    bool enterClicked ;
    char nomC;
    // char  nom;
    for(int i=0; i<nbj; i++)
    {
        char  *nom = "";

        enterClicked=false;

        textout_ex (menuScreen,font1,"Saisir le nom",x+200,y,makecol(30,29,240),makecol(109,158,235));

        blit(menuScreen,screen,0,0,0,0,w,h);

        while(!enterClicked)
        {
            ///exit when enter is pressed
            if( (key[KEY_SPACE] || key[KEY_ENTER]) && strlen(nom)>3 )
            {

                    enterClicked = true;

            }
            else
            {

                nomC=readkey();

                nom = append(nom,nomC);

                textout_ex (menuScreen,font1,nom,x,y,makecol(30,29,240),makecol(255,255,255));

            }
            // partie->joueurs[i].nom[20]=nom ;
            strcpy(partie->joueurs[i].nom,nom);
            textout_ex (menuScreen,font1,"appuyez l'espace pour entrer le nom",168,413,makecol(32,29,240),makecol(109,158,235));
            blit(menuScreen,screen,0,0,0,0,w,h);
        }

        y+=87;
    }

   // blit(menuScreen,screen,0,0,0,0,w,h);

}



/*



        coming from menu.h


*/

/// <-- menu.h
void nomDeJoueurs(int w,int h,int nbDeJoueurs,Partie * newPartie)
{

    ///configuration de la police à partir du dossier source
    //FONT *font1 =load_font("font1.pcx",NULL,NULL);

    /// double buffering screen
    BITMAP *menuScreen = create_bitmap(w,h);
    /// background image
    BITMAP *menuImg = malloc(sizeof(BITMAP));


    /// not exiting till esc is pressed
    bool isDone= false;
    while(!isDone)
    {
        /// menu functionlity
        if(key[KEY_ESC])
        {
            isDone=true;
        }

        /// anim les screen
        switch(nbDeJoueurs)
        {
        case 2: /// testing only on 2 players case
            menuImg = load_bitmap("assets/nomdes_joueurs/nomdes_2joueurs.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_keybuf();
                blit(menuImg,menuScreen,0,0,0,0,w,h);

                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }


            break;
        case 3:

            menuImg = load_bitmap("assets/nomdes_joueurs/nomdes_3joueurs.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_keybuf();
                //rest(40);
                blit(menuImg,menuScreen,0,0,0,0,w,h);
                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }
            break;
        case 4:
            menuImg = load_bitmap("assets/nomdes_joueurs/nomdes_4joueurs.bmp",NULL);
            if(key[KEY_ENTER])
            {
                clear_keybuf();

                blit(menuImg,menuScreen,0,0,0,0,w,h);
                //rest(40);
                saisieLesNoms(w,h,nbDeJoueurs,newPartie,menuScreen);

                isDone=true;
            }
            break;

        default:
            printf("\n \t ERROR IN nomdejoueurs.h \n");
            break;

        }
        /// draw down
        ///set background image for menu

        blit(menuImg,menuScreen,0,0,0,0,w,h);

        //texte à afficher dans l'application
        textout_ex (menuScreen,font,"Appuyer sur ESC pour retourner",0,h-10,makecol(32,29,240),makecol(109,158,235));

        ///Draw top
        /// double buffering
        blit(menuScreen,screen,0,0,0,0,w,h);

        ///show mouse
        show_mouse(screen);

        rest (40);
        clear_bitmap(menuScreen);
    }


}



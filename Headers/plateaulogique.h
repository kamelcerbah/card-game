
void animerOrCartes(BITMAP* plateau, OrCarte *orCartes)
{
    for(int i=0; i<3; i++)
    {
        if(orCartes[i].enFace == true)
        {
            blit(load_bitmap(orCartes[i].fp_Face,NULL),plateau,0,0, orCartes[i].x,orCartes[i].y,95,95);
        }
        else
        {
            blit(load_bitmap(orCartes[i].fp_Back,NULL),plateau,0,0, orCartes[i].x,orCartes[i].y,95,95);
        }

    }
}
void animerJoueurEnTourRole(BITMAP *plateau,Joueur joueur,FONT *font1)
{
    if(joueur.role == saboteur)
    {
        //draw role nom
        textout_ex (plateau,font1,"Saboteur",285,10,makecol(32,29,240),makecol(164,194,244));
        //draw role carte
        blit(load_bitmap("assets/cartes/dwarf/saboteur.bmp",NULL),plateau,0,0, 412,1,95,95);

    }
    else
    {
        //draw role nom
        textout_ex (plateau,font1,"Chercheur d'or",285,10,makecol(32,29,240),makecol(164,194,244));
        //draw role carte
        blit(load_bitmap("assets/cartes/dwarf/miner.bmp",NULL),plateau,0,0, 412,1,95,95);

    }

}
void animerJoueurEnTourPnealityCartes (BITMAP *plateau,Joueur joueur,FONT *font1,int x_debut,int x_inc,int y)
{
    //int x = 219 ;   // x 29         y 193


    if(joueur.chariotPenalite)
    {
        blit(load_bitmap("assets/pnealitycartes/chariot_c.bmp",NULL),plateau,0,0, x_debut,y,95,95);
        // x += 95;  // 95 largeur d'un carte
        x_debut += x_inc;
    }

    if(joueur.lanternePenalite)
    {
        blit(load_bitmap("assets/pnealitycartes/lanterne_c.bmp",NULL),plateau,0,0, x_debut,y,95,95);
        //x += 95;  // 95 largeur d'un carte
        x_debut += x_inc;
    }

    if(joueur.piochePenalite)
    {
        blit(load_bitmap("assets/pnealitycartes/pioche_c.bmp",NULL),plateau,0,0, x_debut,y,95,95);
        //x += 95;  // 95 largeur d'un carte
        x_debut += x_inc;
    }


}

void animerJoueurEnTour(BITMAP *plateau,Joueur joueur,FONT* font1)
{

    //texte à afficher dans l'application
    //textout_ex (plateau,font1,joueur.nom,85,9,makecol(32,29,240),makecol(164,194,244));
    //textprintf_ex(plateau, font1,576, 14, makecol(32,29,240),makecol(164,194,244), " %d ", joueur.score );
//animerJoueurEnTourRole(plateau,joueur,font1);

    // anime les cartes

for(int i =0;i<6;i++){
    if(joueur.cartes[i].onFace == true){
        blit(load_bitmap(joueur.cartes[i].fp_Face,NULL),plateau,0,0, joueur.cartes[i].x ,joueur.cartes[i].y ,95,95);
    }else{
        blit(load_bitmap(joueur.cartes[i].fp_Back,NULL),plateau,0,0, joueur.cartes[i].x ,joueur.cartes[i].y ,95,95);
    }

    }

    // anime pneality cartes
    animerJoueurEnTourPnealityCartes(plateau,joueur,font1,219,95,193);


}

/// deplciha lel joueur.h
/*
void  setJoueursCartesPos(Joueur * joueurs, int nbj)
{
    // set x ,y de carte de joueur en tour
    int x ;
    for(int j=0 ; j<nbj; j++)
    {
        x = 29;
        for(int i =0 ; i<6; i++)
        {
            joueurs[j].cartes[i].x = x;
            joueurs[j].cartes[i].y = 97;


            x+=95; // 95 largeur d'un carte
        }

    }

}
*/

/*
void animerJoueursEnAttend(BITMAP *plateau,Joueur joueur,int pos,int nbj,FONT * font1 ){
int y_nom,y_score,y_logo ;

y_nom = 400 ;

for(int i=0;i<nbj;i++){
    if(i==pos){

    }

}


}
*/
/*
void animerLogoStatic(BITMAP * plateau,int i){
    int y =466;
        switch(i){
    case 0 :
        masked_blit(load_bitmap("assets/logo/logo1.bmp",NULL),plateau,0,0,28,y,40,40);
        break;
    case 1:
        masked_blit(load_bitmap("assets/logo/logo1.bmp",NULL),plateau,0,0,28,y+190,40,40);
        break;
    case 2:
        masked_blit(load_bitmap("assets/logo/logo1.bmp",NULL),plateau,0,0,28,y+190,40,40);
        break;
    case 3:
        masked_blit(load_bitmap("assets/logo/logo1.bmp",NULL),plateau,0,0,28,y+380,40,40);
        break;
    default:break;
    }

}
*/
/*
void animerLogo(int i,long int *timer){
    BITMAP* logo = malloc(sizeof(BITMAP));

        switch(i){
    case 0:
        logo = load_bitmap("assets/miner_winscreen/or1.bmp",NULL);
        break;
    case 1:
        logo = load_bitmap("assets/miner_winscreen/or1.bmp",NULL);
        break;
    case 2:
        logo = load_bitmap("assets/miner_winscreen/or1.bmp",NULL);
        break;
    case 3:
        logo = load_bitmap("assets/miner_winscreen/or1.bmp",NULL);
        break;
    default:break;
    }

    switch(i){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:break;
    }
}
*/
void animerJoueurs(BITMAP* plateau,Joueur * joueurs,int nbj)
{

    FONT *font1 =load_font("font1.pcx",NULL,NULL);
    int  index ;
    //TEXT de joueur en tour
    //textout_ex (plateau,font1,"Les cartes de penalty",29,193,makecol(32,29,240),makecol(164,194,244));
    /// variable des joueurs en attend a gauch
    int y_nom = 400 ;  //Nom pos : x 20      y 400
    int y_score =440 ;   //score pos :x 70        y 440
    // int y_logo ;

    /// variable des joueurs en attend a haut
    int x_nom_top = 145 ;  //Nom pos : x 145      y 321
    int x_penlity =221 ;   //pena  pos :x 221        y 289

    /// trouve index de le joueur en tour
    for(int i=0; i<nbj; i++)
    {
        if(joueurs[i].sonTour== true)
            index = i;
    }


    for(int i=0; i<nbj; i++)
    {
        if(i == index)
        {
            animerJoueurEnTour(plateau,joueurs[i],font1);
        }
        else
        {
            /// animate joueurs en attend a gauch
            textout_ex (plateau,font1,joueurs[i].nom,20,y_nom,makecol(32,29,240),makecol(164,194,244));
            y_nom+=190;
            textprintf_ex(plateau, font1,70, y_score, makecol(32,29,240),makecol(164,194,244), " %d ", joueurs[i].score );
            y_score += 190;
            ///     !!!!!!! draw logos later

            /// animate joueurs en attend nom et penality
            textout_ex (plateau,font1,joueurs[i].nom,x_nom_top,321,makecol(32,29,240),makecol(164,194,244));
            x_nom_top+=288;
            animerJoueurEnTourPnealityCartes(plateau,joueurs[i],font1,x_penlity,47,289);
            x_penlity += 288;


        }
    }

}

// make this func returns the index of the player on turn
int  changementDeTour(Joueur *joueurs,long int *timer,int nbj)
{
    int index ;
    /// trouve index de le joueur en tour
    for(int i=0; i<nbj; i++)
    {
        if(joueurs[i].sonTour== true)
            index = i;
    }

    if(*timer>60)
    {


        index++;

        if(index >= nbj)
        {
            index = 0;
        }

        for(int i=0; i<nbj; i++)
        {
            if(i == index)
            {
                joueurs[index].sonTour= true;
            }
            else
            {
                joueurs[i].sonTour= false;
            }
        }
        *timer = 0;
        joueurs->trois =0;

    }

    return index;

}


void drawPlateauCartes(BITMAP *plateau, Partie partie){
   // int x,y;  // x 125      y 385
   // x= 125;
   // y= 385;
for(int k =0 ; k< partie.cartesDePlateau ; k++){
   // for(int i=0; i<5 ; i++){
    //    x= 125;


       // for(int j=0; j < 9  ; j++){
            if(partie.plateauCartes[k].onFace)
            {
                blit(load_bitmap(partie.plateauCartes[k].fp_Face,NULL),plateau,0,0,partie.plateauCartes[k].x , partie.plateauCartes[k].y,95,95);

            }else{
                blit(load_bitmap(partie.plateauCartes[k].fp_Back,NULL),plateau,0,0,partie.plateauCartes[k].x , partie.plateauCartes[k].y,95,95);

            }
          //  x+=95;
       // }
       // y+=95;
   // }
    }


}

bool chercheurDorGagne(Partie *partie){
for(int i=0;i<partie->cartesDePlateau;i++){

    for(int j =0; j<3;j++){

        if(  partie->plateauCartes[i].x+95 == partie->orCartes[j].x && partie->plateauCartes[i].y == partie->orCartes[j].y  ){

            for(int k=0;k<partie->nbJoueurs;k++){

                if(i == partie->indexjEnTour){

                            partie->joueurs[i].score = partie->orCartes[j].orNb;
                }else{
                        for(int m = 0;m<3;m++){
                            if(m != j)
                            partie->joueurs[m].score = partie->orCartes[m].orNb;
                          //  printf("here 1");

                }
                }
            return true ;
            }


        }
    }
}
return false;

}

/* dead func
void drawJoueurEnTourCartes(BITMAP *plateau, Joueur  joueur )
{

    for(int i = 0; i<6; i++)
    {

        if(joueur.cartes[i].onFace == true)
        {
            blit(load_bitmap(joueur.cartes[i].fp_Face,NULL),plateau,0,0, joueur.cartes[i].x,joueur.cartes[i].y,95,95);
        }
        else
        {
            blit(load_bitmap(joueur.cartes[i].fp_Back,NULL),plateau,0,0, joueur.cartes[i].x,joueur.cartes[i].y,95,95);
        }

    }



}
*/


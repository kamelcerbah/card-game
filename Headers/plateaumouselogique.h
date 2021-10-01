/// mouse position et Que faire


/// use the return to break when acondition is met
// gla3 NotDone
void QDFavecCarteGalerie(Partie* partie,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{
    int x,y;  // x 125      y 385
    // x= 125;
    y= 385;
    /// for every column
    for(int i=0; i<5 ; i++)
    {
        x= 130;
        ///for every row
        for(int j=0; j < 9  ; j++)
        {
            // check if carte is in the right pos
            if(partie->joueurs[indexDeJoueur].cartes[indexCarte].x > x && partie->joueurs[indexDeJoueur].cartes[indexCarte].x < x+95  && partie->joueurs[indexDeJoueur].cartes[indexCarte].y > y && partie->joueurs[indexDeJoueur].cartes[indexCarte].y < y+95)
            {
                if(partie->joueurs[indexDeJoueur].cartes[indexCarte].type == galerie)  // prbbly don' need it later
                {

                    partie->plateauCartes[partie->cartesDePlateau] = partie->joueurs[indexDeJoueur].cartes[indexCarte];
                    partie->plateauCartes[partie->cartesDePlateau].x = x;
                    partie->plateauCartes[partie->cartesDePlateau].y = y;
                    partie->cartesDePlateau++;
                    partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                    partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                    partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                    partie->joueurs[indexDeJoueur].trois++;

                    return;

                }

            }
            x+=95;
        }
        y+=95;
    }

    /// if the pos of the carte isn't right it returns the prev carte x y
    partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
    partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
}


///   QDF : Quoi De Faire avec action cartes casse
void  QDFavecCarteAction_c(Partie* partie,ActionCarteData *carte,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{
    // _c : casse
    int  x;
    int rand1;
    x=125;
    ///check if the action carte of type action is droped on a player
    // get the pos of the player and assigne the penality based on the name of the carte
    for(int i=0; i< partie->nbJoueurs; i++)
    {
        if(i != indexDeJoueur)
        {
            if(carte->x > x && carte->x < x+285  && carte->y > 289 && carte->y < 384)
            {
                if(partie->joueurs[indexDeJoueur].cartes[indexCarte].type == action)
                {

                    switch(carte->nom)
                    {
                    case chariot_c :
                        partie->joueurs[i].chariotPenalite = true;

                        partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        break;
                    case lanterne_c :
                        partie->joueurs[i].lanternePenalite = true;

                        partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        break;
                    case pioche_c :
                        partie->joueurs[i].piochePenalite = true;

                        partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        break;
                    case tous_outils_c:

                        rand1 = rand() % 3 ; // random number 0  1   2
                        switch(rand1)
                        {
                        case 0:
                            partie->joueurs[i].chariotPenalite = true;
                            break;
                        case 1:
                            partie->joueurs[i].lanternePenalite = true;
                            break;
                        case 2:
                            partie->joueurs[i].piochePenalite = true;
                            break;
                        }
                        partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                        partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        break;

                    default:
                        break;
                    }

                }

            } //above this
            x+= 285;
        } // put it below



    }
    /// if the pos of the carte isn't right it returns the prev carte x y
    partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
    partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
}


///   QDF : Quoi De Faire avec action cartes repare
void  QDFavecCarteAction_r(Partie* partie,ActionCarteData *carte,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{
    // _c : casse
    int  x;
    x=125;
    ///check if the action carte of type action is droped on a player
    // get the pos of the player and assigne the penality based on the name of the carte
    for(int i=0; i< partie->nbJoueurs; i++)
    {
        if(i != indexDeJoueur)
        {
            if(carte->x > x && carte->x < x+285  && carte->y > 192 && carte->y < 384)
            {
                if(carte->x > x && carte->x < x+285  && carte->y > 192 && carte->y < 289)
                {
                    /// pour le joueur en tour
                    switch(carte->nom)
                    {
                    case chariot_r :
                        if(partie->joueurs[indexDeJoueur].chariotPenalite == true)
                        {
                            partie->joueurs[indexDeJoueur].chariotPenalite = false;

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;
                    case lanterne_r :
                        if(partie->joueurs[indexDeJoueur].lanternePenalite == true)
                        {
                            partie->joueurs[indexDeJoueur].lanternePenalite = false;

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;
                    case pioche_r :
                        if(partie->joueurs[indexDeJoueur].piochePenalite == true)
                        {
                            partie->joueurs[indexDeJoueur].piochePenalite = false;

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;

                    case chariot_pioche_r:
                        if(partie->joueurs[indexDeJoueur].chariotPenalite == true ||partie->joueurs[indexDeJoueur].piochePenalite == true )
                        {
                            if(partie->joueurs[indexDeJoueur].chariotPenalite == true ){
                                partie->joueurs[indexDeJoueur].chariotPenalite = false;
                            }else{
                            partie->joueurs[indexDeJoueur].piochePenalite = false;
                            }

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;
                    case lanterne_chariot_r:
                        if(partie->joueurs[indexDeJoueur].chariotPenalite == true || partie->joueurs[indexDeJoueur].lanternePenalite == true)
                        {
                            if(partie->joueurs[indexDeJoueur].chariotPenalite == true){
                                partie->joueurs[indexDeJoueur].chariotPenalite = false;
                            }else{
                            partie->joueurs[indexDeJoueur].lanternePenalite = false;
                            }

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;
                    case lanterne_pioche_r:

                        if(partie->joueurs[indexDeJoueur].piochePenalite == true || partie->joueurs[indexDeJoueur].lanternePenalite == true )
                        {
                            if(partie->joueurs[indexDeJoueur].piochePenalite == true){
                                partie->joueurs[indexDeJoueur].piochePenalite = false;
                            }else{
                                partie->joueurs[indexDeJoueur].lanternePenalite = false;
                            }

                            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                        }
                        break;
                    default :
                        break;
                    }
                    // below this
                }



                /// pour les joueurs en attend
                if(carte->x > x && carte->x < x+285  && carte->y > 289 && carte->y < 384)
                {
                    if(partie->joueurs[indexDeJoueur].cartes[indexCarte].type == action)
                    {

                        switch(carte->nom)
                        {
                        case chariot_r :
                            if(partie->joueurs[i].chariotPenalite == true)
                            {
                                partie->joueurs[i].chariotPenalite = false;

                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;
                        case lanterne_r :
                            if(partie->joueurs[i].lanternePenalite == true)
                            {
                                partie->joueurs[i].lanternePenalite = false;

                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;
                        case pioche_r :
                            if(partie->joueurs[i].piochePenalite == true)
                            {
                                partie->joueurs[i].piochePenalite = false;

                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;
                        case chariot_pioche_r:
                            if(partie->joueurs[i].chariotPenalite == true ||partie->joueurs[i].piochePenalite == true )
                            {
                                if(partie->joueurs[i].chariotPenalite == true){
                                    partie->joueurs[i].chariotPenalite = false;
                                }else{
                                    partie->joueurs[i].piochePenalite = false;
                                }

                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;
                        case lanterne_chariot_r:
                            if(partie->joueurs[i].chariotPenalite == true || partie->joueurs[i].lanternePenalite == true)
                            {
                                if(partie->joueurs[i].chariotPenalite == true){
                                                                        partie->joueurs[i].chariotPenalite = false;
                                }else{
                                    partie->joueurs[i].lanternePenalite = false;

                                }
                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;
                        case lanterne_pioche_r:


                            if(partie->joueurs[i].piochePenalite == true || partie->joueurs[i].lanternePenalite == true )
                            {
                                if(partie->joueurs[i].piochePenalite == true){
                                    partie->joueurs[i].piochePenalite = false;
                                }else{
                                partie->joueurs[i].lanternePenalite = false;

                                }

                                partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                                partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;
                            }
                            break;

                        default:
                            break;
                        }

                    }

                } //below this
            }

            x+= 285;
        }



    }
    /// if the pos of the carte isn't right it returns the prev carte x y
    partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
    partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
}




void  QDFavecCarteAction_map(Partie* partie,ActionCarteData *carte,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{
    int y = 384;
    for(int i=0;i<3;i++){
    if(carte->x > 892 && carte->x <987 && carte->y >y && carte->y <y +95 ){
            printf("\n right pos \n");
            partie->orCartes[i].enFace = true;

            partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
            partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
            partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;

            return;

    }
    y+=190;

    }
    /// if the pos of the carte isn't right it returns the prev carte x y
    partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
    partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;


}




void  QDFavecCarteAction_eboulement(Partie* partie,ActionCarteData *carte,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{


    for(int k =0 ; k< partie->cartesDePlateau ; k++){

            // check if carte is in the right pos
            if(partie->joueurs[indexDeJoueur].cartes[indexCarte].x > partie->plateauCartes[k].x && partie->joueurs[indexDeJoueur].cartes[indexCarte].x < partie->plateauCartes[k].x+95  && partie->joueurs[indexDeJoueur].cartes[indexCarte].y > partie->plateauCartes[k].y && partie->joueurs[indexDeJoueur].cartes[indexCarte].y < partie->plateauCartes[k].y+95){

                //if(partie->joueurs[indexDeJoueur].cartes[indexCarte].type == action)  // prbbly don' need it later{

                    partie->plateauCartes[k].onFace =false ;

                    partie->joueurs[indexDeJoueur].cartes[indexCarte] =  pop(&partie->pioche);
                    partie->joueurs[indexDeJoueur].cartes[indexCarte].x =  temp_x;
                    partie->joueurs[indexDeJoueur].cartes[indexCarte].y =  temp_y;


                    return;

               // }

            }

     } //test

    /// if the pos of the carte isn't right it returns the prev carte x y
    partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
    partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
}




void  QDFavecCarteAction(Partie* partie,ActionCarteData *carte,int temp_x,int temp_y,int indexDeJoueur,int indexCarte)
{
    switch(carte->nom )
    {
    case chariot_c :
    case lanterne_c :
    case pioche_c :
    case tous_outils_c :
        // le joueur can't play if he has even one penality
        if(partie->joueurs[partie->indexjEnTour].chariotPenalite ==false && partie->joueurs[partie->indexjEnTour].piochePenalite==false &&partie->joueurs[partie->indexjEnTour].lanternePenalite==false  ){
        QDFavecCarteAction_c(partie,carte,temp_x,temp_y,indexDeJoueur,indexCarte);
        }else{
        /// if the pos of the carte isn't right it returns the prev carte x y
        partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
        partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
        partie->joueurs[indexDeJoueur].trois=0;

        }


        break;
    case chariot_r :
    case lanterne_r :
    case pioche_r:
    case chariot_pioche_r:
    case lanterne_chariot_r :
    case lanterne_pioche_r:

        QDFavecCarteAction_r(partie,carte,temp_x,temp_y,indexDeJoueur,indexCarte);
        break;
    case mapp :
        // le joueur can't play if he has even one penality
        if(partie->joueurs[partie->indexjEnTour].chariotPenalite ==false && partie->joueurs[partie->indexjEnTour].piochePenalite==false &&partie->joueurs[partie->indexjEnTour].lanternePenalite==false  ){
        QDFavecCarteAction_map(partie,carte,temp_x,temp_y,indexDeJoueur,indexCarte);

        }else{
        /// if the pos of the carte isn't right it returns the prev carte x y
        partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
        partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
        partie->joueurs[indexDeJoueur].trois=0;
        }
        break;
    case eboulement :
        // le joueur can't play if he has even one penality
        if(partie->joueurs[partie->indexjEnTour].chariotPenalite ==false && partie->joueurs[partie->indexjEnTour].piochePenalite==false &&partie->joueurs[partie->indexjEnTour].lanternePenalite==false  ){
        QDFavecCarteAction_eboulement(partie,carte,temp_x,temp_y,indexDeJoueur,indexCarte);
        }else{
        /// if the pos of the carte isn't right it returns the prev carte x y
        partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
        partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
        partie->joueurs[indexDeJoueur].trois=0;

        }
        break;
    default :
        printf("what is this card !!! ");
        break;


    }

}

void dragAndDrop(Partie* partie,Joueur *joueur,int indexDeJoueur)
{
    int temp_x,temp_y,indexCarte;
    int x = 28 ;
    if(mouse_y <192 && mouse_y > 96 && mouse_x > 28 && mouse_x < 604)
    {

        for(int i =0; i<6; i++)
        {

            if(mouse_y <192 && mouse_y > 96 && mouse_x > x && mouse_x < x+95)
            {
                temp_x = joueur->cartes[i].x;
                temp_y = joueur->cartes[i].y;

                if(mouse_b && 1)
                {
                    while(mouse_b && 1)
                    {
                        ///Logic
                        if(mouse_x > joueur->cartes[i].x )
                        {
                            joueur->cartes[i].x +=5;

                            if(mouse_x<joueur->cartes[i].x)
                                joueur->cartes[i].x= mouse_x;

                        }

                        else if(mouse_x < joueur->cartes[i].x )

                        {

                            joueur->cartes[i].x -=5;

                            if(mouse_x>joueur->cartes[i].x)
                                joueur->cartes[i].x= mouse_x;
                        }

                        if(mouse_y > joueur->cartes[i].y )
                        {

                            joueur->cartes[i].y +=5;

                            if(mouse_y<joueur->cartes[i].y)
                                joueur->cartes[i].y= mouse_y;

                        }

                        else if(mouse_y < joueur->cartes[i].y )
                        {
                            joueur->cartes[i].y -=5;

                            if(mouse_y>joueur->cartes[i].y)
                                joueur->cartes[i].y= mouse_y;
                        }

                    }
                    indexCarte = i;
                    /// check right position if not reset the x and y of the carte
                    // galerie
                    if(joueur->cartes[indexCarte].type == galerie )
                    {
                        // le joueur can't play if he has even one penality
                        if(partie->joueurs[partie->indexjEnTour].chariotPenalite ==false && partie->joueurs[partie->indexjEnTour].piochePenalite==false &&partie->joueurs[partie->indexjEnTour].lanternePenalite==false  ){
                            QDFavecCarteGalerie(partie,temp_x,temp_y,indexDeJoueur,indexCarte);
                        }else{
                            /// if the pos of the carte isn't right it returns the prev carte x y
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].x = temp_x;
                            partie->joueurs[indexDeJoueur].cartes[indexCarte].y = temp_y;
                            partie->joueurs[indexDeJoueur].trois=0;
                        }

                        return;
                    }
                    else
                    {

                        QDFavecCarteAction(partie,&joueur->cartes[indexCarte],temp_x,temp_y,indexDeJoueur,indexCarte);
                        partie->joueurs[indexDeJoueur].trois++;
                        return;

                    }

                }

            }
            x+=95;

        }
    }


}











const int MAX_parties = 20;

char partie_fname[] = {"gamedata.dat"};


typedef struct {
    int prvTimer;
    int nbDePartie ;
    int nbJoueurs;
    int cartesDePlateau;
    int indexjEnTour;

    ActionCarteData plateauCartes[45];

    ActionCarteData penalityCartes[3];

    Joueur joueurs[4] ;

    OrCarte orCartes[3];

    Pioche pioche ;

    ActionCarteData defausse;

}Partie;

void initPartie(Partie *partie,int nbJoueurs,int nbDePartie){
    // tested partie pioche and DONE
    // tested partie nb of players and partie number and DONE
    // tested partie orCartes and Done
    partie->prvTimer =0 ;
    partie->indexjEnTour=0;
    ///Or cartes                working
    OrCarte orCartes[3];
    iniOrCartes(orCartes);

    /// init pioche de partie
    Pioche pioche ;
    initPioche(&pioche);
    partie->pioche = pioche ;

    partie->nbDePartie = nbDePartie;
    partie->nbJoueurs = nbJoueurs;

    /// initialization de joueurs
    //partie->joueurs = malloc(sizeof(Joueur)*nbJoueurs);
    iniJoueurs(partie->joueurs,nbJoueurs);


    // init orCartes
    for(int i=0;i<3;i++)
        partie->orCartes[i] = orCartes[i];

    for(int i=0;i<nbJoueurs;i++)
        for(int j=0;j<6;j++)
            partie->joueurs[i].cartes[j] = pop(&partie->pioche);

        /// init plateau cartes
        /*
    partie->cartesDePlateau = 1;
    strcpy(partie->plateauCartes[0].fp_Back,"assets/cartes/action/back.bmp");
    strcpy(partie->plateauCartes[0].fp_Face,"assets/cartes/entree_mine.bmp");
    partie->plateauCartes[0].nom= entree_mine;
    partie->plateauCartes[0].onFace = true;
    partie->plateauCartes[0].type = galerie;
    partie->plateauCartes[0].x = 125;
    partie->plateauCartes[0].y = 577;
    */



}

// working with only one partie
void writePartieData( Partie *parties)
{
        Partie partie1 ;
        partie1 = *parties;

    FILE *fp = fopen(partie_fname,"wb");  // to write to file
    if(! fp) return;

    //save partie  data
    fwrite(&partie1,sizeof(Partie),1,fp); /// wrking with only one partie for now
    fclose(fp);


}

Partie readPartieData()
{
    Partie partie1 ;

    FILE *fp;  // to read from file
    fp = fopen(partie_fname,"rb");  // to read from file
    ///if file exists

    /// read data

    //working
    while(1){
         fread(&partie1,sizeof(Partie),1,fp);
            if(feof(fp))
                break;

    }

    return partie1;


   /*  //prv one
    int nbDePartie;
    for(nbDePartie=0; !feof(fp)  ; nbDePartie++)
    {
        if(fread(&parties[nbDePartie],sizeof(Partie),1,fp) != 1) break;
    }
*/

    fclose(fp);


    //return nbDePartie;

}



/// make a func that append a partie to the already existing file







/// all the funcs below use them when u finish plateau
/// when u need to work on the score and saved parties page

///if the partie is already saved read it
/*
void loadPartie(Partie  *partie){
    int items = readPartieData(partie); /// items is the number of items
    items++;
}
*/
/// prbbly won't need it
/// maybe when u enter saved parties page
/// so file doesn't exist u should display a message saying that there is no saved parties
/// same thing for score page
/*
Partie * initPartieData(int nbJoueurs,int nbDePartie){
FILE *parties_f = fopen(partie_fname,"rb");
// si le fichier n'exist pas il ini les parties
    return (!parties_f) ? initEtSavePartie(nbJoueurs,nbDePartie) : loadPartie();
}
*/







// prbbly won't need it but onka ou
/*

/// init the partie and save it
Partie *initEtSavePartie(int nbJoueurs,int nbDePartie){
    Partie partie = malloc(sizeof(Partie));
    initPartie(&partie,nbJoueurs,1);

}

*/

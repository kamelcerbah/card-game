
typedef enum {miner,saboteur} Role;

typedef struct
{
    char nom[30];
    Role role; // inited
    ActionCarteData cartes[6];
    bool chariotPenalite; // inited
    bool lanternePenalite; // inited
    bool piochePenalite; // inited
    bool sonTour; // inited
    int score;  // inited
    int trois;

}Joueur;


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
void iniScoreDeJoueurs(Joueur * joueurs ,int nbDesjoueurs){

    for(int i=0;i<nbDesjoueurs;i++)
        joueurs[i].score=0;

}

void iniRoleDeJoueurs(Joueur * joueurs ,int nbDesjoueurs){
    /*for(int i=0;i<nbDesjoueurs;i++){
            //randomRole = rand() % 2;
        joueurs[i].role = rand() % 2;
    }*/
    int randIndex = rand()%nbDesjoueurs;
      for(int i=0;i<nbDesjoueurs;i++){
            if(i==randIndex){
                joueurs[i].role = 1;
            }else{
            joueurs[i].role = 0;
            }

    }




}

void iniTourDeJoueurs(Joueur * joueurs ,int nbDesjoueurs){
    joueurs[0].sonTour = true;
    for(int i=1;i<nbDesjoueurs;i++)
    joueurs[i].sonTour=false;

}


void iniPenaliteDeJoueurs(Joueur * joueurs ,int nbDesjoueurs){
    for(int i=0;i<nbDesjoueurs;i++){
        joueurs[i].chariotPenalite = false;
        joueurs[i].lanternePenalite = false;
        joueurs[i].piochePenalite = false;

    }
}
void iniJoueurs(Joueur* joueurs ,int nbDesjoueurs){
    for(int i=0;i<nbDesjoueurs;i++)
        joueurs[i].trois = 0;



    iniPenaliteDeJoueurs(joueurs ,nbDesjoueurs);

    iniTourDeJoueurs(joueurs ,nbDesjoueurs);

    iniRoleDeJoueurs(joueurs ,nbDesjoueurs);

    iniScoreDeJoueurs(joueurs ,nbDesjoueurs);

    setJoueursCartesPos(joueurs,nbDesjoueurs);
}


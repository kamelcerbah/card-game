typedef enum {galerie,action} Type;

// _c pour casse  et _r pour repare
typedef enum {carrefour,chemin,impasse,Tright,Tup,chariot_c,chariot_pioche_r,chariot_r,eboulement,lanterne_c,lanterne_chariot_r,lanterne_pioche_r,lanterne_r,mapp,pioche_c,pioche_r,tous_outils_c,entree_mine} Nom;
const int nbActionCartes = 10 ;

 char  cardsFilePaths[5][60] = {"assets/cartes/face/chemin.bmp","assets/cartes/face/carrefour.bmp","assets/cartes/face/impasse.bmp","assets/cartes/face/Tright.bmp","assets/cartes/face/Tup.bmp"};
//cardsFilePaths[0] = "assets/cartes/face/chemin.bmp";

//Il exist deux struct pour action carte car le les fichiers ne peuvent pas enregistrer la structure bitmap
//donc en utilise la preimier struct pour enregistrer dans le fichiers
// et le deuxième pour manipuler dans le program
typedef struct
{
    Nom nom;
    Type type ;
    char fp_Back[60];
    char fp_Face[60];
    int x,y;
    bool onFace;
} ActionCarteData;
/*
typedef struct
{
    Nom nom ;
    Type type ;
    BITMAP *faceImg;
    BITMAP *backImg;
    int x,y;
    bool onFace;

} ActionCartes;
*/
char action_cartes_fname[] = {"cartesdata.dat"};
//make a string array and add all the cards file path



/// init ActionCarteDatas

void actionCartesLibrary(ActionCarteData actionCartes[])
{
    int cardNum = 0;
    int index =0;
    int i;
    int x,y;
    x=0;
    y=0;
    bool onFace = true;

    //carte galerie
    for(i=0; i<10; i++)
    {
        if(index > nbActionCartes/2)
            index=0;

        actionCartes[cardNum].nom = carrefour;
        actionCartes[cardNum].type = galerie;
        strcpy(actionCartes[cardNum].fp_Face,cardsFilePaths[index]);
        strcpy(actionCartes[cardNum].fp_Back,"assets/cartes/back/back.bmp");
        actionCartes[cardNum].onFace= onFace;
        actionCartes[cardNum].x=x;
        actionCartes[cardNum].y =y;

        cardNum++;
        index++;




    }
/*
    for(i=i; i<(9*2); i++)
    {
        actionCartes[i].nom = chemin;
        actionCartes[i].type = galerie;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/galerie/chemin.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    for(i=i; i<(9*3); i++)
    {
        actionCartes[i].nom = impasse;
        actionCartes[i].type = galerie;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/galerie/impasse.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    for(i=i; i<(9*4); i++)
    {
        actionCartes[i].nom = Tright;
        actionCartes[i].type = galerie;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/galerie/Tright.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    for(i=i; i<(9*5); i++)
    {
        actionCartes[i].nom = Tup;
        actionCartes[i].type = galerie;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/galerie/Tup.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //action cartes
    //1
    for(i=i; i<(9*5+2*1); i++)
    {
        actionCartes[i].nom = chariot_c;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/chariot_c.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //2
    for(i=i; i<(9*5+2*2); i++)
    {
        actionCartes[i].nom = chariot_pioche_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/chariot_pioche_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //3
    for(i=i; i<(9*5+2*3); i++)
    {
        actionCartes[i].nom = chariot_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/chariot_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //4
    for(i=i; i<(9*5+2*4); i++)
    {
        actionCartes[i].nom = eboulement;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/eboulement.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //5
    for(i=i; i<(9*5+2*5); i++)
    {
        actionCartes[i].nom = lanterne_c;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/lanterne_c.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //6
    for(i=i; i<(9*5+2*6); i++)
    {
        actionCartes[i].nom = lanterne_chariot_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/lanterne_chariot_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //7
    for(i=i; i<(9*5+2*7); i++)
    {
        actionCartes[i].nom = lanterne_pioche_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/lanterne_pioche_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //8
    for(i=i; i<(9*5+2*8); i++)
    {
        actionCartes[i].nom = lanterne_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/lanterne_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //9
    for(i=i; i<(9*5+2*9); i++)
    {
        actionCartes[i].nom = mapp;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/map.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //10
    for(i=i; i<(9*5+2*10); i++)
    {
        actionCartes[i].nom = pioche_c;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/pioche_c.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
    //11
    for(i=i; i<(9*5+2*11); i++)
    {
        actionCartes[i].nom = pioche_r;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/pioche_r.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }

    //12
    for(i=i; i<(9*5+2*12); i++)
    {
        actionCartes[i].nom = tous_outils_c;
        actionCartes[i].type = action;
        strcpy(actionCartes[i].fp_Face,"assets/cartes/action/action/tous_outils_c.bmp");
        strcpy(actionCartes[i].fp_Back,"assets/cartes/action/back.bmp");
        actionCartes[i].onFace= onFace;
        actionCartes[i].x=x;
        actionCartes[i].y =y;
    }
*/

}


/// Functions

void writeData( ActionCarteData actionCartes[], int items )
{

    FILE *fp = fopen(action_cartes_fname,"wb");  // to write to file
    if(! fp) return;

    //save card  data
    fwrite(actionCartes,sizeof(ActionCarteData),items,fp);
    fclose(fp);

}

int readData(ActionCarteData actionCartes[])
{

    FILE *fp = fopen(action_cartes_fname,"rb");  // to read from file
    ///if file exists
    if(! fp) return 0;

    /// read data
    int n=0;
    for(n=0; !feof(fp); n++)
    {
        if(fread(&actionCartes[n],sizeof(ActionCarteData),1,fp) != 1) break;
    }

    fclose(fp);

    return n;

}
//change this
void shuffleActionCartes(ActionCarteData *actionCartes){

    int randomIndex[nbActionCartes] ;

    for(int i = 0 ;i < nbActionCartes;i++){
        randomIndex[i] = rand() % nbActionCartes;
        //printf("%d",randomIndex[i]);
    }


    ActionCarteData temp;
        for(int i=0 ;i<nbActionCartes;i++){
           // int j = i + rand() / (RAND_MAX / (nb - i) + 1);  // prv : replace randomIndex with j
             //randomIndex = rand() % nb;
             temp = actionCartes[randomIndex[i]] ;
            actionCartes[randomIndex[i]]=actionCartes[i];
            actionCartes[i]=temp;
        }

}


void  iniEtChargementDesCartes(ActionCarteData *actionCartes)
{

    /// initialization et enregistrer des données

    actionCartesLibrary(actionCartes);
    shuffleActionCartes(actionCartes);
    writeData(actionCartes,nbActionCartes);

}

void ChargementDesCartes(ActionCarteData *actionCartes )
{
    ///Read actionCartes data
    int items ;
    items = readData(actionCartes);
    shuffleActionCartes(actionCartes);
    if(items < 1)
        printf("error in actionCartes.h line 299");


}

void initActionCartes(ActionCarteData *actionCartes){
    //les cartes file path
   // FILE *cartes_fp = fopen(action_cartes_fname,"rb");

    // si le fichier .dat des cartes n'exist pas il ini les cartes
    // (!cartes_fp)? iniEtChargementDesCartes(actionCartes):ChargementDesCartes(actionCartes);
     iniEtChargementDesCartes(actionCartes);
    // ChargementDesCartes(actionCartes);

}




/// dead funcs




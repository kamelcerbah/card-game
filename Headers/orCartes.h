typedef struct
{
    int orNb;
    char fp_Back[60];
    char fp_Face[60];
    int x;
    int y;
    bool enFace;

} OrCarte;
void shuffleOrCartes(OrCarte *orCartes ){
        for(int i=0 ;i<3;i++){
           // int j = i + rand() / (RAND_MAX / (3 - i) + 1);
            int j = rand()%3;
            OrCarte temp = orCartes[j] ;
            orCartes[j]=orCartes[i];
            orCartes[i]=temp;
        }

}
void iniNombreDesOr(OrCarte *orCartes)
{
    orCartes[0].orNb=1; // 1 or
    orCartes[1].orNb= 2;// 2 or
    orCartes[2].orNb = 3;// 3 or

}

char *baseEnOrNombre(int nbOr) {
    switch(nbOr){
    case 1 :
        return "assets/cartes/or/1or.bmp";
        break;
    case 2 :
        return "assets/cartes/or/2or.bmp";
        break;
    case 3 :
        return "assets/cartes/or/3or.bmp";
        break;
    default:
        return "";

    }
}


void iniOrCartes(OrCarte *orCartes)
{

    // nombre des pepties d'or en random
    iniNombreDesOr(orCartes);
    int y =385;

    ///testing ,  x and y != 0
    shuffleOrCartes(orCartes);
    for(int i=0 ; i<3;i++){

    strcpy(orCartes[i].fp_Face,baseEnOrNombre(orCartes[i].orNb));
    strcpy(orCartes[i].fp_Back,"assets/cartes/or/dos.bmp");

    orCartes[i].x = 890;
    orCartes[i].y = y;
    orCartes[i].enFace = false;
    y+=190;
    }




}
void resetOrCartes(OrCarte* orCartes){
for(int i=0 ; i<3;i++)
    orCartes[i].enFace = false;

}


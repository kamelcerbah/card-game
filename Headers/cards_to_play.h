typedef struct {
    int top;
    unsigned capacity;
    ActionCarteData actionCartes[10];
}Pioche;
//const int cardNombre =69;
/*
typedef struct {
    int top;
    unsigned capacity;
    ActionCarteData *actionCartes;
}Pioche;
*/
// Function to add an item to pioche.  It increases top by 1
void push(Pioche *pioche, ActionCarteData item)
{

    pioche->actionCartes[++pioche->top] = item;
}
// fil the stack with the cards
void fillPioche(Pioche *pioche ,ActionCarteData actionCartes[]){
      // int randomDebut = rand() % 69 ;
       for(int i=0 ; i<nbActionCartes;i++) //nbActionCartes from actionCartes.h
        push(pioche,actionCartes[i]);
}
void initPioche(Pioche *pioche)
{
    // initialization des cartes des action
    ActionCarteData *actionCartes= malloc(sizeof(ActionCarteData) * nbActionCartes); //nbActionCartes from actionCartes.h
    initActionCartes(actionCartes); /// here u are reading the whole cartes again  !!!!! ?????

    for(int i =0 ; i< (rand() %3);i++)
        shuffleActionCartes(actionCartes);  //shuffleActionCartes from actionCartes.h   nbActionCartes from actionCartes.h
    // initialization de stack pioche
    pioche->capacity = nbActionCartes;  //nbActionCartes from actionCartes.h
    pioche->top = -1;
    fillPioche(pioche,actionCartes);
}

// pioche is empty when top is equal to -1
bool isEmpty(Pioche pioche)
{
    return pioche.top == -1;
}


// Function to remove an item from stack.  It decreases top by 1
ActionCarteData pop(Pioche *pioche)
{
    /// be careful of error here
    return pioche->actionCartes[pioche->top--];
}




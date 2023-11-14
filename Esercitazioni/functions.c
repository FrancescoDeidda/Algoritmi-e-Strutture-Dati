//
// Created by deidd on 08/03/2023.
//

#include "functions.h"
#include <string.h>

typedef Node Node;
typedef Node Node;

int* generaArray(int dimensione, inputType tipo_schema) {
    int *array = (int*) malloc(sizeof(int)*dimensione);
    int max=dimensione*4, min = 0;
    //srand(time(NULL));

    switch (tipo_schema) {
        case ORDINATO:
            array[0] = min = rand();
            for (int i = 1; i < dimensione; i++) {
                min = array[i] = (rand() % (max - min + 1)) + min;
            }
            break;

        case QUASI_ORDINATO:
            for (int i = 0; i < dimensione / 2; i++) {
                min = array[i] = (rand() % (max - min + 1)) + min;
            }
            for (int i = dimensione / 2; i < dimensione; i++) {
                array[i] = rand() % max;
            }
            break;

        case INV_ORDINATO:
            array[0] = max = rand() % max;
            for (int i = 1; i < dimensione; i++) {
                max = array[i] = (rand() % (max)) + 1;
            }
            break;

        case CASUALE:
            for (int i = 0; i < dimensione; i++) {
                array[i] = rand() % max;
            }
            break;
    }
    return array;
}
void stampaArray(int *vet, int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf("%d ", vet[i]);
    }
}

void swap(int *n1, int *n2){
    int sup;
    sup = *n1;
    *n1 = *n2;
    *n2 = sup;
}
void selectionSort(int *vet, int dimensione){

    int min = 0;
    cont_confr_iter = 0, cont_scambi_iter = 0; //min = indice del valore minimo, sup= variabile di supporto

    for (int i = 0; i <= dimensione - 2; i++) {
        min = i;
        for (int j = i + 1; j <= dimensione - 1; j++){
            cont_confr_iter++;
            if (vet[j] < vet[min])//cerco il valore minimo
                min = j; //se lo trovo aggiorno il valore minimo
        }

        cont_scambi_iter++;
        swap(&vet[min], &vet[i]);
    }
    printf("Confronti: %d\nScambi: %d\n",cont_confr_iter,cont_scambi_iter);
}
void selectionSortRicette(Ricetta *ric, int dimensione){
    int min = 0, sup = 0; //min = indice del valore minimo, sup = variabile di supporto

    for(int i = 0; i <= dimensione -2; i++){
        min = i;
        for(int j = i+1; j <= dimensione-1; j++)
            if(compare(&ric[j], &ric[min])==0)
                min = j;

        swapRicette(&ric[i],&ric[min]);
    }
}
void swapRicette(Ricetta *r1, Ricetta *r2){
    Ricetta sup;

    strcpy(sup.nome, r1->nome);
    sup.tempo = r1->tempo;
    sup.difficolta = r1->difficolta;

    strcpy(r1->nome, r2->nome);
    r1->tempo = r2->tempo;
    r1->difficolta = r2->difficolta;

    strcpy(r2->nome, sup.nome);
    r2->tempo = sup.tempo;
    r2->difficolta = sup.difficolta;
}
int compare(Ricetta *r1, Ricetta *r2){
    if(r1->tempo < r2->tempo)
        return 0;
    else if(r1->tempo == r2->tempo && r1->difficolta < r2->difficolta)
        return 0;
    else return 1;
}
int ricercaBanale(int *vet, int numRicercato, int dimensione){
    int pos = 0, contL= 1;
    while(pos < dimensione && vet[pos] <= numRicercato){
        if(numRicercato == vet[pos]){
            contL++;
            printf("Elementi analizzati: %d", contL);
            return pos;
        }
        else pos++, contL++;
    }
    printf("Elementi analizzati: %d", contL);
    return -1;
}
int ricercaBinariaIterativa(int *vet, int numRic, int dimensione){
    int primo = 0, ultimo = dimensione-1, mezzo = 0;
    while(primo <= ultimo){
        contBl++;
        mezzo = (primo+ultimo)/2;
        if(numRic < vet[mezzo]){
            contBl++;
            ultimo = mezzo-1;
        }
        else if(numRic == vet[mezzo]){
            contBl++;
            return mezzo;
        }
        else primo = mezzo+1;
    }
    return -1;
}
int ricercaBinariaRicorsiva(int *vet, int numric, int primo, int ultimo){
    int mezzo;
    if (primo > ultimo){
        contBR++;
        return -1;
    }
    mezzo = (primo + ultimo) / 2;
    if (vet[mezzo] == numric){
        contBR++;
        return mezzo;
    }
    else if (vet[mezzo] < numric){
        contBR++;
        return ricercaBinariaRicorsiva(vet, numric, mezzo + 1, ultimo);
    }
    else{
        contBR++;
        return ricercaBinariaRicorsiva(vet, numric, primo, mezzo - 1);
    }
}
void selectionSortRec(int *vet, int dim, int start){
    int minIndex;
    if(start >= dim-1){
        return;
    }

    minIndex = findmin(vet, start, start+1, dim);
    swap(&vet[minIndex], &vet[start]);
    cont_scambi_ric++;
    selectionSortRec(vet, dim, start+1);
}
int findmin(int *vet, int minpos, int start, int dim){
    if(start == dim){
        return minpos;
    }
    if(vet[start] < vet[minpos]){
        cont_confr_ric++;
        minpos = start;
    }
    return findmin(vet, minpos, start+1, dim);
}
void selectionSortHotels(Hotel *hotels, int dimensione){
    int min = 0, sup = 0; //min = indice del valore minimo, sup = variabile di supporto

    for(int i = 0; i <= dimensione -2; i++){
        min = i;
        for(int j = i+1; j <= dimensione-1; j++)
            if(strcmp(&hotels[j].nome, &hotels[min].nome)<0)
                min = j;

        swapHotel(&hotels[i],&hotels[min]);
    }
}
void swapHotel(Hotel *r1, Hotel *r2){
    Hotel sup;

    strcpy(sup.nome, r1->nome);
    sup.prezzo_notte = r1->prezzo_notte;
    sup.recensione = r1->recensione;

    strcpy(r1->nome, r2->nome);
    r1->prezzo_notte = r2->prezzo_notte;
    r1->recensione = r2->recensione;

    strcpy(r2->nome, sup.nome);
    r2->prezzo_notte = sup.prezzo_notte;
    r2->recensione = sup.recensione;
}
int ricercaBinariaIterativaHotel(Hotel *vet, char* nome, int dimensione){
    int primo = 0, ultimo = dimensione-1, mezzo = 0;
    while(primo <= ultimo){
        contBl++;
        mezzo = (primo+ultimo)/2;
        if(strcmp(nome, vet[mezzo].nome)<0){
            contBl++;
            ultimo = mezzo-1;
        }
        else if(strcmp(nome,vet[mezzo].nome)==0){
            contBl++;
            return mezzo;
        }
        else primo = mezzo+1;
    }
    return -1;
}
MatriceSparsa *nuovaMatriceSparsa(int dimensione, MatriceSparsa * matrice){

        printf("Inserire la riga in cui posizionare l'elemento:\n");
        scanf("%d", &matrice[1].riga);
        printf("Inserire la colonna in cui posizionare l'elemento:\n");
        scanf("%d", &matrice[1].colonna);
        printf("Inserire il valore dell'elemento da inserire:\n");
        scanf("%d", &matrice[1].valore);

        for(int i = 2; i <= dimensione; i++){
            printf("Inserire la riga in cui posizionare l'elemento nenno:\n");
            scanf("%d", &matrice[i].riga);
            printf("Inserire la colonna in cui posizionare l'elemento:\n");
            scanf("%d", &matrice[i].colonna);
            printf("Inserire il valore dell'elemento da inserire:\n");
            scanf("%d", &matrice[i].valore);

            if(matrice[i].riga < matrice[i-1].riga)
                swapElementoMatrice(&matrice[i], &matrice[i-1]);
            else if(matrice[i].riga == matrice[i-1].riga && matrice[i].colonna < matrice[i-1].colonna)
                swapElementoMatrice(&matrice[i], &matrice[i-1]);
        }

    return matrice;

}
void swapElementoMatrice(MatriceSparsa *e1, MatriceSparsa *e2){
    MatriceSparsa eSup;

    eSup.riga = e1->riga;
    eSup.colonna = e1->colonna;
    eSup.valore = e1->valore;

    e1->riga = e2->riga;
    e1->colonna = e2->colonna;
    e1->valore = e2->valore;

    e2->riga = eSup.riga;
    e2->colonna = eSup.colonna;
    e2->valore = eSup.valore;
}
void stampaMatriceSparsa(MatriceSparsa *mat){
    int c=1;
    for(int i = 0; i < RIGHE_MATRICE; i++){
        for(int j = 0; j < COLONNE_MATRICE; j++)
            if(i == mat[c].riga && j == mat[c].colonna){
                printf(" %d ", mat[c].valore);
                c++;
            }
            else printf(" 0 ");
        printf("\n");
    }

}
int ricercaMatriceSparsaIterativa(MatriceSparsa *mat, int numRic, int dimensione){ //Ricerca binaria iterativa
    int primo = 1, ultimo = dimensione-1, mezzo;
    while(primo <= ultimo){
        contBl++;
        mezzo = (primo+ultimo)/2;
        if(numRic < mat[mezzo].valore){
            contBl++;
            ultimo = mezzo-1;
        }
        else if(numRic == mat[mezzo].valore){
            contBl++;
            return mezzo;
        }
        else primo = mezzo+1;
    }
    return -1;
}
void trasp_rapida(MatriceSparsa *a, MatriceSparsa *b){
    int num_colonna = a[0].colonna;
    int num_val = a[0].valore;
    int curPos;
    b[0].riga = num_colonna;
    b[0].colonna = a[0].riga;
    b[0].valore = num_val;

    int *terminiRiga = (int*)malloc((RIGHE_MATRICE*COLONNE_MATRICE)* sizeof(int));
    int *posIniziale = (int*)malloc((RIGHE_MATRICE*COLONNE_MATRICE)* sizeof(int));

    if(num_val > 0 ){
        //Creazione termini riga
        for(int i = 0; i < num_colonna; i++)
            terminiRiga[i] = 0;
        for(int i = 1; i <= num_val; i++)
            terminiRiga[a[i].colonna] = terminiRiga[a[i].colonna]+1;

        //Creazione posIniziale
        posIniziale[0] = 1;
        for(int i = 1; i < num_colonna; i++)
            posIniziale[i] = posIniziale[i-1] + terminiRiga[i-1];

        //Trasposizione
        for(int i = 1; i <= num_val; i++){
            curPos = posIniziale[a[i].colonna];
            posIniziale[a[i].colonna] = posIniziale[a[i].colonna]+1;

            b[curPos].riga = a[i].colonna;
            b[curPos].colonna = a[i].riga;
            b[curPos].valore = a[i].valore;
        }
    }
    printf("\nFINE\n");
}

int* insuccesso(char* pat){
    int i;
    int n = strlen(pat);
    int* insucc = (int*)calloc(n,sizeof(int));

    insucc[0] = -1;

    //analisi dei prefissi
    for(int j = 1; j < n; j++){
        i = insucc[j-1];
        while((pat[j] != pat[i+1]) && (i >= 0))
            i = insucc[i];

        if(pat[j] == pat[i+1])
            insucc[j] = i+1;
        else insucc[j] = -1;
    }
    return insucc;
}
int KMP_match(char *stringa, char *pat){
    int* insucc = insuccesso(pat);

    int i = 0, j = 0;
    int lenS = strlen(stringa), lenP = strlen(pat);

    while(i < lenS && j < lenP){
        if(stringa[i] == pat[j])
            i++, j++;

        else if(j == 0)
            i++;
        else j = insucc[j-1]+1;
    }
    free(insucc);
    if(j == lenP)
        return i-lenP;
    else return -1;
}
int KMP_matchCiclico(char *stringa, char *pat){
    int* insucc = insuccesso(pat);
    int i = 0, j = 0;
    int lenS = strlen(stringa), lenP = strlen(pat);

    while(i < lenS && j < lenP){
        if(stringa[i] == pat[j])
            i++, j++;
        else if(j == 0)
            i++;
        else j= insucc[j-1]+1;
    }

    if(i == lenS && j < lenP){
        i=0;
        while(i < lenS && j < lenP){
            if(stringa[i] == pat[j]){
                i++, j++;
            }
            else if(j == 0)
                i++;
            else j= insucc[j-1]+1;
        }
    }
    free(insucc);
    if(j == lenP && i >= j)
        return i-lenP;
    else if(j == lenP && i < j){
        i = lenS - (lenP-i);//Ottengo la posizione dell'inizio del pattern all'interno della stringa ciclica
        return i;
    }

    else return -1;
}


///ESERCITAZIONE 5
bool isEmptyQueue(Queue *queue){
    if(queue->front == NULL)
        return true;
    else return false;
}
bool isFullQueue(Queue *queue){
    if(queue == MAX_SIZE-1)
        return true;
    else return false;
}
void pushQueue(Queue* queue, Ordine val){
    if(isFullQueue(queue))
        printf("Errore overflow");
    else{
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->link = NULL;

        if(isEmptyQueue(queue)){
            queue->front = new_node;
            queue->back = new_node;
        }
        else {
            queue->back->link = new_node;
            queue->back = new_node;
        }
        queue->cont++;
    }
}
Ordine popQueue(Queue* queue){
    Ordine val;
    Node *temp;
    if(isEmptyQueue(queue)){
        printf("Errore underflow");
    }
    else{
        temp = queue->front;
        val = queue->front->data;

        if(queue->cont==1)
            queue->front = queue->back = NULL;
        else{
            queue->front = queue->front->link;
        }


        queue->cont--;
        free(temp);
    }
    return val;
}
void printQueue(Queue *queue){
    Node *nodo = queue->front;
    while(nodo != NULL){
        printf("Nome articolo %s - Prezzo %f - Destinatario: %s\n",
               nodo->data.articolo, nodo->data.prezzo, nodo->data.destinatario);
        nodo = nodo->link;
    }
}
bool isEmptyStack(Stack* stack){
    if(stack->top == NULL)
        return true;
    else return false;
}
bool isFullStack(Stack* stack){
    if(stack == MAX_SIZE-1)
        return true;
    else return false;
}
void pushStack(Stack *stack, Ordine val){
    if(isFullStack(stack))
        printf("Errore overflow");
    else{
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = val;
        new_node->link = NULL;

        if(isEmptyStack(stack))
            stack->top = new_node;
        else{
            new_node->link = stack->top;
            stack->top = new_node;
        }
        stack->cont++;
    }
}
Ordine popStack(Stack *stack){
    Ordine val;
    Node *temp;
    if(isEmptyStack(stack)){
        printf(("Errore undeflow"));
        strcpy(val.articolo, "-1");
        val.prezzo = -1;
        strcpy(val.destinatario, "-1");
    }
    else{
        temp = stack->top;
        val = stack->top->data;

        stack->top = stack->top->link;
        stack->cont--;
        free(temp);
    }
    return val;
}
void printStack(Stack *stack){

    Node *nodo = stack->top;
    while(nodo != NULL){
        printf("Nome articolo %s - Prezzo %.2f - Destinatario: %s\n",
               nodo->data.articolo, nodo->data.prezzo, nodo->data.destinatario);
        nodo = nodo->link;
    }
}


///ESERCITAZIONE 6 SPOTIFY VERSION
Song* acquireSong()
{
    Song* new_s = (Song*)malloc(sizeof(Song));
    printf("\nInsert title -> ");
    scanf("%[^\n]s", new_s->title);
    getchar();

    printf("Insert genre -> ");
    scanf("%[^\n]s", new_s->genre);
    getchar();

    printf("Insert length -> ");
    scanf("%f", &(new_s->length));
    getchar();

    new_s->prev = NULL;
    new_s->next = NULL;

    return new_s;
}
void insertSong(PlayList *pl, Song* s){
    if(pl->top == NULL)
        pl->top = s;
    else{
        //ricerca della posizione in cui inserire (tmp_prev e tmp_next sono due puntatori d'appoggio)
        struct song *tmp_prev = NULL;
        struct song *tmp_next = pl->top;

        while(tmp_next != NULL && strcmp(tmp_next->title,s->title) <= 0){
            tmp_prev = tmp_next;
            tmp_next = tmp_next->next;
        }

        //ora conosciamo il nodo a cui appendere il nuovo nodo s
        if(tmp_next == NULL)
            tmp_prev->next = s, s->prev = tmp_prev;
        else if(tmp_prev == NULL)
            tmp_next->prev = s, s->next = tmp_next, pl->top = s;
        else
            tmp_prev->next = s, tmp_next->prev = s, s->prev = tmp_prev, s->next = tmp_next;
    }
}
Song* findSong(PlayList *pl, char title[]){
    if(pl->top == NULL)
        printf("\nPlaylist vuota\n");

    struct song *tmp_prev = NULL;
    struct song *tmp_next = pl->top;

    while(tmp_next != NULL){
        if(strcmp(tmp_next->title,title)==0){
            return tmp_next;
        }
        tmp_prev = tmp_next;
        tmp_next = tmp_next->next;
    }
    return NULL;
}
void deleteSong(PlayList* pl, Song* s){

    if(pl->top == NULL)
        printf("\nNon c'è n'è di brani\n");

    if(s != NULL && s->next != NULL && s->prev != NULL) {
        s->next->prev = s->prev;
        s->prev->next = s->next;
    }
    else if(s != NULL && s->next == NULL){
        s->prev->next = s->next;
    }
    else if(s != NULL && s->prev == NULL){
        s->next->prev = s->prev;
        pl->top = pl->top->next;
    }

    free(s);
}
void modifySong(PlayList* pl, Song* s){

    if(pl->top == NULL)
        printf("\nPlaylist vuota\n");

    if(s != NULL) {
        printf("Inserisci il nuovo titolo:\n");
        scanf("%s", s->title);
    }
}
void printPlaylist(PlayList* pl){
    int c=1;
    Song* s = pl->top;
    if(pl->top == NULL)
        printf("Playlist vuota\n");
    else
        while(s != NULL){
            printf("\nTitle: %s - Genre: %s - Lenght: %.2f\n",s->title, s->genre, s->length);
            s = s->next;
        }
}
void printSong(Song* t){
    printf("TITLE    :\t %s \n", t->title);
    printf("GENRE    :\t %s \n", t->genre);
    printf("LENGTH   :\t %.2f \n\n", t->length);
}
Song* nextSong(Song* s){
    if(s->next != NULL)
        return s->next;
    else return NULL;
}
Song* prevSong(Song* s){
    if(s->prev != NULL)
        return s->prev;
    else return NULL;
}
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC){

    Song* tmpA = plA->top, *tmpB = plB->top, *tmpC, *ultimoC;

    if(plA->top == NULL) {
        plC->top = plB->top;
        plC->top->prev = NULL;
    }
    else if(plB->top == NULL) {
        plC->top = plA->top;
        plC->top->prev = NULL;
    }
    if(strcmp(tmpA->title,tmpB->title)<0){
        tmpC = ultimoC = tmpA;
        tmpA = tmpA->next;
        ultimoC->next = NULL;
    }else{
        tmpC = ultimoC = tmpB;
        tmpB = tmpB->next;
        ultimoC->next = NULL;
    }

    plC->top = tmpC;

    while(tmpA != NULL && tmpB != NULL){
        if(strcmp(tmpA->title,tmpB->title)<0){
            tmpC->next = tmpA;
            tmpC = tmpA;
            tmpA = tmpA->next;
            tmpC->next = NULL;
        }else{
            tmpC->next = tmpB;
            tmpC = tmpB;
            tmpB = tmpB->next;
            tmpC->next = NULL;
        }
    }

    if(tmpA == NULL)
        tmpC->next = tmpB;
    else
        tmpC->next = tmpA;

    plA->top = NULL;
    plB->top = NULL;
}


///ESERCITAZONE 7
Paziente nuovoPaziente(ProntoSoccorso *ps)
{
    Paziente p;

    printf("\nNome paziente -> ");
    scanf("%[^\n]s", p.nome);
    getchar();

    do
    {
        printf("\nCodice paziente (0 = bianco, 1 = verde, 2 = giallo, 3 = rosso)-> ");
        scanf("%u", &p.codice);
        getchar();

        if(p.codice < BIANCO || p.codice > ROSSO)
            printf("\nCodice non valido");
    }while(p.codice < BIANCO || p.codice > ROSSO);

    if(p.codice == BIANCO)
    {
        ps->numeroB++;
        p.ordine = ps->numeroB;
    }
    else if(p.codice == GIALLO)
    {
        ps->numeroG++;
        p.ordine = ps->numeroG;

    }
    else if (p.codice == VERDE)
    {
        ps->numeroV++;
        p.ordine = ps->numeroV;
    }
    else
    {
        ps->numeroR++;
        p.ordine = ps->numeroR;
    }
    return p;
}
int priorita(Paziente p1, Paziente p2){
    if((p1.codice < p2.codice) || (p1.codice == p2.codice && p1.ordine < p2.ordine))
        return 1; else return 2;
}
void insertHeap(Paziente heap[DIM_HEAP], Paziente item, int *n){
    //Inserisce un nuovo item in un heap di n elementi

    if(*n == DIM_HEAP-1){
        printf("\nL'heap è pieno\n");
        return;
    }
    *n += 1;

    int i = *n;
    printf("\n%d\n", *n);
    while(i != 1 && priorita(item, heap[i/2])==1){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = item;
}
Paziente deleteHeap(Paziente heap[DIM_HEAP], int *n){
    //Cancella e restituisce l'elemento radice in un heap di n elementi

    Paziente item = heap[1];
    Paziente temp = heap[*n];

    *n = *n - 1;
    int padre = 1, figlio = 2;

    while(figlio <= *n){
        if(figlio < *n && priorita(heap[figlio], heap[figlio+1])==2)
            figlio++;
        if(priorita(temp,heap[figlio])==1)
            break;
        heap[padre] = heap[figlio];
        padre = figlio;
        figlio *= 2;
    }
    heap[padre] = temp;
    return item;
}
void printHeap(Paziente heap[DIM_HEAP], int *n){
    for(int i = 1; i <= *n; i++){
        //printf("\nNome: %s -- Codice: %s -- Ordine: %d", heap[i].nome, heap[i].codice, heap[i].ordine);
        printf("\nNome: %s", heap[i].nome);
        switch(heap[i].codice){
            case 0:
                printf(" Codice: BIANCO ");
                break;
            case 1:
                printf(" Codice: GIALLO ");
                break;
            case 2:
                printf(" Codice: ARANCIONE ");
                break;
            case 3:
                printf(" Codice: ROSSO ");
                break;
            default:
                printf(" CODICE ERRATO ");
                break;
        }
        printf(" Ordine: %d", heap[i].ordine);
    }
}


///ESERCITAZIONE 8
/* -------------------------------
 Funzioni gia' implementate (NON MODIFICARE):
 ------------------------------- */
Birra acquisisci_birra()
{
    Birra b;
    getchar();

    printf("nome: ");
    scanf("%[^\n]s", b.nome);
    getchar();

    printf("gradi: ");
    scanf("%f", &b.gradi);

    printf("bottiglie: ");
    scanf("%d", &b.bottiglie);

    return b;
}
void stampa_birra(Birra b)
{
    printf("--------------------- \n");
    printf("nome:  %s \n", b.nome);
    printf("gradi: %.1f \n", b.gradi);
    printf("bottiglie: %d \n", b.bottiglie);
    printf("--------------------- \n");
}
Nodo* crea_nodo(Birra b)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node != NULL)
    {
        new_node->key = b;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}
Nodo* carica_test()
{
    Nodo *root = NULL;
    int i;
    Birra elenco[NUM_TEST] = {{"Ichnusa", 4.7, 3}, {"Founders", 5.7, 15}, {"Peroni", 4.7, 2},
                              {"San Miguel", 3.2, 4}, {"Miller", 4.7, 7}, {"Guinnes", 4.2, 1},
                              {"Best Brau", 4.7, 12}, {"Barley", 5.0, 7}, {"Chouffe", 8.0, 12},
                              {"Franziskaner", 5, 10}, {"Heineken", 5.0, 7}, {"Kwak", 8.0, 14},
                              {"Paulaner", 5.5, 10}, {"Rubiu", 4.5, 10}, {"Tuborg", 5.0, 3}};


    for(i = 0; i < NUM_TEST; i++)
    {
        Nodo *new_birra = crea_nodo(elenco[i]);
        root = insert_nodo(root, new_birra);
    }

    return root;
}
/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node)
{
    Nodo *y = NULL;
    Nodo *x = root;
    while(x != NULL){ //Cerco un cammino discendente dalla radice
        y = x;
        if(strcmp(new_node->key.nome,x->key.nome)<0)
            x = x->left;
        else x = x->right;
    }
    //Usciti da questo ciclo y è il puntatore al padre del nuovo nodo
    new_node->parent = y;

    if(y == NULL)
        root = new_node;
    else if(strcmp(new_node->key.nome, y->key.nome)<0)
        y->left = new_node;
    else y->right = new_node;

    return root;
}
void inorder(Nodo* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    stampa_birra(root->key);
    inorder(root->right);
}
void preorder(Nodo* root)
{
    if(root == NULL)
        return;
    stampa_birra(root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Nodo* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    stampa_birra(root->key);
}
int profondita(Nodo* root)
{
    if(root == NULL)
        return 0;
    int sx = profondita(root->left);
    int dx = profondita(root->right);

    return 1 + max(sx, dx);
}
int max(int v1, int v2)
{
    if(v1 > v2)
        return v1;
    else v2;
}
Nodo* ricerca(Nodo* root, char* nome_birra) //Ho scelto la versione iterativa
{
    while(root != NULL){
        if(strcmp(nome_birra, root->key.nome) == 0)
            return root;
        if(strcmp(nome_birra, root->key.nome) < 0)
            root = root->left;
        else root = root->right;
    }
    return NULL;
}
Nodo* abr_min(Nodo* root)
{
    Nodo* node = root;
    while(node->left != NULL)
        node = node->left;
    return node;
}
Nodo* abr_max(Nodo* root)
{
    Nodo* node = root;
    while(node->right != NULL)
        node = node->right;
    return node;
}
Nodo* abr_pred(Nodo* x)
{
    Nodo *y;
    if(x->left != NULL)
        return abr_max(x->left);
    y = x->parent;
    while(y != NULL && x == x->left){
        x = y;
        y = y->parent;
    }
    return y;
}
Nodo* abr_succ(Nodo* x)
{
    Nodo *y;
    if(x->right != NULL)
        return abr_min(x->right);
    y = x->parent;
    while(y != NULL && x == x->right){
        x = y;
        y = y->parent;
    }
    return y;
}
Nodo* delete_node(Nodo* root, Nodo* nodo)
{
    Nodo *y, *x;
    if(nodo->left == NULL || nodo->right == NULL)
        y = nodo;
    else y = abr_succ(nodo);
    if(y->left != NULL)
        x = y->left;
    else x = y->right;
    if(x != NULL)
        x->parent = y->parent;
    if(y->parent == NULL)
        root = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else y->parent->right = x;
    if(y != nodo)
        nodo->key = y->key;
    free(y);
    return root;
}


void carica_citta_test(Citta grafo[], int * num_nodi) {
    //AGGIUNTO PUNTATORE AD INTERO CONTENENTE IL NUMERO DELLE CITTA' FACENTI PARTE DEL GRAFO
    //AGGIUNTO INCREMENTO DEL NUMERO DELLE CITTA DOPO UN INSERIMENTO

    *num_nodi = 0;

    //Cagliari
    strcpy(grafo[0].nome, "Cagliari");
    strcpy(grafo[0].nazione, "Italia");
    grafo[0].abitanti = 300000;
    grafo[0].lista_adj = NULL;
    *num_nodi += 1;


    //Zurigo
    strcpy(grafo[1].nome, "Zurigo");
    strcpy(grafo[1].nazione, "Svizzera");
    grafo[1].abitanti = 400000;
    grafo[1].lista_adj = NULL;
    *num_nodi += 1;

    //Lione
    strcpy(grafo[2].nome, "Lione");
    strcpy(grafo[2].nazione, "Francia");
    grafo[2].abitanti = 500000;
    grafo[2].lista_adj = NULL;
    *num_nodi += 1;

    //Genova
    strcpy(grafo[3].nome, "Genova");
    strcpy(grafo[3].nazione, "Italia");
    grafo[3].abitanti = 800000;
    grafo[3].lista_adj = NULL;
    *num_nodi += 1;

    //Roma
    strcpy(grafo[4].nome, "Roma");
    strcpy(grafo[4].nazione, "Italia");
    grafo[4].abitanti = 4000000;
    grafo[4].lista_adj = NULL;
    *num_nodi += 1;

    //New York
    strcpy(grafo[5].nome, "New York");
    strcpy(grafo[5].nazione, "USA");
    grafo[5].abitanti = 8500000;
    grafo[5].lista_adj = NULL;
    *num_nodi += 1;

    //Bilbao
    strcpy(grafo[6].nome, "Bilbao");
    strcpy(grafo[6].nazione, "Spagna");
    grafo[6].abitanti = 350000;
    grafo[6].lista_adj = NULL;
    *num_nodi += 1;

    //Berlino
    strcpy(grafo[7].nome, "Berlino");
    strcpy(grafo[7].nazione, "Germania");
    grafo[7].abitanti = 3500000;
    grafo[7].lista_adj = NULL;
    *num_nodi += 1;

    //Londra
    strcpy(grafo[8].nome, "Londra");
    strcpy(grafo[8].nazione, "Gran Bretagna");
    grafo[8].abitanti = 8700000;
    grafo[8].lista_adj = NULL;
    *num_nodi += 1;

    //Miami
    strcpy(grafo[9].nome, "Miami");
    strcpy(grafo[9].nazione, "USA");
    grafo[9].abitanti = 450000;
    grafo[9].lista_adj = NULL;
    *num_nodi += 1;

    //Tokyo
    strcpy(grafo[10].nome, "Tokyo");
    strcpy(grafo[10].nazione, "Giappone");
    grafo[10].abitanti = 13700000;
    grafo[10].lista_adj = NULL;
    *num_nodi += 1;
}
void carica_grafo_test_orientato(Citta grafo[], int * num_nodi) {
    carica_citta_test(grafo, num_nodi);

    //Creazione archi
    crea_arco_orientato(grafo, 0, 1, *num_nodi);
    crea_arco_orientato(grafo, 0, 4, *num_nodi);

    crea_arco_orientato(grafo, 1, 0, *num_nodi);
    crea_arco_orientato(grafo, 1, 2, *num_nodi);

    crea_arco_orientato(grafo, 2, 1, *num_nodi);
    crea_arco_orientato(grafo, 2, 3, *num_nodi);

    crea_arco_orientato(grafo, 4, 0, *num_nodi);
    crea_arco_orientato(grafo, 4, 1, *num_nodi);
    crea_arco_orientato(grafo, 4, 5, *num_nodi);
    crea_arco_orientato(grafo, 4, 6, *num_nodi);

    crea_arco_orientato(grafo, 5, 1, *num_nodi);

    crea_arco_orientato(grafo, 6, 7, *num_nodi);

    crea_arco_orientato(grafo, 8, 9, *num_nodi);
    crea_arco_orientato(grafo, 9, 8, *num_nodi);

    crea_arco_orientato(grafo, 9, 10, *num_nodi);
}
void carica_grafo_test_non_orientato(Citta grafo [], int * num_nodi) {
    carica_citta_test(grafo, num_nodi);

    //Creazione archi
    crea_arco_non_orientato(grafo, 0, 1, *num_nodi);

    crea_arco_non_orientato(grafo, 0, 4, *num_nodi);

    crea_arco_non_orientato(grafo, 1, 2, *num_nodi);

    crea_arco_non_orientato(grafo, 2, 3, *num_nodi);

    crea_arco_non_orientato(grafo, 4, 1, *num_nodi);

    crea_arco_non_orientato(grafo, 4, 5, *num_nodi);

    crea_arco_non_orientato(grafo, 4, 6, *num_nodi);

    crea_arco_non_orientato(grafo, 5, 1, *num_nodi);

    crea_arco_non_orientato(grafo, 6, 7, *num_nodi);

    crea_arco_non_orientato(grafo, 8, 9, *num_nodi);

    crea_arco_non_orientato(grafo, 9, 10, *num_nodi);
}
void aggiungi_nodo(Citta grafo[], int *num_nodi) {
    printf("\nInserisci il nome della città che vuoi inserire nella struttura grafo: ");
    scanf("%49s", grafo[*num_nodi].nome);
    printf("\nInserisci il nome della nazione della città: ");
    scanf("%49s", grafo[*num_nodi].nazione);
    printf("\nInserisci il numero di abitanti della città: ");
    scanf("%d", &grafo[*num_nodi].abitanti);
    grafo[*num_nodi].lista_adj = NULL;
    *num_nodi = +1;
}
void crea_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi) {
    // inserire qui il codice della funzione...
    // allocazione e inizializzazione del nodo da inserire
    GNode * new = (GNode *) calloc(1 , sizeof(GNode *));
    new->link = NULL;
    new->vertex_id = id_testa;

    // controllo se la lista di adiacenza è vuota e in tal caso inserisco "new" in testa
    if (grafo[id_coda].lista_adj == NULL)
        grafo[id_coda].lista_adj = new;

        // se non è vuota le possibilita' saranno INSERIMENTO IN TESTA, IN CODA e AL CENTRO
    else {
        // inizializzo due putatori ausiliari per scorrere la lista
        GNode * tmp_prev = NULL;
        GNode * tmp_next = grafo[id_coda].lista_adj;

        // scorro la lista finchè alla posizione successiva non trovo un valore "id" maggiore di quello da inserire
        while ((tmp_next != NULL) && (tmp_next->vertex_id < id_testa)) {
            tmp_prev = tmp_next;
            tmp_next = tmp_next->link;
        }

        // una volta trovata la posizione generica dove inserire il nodo posso riconoscere la situazione attuale

        // inserimento alla fine della lista
        if (tmp_next == NULL)
            tmp_prev->link = new;
            // inserimento all'inizio della lista
        else if (tmp_prev == NULL) {
            new->link = tmp_next;
            grafo[id_coda].lista_adj = new;
        }
            // inserimento al centro
        else {
            new->link = tmp_next;
            tmp_prev->link = new;
        }
    }
}
void crea_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi) {
    // banalmente creo 2 archi orientati da "id_coda -> id_testa" e da "id_testa -> id_coda"
    crea_arco_orientato(grafo, id_coda, id_testa, num_nodi);
    crea_arco_orientato(grafo, id_testa, id_coda, num_nodi);
}
void stampa_lista_adiacenze(Citta grafo[], int num_nodi) {
    GNode * next = NULL;
    for (int i = 0; i < num_nodi; i++) {
        Citta * city = &grafo[i];
        stampa_citta(grafo, i);
    }
}
void stampa_citta(Citta grafo[], int id) {
    Citta * city = &grafo[id];
    printf("\n\n"
           "ID: %d\n"
           "NOME: %s\n"
           "NAZIONE: %s\n"
           "ABITANTI: %d\n"
           "ADIACENZE: ", id, city->nome, city->nazione, city->abitanti);

    // next punta all'adiacenza successiva di grafo[id]
    GNode * next = city->lista_adj;
    while(next != NULL) {
        // finchè son presenti nodi nella lista di adiacenza ne stampo la città corrispondente
        printf(" -> %s ", grafo[next->vertex_id].nome);
        next = next->link;
    }
}
void DFS(Citta grafo[], int visited[], int start_id) {
    //visita (stampa)
    stampa_citta(grafo, start_id);
    //marco il nodo come visitato
    visited[start_id] = 1;

    // tmp punta alla lista delle adiacenze di grafo[start_id]
    GNode * tmp = grafo[start_id].lista_adj;
    int id_next;

    //controllo la lista delle adiacenze del nodo corrente
    while(tmp != NULL) {
        // salvo l'id della prossima adiacenza (se presente)
        id_next = tmp->vertex_id;

        // controllo se la successiva adiacenza è un nodo visitato
        if(!visited[id_next])
            // se non è ancora stato visitato procedo con la visita in profondità di quel nodo
            DFS(grafo, visited, id_next);

        // passo all'adiacenza successiva
        tmp = tmp->link;
    }
}
void BFS(Citta grafo[], int visited[], int start_id, int num_nodi) {
    // visita (stampa)
    stampa_citta(grafo, start_id);
    // marco il nodo come visitato
    visited[start_id] = 1;

    // definisco ed inizializzo una GQueue (coda basata sulla struttura GNode)
    GQueue q = {NULL, NULL, 0};
    // inserisco nella coda la città di partenza
    pushGQueue(&q, &grafo[start_id]);

    // i tiene traccia dell'id di una città rimossa dalla coda tramite "popGQueue";
    // tmp tiene traccia della successiva adiacenza
    int i;
    GNode* tmp = NULL;

    // finchè vi sono elementi in coda
    while( !isEmptyGQueue(&q) ) {
        // tramite una popGQueue rimuovo la città dal dietro della coda e ne ottengo l'id
        i = popGQueue(&q);
        // tmp <- lista delle adiacenze di grafo[i] (ovvero della città appena rimossa dalla coda)
        tmp = grafo[i].lista_adj;

        // fin quando esiste un'adiacenza successiva
        while(tmp != NULL) {
            // controllo se l'adiacenza corrente è già stata visitata
            if ( !visited[tmp->vertex_id] ) {
                // se non è ancora stata visitata allora procedo con la visita della città corrispondente
                // inserisco la città nella coda
                pushGQueue(&q, &grafo[tmp->vertex_id]);
                // visito (stampa)
                stampa_citta(grafo, tmp->vertex_id);
                // marco come visitato
                visited[tmp->vertex_id] = 1;
            }
            // tmp viene aggiornato con l'adiacenza immediatamente successiva (se esiste)
            tmp = tmp->link;
        }
    }
}
void freeVisited(int * visited, int num_nodi) {
    // inizializzo il vettore dei nodi visitati a 0
    for (int i = 0; i < num_nodi; i++)
        visited[i] = 0;
}
// funzioni di gestione di una coda (adattate a struttura GNode)
bool isEmptyGQueue(GQueue * queue) {
    if (!queue->cont)
        return true;
    else return false;
}
bool isFullGQueue(GQueue * queue) {
    if(queue->cont >= DIM_CODA)
        return true;
    else return false;
}
void pushGQueue(GQueue * queue, Citta * city) {
    if (isFullGQueue(queue))
        printf("[Overflow Error]: Coda Piena %d/%d", queue->cont, DIM_CODA);
    else {
        GNode * newNode = (GNode *)calloc(sizeof(GNode), 1);
        /*newNode->vertex_id = city->id,*/ newNode->link = NULL;

        if (isEmptyGQueue(queue)) { queue->front = newNode, queue->back = newNode; }
        else { queue->back->link = newNode, queue->back = newNode; }

        queue->cont++;
    }
}
int popGQueue(GQueue * queue) {
    int out = -1;

    if(isEmptyGQueue(queue)) {
        printf("[Underflow Error]: Coda Vuota");
    }
    else {
        GNode * temp = queue->front;
        out = queue->front->vertex_id;

        if(queue->cont == 1)
            queue->front = NULL, queue->back = NULL;
        else queue->front = temp->link;

        queue->cont--;
        free(temp);
    }
    return out;
}
bool cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi) {
    GNode * tmp_prev = NULL;
    GNode * tmp_next = grafo[id_coda].lista_adj;

    while (tmp_next != NULL) {
        if(tmp_next->vertex_id == id_testa) {
            if (tmp_prev == NULL) {
                grafo[id_coda].lista_adj = NULL;
                free(tmp_next);
            }
            else if(tmp_next == NULL) {
                tmp_prev->link = NULL;
                free(tmp_next);
            }
            else {
                tmp_prev->link = tmp_next->link;
                free(tmp_next);
            }

            return true;
        }

        tmp_prev = tmp_next;
        tmp_next = tmp_next->link;
    }

    printf("ERRORE: Arco Orientato    [%d -> %d] o (%s -> %s)    NON TROVATO!",
           id_coda, id_testa, grafo[id_coda].nome, grafo[id_testa].nome);

    return false;
}
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi) {
    cancella_arco_orientato(grafo, id_coda, id_testa, num_nodi);
    cancella_arco_orientato(grafo, id_testa, id_coda, num_nodi);
}
void componenti_connesse(Citta grafo[], int visited[], int num_nodi) {
    bool not_visited_yet = true;
    int next_not_visited = 0;
    int i;

    while(not_visited_yet) {
        printf("COMPONENTE CONNESSA CON ID RADICE %d:\n\n", next_not_visited);
        DFS(grafo, visited, next_not_visited);

        for (i = 1; i < num_nodi; i++) {
            if( !visited[i] ) {
                next_not_visited = i;
                break;
            }
        }

        if (i >= num_nodi)
            not_visited_yet = false;
    }
}

void carica_auto_test(Nodo* parcheggio[])
{
    Auto a0 = {"PI555TA", 12, 15};
    Auto a1 = {"CA220TO", 7, 59};
    Auto a2 = {"EG000AL", 19, 45};
    Auto a3 = {"GO000LE", 15, 20};
    Auto a4 = {"BA220TO", 10, 35};
    Auto a5 = {"AP111LE", 15, 20};
    Auto a6 = {"MI123FT", 18, 40};
    Auto a7 = {"NO985LE", 20, 30};
    Auto a8 = {"GI124CH", 11, 20};
    Auto a9 = {"LO199RE", 9, 30};
    Auto a10 = {"ZA156KF", 7, 10};

    inserisci_auto(parcheggio, a0);
    inserisci_auto(parcheggio, a1);
    inserisci_auto(parcheggio, a2);
    inserisci_auto(parcheggio, a3);
    inserisci_auto(parcheggio, a4);
    inserisci_auto(parcheggio, a5);
    inserisci_auto(parcheggio, a6);
    inserisci_auto(parcheggio, a7);
    inserisci_auto(parcheggio, a8);
    inserisci_auto(parcheggio, a9);
    inserisci_auto(parcheggio, a10);
}
//Funzione hash che calcola la somma in decimale dei caratteri presenti nella targa e fa il modulo 7 (7 caratteri nella targa)
int hash_function(char targa[]){
    int sum = 0;
    for(int i = 0; i < MAX_TARGA; i++){
        sum += (int)targa[i];
    }
    return sum%NUM_PIANI;
}
Auto acquisisci_auto(){
    Auto auto auto1;
    printf("Inserire la targa dell'auto:\n");
    scanf("%s", auto1.targa);
    printf("Inserire l'ora di arrivo\n");
    scanf("%d", &auto1.ora);
    printf("Inserire il minuto di arrivo\n");
    scanf("%d", &auto1.min);
    return auto1;
}
void inserisci_auto(Nodo2 *parcheggio[], Auto a){

    int piano = hash_function(a.targa);

    Nodo2 *tmp = parcheggio[piano], *inizio = parcheggio[piano];

    if(parcheggio[piano] == NULL){
        parcheggio[piano] = calloc(1, sizeof(Nodo));
        parcheggio[piano]->info = a;
        parcheggio[piano]->link = NULL;
        inizio = parcheggio[piano];
    }else{
        while(parcheggio[piano] != NULL && tmp->link != NULL){
            parcheggio[piano] = parcheggio[piano]->link;
            tmp = tmp->link; //tmp indica l'elemento precedente all'ultimo
        }
        parcheggio[piano] = calloc(1,sizeof(Nodo));
        parcheggio[piano]->info  =  a;
        parcheggio[piano]->link = NULL;
        tmp->link = parcheggio[piano];
    }
    parcheggio[piano] = inizio;
}
void stampa_piano(Nodo* parcheggio[], int piano){

    Nodo2* posizione = parcheggio[piano];
    if(posizione == NULL)
        printf("Piano %d vuoto\n", piano);
    while(posizione != NULL){
        printf(" Targa: %s\n Ora di arrivo: %d\n Minuti di arrivo: %d\n\n", posizione->info.targa, posizione->info.ora, posizione->info.min);
        posizione = posizione->link;
    }
}
void stampa_parcheggio(Nodo* parcheggio[]){
    for(int i = 0; i < NUM_PIANI; i++){
        printf("Piano %d -----------------------\n", i);
        stampa_piano(parcheggio, i);
    }
}
Nodo2* ricerca_auto(Nodo2 *parcheggio[], char targa[]){
    for(int i = 0; i < NUM_PIANI; i++){
        Nodo2* posizione = parcheggio[i];
        while(posizione != NULL){
            if(strcmp(targa, posizione->info.targa) == 0)
                return posizione;
            posizione = posizione->link;
        }
    }
    return NULL;
}
void elimina_auto(Nodo2 *parcheggio[], char targa[]){
    for(int i = 0; i < NUM_PIANI; i++){

        Nodo2* posizione = parcheggio[i], *tmp, *prec;
        while(posizione != NULL){
            printf("\nCONTROLLO NEL PIANO: %d", i);
            if (posizione->link == NULL) { //Cancellazione in testa senza elementi successivi
                if (strcmp(targa, posizione->info.targa) == 0) {
                    parcheggio[i] = NULL;
                    free(parcheggio[i]);
                    printf("Auto eliminata nel piano %d\n", i);
                    break;
                }
            } else {
                if(posizione->link != NULL && parcheggio[i] == posizione) { //Cancellazione in testa con elementi successivi
                    if (strcmp(targa, posizione->info.targa) == 0) {
                        tmp = posizione;
                        parcheggio[i] = parcheggio[i]->link;
                        free(tmp);
                        break;
                    }
                }
                else if(posizione->link != NULL){ //Cancellazione in mezzo
                    printf("CANCELLO IN MEZZO");
                    if (strcmp(targa, posizione->info.targa) == 0) {
                        tmp = posizione;
                        prec->link = posizione->link;
                        free(tmp);
                        break;
                    }
                }
            }
            prec = posizione;
            posizione = posizione->link;
        }
    }
}

void insertionSort(int lista[], int dim){

    int prossimo = 0, j=0;
    cont_confr_iter = 0, cont_scambi_iter = 0;

    for(int i = 1; i < dim; i++){
        prossimo = lista[i];
        //cont_scambi_iter++;
        for(j = i-1; j >= 0; j--){
            cont_confr_iter++;
            if(prossimo < lista[j]){
                lista[j+1] = lista[j];
                cont_scambi_iter++;
            }
            else break;
        }
        lista[j+1] = prossimo;
        cont_scambi_iter++;
    }
    printf("Confronti: %d\nScambi: %d\n",cont_confr_iter,cont_scambi_iter);
}
void quickSort(int lista[], int u, int v){

    int q;
    if(u == v) return;
    q = perno(lista, u,v);
    if(u < q)
        quickSort(lista, u, q-1);
    if(q < v)
        quickSort(lista, q+1, v);

}
int perno(int lista[], int primo, int ultimo){

    int i = primo, j = ultimo + 1, pivot = lista[primo];
    while(i < j){
        do{
            i++;
        }while(i <= ultimo && lista[i] <= pivot);
        do{
            cont_confr_iter++;
            j--;
        }while(j >= primo && lista[j] > pivot);
        if(i < j){
            swap(&lista[i], &lista[j]);
            cont_scambi_iter++;
        }
    }
    swap(&lista[primo], &lista[j]);
    cont_scambi_iter++;
    return j;
}
void quickInsertionSort(int lista[], int u, int v){

    int q = 0, m;
    if(u == v) return;
    printf("Inserire il valore m \n(Sara' il valore tramite il quale dedicederemo se effettuare un "
           "passo del quick sort o\nse utilizzare l'insertion sort)\nInserire un valore da 0 a %d:\n", DIM_STACK-1);
    scanf("%d", &m);
    q = perno(lista, u,v);
    if(u < q) {
        if((q-1-u) > m)
            quickSort(lista, u, q - 1);
        else insertionSort(lista, DIM_STACK);
    }
    if(q < v){
        if((q-1-u) > m)
            quickSort(lista, q+1, v);
        else insertionSort(lista, DIM_STACK);
    }
}

void mergesort(int lista[], int ordinata[], int lower, int upper){

    int medium;
    if(lower >= upper) return;
    medium = (lower + upper)/2;
    mergesort(lista, ordinata, lower, medium);
    mergesort(lista, ordinata, medium+1, upper);
    merge(lista, ordinata, lower, medium, upper);
}
void merge(int lista[], int ordinata[], int i, int m, int n){
        //i --> lower
        //m --> medium
        //n --> upper
        //j --> Indice per la seconda parte di lista
        //k --> Indice per la lista ordinata
        //pos_iniziale --> Posizione iniziale nella lista
        int j = m + 1, k = i, pos_iniziale = i;

        while(i <= m && j <= n){
            cont_confr_iter++;
            if(lista[i] <= lista[j]){
                cont_confr_iter++;
                ordinata[k] = lista[i];
                cont_scambi_iter++;
                i++,k++;
            }else{
                cont_confr_iter++;
                ordinata[k] = lista[j];
                cont_scambi_iter++;
                j++, k++;
            }
        }
        if(i > m){//ordinata[k], ..., ordinata[n] <-- lista[j], ..., lista[n]
            cont_confr_iter++;
            for(int t = j; t <= n; t++){
                ordinata[k+t-j] = lista[t];
                cont_scambi_iter++;
            }
        }
        else
            for(int t = i; t <= m; t++){
                ordinata[k+t-i] = lista[t];
                cont_scambi_iter++;
            }


        for(int l = pos_iniziale; l <= n; l++){
            lista[l] = ordinata[l];
            cont_scambi_iter++;
        }
}
void heapsort(int lista[], int n){
    //Si costruisce l'heap associato all'insieme da ordinare lista
    cont_confr_iter = 0, cont_scambi_iter = 0;

    for(int i = n/2; i > 0; i--)
        adatta(lista, i , n);
    //Si estrae di volta in volta, il massimo lista[1] e lo si posizione in fondo alla sequenza
    for(int i = n-1; i > 0; i--){
        swap(&lista[1], &lista[i+1]);
        adatta(lista, 1, i);
    }
    printf("Confronti: %d\nScambi: %d\n",cont_confr_iter,cont_scambi_iter);
}
void adatta(int lista[], int radice, int n){

    int temp = lista[radice], figlio = radice*2; //figlio sx
    while(figlio <= n){
        cont_confr_iter++;
        //trova il  maggiore tra il figlio sx e il figlio dx
        if(figlio < n && lista[figlio] < lista[figlio+1]){
            figlio = figlio+1;
            cont_confr_iter++;
            cont_scambi_iter++;
        }

        //Confronta la radice e figlio max
        if(temp > lista[figlio]){ //il padre di figlio sarà la posizione corretta
            cont_confr_iter++;
            break;
        }
        else{
            lista[figlio/2] = lista[figlio]; //il figlio si sposta verso il padre
            //ripeti sul sottoalbero selezionato
            figlio = figlio * 2;
            cont_scambi_iter++;
        }
    }
    lista[figlio/2] = temp; //Copia la radice nella posizione corretta
    cont_scambi_iter++;
}
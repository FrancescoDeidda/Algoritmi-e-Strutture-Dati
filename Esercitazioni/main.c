#include "functions.h"
                                          //INDICA IL NUMERO DELL'ESERCITAZIONE
#define ESERCIZIO 1                                                 //INDICA L'ESERCIZIO RELATIVO ALL'ESERCITAZIONE SELEZIONATA

int dimensioni[] = {500,1000,2000,5000,10000,20000, 50000};

int contBl = 0, contBR = 0; //Contatori controlli ricerca binaria iterativa e ricorsiva
int cont_confr_ric, cont_scambi_ric;
int cont_confr_iter, cont_scambi_iter;

#if ESERCITAZIONE == 1                                                                                                  ///ESERCITAZIONE 1
int main() {
    int dim, numRic; //Dimensione dei vettori quando la dimensione è richiesta dall'utente
    int *vetOrd, *vetQuaOrd, *vetInvOrd, *vetCas;

    clock_t start, end;

    srand(time(NULL));
#if ESERCITAZIONE == 1 && ESERCIZIO == 1                                                                                                      ///1_1 SELECTION SORTO VETTORI

    for(int i = 0; i <= 6; i++){ //IMPOSTARE IL LIMITE A 6 NON COMPRESO PER TESTARE FINO A 500.000
    vetOrd = generaArray(dimensioni[i], ORDINATO);
    vetQuaOrd = generaArray(dimensioni[i], QUASI_ORDINATO);
    vetInvOrd = generaArray(dimensioni[i], INV_ORDINATO);
    vetCas = generaArray(dimensioni[i], CASUALE);

    printf("\n\n\n\nVETTORI DI DIMENSIONE %d\n", dimensioni[i]);

    printf("\nOrdino il vettore ordinato\n");
    start = clock();
    selectionSort(vetOrd, dimensioni[i]);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetOrd, dimensioni[i]);

    printf("\nOrdino il vettore parzialmente ordinato\n");
    start = clock();
    selectionSort(vetQuaOrd, dimensioni[i]);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetQuaOrd, dimensioni[i]);

    printf("\nOrdino il vettore inversamente ordinato\n");
    start = clock();
    selectionSort(vetInvOrd, dimensioni[i]);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetInvOrd, dimensioni[i]);

    printf("\nOrdino il vettore casuale\n");
    start = clock();
    selectionSort(vetCas, dimensioni[i]);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetCas, dimensioni[i]);

    free(vetOrd);
    free(vetQuaOrd);
    free(vetInvOrd);
    free(vetCas);
    }
#elif ESERCITAZIONE == 1 && ESERCIZIO == 2                                                                                                    ///1_2 SELECTION SORT RICETTE (MAIN)

    printf("Quante ricette vuoi inserire?\n");
    scanf("%d", &dim);

    Ricetta ricette[dim]; //Dichiaro il vettore di ricette della dimensione scelta dall'utente

    for(int i = 0; i < dim; i++){
        printf("Inserisci il nome della ricetta:\n");
        scanf("%s", ricette[i].nome);
        getchar();
        printf("Inserisci il tempo di preparazione in minuti:\n");
        //scanf("%lf", &ricette[i].tempo);
        ricette[i].tempo = rand()%100;
        ricette[i].difficolta = 0;
        while(ricette[i].difficolta < 1 || ricette[i].difficolta > 10){
            printf("Inserisci la difficolta' di esecuzione della ricetta: (1 --> molto semplice, 10 --> Estremamente complessa)\n");
            //scanf("%d", &ricette[i].difficolta);
            ricette[i].difficolta = rand()%10;
        }
    }

    printf("\n\nSTAMPO LE RICETTE\n\n");
    for(int i = 0; i < dim; i++){
        printf("\nNome ricetta: %s\n", ricette[i].nome);
        printf("Tempo esecuzione: %.2f\n", ricette[i].tempo);
        printf("Difficolta: %d\n\n\n", ricette[i].difficolta);
    }

    selectionSortRicette(ricette, dim);

    printf("\n\nSTAMPO LE RICETTE ORDINATE\n\n");
    for(int i = 0; i < dim; i++){
        printf("\nNome ricetta: %s\n", ricette[i].nome);
        printf("Tempo esecuzione ricetta: %.2f\n", ricette[i].tempo);
        printf("Difficolta: %d\n\n\n", ricette[i].difficolta);
    }

#elif ESERCITAZIONE == 1 && ESERCIZIO == 345                                                                                                  ///1_3-4-5 RICERCHE A CONFRONTO
    ///1_3 RICERCA BANALE (MAIN)
    printf("Inserire la dimensione del vettore in cui fare la ricerca: ");
    scanf("%d", &dim);
    vetOrd = generaArray(dim, CASUALE);
    selectionSort(vetOrd,dim);

    printf("\nStampo il vettore ordinato:\n");
    stampaArray(vetOrd, dim);

    printf("\nChe numero vuoi cercare?\n");
    scanf("%d", &numRic);

    printf("Dimensione del vettore: %d", dim);

    printf("\nAvvio la ricerca banale...\n");
    start = clock();
    printf("\nTrovato in posizione: %d",ricercaBanale(vetOrd,numRic, dim));
    end = clock();
    printf("\nTempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);

    printf("\nAvvio la ricerca binaria iterativa...\n");
    start = clock();
    printf("\nTrovato in posizione: %d", ricercaBinariaIterativa(vetOrd,numRic,dim));
    end = clock();
    printf("\nControlli effettuati: %d", contBl);
    printf("\nTempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);

    printf("\nAvvio la ricerca binaria ricorsiva...\n");
    start = clock();
    printf("\nTrovato in posizione: %d", ricercaBinariaRicorsiva(vetOrd,numRic,0,dim-1));
    end = clock();
    printf("\nControlli effettuati: %d", contBR);
    printf("\nTempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);

    free(vetOrd);

#endif
    return 0;
}
#elif ESERCITAZIONE == 2                                                                                                ///ESERCITAZIONE 2
int main() {

    int dim = 0;
    int *vetOrd, *vetQuaOrd, *vetInvOrd, *vetCas;

    char nome[20];

    clock_t start, end;

    srand(time(NULL));

#if ESERCITAZIONE == 2 && ESERCIZIO == 1                                                                                ///2_1 SELECTION SORT RICORSIVO

    for(int i = 0; i < 5; i++){ //IMPOSTARE IL LIMITE A 6 NON COMPRESO PER TESTARE FINO A 500.000
    vetOrd = generaArray(dimensioni[i], ORDINATO);
    vetQuaOrd = generaArray(dimensioni[i], QUASI_ORDINATO);
    vetInvOrd = generaArray(dimensioni[i], INV_ORDINATO);
    vetCas = generaArray(dimensioni[i], CASUALE);

    printf("\n\n\n\nVETTORI DI DIMENSIONE %d\n", dimensioni[i]);

    printf("\nOrdino il vettore ordinato\n");
    start = clock();
    selectionSortRec(vetOrd, dimensioni[i],0);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetOrd, dimensioni[i]);

    printf("\nOrdino il vettore parzialmente ordinato\n");
    start = clock();
    selectionSortRec(vetQuaOrd, dimensioni[i],0);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetQuaOrd, dimensioni[i]);

    printf("\nOrdino il vettore inversamente ordinato\n");
    start = clock();
    selectionSortRec(vetInvOrd, dimensioni[i],0);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetInvOrd, dimensioni[i]);

    printf("\nOrdino il vettore casuale\n");
    start = clock();
    selectionSortRec(vetCas, dimensioni[i],0);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetCas, dimensioni[i]);

    free(vetOrd);
    free(vetQuaOrd);
    free(vetInvOrd);
    free(vetCas);
    }

#elif ESERCITAZIONE == 2 && ESERCIZIO == 2                                                                              ///2_2 ORDINAMENTI A CONFRONTO

    printf("Inserire la dimensione del vettore: ");
    scanf("%d", &dim);

    vetOrd = generaArray(dim, CASUALE); //Definisco due vettori da ordinare con Selection Sort Iterativo
    vetCas = generaArray(dim, CASUALE); //Definisco due vettori da ordinare con Selection Sort Ricorsivo

    printf("\nVettori da %d elementi\n", dim);

    printf("\nSelection Sort iterativo\n");
    start = clock();
    selectionSort(vetOrd,dim);
    end = clock();
    printf("Tempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetOrd,dim);

    printf("\nSelection Sort ricorsivo\n");
    start = clock();
    selectionSortRec(vetCas, dim,0);
    end = clock();
    printf("\nConfronti effettuati: %d\nScambi effettuati: %d", cont_confr_ric, cont_scambi_ric);
    printf("\nTempo di esecuzione: %lf\n",((double)end - start)/CLOCKS_PER_SEC);
    //stampaArray(vetCas,dim);

    free(vetOrd);
    free(vetQuaOrd);
    free(vetInvOrd);
    free(vetCas);

#elif ESERCITAZIONE == 2 && ESERCIZIO == 3                                                                              ///2_3 RICERCA BINARIA ITERATIVA HOTEL

    printf("Quante hotel vuoi inserire?\n");
    scanf("%d", &dim);

    Hotel hotels[dim]; //Dichiaro il vettore di ricette della dimensione scelta dall'utente

    for(int i = 0; i < dim; i++){
        printf("Inserisci il nome dell'hotel:\n");
        scanf("%s", hotels[i].nome);
        getchar();
        //printf("Inserisci il prezzo di pernotamento:\n");
        //scanf("%lf", &hotels[i].prezzo_notte);
        hotels[i].prezzo_notte = rand()%100;
        hotels[i].recensione = rand()%5;
    }

    printf("\n\nSTAMPO GLI HOTEL\n\n");
    for(int i = 0; i < dim; i++){
        printf("\nNome hotel: %s\n", hotels[i].nome);
        printf("Prezzo per notte: %.2f\n", hotels[i].prezzo_notte);
        printf("Recensione: %d\n\n\n", hotels[i].recensione);
    }

    selectionSortHotels(hotels, dim); //Ricerca binaria per gli hotel, da creare modificando quella normale (iterativa)

    printf("\n\nStampo gli hotel ordinati\n\n");
    for(int i = 0; i < dim; i++){
        printf("\nNome hotel: %s\n", hotels[i].nome);
        printf("Prezzo per notte: %.2f\n", hotels[i].prezzo_notte);
        printf("Recensione: %d\n\n\n", hotels[i].recensione);
    }

    printf("Che hotel vuoi cercare ? Inserisci il nome\n");
    scanf("%s", &nome);

    printf("Hai inserito %s", nome);

    printf("\nTrovato in posizione: %d", ricercaBinariaIterativaHotel(hotels,nome,dim));

#endif
    return 0;
}
#elif ESERCITAZIONE == 3                                                                                                ///ESERCITAZIONE 3
    int main() {

        int elementoDaCercare;

        printf("----------------- ESERCITAZIONE 3 -----------------\n");

#if ESERCITAZIONE == 3

        MatriceSparsa *matrice;
        MatriceSparsa *matriceTrasposta;

        matrice = (MatriceSparsa *) malloc(sizeof(MatriceSparsa));
        matriceTrasposta = (MatriceSparsa *) malloc(sizeof(MatriceSparsa));

        printf("Quanti elementi vuoi inserire nella matrice?\n");
        scanf("%d", &matrice[0].valore);
        matrice[0].riga = RIGHE_MATRICE;
        matrice[0].colonna = COLONNE_MATRICE;
        matriceTrasposta[0].riga = COLONNE_MATRICE;
        matriceTrasposta[0].colonna = RIGHE_MATRICE;

        matrice = (MatriceSparsa *) realloc(matrice, (matrice[0].valore+1) * sizeof(MatriceSparsa));
        matriceTrasposta = (MatriceSparsa *) realloc(matriceTrasposta, (matrice[0].valore+1) * sizeof(MatriceSparsa));

        matrice = nuovaMatriceSparsa(matrice[0].valore, matrice);
        stampaMatriceSparsa(matrice);

        printf("Che elemento vuoi cercare?\n");
        scanf("%d", &elementoDaCercare);
        printf("Trovato in posizione: %d\n", ricercaMatriceSparsaIterativa(matrice,elementoDaCercare,matrice[0].valore));

        printf("Stampo la matrice sparsa\n");
        for(int i = 1; i <= matrice[0].valore; i++){
            printf("%d ", matrice[i].valore);
        }

        printf("\nEseguo la trasposizione\n");
        trasp_rapida(matrice, matriceTrasposta);

        printf("\nStampo la matrice trasposta\n");
        stampaMatriceSparsa(matriceTrasposta);

        free(matrice);
        free(matriceTrasposta);
#endif
    return 0;
}
#elif ESERCITAZIONE == 4                                                                                                ///ESERCITAZIONE 4
int main() {

    char stringa1[] = {'a','b','a','b','a','b','c','c','d','e','a', '\0'};
    char stringa2[] = {'b','c','e','b','c','a','b','c','a','b','a', '\0'};
    char pat[] = {'a','b','a','b','c','\0'};

    printf("Trovato match normale in posizione: %d\n", KMP_match(stringa1, pat));
    printf("Trovato match ciclico in posizione: %d\n", KMP_matchCiclico(stringa2, pat));

    return 0;
}

#elif ESERCITAZIONE == 5                                                                                                ///ESERCITAZIONE 5
int main() {

    int scelta=1;
    Ordine ordine;

    //dichiarazione e inizializzazione della Coda
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;

    //dichiarazione e inizializzazione dello Stack
    Stack stack;
    stack.top = NULL;
    stack.cont = 0;

    //istruzioni e chiamate per i test...

    while (scelta != 0){
        printf("Cosa vuoi fare?\n1) Inserire un nuovo ordine in coda\n2) Togliere un ordine dalla coda per processarlo\n"
               "3) Inserire un nuovo ordine nello stack per il trasporto\n4) Togliere un ordine dallo stack per consegnarlo\n"
               "5) Processare il primo ordine in coda e automaticamente prepararlo per la consegna\n"
               "6) Stampare lo stato della coda degli ordini\n7) Stampare lo stato dello stack delle consegne\n"
               "0) Esci\n");
        scanf("%d", &scelta);

        switch(scelta){

            case 1:
                printf("Inserisci il nome dell'articolo:\n");
                scanf("%s", ordine.articolo);
                printf("Inserisci il prezzo dell'articolo:\n");
                scanf("%lf", &ordine.prezzo);
                printf("Inserisci il destinatario dell'articolo:\n");
                scanf("%s", ordine.destinatario);
                pushQueue(&queue, ordine);
                break;
            case 2:
                popQueue(&queue);
                break;
            case 3:
                printf("Inserisci il nome dell'articolo:\n");
                scanf("%s", &ordine.articolo);
                printf("Inserisci il prezzo dell'articolo:\n");
                scanf("%f", &ordine.prezzo);
                printf("Inserisci il destinatario dell'articolo:\n");
                scanf("%s", &ordine.destinatario);
                pushStack(&stack, ordine);
                break;
            case 4:
                popStack(&stack);
                break;
            case 5:
                pushStack(&stack, popQueue(&queue));
                break;
            case 6:
                printf("Stampo lo stato della coda degli ordini:\n");
                printQueue(&queue);
                break;
            case 7:
                printf("Stampo lo stato dello stack delle consegne:\n");
                printStack(&stack);
                break;
            default:
                break;
        }
    }
    return 0;
}

#elif ESERCITAZIONE == 6                                                                                                ///ESERCITAZIONE 6
int main()
{
    char canzone[50];

    //Creazione di una PLAYLIST. Utilizzare e riempire questa playlist
    PlayList p,q, *mergedPlaylist;
    strcpy(p.name, "My favourite songs");
    p.top = NULL;

    //altre chiamate e istruzioni per testare il funzionamento delle funzioni create
    //...
    printf("Inserisci gli elementi nella prima playlist:\n");

    insertSong(&p,acquireSong());
    insertSong(&p,acquireSong());
    insertSong(&p,acquireSong());

    printf("\nStampo la playlist 1:\n");
    printPlaylist(&p);

    /*printf("Che canzone vuoi cancellare?\n");
    scanf("%s", canzone);
    deleteSong(&p, findSong(&p, canzone));

    printf("\nStampo la playlist:\n");
    printPlaylist(&p);

    printf("Che canzone vuoi modificare?\n");
    scanf("%s", canzone);
    modifySong(&p, findSong(&p, canzone));

    printf("\nStampo la playlist:\n");
    printPlaylist(&p);

    printf("Che canzone vuoi cercare?\n");
    scanf("%s", canzone);
    printSong(findSong(&p, canzone));

    printf("Inserisci il brano di cui vuoi il successivo\n");
    scanf("%s", canzone);
    printf("\nIl prossimo brano e': ");
    printSong(nextSong(findSong(&p, canzone)));

    printf("Inserisci il brano di cui vuoi il precedente\n");
    scanf("%s", canzone);
    printf("\nIl prossimo brano e': \n");
    printSong(prevSong(findSong(&p, canzone)));*/

    printf("Inserisci gli elementi nella seconda playlist:\n");

    insertSong(&q,acquireSong());
    insertSong(&q,acquireSong());
    insertSong(&q,acquireSong());

    printf("\nStampo la playlist 2:\n");
    printPlaylist(&q);

    mergedPlaylist = (PlayList*)malloc(sizeof(PlayList));

    mergePlayList(&p,&q,mergedPlaylist);

    printf("\nStampo la playlist dopo il merge:\n");
    printPlaylist(mergedPlaylist);

    return 0;
}

#elif ESERCITAZIONE == 7
int main() {
    //inizializzazione pronto soccorso
    ProntoSoccorso ps;
    ps.numeroB = ps.numeroG = ps.numeroV = ps.numeroR = 0;

    //inizializzazione della Coda con priorita'
    Paziente codaPrio[DIM_HEAP];
    int dim_coda = 0;

    //IMPLEMENTARE IL MAIN

    insertHeap(codaPrio, nuovoPaziente(&ps), &dim_coda);
    insertHeap(codaPrio, nuovoPaziente(&ps), &dim_coda);
    printHeap(codaPrio, &dim_coda);
    deleteHeap(codaPrio, &dim_coda);
    printHeap(codaPrio, &dim_coda);



    return 0;
}

#elif ESERCITAZIONE == 8
int main() {
    Nodo *root = NULL; // Radice dell'ABR

    //variabili ausiliarie
    int scelta;
    Birra tmp_birra;
    Nodo* tmp_nodo;
    int prof;
    char tmp_nome[DIM_NOME];


    do
    {
        //Menu con le operazioni disponibili
        printf("\nMENU:\n");
        printf("1) inserisci nuova birra \n");
        printf("2) visita INORDER \n");
        printf("3) visita PREORDER \n");
        printf("4) visita POSTORDER \n");
        printf("5) calcolo profondita \n");
        printf("6) ricerca di una birra \n");
        printf("7) ricerca del minimo \n");
        printf("8) ricerca del massimo \n");
        printf("9) ricerca del precedente di una birra \n");
        printf("10) ricerca del successore di una birra \n");
        printf("11) cancellazione di una birra \n");
        printf("12) carica birre di test (in un ABR vuoto)\n");
        printf("13) esci \n");

        printf("scelta: ");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1:
                tmp_birra = acquisisci_birra();
                tmp_nodo = crea_nodo(tmp_birra);
                root = insert_nodo(root, tmp_nodo);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                prof = profondita(root);
                printf("\nProfondita: %d\n", prof);
                break;

            case 6:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                    printf("\nTrovata birra %s\n", tmp_nodo->key.nome);
                else
                    printf("\nBirra %s non trovata\n", tmp_nome);
                break;

            case 7:
                tmp_nodo = abr_min(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 8:
                tmp_nodo = abr_max(root);
                printf("Il minimo e': %s\n", tmp_nodo->key.nome);
                break;

            case 9:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_pred(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl precedente e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un precedente\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 10:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    tmp_nodo = abr_succ(tmp_nodo);
                    if(tmp_nodo != NULL)
                        printf("\nIl successore e': %s\n", tmp_nodo->key.nome);
                    else
                        printf("\nNon esiste un successore\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;

            case 11:
                printf("\nBirra da cercare: ");
                getchar();
                scanf("%[^\n]s", tmp_nome);
                tmp_nodo = ricerca(root, tmp_nome);

                if(tmp_nodo != NULL)
                {
                    root = delete_node(root, tmp_nodo);
                    printf("\nNodo eliminato\n");
                }

                else
                    printf("\nBirra non trovata\n");
                break;


            case 12:
                root = carica_test();
                break;

            case 13:
                printf("\nCiao!\n");
                break;

            default:
                printf("\nScelta non valida\n");

        }

    } while(scelta != 13);


    return 0;
}

#elif ESERCITAZIONE == 9
int main() {
    Citta grafo[MAX_VERTICI];
    int num_nodi;
    int *visited = (int*)calloc(NUM_NODI_TEST, sizeof(int));
    int scelta = 90;

    carica_citta_test(grafo,&num_nodi);
    //carica_grafo_test_non_orientato(grafo, &num_nodi);
    carica_grafo_test_orientato(grafo, &num_nodi);

    do{
        printf("\n\nChe cosa vuoi fare?\n"
               "0)  Esci\n"
               "1)  Aggiungi un nodo\n"
               "2)  Creare un arco tra due nodi\n"
               "3)  Stampa lista di adiacenze\n"
               "4)  Visita in profondita'\n"
               "5)  Visita in ampiezza\n"
               "6)  Cancella arco orientato\n"
               "7)  Cancella arco non orientato\n"
               "8)  Stampa la componenti connesse\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                printf("Aggiunta di un nodo\n");
                aggiungi_nodo(grafo, &num_nodi);
                break;
            case 2:
                printf("Inserisci i due nodi tra i quali creare il collegamento, nodi totali: %d\nPremi invio dopo ogni valore", num_nodi);
                crea_arco_non_orientato(grafo, scanf("%d"), scanf("%d"),num_nodi);
                break;
            case 3:
                printf("Stampo la lista di adiacenze\n");
                stampa_lista_adiacenze(grafo,num_nodi);
                break;
            case 4:
                printf("Visita in profondita':\n");
                DFS(grafo,visited,0);
                break;
            case 5:
                printf("Visita in ampiezza\n");
                BFS(grafo,visited,0,num_nodi);
                break;
            case 6:
                printf("Inserisci i due nodi tra i quali cancellare il collegamento, nodi totali: %d\nPremi invio dopo ogni valore", num_nodi);
                cancella_arco_orientato(grafo, scanf("%d"), scanf("%d"),num_nodi);
                break;
            case 7:
                printf("Inserisci i due nodi tra i quali cancellare il collegamento, nodi totali: %d\nPremi invio dopo ogni valore", num_nodi);
                cancella_arco_non_orientato(grafo, scanf("%d"), scanf("%d"),num_nodi);
                break;
            case 8:
                printf("Stampo le componenti connesse:\n");
                componenti_connesse(grafo, visited, num_nodi);
                break;
            default:
                printf("Errore, valore non valido\n");
                break;
        }
    }while(scelta != 0);

    free(visited);

    printf("\nFINE");
}

#elif ESERCITAZIONE == 10
int main() {
    Nodo* parcheggio[NUM_PIANI];
    int i = 0, scelta = 9, piano = 0;
    char targa[DIM_NOME];

    for(i = 0; i < NUM_PIANI; i++)
        parcheggio[i] = NULL;

    //inserire qui le funzioni per i test

    printf("\nPARCHEGGIO AUTOMATIZZATO\n");

    while(scelta != 0){

        printf("Cosa vuoi fare?\n 1) Inserisci un auto\n 2) Stampa piano\n "
               "3) Stampa parcheggio\n 4) Ricerca auto\n 5) Elimina auto\n"
               " 6) Carica le auto test\n 0) Esci\n");
        scanf("%d", &scelta);

        switch (scelta){
            case 0:
                printf("\nESCO\n");
                break;
            case 1:
                printf("\nInserimento auto\n");
                inserisci_auto(parcheggio, acquisisci_auto());
                break;
            case 2:
                printf("\nStampo il piano\n Inserisci il numero del piano\n");
                scanf("%d", &piano);
                stampa_piano(parcheggio, piano);
                break;
            case 3:
                printf("\nStampo il parcheggio\n");
                stampa_parcheggio(parcheggio);
                break;
            case 4:
                printf("\nRicerca auto\n Inserisci la targa:\n");
                scanf("%s", targa);
                printf("Le informazioni dell'auto targata %s sono:\n Targa: %s \n"
                       " Ora di arrivo: %d\n Minuti di arrivo: %d\n",
                       ricerca_auto(parcheggio, targa)->info.targa,
                       ricerca_auto(parcheggio, targa)->info.targa,
                       ricerca_auto(parcheggio, targa)->info.ora,
                       ricerca_auto(parcheggio, targa)->info.min);
                break;
            case 5:
                printf("\nElimino l'auto\n Inserisci la targa\n");
                scanf("%s", targa);
                elimina_auto(parcheggio, targa);
                break;
            case 6:
                printf("Carico le auto test...");
                carica_auto_test(parcheggio);
                break;
            default:
                printf("\nVALORE NON VALIDO\n");
                break;
        }
    }
    return 0;
}

#elif ESERCITAZIONE == 11
int main() {

    int *lista1, *lista2, *lista3; //Lista di 50 elementi da generare casualmente

    srand(time(NULL));

    lista1 = generaArray(DIM_STACK, CASUALE); //Genero dinamicamente il vettore di numeri casuali
    lista2 = generaArray(DIM_STACK, CASUALE); //Genero dinamicamente il vettore di numeri casuali
    lista3 = generaArray(DIM_STACK, CASUALE); //Genero dinamicamente il vettore di numeri casuali

    printf("Stampo la prima lista casuale:\n");
    stampaArray(lista1, DIM_STACK);
    printf("\nStampo la seconda lista casuale:\n");
    stampaArray(lista2, DIM_STACK);
    printf("\nStampo la terza lista casuale:\n");
    stampaArray(lista3, DIM_STACK);

    printf("\nStampo la prima lista ordinata (insertionSort):\n");
    insertionSort(lista1, DIM_STACK); //Ordino la prima lista con l'insertion
    stampaArray(lista1, DIM_STACK);
    printf("\nStampo la seconda lista ordinata (quickSort):\n");
    quickSort(lista2, 0, DIM_STACK-1);
    stampaArray(lista2, DIM_STACK);
    printf("\nStampo la terza lista ordinata (quickInsertionSort):\n");
    quickInsertionSort(lista3, 0, DIM_STACK-1);
    stampaArray(lista3, DIM_STACK);

    printf("\nFINE\n");

    return 0;
}

#elif ESERCITAZIONE == 12
int main() {

    int *vet1, *vetSelection, *vetInsertion, *vetQuickSort, *vetHeapSort, *vetMergeSort;
    int *lista1, *listaOrdinata; //Lista di 50 elementi da generare casualmente
    int dim, schema;
    int lista2[DIM_STACK+1];
    clock_t start, end;

    lista2[0] = -1;

    srand(time(NULL));

    //Carico il vettore per l'heap partendo dalla cella in posizione 0
    for(int i = 1; i < DIM_STACK+1; i++){
        lista2[i] = rand()%100;
    }

    printf("Di che dimensione vuoi creare gli array?\n"
           " 0: 500 \n 1: 1000 \n 2: 2000 \n 3: 5000 \n 4: 10000 \n 5: 20000 \n 6: 50000\n--> ");
    scanf("%d", &dim);
    printf("Con quale schema vuoi generare gli array?\n"
           " 0: Ordinato \n 1: Parzialmente ordinato \n 2: Inversamente ordinato \n 3: Casuale\n-->");
    scanf("%d", &schema);


        switch(dim) {
            case 0:
                dim = 500;
                break;
            case 1:
                dim = 1000;
                break;
            case 2:
                dim = 2000;
                break;
            case 3:
                dim = 5000;
                break;
            case 4:
                dim = 10000;
                break;
            case 5:
                dim = 20000;
                break;
            case 6:
                dim = 50000;
                break;
            default:
                printf("Valore non valido. Dimensione di default: 500");
                dim = 500;
                break;
        } //Determina la dimensione degli array a partire dalla scelta dell'utente

        vet1 = generaArray(dim, schema);
        vetSelection = calloc(dim, sizeof(int*));
        vetInsertion = calloc(dim, sizeof(int*));
        vetQuickSort = calloc(dim, sizeof(int*));
        vetHeapSort = calloc(dim+1, sizeof(int*));
        vetMergeSort = calloc(dim, sizeof(int*));

        for(int i = 0; i < dim; i++){
            vetSelection[i] = vetInsertion[i] = vetQuickSort[i] = vetMergeSort[i] = vet1[i];
        }
        for(int i = 0, j = 1; i < dim; i++, j++){
            vetHeapSort[j] = vet1[i]; //Per l'Heap Sort ho bisogno di copiarlo diversamente in quanto ha le celle sfalzate di una
        }

        free(vet1);

        listaOrdinata = calloc(dim, sizeof(int*)); //Lista utilizzata dall'Heap Sort

        printf("\nDimensione vettori: %d\n", dim);
        printf("Schema vettori: %d\n", schema);

        printf("\nSelection Sort ----------------------------------------------------------------\n");
        start = clock();
        selectionSort(vetSelection, dim);
        end = clock();
        free(vetSelection);
        printf("Tempo: %lf\n", ((double)end - start)/CLOCKS_PER_SEC);

        printf("\nInsertion Sort ----------------------------------------------------------------\n");
        start = clock();
        insertionSort(vetInsertion, dim);
        end = clock();
        free(vetInsertion);
        printf("Tempo: %lf\n", ((double)end - start)/CLOCKS_PER_SEC);

        printf("\nMerge Sort ----------------------------------------------------------------\n");
        cont_confr_iter = 0, cont_scambi_iter =0;
        start = clock();
        mergesort(vetMergeSort, listaOrdinata,0, dim-1);
        end = clock();
        free(vetMergeSort);
        free(listaOrdinata);
        printf("Confronti: %d\nScambi: %d\n",cont_confr_iter,cont_scambi_iter);
        printf("Tempo: %lf\n", ((double)end - start)/CLOCKS_PER_SEC);

        printf("\nHeap Sort ----------------------------------------------------------------\n");
        start = clock();
        heapsort(vetHeapSort, dim);
        end = clock();
        free(vetHeapSort);
        printf("Tempo: %lf\n", ((double)end - start)/CLOCKS_PER_SEC);

        printf("\nQuick Sort ----------------------------------------------------------------\n");
        cont_confr_iter = 0, cont_scambi_iter =0;
        start = clock();
        quickSort(vetQuickSort, 0, dim-1);
        end = clock();
        free(vetQuickSort);
        printf("Confronti: %d\nScambi: %d\n",cont_confr_iter,cont_scambi_iter);
        printf("Tempo: %lf\n", ((double)end - start)/CLOCKS_PER_SEC);



    /*if(dim < 50000){
        stampaArray(vetSelection,dim);
        stampaArray(vetInsertion,dim);
        stampaArray(vetHeapSort,dim+1); //Nell'Heap Sort abbiamo bisogno di una cella in più (la prima non è utilizzata)
        stampaArray(vetQuickSort,dim);
        stampaArray(vetMergeSort,dim);
    }*/


    printf("\nSTOP\n");

/*
    printf("Stampo la prima lista casuale:\n");
    stampaArray(lista1, DIM_STACK);
    printf("\nStampo la seconda lista casuale:\n");
    for(int i = 1; i < DIM_STACK+1; i++)
        printf("%d ", lista2[i]);*/
/*
    printf("\nStampo la prima lista ordinata (mergesort):\n");
    mergesort(lista1, listaOrdinata, 0, DIM_STACK-1);
    stampaArray(lista1, DIM_STACK);
    printf("\nStampo la seconda lista ordinata (heapsort):\n");
    heapsort(lista2, DIM_STACK+1);
    for(int i = 1; i < DIM_STACK+1; i++)
        printf("%d ", lista2[i]);*/

    return 0;
}

#endif
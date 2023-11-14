//
// Created by deidd on 08/03/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#ifndef ESERCITAZIONI_FUNCTIONS_H
#define ESERCITAZIONI_FUNCTIONS_H

#endif //ESERCITAZIONI_FUNCTIONS_H

extern int contBl, contBR; //Contatori controlli ricerca binaria iterativa e ricorsiva
extern int cont_confr_ric, cont_scambi_ric;
extern int cont_confr_iter, cont_scambi_iter;

typedef enum{ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;

///Macro che gestisce la compilazione automatica delle esercitazioni
#define ESERCITAZIONE 12

#define DIM_NOME 50
#define RIGHE_MATRICE 5
#define COLONNE_MATRICE 5
#define MAX_SIZE 10

#define DIM_CODA 10 // modificare a piacimento
#define DIM_STACK 10 // modificare a piacimento
#define DIM_STRING 50

//Esercitazione 6 Spotify Version
#define DIM_TITLE 50
#define DIM_GENRE 50
#define DIM_NAME 50

//Esercitazione 7
#define DIM_HEAP 50

//ESERCITAZIONE 8
#define NUM_TEST 15

//ESERCITAZIONE 9
#define MAX_VERTICI 20
#define DIM 50
#define NUM_NODI_TEST 11

//ESERCITAZIONE 10
#define MAX_TARGA 10
#define NUM_PIANI 7

typedef struct{
    char nome[DIM_NOME];
    double tempo;
    int difficolta;
}Ricetta;
typedef struct{
    char nome[DIM_NOME];
    double prezzo_notte;
    int recensione;
}Hotel;
typedef struct{
    int riga;
    int colonna;
    int valore;
}MatriceSparsa;

///ESERCITAZIONE 5

typedef struct
{
    char articolo[DIM_STRING];
    double prezzo;
    char destinatario[DIM_STRING];
}Ordine;
struct node
{
    Ordine data;
    struct node* link;
};
typedef struct node Node;
typedef struct
{
    Node* front;
    Node* back;
    int cont;
}Queue;
typedef struct
{
    Node* top;
    int cont;
}Stack;


///ESERCITAZIONE 6

//struttura che rappresenta una CANZONE
struct song
{
    char title[DIM_TITLE];
    char genre[DIM_GENRE];
    float length;
    struct song* prev;
    struct song* next;
};
typedef struct song Song;
//struttura che rappresenta una PLAYLIST
struct playlist
{
    char name[DIM_NAME];
    Song* top;
};
typedef struct playlist PlayList;

//ESERCITAZIONE 7


///ESERCITAZIONE 7

//stuttura che rappresenta un Pronto soccorso
typedef struct
{
    int numeroB;
    int numeroG;
    int numeroV;
    int numeroR;
} ProntoSoccorso;
//enumerazione che rappresenta i codici del pronto soccorso
typedef enum {BIANCO, VERDE, GIALLO, ROSSO} Codice;
//struttura che rappresenta un Paziente
typedef struct
{
    char nome[DIM_NOME];
    Codice codice;
    int ordine;
}Paziente;


///ESERCITAZIONE 8

typedef struct
{
    char nome[DIM_NOME];
    float gradi;
    int bottiglie;
} Birra;

typedef struct nodo
{
    Birra key;
    struct nodo *parent;
    struct nodo *left;
    struct nodo *right;
}Nodo;


///ESERCITAZIONE 9

typedef struct gnode{
    int vertex_id;
    struct gnode* link;
}GNode;

typedef struct {
    char nome[DIM_NOME];
    int  abitanti;
    char nazione[DIM_NOME];
    GNode* lista_adj;
} Citta;

typedef struct {
    GNode* front;
    GNode* back;
    int cont;
}GQueue;


typedef struct
{
    char targa[MAX_TARGA];
    int ora;
    int min;
}Auto;

typedef struct nodo2
{
    Auto info;
    struct nodo *link;
}Nodo2;

int* generaArray(int dimensione, inputType tipo_schema);
void stampaArray(int *vet, int dimensione);

void swap(int *n1, int *n2);
void selectionSort(int *vet, int dimensione);
void selectionSortRicette(Ricetta *vet, int dimensione);
void swapRicette(Ricetta *r1, Ricetta *r2);
int compare(Ricetta *r1, Ricetta *r2);
int ricercaBanale(int *vet, int numRicercato, int dimensione);
int ricercaBinariaIterativa(int *vet, int numRic, int dimensione);
int ricercaBinariaRicorsiva(int *vet, int numric, int primo, int ultimo);
void selectionSortRec(int *vet, int dim, int start);
int findmin(int *vete, int minpos, int start, int dim);
void selectionSortHotels(Hotel *hotels, int dimensione);
void swapHotel(Hotel *r1, Hotel *r2);
int ricercaBinariaIterativaHotel(Hotel *vet, char* nome, int dimensione);
MatriceSparsa *nuovaMatriceSparsa(int dimensione, MatriceSparsa *matrice);
void swapElementoMatrice(MatriceSparsa *e1, MatriceSparsa *e2);
void stampaMatriceSparsa(MatriceSparsa *mat);
int ricercaMatriceSparsaIterativa(MatriceSparsa *mat, int numRic, int dimensione);
void trasp_rapida(MatriceSparsa *matrice1, MatriceSparsa *matrice2);
int* insuccesso(char pat[]);
int KMP_match(char *stringa, char *pat);
int KMP_matchCiclico(char *stringa, char *pat);

bool isEmptyQueue(Queue *queue);
bool isFullQueue(Queue *queue);
void pushQueue(Queue* queue, Ordine val);
Ordine popQueue(Queue* queue);
void printQueue(Queue *queue);
bool isEmptyStack(Stack* stack);
bool isFullStack(Stack* stack);
void pushStack(Stack *stack, Ordine val);
Ordine popStack(Stack *stack);
void printStack(Stack *stack);

//funzioni (gia' definite) per l'acquisizione e per la stampa di una canzone
Song* acquireSong(); //acquisisce i dati di UNA canzone chiedendoli all'utente
void insertSong(PlayList *pl, Song* s); //Inserisce una canzone (creata con la funzione acquire) nella lista in maniera ordinata
Song* findSong(PlayList *pl, char title[]); //Cerca una canzone nella lista (tramite il titolo) e restituisce il suo puntatore
void deleteSong(PlayList* pl, Song* s); //elimina una canzone già presente (trovata la tramite la funzione findSong) e dealloca l'elemento
void modifySong(PlayList* pl, Song* s); //modifica una canzone già presente (trovata tramite la funzione findSong) e la riposizione nella posizione corretta
void printPlaylist(PlayList* pl); //Stampa l'intera playlist di canzoni
void printSong(Song* s); //stampa i dati relativi ad UNA canzone (passata tramite puntatore)
Song* nextSong(Song* s); //Restituisce il puntatore alla canzone successiva rispetto a quella passata come puntatore se presente, altrimenti restituisce NULL
Song* prevSong(Song* s); //Restituisce il puntatore alla canzone precedente rispetto a quella passata come puntatore se presente, altrimenti restituisce NULL
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC); //fone le lista plA e plB in un'unica lista plC (anch'essa passata come parametro). NESSUN nuovo nodo deve essere allocato

/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps);
int priorita(Paziente p1, Paziente p2);
void insertHeap(Paziente heap[DIM_HEAP], Paziente item, int *n);
Paziente deleteHeap(Paziente heap[DIM_HEAP], int *n);
void printHeap(Paziente heap[DIM_HEAP], int *n);

///ESERCITAZIONE 8
/* -------------------------------
 Funzioni gia' implementate:
 ------------------------------- */
Birra acquisisci_birra();
void stampa_birra(Birra b);

Nodo* crea_nodo(Birra b);
Nodo* carica_test();
/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node);
void inorder(Nodo* root);
void preorder(Nodo* root);
void postorder(Nodo* root);
int profondita(Nodo* root);
int max(int v1, int v2);
Nodo* ricerca(Nodo* root, char* nome_birra);
Nodo* abr_min(Nodo* root);
Nodo* abr_max(Nodo* root);
Nodo* abr_succ(Nodo* x);
Nodo* abr_pred(Nodo* x);
Nodo* delete_node(Nodo* root, Nodo* nodo);

///ESERCITAZONE 9

/* ==============================
 * Funzioni gia' implementate
 * ============================== */
void carica_citta_test(Citta grafo[], int * num_nodi);
void carica_grafo_test_orientato(Citta grafo[], int * num_nodi);
void carica_grafo_test_non_orientato(Citta grafo [], int * num_nodi);
void aggiungi_nodo(Citta grafo[], int *num_nodi);
void crea_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void crea_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void stampa_lista_adiacenze(Citta grafo[], int num_nodi);
void stampa_citta(Citta grafo[], int id);
void DFS(Citta grafo[], int visited[], int start_id);
void BFS(Citta grafo[], int visited[], int start_id, int num_nodi);
void freeVisited(int * visited, int num_nodi);
//Funzione che gestione la coda (modificate per la nuova struttura Node)
bool isEmptyGQueue(GQueue * queue);
bool isFullGQueue(GQueue * queue);
void pushGQueue(GQueue * queue, Citta * city);
int popGQueue(GQueue * queue);
bool cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void componenti_connesse(Citta grafo[], int visited[], int num_nodi);

int hash_function(char targa[]);
Auto acquisisci_auto();
void inserisci_auto(Nodo2 *parcheggio[], Auto a);
void carica_auto_test(Nodo* parcheggio[]);
void stampa_piano(Nodo* parcheggio[], int piano);
void stampa_parcheggio(Nodo* parcheggio[]);
Nodo2* ricerca_auto(Nodo2 *parcheggio[], char targa[]);
void elimina_auto(Nodo2 *parcheggio[], char targa[]);

void insertionSort(int lista[], int dim);
void quickSort(int lista[], int u, int v);
int perno(int lista[], int primo, int ultimo);
void quickInsertionSort(int lista[], int u, int v);

void mergesort(int lista[], int ordinata[], int lower, int upper);
void merge(int lista[], int ordinata[], int i, int m, int n);
void heapsort(int lista[], int n);
void adatta(int lista[], int radice, int n);


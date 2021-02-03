#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Tdato{
  int numero;
  //metodi
  Tdato(){
    numero = 0;
  }
  Tdato(int x){
    numero = x;
  }
  ~Tdato(){
    //
  }
  void stampa() const{
    cout << numero;
  }
} Tdato;

typedef struct Tnodo{
  Tdato dato;
  Tnodo* next;
  Tnodo(){
    dato = Tdato();
    next = NULL;
  }
  Tnodo(Tdato _dato, Tnodo* _next){
    dato = _dato;
    next = _next;
  }
  ~Tnodo(){
    //
  }
  void stampa() const{
    dato.stampa();
  }
}Tnodo;

typedef struct TipoCoda {
  Tnodo* head;
  Tnodo* tail;

  TipoCoda(){
    head=NULL; 
    tail=NULL;
  }
  //metodi alternativi alle funzioni//
  void put(Tdato d){
    Tnodo* n = new Tnodo(d, head);
    head = n;
  }
  Tdato get(){
    Tnodo* q = head;
    if(q->next==NULL){
      Tdato d = q->dato;
      delete q;
      head = NULL;
      return d;
    }
    while(q->next->next!=NULL){
      q = q->next;
    }
    Tdato d = q->next->dato;
    delete q->next;
    q->next=NULL;
    return d;
  }
  void print ()const{
    Tnodo* q = head;
    while(q != NULL){
      q->dato.stampa();
      q = q->next;
    }
  } 
} TipoCoda;



Tnodo* insertFirst(Tnodo* s, Tdato d);
Tnodo* removeFirst(Tnodo* s);
Tnodo* insertLast(Tnodo* s, Tdato d);
Tnodo* removeLast(Tnodo* s);
Tnodo* insertOrder(Tnodo* s, Tdato d);
Tnodo* removeSearch(Tnodo* s, Tdato d);
void stampa(Tnodo* s);

//coda head-tail
void put(TipoCoda* p, Tdato d);
Tdato read(TipoCoda* p);
Tdato get(TipoCoda* p);


int main() {
  Tnodo* lista = NULL;
  lista = insertFirst(lista, Tdato(1));
  lista = insertFirst(lista, Tdato(2));
  lista = insertFirst(lista, Tdato(3));
  stampa(lista);
  lista = removeFirst(lista);
  stampa(lista);
  lista = insertLast(lista, Tdato(4));
  stampa(lista);
  lista = removeLast(lista);
  stampa(lista);
  lista = insertFirst(lista, Tdato(8));
  stampa(lista);
  lista = insertOrder(lista, Tdato(6));
  stampa(lista);
  lista = removeSearch(lista, Tdato(6));
  stampa(lista);
}

Tnodo* insertFirst(Tnodo* s, Tdato d){
  Tnodo* q = new Tnodo();
  q->dato = d;
  q->next = s;
  return q;
}

Tnodo* removeFirst(Tnodo* s){
  if(s == NULL){
    return NULL;
  }
  Tnodo* q = s;
  s = s->next;
  delete q;
  return s;
}

void stampa(Tnodo* s){
  Tnodo* p = s;
  while(p != NULL){
    p->stampa();
    cout << endl;
    p = p->next;
  }
  cout << endl;
}

Tnodo* insertLast(Tnodo* s, Tdato d){
  Tnodo* q = new Tnodo();
  q->dato = d;
  if(s == NULL){
    return q;
  }
  Tnodo* p = s;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = q;
  return s;
}

Tnodo* removeLast(Tnodo* s){
  if(s == NULL){
    return NULL;
  }
  if(s->next == NULL){
    delete s;
    return NULL;
  }
  Tnodo* p = s;
  while(p->next->next != NULL){
    p = p->next;
  }
  delete p->next;
  p->next = NULL;
  return s;
}

Tnodo* insertOrder(Tnodo* s, Tdato d){
  if(s == NULL){
    Tnodo* q = new Tnodo();
    return q;
  }
  if(s->dato.numero < d.numero){ //condizione
    return insertFirst(s, d);
  }
  Tnodo* p = s;
  while(p->next != NULL && p->next->dato.numero > d.numero){
    p = p->next;
  }
  Tnodo* q = new Tnodo(d, p->next);
  p->next = q;
  return s;
}

Tnodo* removeSearch(Tnodo* s, Tdato d){
  if (s != NULL) {
    Tnodo* q = s;
    if (q->dato.numero == d.numero) { //condizione
      s = s->next;
    delete q; 
    return s;
    } else {
      while(q->next != NULL) {
        if (q->next->dato.numero == d.numero) {
          Tnodo* r = q->next;
          q->next = q->next->next;
          delete r;
          return s;
        }
        if (q->next != NULL){ 
          q=q->next; 
        }
      }
    }
  }
  return NULL; 
}

void put(TipoCoda* p, Tdato d){
  TipoCoda* n;
  n = p;
  Tnodo* q =new Tnodo(d,NULL);
  if (n->tail==NULL){ //lista vuota
    n->head = q; 
  } else { 
    n->tail->next =q; 
  }
  n->tail = q;
  p = n;
}

Tdato read(TipoCoda* p){
  Tdato d;
  if(p->head!=NULL){
    d = p->head->dato;
  }
  return d;
}

Tdato get(TipoCoda* p){
  Tdato d; //invoco costruttore default
  if (p->head==NULL){//lista vuota 
    return d; //devo comunque ritornare qualcosa
  } 
  d = p->head->dato;
  //caso 1 solo nodo
  if (p->head->next==NULL) {
    p->head=NULL; 
    p->tail=NULL;
  } else {
    Tnodo* s= p->head;
    p->head = p->head->next;
    delete s;
  }
  return d;
}


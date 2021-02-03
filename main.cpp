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
    cout << endl;
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
    p = p->next;
  }
  cout << endl;
}

int main() {
  Tnodo* listaLIFO = NULL;
}
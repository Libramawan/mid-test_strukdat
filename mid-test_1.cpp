/**
 * Author   : Prayudha A.L
 * NPM      : 140810180008
 * Deskripsi: Program ini dapat mendata semua pengunjung yang membeli makanannya. 
 * Tahun    : 2019
*/

#include <iostream>
#include<string>
using namespace std;

struct pesanan{
    int nomer;
    char nama[20];
    int jumlah;
    int harga;
    pesanan* next;
};

typedef pesanan* pointer;
typedef pointer list;

void createList(list head){
    head = NULL;
}

void createNode(pointer& pNew){
  pNew= new pesanan;
  cout<<"Masukan No: "; cin>>pNew->nomer;
  cout<<"Masukan Nama Makanan : ";cin.ignore(); cin.getline(pNew->nama,20);
  cout<<"Masukan Jumlah : "; cin>>pNew->jumlah;
  cout<<"Masukan Harga : "; cin>>pNew->harga;
  pNew->next=NULL;
}

void insertFirst(list& First, pointer pBaru){
  if(First==NULL){
    First=pBaru;
  }
  else{
    pBaru->next=First;
    First=pBaru;
  }
}

void traversal(list head){
    pointer pBantu;
    pBantu=head;
    cout<<"Nomer\tNama Makanan\tJumlah\t\tHarga"<<endl;
    while(pBantu!=NULL){
    cout<<pBantu->nomer<<"\t"<<pBantu->nama<<"\t\t"<<pBantu->jumlah<<"\t\t"<<pBantu->harga<<endl;
    pBantu=pBantu->next;
  }
}

// void update (List& head, pointer& pToUpdate)

void swap(pointer& a,pointer& b){
     int temp = a->jumlah;
     a->jumlah = b->jumlah;
     b->jumlah = temp;
 }

 void sorting(list& head){
     int swapped;
     pointer ptr1;
     pointer lptr = NULL;

     if (head == NULL)
         return;

     do{
         swapped = 0;
         ptr1 = head;

         while(ptr1->next!=lptr){
             if (ptr1->jumlah < ptr1->next->jumlah){
                 swap(ptr1,ptr1->next);
                 swapped = 1;
             }
             ptr1 = ptr1->next;
         }
         lptr = ptr1;
     } while(swapped);
 }

 int main(){
    pointer p;
    list uts;
    char pemesan[20];
    int n;

    createList(uts);
    cout<<"Masukan Nama pemesan : "; cin.ignore(); cin.getline(pemesan,20);
    
    cout<<"Masukan banyak pesanan :"; cin>>n;
    
    for(int i=0;i<n;i++){
        createNode(p);
        insertFirst(uts,p);
    }
    cout<<"Nama Pemesan : "<<pemesan<<endl;
    traversal(uts);
    
    cout<<"\nUPDATE JUMLAH MAKANAN"<<endl;
    // update(uts,p);
    sorting(uts);
    traversal(uts);
}
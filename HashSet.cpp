#include "HashSet.h"
#include <iostream>
#include <sstream>

template<class T>
HashSet<T>::HashSet() {
    for (int i = 0; i < hashSetModulo; i++) {
        tab[i] = NULL;
    }


}

template<class T>
HashSet<T>::HashSet(const HashSet<T>& orig) {
    this->addAllFrom(orig);


}

template<class T>
HashSet<T>::~HashSet(){
    Bucket<T> * temp = NULL;
    Bucket<T> * prev = NULL;
    for(int i = 0; i < this->hashSetModulo; i++){
        temp = this->tab[i];
        while(temp != NULL){
            prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
}

template<class T>
void HashSet<T>::addToBucket(const T& s, unsigned bucketNo) {
    Bucket<T> * prev = NULL;
    Bucket<T> * temp = tab[bucketNo];

    while (temp != NULL && temp->s != s) {
        prev = temp;
        temp = temp->next;
    };

    if (temp == NULL) {
        if (prev == NULL) {
            tab[bucketNo] = new Bucket<T>;
            tab[bucketNo]->s = s;
            return;
        } else {
            prev->next = new Bucket<T>;
            prev->next->s = s;
        }
    };
};

template<class T>
unsigned HashSet<T>::getHash(const T& s) {
    const unsigned seed = 3;
    const unsigned factor = 101;

  if(&s==NULL)
  {

    throw s;
    return 0;
  }


    string  o;
    ostringstream oss;
    oss<<s;
    o = oss.str();


    unsigned hash = seed;
    for (auto c : o) {
        hash = hash * factor + c;
    }

    hash = hash % hashSetModulo;
    //TEST sprawdzający jak są generowane hashe
    //cout<<"Hash:"<<hash<<endl;
    return hash;
}

template<class T>
void HashSet<T>::add(const T & s) {

 if(&s==NULL)
  {
   throw s;
   return;
  }

    addToBucket(s, getHash(s));
}

template<class T>
bool HashSet<T>::isInSet(const T& s) {
    unsigned hash = getHash(s);

    Bucket<T> * temp = tab[hash];

    while( temp != NULL && temp->s != s){
        temp = temp->next;
    }

    if(temp == NULL)
        return false;
    else
        return true;
}

template<class T>
void HashSet<T>::printSet() {
    Bucket<T> * temp = NULL;

    for (int i = 0; i < hashSetModulo; i++) {
        temp = tab[i];
        while (temp != NULL) {
            cout << temp->s << endl;
            temp = temp->next;
        };
    }
}

template<class T>
void HashSet<T>::addAllFrom(const HashSet<T> &h) {
    for(int i = 0; i < h.hashSetModulo; i++){
        Bucket<T> * b = h.tab[i];
        while(b!=NULL){
            add(b->s);
            b = b->next;
        }
    }
}

template<class T>
HashSet<T> HashSet<T>::operator+(const HashSet<T>& h2) {
    HashSet<T> newOne;
    newOne.addAllFrom(*this);
    newOne.addAllFrom(h2);

    return newOne;
}

template<class T>
void HashSet<T>::remove(const T& s) {

    if (length()==0)
    {
        string a = "Nieudana próba usuniecia elementu z pustego kontenera";
        throw a;
    }

    unsigned hash = getHash(s);


    Bucket<T> * prev = NULL;
    Bucket<T> * temp = this->tab[hash];

    while(temp != NULL && temp->s != s){
        prev = temp;
        temp = temp->next;
    };

    if(temp != NULL){
        if(prev == NULL)
            tab[hash] = temp->next;
        else
            prev->next = temp->next;

        delete temp;
    }


}

template<class T>
HashSet<T> HashSet<T>::operator-(const HashSet<T>& h) {
    HashSet<T> newOne;
    newOne.addAllFrom(*this);
    for(int i = 0; i < h.hashSetModulo; i++){
        Bucket<T> * b = h.tab[i];
        while(b!=NULL){
            newOne.remove(b->s);
            b = b->next;
        }
    }
    return newOne;
}

template<class T>
HashSet<T> HashSet<T>::operator*(const HashSet<T>& h) {
    HashSet<T> newOne;
    for(int i = 0; i < h.hashSetModulo; i++){
        Bucket<T> * b = h.tab[i];
        while(b!=NULL){
            if(this->isInSet(b->s))
                newOne.add(b->s);
            b = b->next;
        }
    }
    return newOne;
}

template<class T>
unsigned HashSet<T>::length() {
    int length = 0;

    for(int i = 0; i < this->hashSetModulo; i++){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
            length++;
            b = b->next;
        }
    }

    return length;
}








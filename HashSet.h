#ifndef HASHSET_H
#define HASHSET_H

#include <string>
#include <iostream>

using namespace std;

 /**
 * @brief Klasa iteratora
 */
template<class T>
 class ListIterator;

 /**
 * @brief Struktura Bucket
 */
template<class T>
struct Bucket{
     /**
 * @brief Element struktury.
 */
    T s;
     /**
 * @brief Wskaznik na nastepny 'wyraz' listy.
 */
    Bucket * next = NULL;
};
/**
 * @brief Klasa HashSet
 */
template<class T>
class HashSet{
private:
    static const unsigned hashSetModulo = 1000;
    Bucket<T> * tab[hashSetModulo];



    void addToBucket(const T& s, unsigned hash);
    static unsigned getHash(const T &s);
    void addAllFrom(const HashSet<T>&);


public:
    /**
 * @brief Konstruktor
 */
    HashSet();
    /**
 * @brief Konstruktor kopiujacy
 */
    HashSet(const HashSet<T> & orig);
    /**
 * @brief Destruktor czyszczacy pamiec
 */
    /*virtual*/ ~HashSet();
/**
 * @brief Dodaje do koszyka
 * @param ciag znakow
 */
    void add(const T &s);
    /**
 * @brief Drukuje obiekt
 */
    void printSet();
    /**
 * @brief Sprawdza czy dany element jest w zbiorze
 */
    bool isInSet(const T &s);
    /**
 * @brief Zlicza ilosc obiektow
 *@param Obiekt
 *@return Ilosc obiektow
 */
    unsigned length();
 /**
 * @brief Funkcja dodaje do siebie dwa obiekty
  * @param Obiekty
  *@return Nowy Obiekt
 */
    HashSet operator+(const HashSet<T>&);
/**
 * @brief Funkcja odejmuje od siebie dwa obiekty
  * @param Obiekty
  *@return Nowy obiekt
 */
    HashSet operator-(const HashSet<T>&);
    /**
 * @brief Funkcja bioraca czesc wspolna dwoch obiektow
  * @param Obiekty
  *@return Nowy obiekt
 */
    HashSet operator*(const HashSet<T>&);

/**
 * @brief Usuwa dany element
  * @param Ciag znakow
 */
    void remove(const T &s);
 /**
 * @brief Tworzy iterator
 */
     ListIterator<T>* createIterator()  ;
     friend class ListIterator<T>;




     Bucket<T> *   Begin()
     {
      Bucket<T> * wyn=NULL;
      for(int i = 0; i < this->hashSetModulo; i++){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
          wyn=b;
          break;
        }
    }
    return wyn;
}


   Bucket<T> *   End()
     {
         Bucket<T> * wyn=NULL;
    for(int i = 0; i < this->hashSetModulo; i++){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
          wyn=b;
          b = b->next;

        }
    }
    return wyn;
}

   Bucket<T> *   Next(int index)
     {
         Bucket<T> * wyn=NULL;
    for(int i = index+1; i < this->hashSetModulo; i++){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
          wyn=b;
          b = b->next;

        }
    }
    return wyn;
}


   Bucket<T> *   Prev(int index)
     {
         Bucket<T> * wyn=NULL;
    for(int i = index-1; i > 0; i--){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
          b = b->next;
          wyn=b;
        }
    }
    return wyn;
}

 Bucket<T> *   getElem(int index)
     {
         int cnt=-1;
         Bucket<T> * wyn=NULL;
    for(int i = 0; i < this->hashSetModulo; i++){
        Bucket<T> * b = this->tab[i];
        while(b!=NULL){
          wyn=b;
          cnt++;
          if(cnt==index)
          {
              return wyn;

          }


          b = b->next;

        }
    }
    return wyn;
}

};


template<class T>
class ListIterator {

     HashSet<T>* stk;
   int index;


public:
   ListIterator<T>(   HashSet<T>* s ) { stk = s;index=0;}
 /**
 * @brief Funkcja która ustawia wskaźnik na początek
 */
   Bucket<T> *  Begin()
    {
   index = 0;
   return stk->Begin();
   }

/**
 * @brief Funkcja która ustawia wskaźnik na koniec
 */
   Bucket<T> *  End()                            { index = stk->length(); return stk->End();}
   /**
 * @brief Funkcja która ustawia wskaźnik na następny element
 */
   Bucket<T> * Next()                            { index++; return stk->Next(index);}
   /**
 * @brief Funkcja która ustawia wskaźnik na poprzedni element
 */
  Bucket<T> * Prev()                            { index--; return stk->Prev[index];}

/**
 * @brief Funkcja sprawdzajaca czy jest nastepny element
 */
   bool hasNext(){
                if (index==(stk->length()))
                    {return false;}
                   else
                    {return true;}
                }

   bool isDone()
      { return index == stk->length(); }
/**
 * @brief Funkcja zwraca element o danym indeksie
 */
   Bucket<T> * currentItem()
       { return stk->getElem(index); }

/**
 * @brief Funkcja zwracajaca numer indeksu
 */
   int  getIndex()  { return index; }
   int lenght()                          { return stk->length(); }




   ListIterator<T> & operator++() { // preinkrementacje, czyli najpierw  zwiêkszamy a potem zwracamy
    ++index;
    return *this;
  }


  ListIterator<T>  operator++(int) {  // specjalny zapis do postinkrementacji
    ListIterator<T>  kopia = (*this);
     ++index;
    return kopia; // zwracamy kopiê, a nie orygina³
  }


};

template<class T>
ListIterator<T>* HashSet<T>::createIterator()   {

     return new ListIterator<T>( this ); }


#endif /* HASHSET_H */

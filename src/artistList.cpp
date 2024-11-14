// artistList.cpp: function definitions for prototypes for artistList.h header file
// place header includes here
#include "artistList.hpp"
#include <iostream>

ArtistList::ArtistEntry::ArtistEntry(ArtistList* list, const Artist& a) {
    this->list = list;
    this->artist = a;
    this->next = nullptr;
    this->prev = nullptr;
}

// Allocate a new artist list. Constructor as empty list
ArtistList::ArtistList() {
    length = 0;
    first = nullptr;
    last = nullptr;
}

std::size_t ArtistList::size() const {return length;}

bool ArtistList::is_empty() const {return length==0;}


ArtistList::ArtistList(const ArtistList & list) {
  first = nullptr;
  last = nullptr;
  length = 0;

  ArtistEntry* current = list.first;

    while (current != nullptr) {
        appendArtist(current->artist);
        current = current->next;
    }
}

// Delete a artist list (and all entries)
ArtistList::~ArtistList() noexcept {
  ArtistEntry* current = first;
    while (current != nullptr) {
        ArtistEntry* next = current->next;
        delete current;
        current = next;
    }
}

// prepend an artist at the beginning of list
void ArtistList::prependArtist(const Artist& a) {
  ArtistEntry* newEntry = new ArtistEntry(this,a);
  if (is_empty()){
    first = last = newEntry;
  } else {
    first->prev = newEntry;
    newEntry->prev = nullptr;
    newEntry->next = first;
    first = newEntry;
  }
  ++length;
}

// append an artist to the end of the list
void ArtistList::appendArtist(const Artist& a) {
  //std::cout<<"APPEEEND"<<std::endl;
  ArtistEntry* newEntry = new ArtistEntry(this, a);

  if (is_empty()) {
    first = newEntry;
    last = newEntry;
  } else {
    last->next = newEntry;
    newEntry->prev = last;
    last = newEntry;
  }
  ++length;
  //std::cout<<length<<std::endl;
  //
}

// remove the first artist from the list
void ArtistList::removeFirstArtist() {
  if (is_empty()) {return;}

  ArtistEntry* ptr = first;

  first = first->next;

  if (first != nullptr) {
    first->prev = nullptr;
    } else {
        last = nullptr;
    }
  delete ptr;
  length--;
}

// remove last artist from the list
void ArtistList::removeLastArtist() {
  if (is_empty()){return;}
  ArtistEntry* ptr = last;

  last = last->prev;
  last->next = nullptr;

  delete ptr;
  length--;
}

Artist * ArtistList::at(size_t index) {
  //return this->list[index];
  if (index >= length) {
        return nullptr;
    }

    ArtistEntry* current = first;
    for (std::size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return &current->artist;
}

// print an artist list
void ArtistList::printArtistList() const {
  ArtistEntry* ptr = first;
  while(ptr!=nullptr){
      ptr->artist.printArtist();
      ptr = ptr->next;
  }
}
/*




// print an artist list
void ArtistList::printArtistList() const {
  //
}

// find an artist by name in an unsorted list
Artist *ArtistList::findArtistName(const std::string& name) const {
  //
}

// remove artist by name in an unsorted list
void ArtistList::removeArtistbyName(const std::string & name) {
  //
}

void ArtistList::insertArtistAt(std::size_t index, const Artist& artist) {
  //
}

Artist * ArtistList::at(size_t index) {
  //
}

const Artist * ArtistList::at(size_t index) const {
  //
}

Artist* ArtistList::firstArtist() {
  //
}

const Artist* ArtistList::  firstArtist() const {
  //
}

Artist* ArtistList:: lastArtist() {
  //
}

const Artist* ArtistList:: lastArtist() const {
  //
  
}

*/

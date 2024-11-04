// artistList.cpp: function definitions for prototypes for artistList.h header file
// place header includes here

ArtistList::ArtistEntry::ArtistEntry(ArtistList* list, const Artist& a) {
  /* Insert your code here */
}

// Allocate a new artist list
ArtistList::ArtistList() {
  /* Insert your code here */
}

std::size_t ArtistList::size() const {
  /* Insert your code here */
}

bool ArtistList::is_empty() const {
  /* Insert your code here */
}

ArtistList::ArtistList(const ArtistList & list) {
  /* Insert your code here */
}

// Delete a artist list (and all entries)
ArtistList::~ArtistList() noexcept {
  /* Insert your code here */
}

// prepend an artist at the beginning of list
void ArtistList::prependArtist(const Artist& a) {
  /* Insert your code here */
}

// append an artist to the end of the list
void ArtistList::appendArtist(const Artist& a) {
  /* Insert your code here */
}

// remove the first artist from the list
void ArtistList::removeFirstArtist() {
  /* Insert your code here */
}

// remove last artist from the list
void ArtistList::removeLastArtist() {
  /* Insert your code here */
}

// print an artist list
void ArtistList::printArtistList() const {
  /* Insert your code here */
}

// find an artist by name in an unsorted list
Artist *ArtistList::findArtistName(const std::string& name) const {
  /* Insert your code here */
}

// remove artist by name in an unsorted list
void ArtistList::removeArtistbyName(const std::string & name) {
  /* Insert your code here */
}

void ArtistList::insertArtistAt(std::size_t index, const Artist& artist) {
  /* Insert your code here */
}

Artist * ArtistList::at(size_t index) {
  /* Insert your code here */
}

const Artist * ArtistList::at(size_t index) const {
  /* Insert your code here */
}

Artist* ArtistList::firstArtist() {
  /* Insert your code here */
}

const Artist* ArtistList::  firstArtist() const {
  /* Insert your code here */
}

Artist* ArtistList:: lastArtist() {
  /* Insert your code here */
}

const Artist* ArtistList:: lastArtist() const {
  /* Insert your code here */
}

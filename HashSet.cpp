#include <cstdlib>
#include <iostream>

#include "HashSet.h"

using namespace std;

// Initialize our member variables in the constructor
HashSet::HashSet(int capacity, int method) {
  this->capacity = capacity;
  this->method = method;
  mysize = 0;
  elements = new HashNode*[capacity](); // all are initialized to nullptr using ()
}

int HashSet::hash(int value) const {
  return abs(value) % capacity;
}

// Private helper for calculating the bucket of a given a value
int HashSet::getIndexOf(int value) const {
  return hash(value) % capacity;
}

void HashSet::add(int value) {
  if (!contains(value)) {
  int bucket = getIndexOf(value);
  // insert at the front of the list in that bucket
  elements[bucket] = new HashNode{value, elements[bucket]};
  mysize++;
  }
  if (mysize / capacity >= 2) {
     rehash();
  }
}

bool HashSet::contains(int value) const {
  HashNode* curr = elements[getIndexOf(value)];
  while (curr != nullptr) {
    if (curr->data == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

HashSet::~HashSet() {
  clear(); // Remove all elements
  delete[] elements; // Also delete the array itself
}

// Remove all elements in our set so all buckets in our array are nullptr
void HashSet::clear() {
  for (int i = 0; i < capacity; i++) {
    // free list in bucket i
    while (elements[i] != nullptr) {
      HashNode* curListNode = elements[i];
      elements[i] = elements[i]->next;
      delete curListNode;
    }
  }
  mysize = 0;
}

void HashSet::rehash() {
  HashNode** oldElements = elements;
  int oldCapacity = capacity;
  capacity *= 2;
  elements = new HashNode*[capacity]();
  for (int i = 0; i < oldCapacity; i++) {
    HashNode* curr = oldElements[i];
    while (curr != nullptr) { // iterate over old bucket
      HashNode* prev = curr;
      curr = curr->next; // don’t lose access to rest of old bucket
      int newBucket = getIndexOf(prev->data);
      prev->next = elements[newBucket]; // put prev node at front of new bucket
      elements[newBucket] = prev; // update new bucket pointer
    }
  }
  delete[] oldElements;
}

void HashSet::printBucket(int value) {
  int bucket = getIndexOf(value);
  HashNode* curr = elements[bucket];
  while (curr != nullptr) {
    cout << curr->data << " -> ";
    curr = curr->next;
  }
  cout << "nullptr" << endl;
}

void HashSet::printHashSet() {
  for (int i = 0; i < capacity; i++) {
    cout << "Bucket " << i << ": ";
    HashNode* curr = elements[i];
    while (curr != nullptr) {
      cout << curr->data << " -> ";
      curr = curr->next;
    }
    cout << "nullptr" << endl;
  }
} 
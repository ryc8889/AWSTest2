#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

/**
 * Name: Ricky Chen
 * Login: cs100uac
 * ID: A10112043
 */


using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2013
 * Author: P. Kube (c) 2013
 */
int main() {

  /* Create an STL vector of some ints */
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pr = b.insert(*vit);
    cout << "vit = " << *vit << endl;
    if(! pr.second ) {
      cout << "Incorrect bool return value when inserting " << *vit << endl;
      return -1;
    }
    if(*(pr.first) != *vit) {
      cout << "Incorrect iterator return value when inserting " << *vit << endl;
      return -1;
    }  
  }

  /* Test size. */
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout<< "bsize is" << b.size() << endl;
    cout<< "vsize is" << v.size() << endl;
    cout << "... which is incorrect." << endl;
    return -1;
  }
    cout<<"simple test" << endl;
    for(BST<int>::iterator it = b.begin(); it != b.end(); ++it){
	cout<<*it<< endl;
	}



  /* Test find return value. */
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
  
  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());

  /* Test BST iterator; should iterate inorder */
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  for(; vit != ven; ++vit) {
    if(! (it != en) ) {
      cout << *it << "," << *vit << ": Early termination of BST iteration." << endl;
      return -1;
    }
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++it;
  }
  cout << "OK." << endl;

/* Testing clear and checking clear size afterwards*/
 BST<int> c;
 vit = v.begin();
 ven = v.end();
  for(vit = v.begin(); vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pr = c.insert(*vit);
    }
  c.clear();
  cout<< "clear size is" << c.size() << endl;
  if(c.size() != 0){
	cout << "fail" << endl;
	return -1;  
  }
/* Testing BST destructor */
BST<int>* d = new BST<int>();
d->insert(3);
delete d;

/*Test Clear then add and size after */
 BST<int> e;
 vit = v.begin();
 ven = v.end();
  for(vit = v.begin(); vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pr = e.insert(*vit);
    }
  e.clear();
  e.insert(5);
  cout<< "e size is " << e.size() << endl;
/* Test insert of same item */
 BST<int> f;
 vit = v.begin();
 ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return a std::pair
    // with second part true
    std::pair<BST<int>::iterator,bool> pk = f.insert(*vit);
    }
  std::pair<BST<int>::iterator,bool> pi = f.insert(3);
  if(pi.second){
	cout << "you fucked up" << endl;
        cout << "value is " << *(pi.first) << endl;
	return -1;
  }
/* Clear an empty tree */
BST<int> q;
q.clear();
}

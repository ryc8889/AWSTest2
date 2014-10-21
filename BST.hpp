#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

/**
 * Name: Ricky Chen
 * Login: cs100uac
 * ID: A10112043
 */

template<typename Data>
class BST {
private:

/** private method for locating smallest(first)
 *  item in a BST
 */
  static BSTNode<Data>* first(BSTNode<Data>* Node){
    if(Node->left == nullptr && Node->parent == nullptr){
	return Node;
    }
    else if(Node->left == nullptr){
	return first(Node->parent);
    }
    else{
	while(Node->left != nullptr){
	Node = Node->left;
	}
	return Node;
	}
}

protected:

  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */
  virtual ~BST() {
	clear();
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ 
  virtual std::pair<iterator,bool> insert(const Data& item) {
	BSTNode<Data>* curr;
   if(root == nullptr){ //if no tree
	  root = new BSTNode<Data>(item);
	  curr = root;
	  isize+=1;
	  return std::make_pair(BST<Data>::iterator(curr), true);
	}
   else{
	curr = root;
	while(curr != nullptr){ 
	  if(item < curr->data){ //go to left subtree
	    if(curr->left == nullptr){ //if no children
	      curr->left = new BSTNode<Data>(item); //add as new item
	      curr->left->parent = curr; //set new item's parent to curr
	      curr = curr->left; //move curr (not necessary)
	      isize += 1; //increment size
	     return std::make_pair(BST<Data>::iterator(curr), true);
	    }
	    else{
	      curr = curr->left;
	    }
	  }
	  else if(item > curr->data){
	    if(curr->right == nullptr){
	      curr->right = new BSTNode<Data>(item);
	      curr->right->parent = curr;
	      curr = curr->right;
	     isize+=1;
	     return std::make_pair(BST<Data>::iterator(curr), true);
	    }
	    else{
	      curr = curr->right;
	   }
	  }
	  else{ //if curr = the item then return
	return std::make_pair(BST<Data>::iterator(curr), false);
	}
      }
   }
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const{
	BSTNode<Data>* curr;
	if(root == nullptr)
		return end();
	else
		curr = root;
	while(curr != nullptr){
		if(item < curr->data){
			if(curr->left == nullptr){
			return end();
			}
			else{
			curr = curr->left;
			}
		}
		else if(curr->data < item){
			if(curr->right == nullptr){
			return end();
			}
			else{
			curr = curr->right;
			}
		}
		else{
			return typename BST<Data>:: iterator(curr);
		}  
	}
}

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
	return isize;
  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ // TODO
  void clear() {
	delete root;
	isize = 0;
	root = nullptr;
		
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
	if(isize == 0)
		return true;
	else
		return false;

  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
	return typename BST<Data>:: iterator(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(nullptr);
  }

 };


#endif //BST_HPP

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/**
 * Name: Ricky Chen
 * Login: cs100uac
 * ID: A10112043
 */


/** This class template defines a node type for the BST container.
 *  Note that all members are public. So, the BST implementation should
 *  take care not to expose any BSTNode objects.
 */
template<typename Data>
class BSTNode {

public:

  /** Member variables. */
  BSTNode<Data>* parent;
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  const Data data;  // the const Data in this node
  int info;  // variable used in advanced algorithms 

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = nullptr;
  }


  /** Return the inorder successor of this BSTNode in a BST,
   *  or nullptr if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or nullptr if there is none.
   *  Conditions to check: 
   *  1. right one all the way left
   *  2. find ancestor whose left chidl is an ancestor
   *  of the node you want to find the successor to
   */ // TODO
  BSTNode<Data>* successor() {
	BSTNode<Data> *prev, *tmp = this;
	if(tmp->right != NULL){
		prev = tmp;
		tmp = tmp->right;	
		while(tmp->left != NULL){
		prev = tmp;
		tmp = tmp->left;
		}
		return tmp;
	}
	else{
	prev = tmp->parent;
	while(prev != NULL && tmp == prev->right)
	{
		tmp = prev;
		prev = prev->parent;
	}
	return prev;
	}
	return 0;
 }

~BSTNode(){
	delete left;
	delete right;
	}
};

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; i:" << std::setw(10) << n.info;   // its info field
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP

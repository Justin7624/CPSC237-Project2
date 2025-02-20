/****************************************************************
*    Author:           Justin Allen                             *
*    Creation Date:    February 29, 2024                        *
*    Due Date:         March 8th, 2024                          *
*    Course:           CSC237 010                               *
*    Professor Name:   Dr. Spiegel                              *
*    Assignment:       #2                                       *
*    File:             CLinkedList.h            			          *          
*    Description:      This file defines a templated circular-  *
*                      linked list (CLinkedList) and a list     *
*                      iterator (CListItr) for traversing the   *
*                      linked list. The CLinkedList class       *
*                      supports ordered insert, remove, deep    *
*                      copy, and backward printing. The file    *
*                      also includes a global << operator for   *
*                      easy output. CListItr acts as an iterator*
*                      for the linked list, providing methods   *
*                      for traversal and overloaded operators   *
*                      (++ and *) for ease of use.              *
****************************************************************/

#ifndef _CLinkedList_
#define _CLinkedList_
#include <assert.h>
#include <iostream>
#include "Node.h"
#include "ListIterator.h"

using namespace std;


// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;

template <typename eltType> class CLinkedList
{
  public:
    // Construct empty CLinkedList
    /*************************************************************************
    * Function name: CLinkedList
    * Member Type: Mutator
    * Creates an empty list with a single pointer last set to NULL
    **************************************************************************/
    CLinkedList();
    // Construct deep copy of another CLinkedList
    /*************************************************************************
    * Function name: CLinkedList(CLinkedList&)
    * Member Type: Mutator
    * Requires: A CLinkedList&
    * Description: Creates a copy of the CLinkedList that was passed in
    **************************************************************************/
    CLinkedList(CLinkedList&);

    // destroy CLinkedList
    /**************************************************************************
    * Function name: ~CLinkedList
    * Member Type: Mutator
    * Description: Destroys a CLinkedList by recursion
    **************************************************************************/
    ~CLinkedList();

    // Assign another CLinkedList to this CLinkedList; deep copy
    /*************************************************************************
    * Function name: operator=
    * Member Type: Mutator
    * Requires: const CLinkedList& (The list to be copied)
    * Description: Copies the given list to a new one
    **************************************************************************/
    CLinkedList& operator=(const CLinkedList&);

    // Is the CLinkedList empty?
    /**************************************************************************
    * Function name: isEmpty
    * Member Type: Inspector
    * Description: Returns true if the list is empty
    **************************************************************************/
    bool isEmpty() const;

    /**************************************************************************
    * Function name: find
    * Member Type: Facilitator
    * Requires: eltType (thing to be found wihtin the CLinkedList)
    * Description: Returns true if the list item was found
    **************************************************************************/
    bool find(eltType);

    // Ordered insert/remove
    /*************************************************************************
    * Function name: orderedInsert
    * Member Type: Mutator
    * Requires: eltType (thing to be added to the CLinkedList)
    * Description: Inserts a given eltType into the list in ascending order
    **************************************************************************/
    void orderedInsert(eltType);
    /**************************************************************************
    * Function name: remove
    * Member Type: Mutator
    * Requires: eltType (thing to be removed from the CLinkedList)
    * Description: Removes a given eltType from the list, but keeps it in ascending order
    **************************************************************************/
    void remove(eltType);

    //backwards print
    /************************************************************************
    * Function name: startBackwardsPrint
    * Description: Gives a starting place for backwardsPrint to start its recursive cycle
    **************************************************************************/
    void startBackwardsPrint();
    /*
    * Function name: backwardsPrint
    * Member Type: Inspector
    * Requires: Node<eltType> *l (an iterator)
    * Description: Recursively prints the CLinkedList in descending order
    **************************************************************************/
    void backwardsPrint(Node<eltType> *l);

  private:
    // circular linked list pointer, points at LAST elt (largest int)
    Node<eltType>*	last;

    // Get a copy of a (deep) Node
    void	copy(CLinkedList<eltType> &);

    // Free Nodes of a linked list
    void	destroy(Node<eltType> *);

  // Needed to use a list iterator
  friend class CListItr<eltType>;
};

template <typename eltType>
  ostream& operator<<(ostream &os,const CLinkedList<eltType> &l);

// class CListItr

template <typename eltType> class CListItr
{
  public:
    // Construct a List Iterator
    /**************************************************************************
    * Function name: CListItr
    * Member Type: Mutator
    * Requires: const CLinkedList<eltType> &l (the ClinkedList to be traversed)
    * Description: Creates a iterator of type eltType called l, which has a pointer called curr
    * and a const reference to the CLinkedList to be traversed
    **************************************************************************/
    CListItr(const CLinkedList<eltType> &l);

    // Set curr to point at the first Node of list
    /*************************************************************************
    * Function name: begin
    * Member Type: Mutator
    * Description: Sets the iterator to point to the first Node in the CLinkedList
    **************************************************************************/
    void begin();
    // Go to curr->next
    /*************************************************************************
    * Function name: next
    * Member Type: Mutator
    * Description: Moves curr to the next Node in the list
    **************************************************************************/
    void next();
    //see if curr is at the smallest number
    /**************************************************************************
    * Function name: isFirstNode
    * Member Type: Inspector
    * Description: Returns true if curr is at the front of the CLinkedList
    **************************************************************************/
    bool isFirstNode();
    //see if curr is at the largest number
    /*************************************************************************
    * Function name: isLastNode
    * Member Type: Inspector
    * Description: Returns true if curr is at the end of the CLinkedList
    **************************************************************************/
    bool isLastNode();
    //pre increment overloaded ++ based on .h
    /**************************************************************************
    * Function name: &operator ++()
    * Member Type: Mutator
    * Descrition: Pre increment ++ that moves curr to the next Node
    **************************************************************************/
    CListItr &operator ++();
    //post increment
    /**************************************************************************
    * Function name: operator ++(int)
    * Member Type: Mutator
    * Requires: int
    * Description: Post increment ++ that moves curr to the next Node
    **************************************************************************/
    CListItr operator ++(int);
    //dereference operator overloaded
    /**************************************************************************
    * Function name: operator *()
    * Member Type: Mutator
    * Description: Derefence operator that returns the value of curr
    **************************************************************************/
    eltType operator *();
    //const dereference operator
    /**************************************************************************
    * Function name: operator *() const
    * Member Type: Mutator
    * Description: Const derefence operator that returns the value of curr
    **************************************************************************/
    eltType operator *() const;
  private:
    const CLinkedList<eltType> &list;
    Node<eltType> *curr;
};


/* **************************************************************
   ************** Linked List Implementations *******************
   **************************************************************/


// Construct empty CLinkedList
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}

// Copy constructor. copy() does the deep copy
template <typename eltType> 
  CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{copy(cl);}

// Free all Nodes
template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{
  if(isEmpty())
    return;
  destroy(last->next);
}

// Assignment operator: copy() does the deep copy
template <typename eltType> CLinkedList<eltType> 
  &CLinkedList<eltType>::operator =(const CLinkedList<eltType>& cl)
{	if (this != &cl)
  {	destroy(last);
    last = copy(cl.last);
  }
  return *this;
}

// Place x into the list in order
template <typename eltType> 
    void CLinkedList<eltType>::orderedInsert(eltType x)
{	
  if(isEmpty())
  {
    assert(last=new Node <eltType>(x,last));
    last->next = last; //set it equal to itself
  } //x<last->data)
  else if(x>last->data)
  {  
    //makes pointer to new Node, then points last->next at it
    Node <eltType> *tempNode = new Node <eltType> (x,last->next);
    last->next = tempNode;
    last = last->next;
  }
  else
  {
    //start at second elt
    Node <eltType> *p = last->next; //starts it at front of list
    Node <eltType> *shadowp = last; 

    //searches list for where x should be
    while(x>p->data)//reverse its >
    {
      shadowp= p;
      p = p->next;// move p forward
    }
    //now handle individual cases
    //x is bigger than current last

    assert((shadowp->next = new Node<eltType>(x,p)) != NULL); //insert it behind p, point it at p
  }
}

template <typename eltType> bool CLinkedList<eltType>::find(eltType x)
{	
  Node<eltType> *p = last;
  while (p != NULL && p->data != x)
    p = p->next;
  return (p != NULL && p->data == x);
}

template <typename eltType> inline bool CLinkedList<eltType>::isEmpty() const
{return (last == NULL);}

// Remove a Node in an ordered list
template <typename eltType> void CLinkedList<eltType>::remove(eltType x)
{	
  if(isEmpty())
  {
    cout << "The list is empty, there is nothing to remove" << endl;
    return;
  }

  Node<eltType>*	p = last->next;//points it at front of list
  Node<eltType>*	shadowp = last;
  while ( p != NULL && p->data != x )
  {	
    shadowp = p;
    p = p->next;//move p forward, same as ordered insert loop
    if(shadowp==last)
    {
      cout<< x << " was not removed " << endl;
      return;
    }
  }
  assert(p != NULL);		// x is not in the CLinkedList
  if (p == p->next)
  {
    last = NULL;
  } 
   else if (p == last) //if the element found is last
    {
    //cout << "p == last loop entered" << endl;
    last = shadowp;	
    last->next = p->next;
    }//set last to be one step behind p
  else
    shadowp->next = p->next;	// x is farther down in the CLinkedList

  cout<< x << " was removed " << endl;
  delete p;
}

// Remove all Nodes in the linked list, starting at l
template <typename eltType> void CLinkedList<eltType>::destroy(Node<eltType> *l)
{	

  if(l!=last)
    destroy(l->next);

  //l is a pointer set to last->next
  delete l;

}

template <typename eltType> void CLinkedList<eltType>::startBackwardsPrint() 
{
  if (isEmpty())
  {
    return;
  }
  backwardsPrint(last->next);
}

template <typename eltType> void CLinkedList<eltType>::backwardsPrint(Node<eltType> *l)
{
  if(l!=last)
    backwardsPrint(l->next);

  cout << l->data << " ";

}

// The deep copy. Copy the source list l, one Node at a time
template <typename eltType> 
  void CLinkedList<eltType>::copy(CLinkedList<eltType> &l)
{	
  CListItr<eltType>	lt(l); //create list iterator
  if (!l.isEmpty())
  {	

    for (lt.begin(); !lt.isLastNode(); ++lt)
    {	
      orderedInsert(*lt);

    }

    orderedInsert(*lt);
  }
  return;
}

// Output a linked list, using a list iterator
template <typename eltType> 
  ostream& operator<<(ostream &os,const CLinkedList<eltType> &l)
{
  if(l.isEmpty())
  {
    return os;
  }
  CListItr<eltType>	lt(l);
  for (lt.begin(); !lt.isLastNode(); ++lt)
    os << (*lt) << " ";
  os << (*lt);
  return os;
}


/* ****************************************************************
   ************** List Iterator Implementations *******************
   ****************************************************************/

// Construct a list iterator
template <typename eltType> 
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l): list(l),curr(l.last->next) 
{}

// Set curr to point at list's head
template <typename eltType> void CListItr<eltType>::begin(void)
{curr = list.last->next;} //next in line after last is the first element


// Move curr to next Node
template <typename eltType> void CListItr<eltType>::next(void)
{
  assert( curr != NULL );
  curr = curr->next;
}

template <typename eltType> bool CListItr<eltType>::isFirstNode(void)
{
  return curr ==list.last->next;
}

template <typename eltType> bool CListItr<eltType>::isLastNode(void)
{
  return curr == list.last;
}

//pre increment
template <typename eltType> CListItr<eltType> &CListItr<eltType>::operator++(void)
{
   assert(curr != NULL );
   next();
   return *this;
}

//post increment ++
template <typename eltType> CListItr<eltType> CListItr<eltType>::operator++(int)
{
   CListItr<eltType>*	temp = *this;
   assert(curr != NULL );
   next();
   return temp;
}

template <typename eltType> eltType CListItr<eltType>::operator*(void)
{
  assert( curr != NULL );
  return curr->data;
}

template <typename eltType> eltType CListItr<eltType>::operator*(void) const
{
  assert( curr != NULL );
  return curr->data;
}

#endif

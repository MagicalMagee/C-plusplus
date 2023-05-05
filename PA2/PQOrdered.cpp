//
// PQOrdered.cpp
// Class Section: CS 210-07
// Date: 11 November 2022
//
// PQOrdered.cpp
// Implement your Ordered Priority Queue in this file
#include "PriorityQueue.h"
#include "TestDriver.h"
// Your code here

// Global Variable
int count;

// Default
PriorityQueue::PriorityQueue() {
    max_capacity = DEFAULT_MAX_CAPACITY;
    pq = std::unique_ptr<Element[]>(new Element[max_capacity]);
}

// Parameterized constructor
PriorityQueue::PriorityQueue(int size) {
    max_capacity = size;
    pq = std::unique_ptr<Element[]>(new Element[size]);
}

//  Inserts a new object into the priority queue.  Returns true if
//  the insertion is successful.  If the PQ is full, the insertion
//  is aborted, and the method returns false.
bool PriorityQueue::insert(Element &element) {
    // Flag, temp, and i variables
    bool flag = false;

    // Inserts new object into the priority queue 
    if(size() <= max_capacity) {
        pq[count] = element;
        pq[max_capacity].fifo++;
        flag = true;
    }
    
    // Temp variable
    Element temp;
    
    // This will fix the inordered array
    // Making it in ascending order with the added element with its proper priority
    for(count = 0; count < max_capacity; count++) {
        for(int i = count + 1; i < max_capacity; i++)
        if (pq[i].priority < pq[i-1].priority && pq[i].priority != -1) {
            temp = pq[i];
            pq[i] = pq[i-1];
            pq[i-1] = temp;
        }
    }
    
    // Returns the boolean flag
    return flag;
}

//  The object of the highest priority must be the one returned by the
//  remove() method; and if multiple objects have the same priority,
//  the one in the queue the longest shall be returned, ie, FIFO
//  return order must be preserved for objects of identical priority.
//  Returns the default constructed Element if the PQ is empty.
Element PriorityQueue::remove() {
    return Element();
}

//  Deletes all instances of the parameter from the PQ if found, and
//  returns true.  Returns false if no match to the parameter obj is found.
bool PriorityQueue::del(Element &element) {
    // Boolean flag to be returned
    bool flag = false;

    // Loops entire PQ
    for(int i = 0; i < max_capacity; i++){

        // Check any deleted instances, return true if found or false if no match
        if(pq[i].name == element.name && pq[i].priority == element.priority){
            pq[i].name = "None";
            pq[i].priority = -1;
            flag = true;
        }
    }
    return flag;
}

//  Returns the object of highest priority in the PQ; if multiple
//  objects have the same highest priority, return the one that has
//  been in the PQ the longest, but does NOT remove it.
//  Returns default constructed Element if the PQ is empty.
Element PriorityQueue::peek() {
    // Returns the first element in Priority Queue
    return pq[0];

    // Returns default constructed Element if the PQ is Empty
    if(isEmpty()){
        // Returns default
        return Element();
    }
}

//  Returns true if the priority queue contains the specified element
//  false otherwise.
bool PriorityQueue::contains(Element &element) {
    // Flag for the boolean
    bool flag = false;

    // Loops through the PQ until it finds the specified element raising the flag as true
    // else false
    for(count = 0; count < max_capacity; count++) {
        if(pq[count].name == element.name && pq[count].priority == element.priority) {
            flag = true;
        }
    }
    return flag;
}

//  Returns the number of objects currently in the PQ.
int PriorityQueue::size() {
    // Counter
    count = 0;

    // Loops until the very end until it counts everything
    while(count < pq[max_capacity].fifo) {
        count++;
    }
    return count;   
}

//  Returns the PQ to its default state.
void PriorityQueue::clear() {
    pq = std::unique_ptr<Element[]>(new Element[max_capacity]);
    max_capacity = 0;
} 

//  Returns true if the PQ is empty, otherwise false.
bool PriorityQueue::isEmpty() {
    count = 0;

    // Loops the entire PQ
    while(count < max_capacity) {
        // If statement that will check if PQ is empty or not
        if(pq[count].fifo != 0) {
            return false; 
        }
        count++;
    }
    return true;
} 

//  Returns true if the PQ is full, otherwise false.
bool PriorityQueue::isFull() {
    count = 0;

    // To check if PQ is full via if statement
    if(max_capacity != count) {
        return false; 
    } else
    return true;
}

/* IMPORTANT: main() must be EXACTLY how it was provided
** provided to you when you submit your assignment.
**
** If you edit main for your own testing purposes,
** you MUST restore it to how it was provided to
** you before submission. 
*/
int main() {
    test_PQOrdered();
    return 0;
}

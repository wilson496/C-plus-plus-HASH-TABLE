/*

Cameron Wilson
V00822184
October 1st, 2015

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_set.h"

using namespace std;

//constructor
string_set::string_set() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++){
		hash_table[i] = NULL;
	} 
	
}	
	
//add a node into a specific position in the hash table.  	
void string_set::add(const char *s) {
	
	//throw duplicate_exception if s is already in list
	if (contains(s) == 1){
		throw duplicate_exception();
	}
	
	//create a node to store string
	node *c = new node();
	
	if (c == NULL){
		throw memory_exception();
	}
	
	//point node to string 
	c->s = new char[strlen(s)+1];
	
	if (c->s == NULL){
		throw memory_exception();
	}
	
	strcpy(c->s, s);
	c->next = hash_table[hash_function(s)];
	hash_table[hash_function(s)] = c;
	
	//reset the iterator
	reset();
	
	
}

void string_set::remove(const char *s) {
	
	//case empty. nothing here 
	
	if (contains(s) == 0){ 
		throw not_found_exception();
	}
	
	//assign a variety of pointers as new nodes to track iterator throughout the 
	//lists in the hash table. 
	node *curr = new node();
	if (curr == NULL){
		throw memory_exception();
	}
	node *prev = new node();
	if (prev == NULL){
		throw memory_exception();
	}
	node *deleteP = new node();
	if (deleteP == NULL){
		throw memory_exception();
	}
	
		
	//case 1. at the head 
	
	if (strcmp(hash_table[hash_function(s)]->s, s) == 0){
		
		hash_table[hash_function(s)] = hash_table[hash_function(s)]->next;
		
		curr->next = NULL;
	
		delete curr;
		
	}
	
	
	//case 2, everything else 
	
	else{
		curr = hash_table[hash_function(s)]->next;
		prev = hash_table[hash_function(s)];
		
		while(curr != NULL && strcmp(curr->s,s) == 0){
			prev = curr; 
			curr = curr->next; 
			
		}
		if(curr == NULL){
			return;
		}
		else{
			deleteP = curr; 
			curr = curr->next;
			prev->next = curr;
			delete deleteP;
			
		}
	}
	//reset iterator
	reset();
}

//determine if a particular string is in the hash table 
int string_set::contains(const char *s) {
	
	int h = hash_function(s); 
	node *current = hash_table[h]; 
	
	while(current != NULL){
		if (strcmp(current->s, s) == 0){ //we have found the string
			return 1; //return value of 1, which evaluates to true
			
		}
		else{
			current = current->next;
		}
			
	}
	
	return 0; 
	
}

//reset the iterator, as to return to the beginning of the hash table 
//
void string_set::reset() {
	iterator_index = 0; 
	iterator_node = hash_table[iterator_index];
}

//Return the node that is next to the current node.
const char *string_set::next() {
	
	//go through each index of the hash table
	while(iterator_index < HASH_TABLE_SIZE){
		
		//hash table index null? There might be something else in the list,
		//so we proceed through regardless. 
		if(hash_table[iterator_index] == NULL){
			iterator_index++;
			continue;
		}

		//if the node is null (which it will be by default), point it toward the hash_table position that is not null
		//and return the value that's there, since it's not null at the specified hash table position 
		else if(iterator_node == NULL){
				
			iterator_node = hash_table[iterator_index];
			return iterator_node->s;
			
		//otherwise, look to see if the next node is not null	
		}else {
			if (iterator_node->next == NULL){
				iterator_node = NULL;
				iterator_index++;
				continue;
			}
			
			iterator_node = iterator_node->next;
			return iterator_node->s;
		
		}
		
		
	}	
	//if the hash table is completely empty, return null, since nothing can be returned 
	return NULL;

}

//deconstructor
string_set::~string_set() {
	
	node *p;
	node *c;
	
	//iterate through each element in the hash table 
	for (int i = 0; i < HASH_TABLE_SIZE; i++){
		
		if(hash_table[i] == NULL){
			p = hash_table[i];
		}
		
		while(p != NULL){
			c = p->next;
			delete(p->s);
			delete(p);
			p = c;
		}	
	
	}
	
}

//convert the string s, into it's appropriate hash value 
int string_set::hash_function(const char *s) {
	
		int h = 0;
		int sum = 0;
		
		
		//loop to count each character, THEN CAST INTO INT, add up and return 
			
		for (int i = 0; s[i] != '\0'; i++){
			h = (int) s[i] % HASH_TABLE_SIZE;
			sum = sum + h;
		}
		
		return sum;
}

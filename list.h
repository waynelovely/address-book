/*
 *
 *  Created by Wayne Lovely on 6/20/13.
 *  Copyright (c) 2013 Wayne Lovely. All rights reserved.
 *
 * header file for list.c
 */

/*
 * just some defines
 */
#define NAME_MAX_SIZE     50
#define ADDRESS1_MAX_SIZE 50
#define ADDRESS2_MAX_SIZE 50
#define CITY_MAX_SIZE     30
#define STATE_MAX_SIZE     3
#define ZIP_MAX_SIZE      10


#define EMPTY_ENTRY -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * entry - main container for data, we will build a linked list
 */
struct entry {
  char name[NAME_MAX_SIZE];
  char address1[ADDRESS1_MAX_SIZE];
  char address2[ADDRESS2_MAX_SIZE];
  char city[CITY_MAX_SIZE];
  char state[STATE_MAX_SIZE];
  char zip[ZIP_MAX_SIZE];

  struct entry *prev;
  struct entry *next;
};

// pointers to the start and end of the list
struct entry *head;
struct entry *tail;

// make an entry "object" with some data
struct entry *new_entry( char *name, char *address1, char *address2, char *city, char *state, char *zip );

// list all of the entries in memory
void list_entries();

// wipe the list from memory, still have to commit the change to the database to stick
void delete_list();

// pretty format an address book entry
void print_entry(struct entry *this_entry);

// find the first occurance of an entry based on field/value match
struct entry *retrieve_entry( char * field, char * value );

// debugging for searching through list
void search_entries( char * field, char * value );

// add an entry in memory
int add_entry_to_list( struct entry *entry_to_add );

// remove an entry from memory
void delete_entry(struct entry *e);

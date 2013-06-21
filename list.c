/*
 *
 *  Created by Wayne Lovely on 6/20/13.
 *  Copyright (c) 2013 Wayne Lovely. All rights reserved.
 *
 *  Routines for managing an linked list
 */


#include "list.h"

/*
 * new_entry - allocate memory for an entry given inputs
 */
struct entry *new_entry( char *name, char *address1, char *address2, char *city, char *state, char *zip ) {

  struct entry *fresh_entry;

  fresh_entry = malloc( sizeof( struct entry ) );

  if ( !fresh_entry ) {
    printf("Problem allocating entry\n");
    exit(EXIT_FAILURE);
  }

  memset( fresh_entry, 0, sizeof( struct entry ) );

  strncpy( fresh_entry->name,     name,     NAME_MAX_SIZE );
  strncpy( fresh_entry->address1, address1, ADDRESS1_MAX_SIZE );
  strncpy( fresh_entry->address2, address2, ADDRESS2_MAX_SIZE );
  strncpy( fresh_entry->city,     city,     CITY_MAX_SIZE );
  strncpy( fresh_entry->state,    state,    STATE_MAX_SIZE );
  strncpy( fresh_entry->zip,      zip,      ZIP_MAX_SIZE );

  return( fresh_entry );
}


/*
 * list_entries - print out all the entries in the list
 */
void list_entries() {

  struct entry *current=head;

  if (!current) {
    printf("\nNOTICE: The list is empty\n");
    return;
  }

  printf("\nAddresses in memory:\n");

  while (current) {
    print_entry(current);
    current = current->next;
  }

}

/*
 * delete_list - wipe out all entries
 */
void delete_list() {

  struct entry *current=head;

  if (!head) {
    printf("\nNOTICE: The list is empty\n");
    return;
  }

  while (head) {
    head = current->next;

    if (current) {
      free(current);
    }

    current = head;
  }

  tail = head;

}

/*
 * print_entry - pretty format an entry in the list
 */
void print_entry(struct entry *this_entry) {

  printf("\n");
  printf("NAME           : %s\n", this_entry->name);
  printf("ADDRESS1       : %s\n", this_entry->address1);
  printf("ADDRESS2       : %s\n", this_entry->address2);
  printf("CITY,STATE,ZIP : %s,%s,%s\n\n", this_entry->city, this_entry->state, this_entry->zip);

}

/*
 * retrieve_entry - just return the first entry in which the name matches
 */
struct entry *retrieve_entry( char * field, char * value ) {

  struct entry *current=head;

  while (current) {

    if ( (!strncmp(field, "name", 4)) && 
         (!strncmp(current->name, value, NAME_MAX_SIZE)) ) {
      return current;
    }

    if ( (!strncmp(field, "address1", 8)) && 
         (!strncmp(current->address1, value, ADDRESS1_MAX_SIZE)) ) {
      return current;
    }

    if ( (!strncmp(field, "address2", 8)) && 
         (!strncmp(current->address2, value, ADDRESS2_MAX_SIZE)) ) {
      return current;
    }

    if ( (!strncmp(field, "city", 4)) && 
         (!strncmp(current->city, value, CITY_MAX_SIZE)) ) {
      return current;
    }

    if ( (!strncmp(field, "state", 5)) && 
         (!strncmp(current->state, value, STATE_MAX_SIZE)) ) {
      return current;
    }

    if ( (!strncmp(field, "zip", 3)) && 
         (!strncmp(current->zip, value, ZIP_MAX_SIZE)) ) {
      return current;
    }

    current = current->next;
  }

  // return NULL if we fall of the end of the list
  return current;
}


/*
 * search_entries - debug function,print out first entry meeting field/value criteria
 */
void search_entries( char * field, char * value ) {

  struct entry *current=head;

  while (current) {

    if ( (!strncmp(field, "name", 4)) && 
         (!strncmp(current->name, value, NAME_MAX_SIZE)) ) {
      print_entry(current);
    }

    if ( (!strncmp(field, "address1", 8)) && 
         (!strncmp(current->address1, value, ADDRESS1_MAX_SIZE)) ) {
      print_entry(current);
    }

    if ( (!strncmp(field, "address2", 8)) && 
         (!strncmp(current->address2, value, ADDRESS2_MAX_SIZE)) ) {
      print_entry(current);
    }

    if ( (!strncmp(field, "city", 4)) && 
         (!strncmp(current->city, value, CITY_MAX_SIZE)) ) {
      print_entry(current);
    }

    if ( (!strncmp(field, "state", 5)) && 
         (!strncmp(current->state, value, STATE_MAX_SIZE)) ) {
      print_entry(current);
    }

    if ( (!strncmp(field, "zip", 3)) && 
         (!strncmp(current->zip, value, ZIP_MAX_SIZE)) ) {
      print_entry(current);
    }

    current = current->next;
  }


}

/*
 * add_entry_to_list - given an entry, add it the end of the list and move the tail pointer
 *                     if it's the only entry, also make it the head and tail
 */
int add_entry_to_list( struct entry *entry_to_add ) {

  struct entry *current;

  if (!entry_to_add) {
    printf("\nNOTICE: empty entry was passed in\n");
    return EMPTY_ENTRY;
  }

  if (!head) {
    tail = head = entry_to_add;
    tail->prev = NULL;
    tail->next = NULL;
  } else {

    // set up prev & next on new entry then move tail to the new end of list
    entry_to_add->prev = tail;
    tail->next = entry_to_add;
    tail = tail->next;
    tail->next = NULL;

  }

  return 0;
}

/*
 * delete_entry - fix up the pointers to cut the specified entry out of the list, 
 * then free the memory for this entry
 */
void delete_entry(struct entry *e) {

  struct entry *current=head;

  while (current) {

    if ( current == e ) {

      if ( e == head ) {
        head = e->next;
      }

      if ( e == tail ) {
        tail = e->prev;
      }

      if ( e->prev ) {
        e->prev->next = e->next;
      }

      if ( e->next ) {
        e->next->prev = e->prev;
      }

      printf("\nRemoving first entry with name of '%s'\n", e->name);
      free(e);

      break;
    }

    current = current->next;
  }


}


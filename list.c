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

  printf( "incoming state = %s\n", state );

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

  while (current) {
    printf("name on this node = %s\n", current->name);
    current = current->next;
  }

}

/*
 * print_entry
 *
 */
void print_entry(struct entry *this_entry) {

  printf("NAME           : %s\n", this_entry->name);
  printf("ADDRESS1       : %s\n", this_entry->address1);
  printf("ADDRESS2       : %s\n", this_entry->address2);
  printf("CITY,STATE,ZIP : %s,%s,%s\n\n", this_entry->city, this_entry->state, this_entry->zip);

}

/*
 * search_entries
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
    return EMPTY_ENTRY;
  }

  if (!head) {
    tail = head = entry_to_add;
    tail->prev = NULL;
    tail->next = NULL;
  } else {

    printf("we had a head node, append to list and move tail pointer\n");

    // set up prev & next on new entry then move tail to the new end of list
    entry_to_add->prev = tail;
    tail->next = entry_to_add;
    tail = tail->next;
    tail->next = NULL;

  }

  return 0;
}

void enter_address() {

  struct entry *fresh_entry;

  char name[NAME_MAX_SIZE];
  char address1[ADDRESS1_MAX_SIZE];
  char address2[ADDRESS2_MAX_SIZE];
  char city[CITY_MAX_SIZE];
  char state[STATE_MAX_SIZE];
  char zip[ZIP_MAX_SIZE];

  printf("Enter Name:");
  gets(name);

  printf("Enter Address1:");
  gets(address1);

  printf("Enter Address2:");
  gets(address2);

  printf("Enter City:");
  gets(city);

  printf("Enter State:");
  gets(state);

  printf("Enter Zip:");
  gets(zip);

  fresh_entry = new_entry(name, address1, address2, city, state, zip);
  add_entry_to_list(fresh_entry);

}


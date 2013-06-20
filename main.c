/*
 * A demo program in C for company X
 *
 * We wish to do a few things:
 *
 *   1. interact with the user on the command line
 *   2. create/remove/update/delete entries from a data structure
 *   3. persist that data structure to db tables
 *   4. load the data structure into memory from db tables
 *
 */

#include "list.h"

void run_menu();
void enter_address();


int main() {

  struct entry *set[10];

  struct entry *e = new_entry("Wayne Lovely", "123 W Main St", "", "Kalamazoo", "MI", "49007");

  tail = head = e;

  printf("name = %s\n", e->name);
  printf("state = %s\n", e->state);

  add_entry_to_list(e);

  list_entries();

  printf("Adding some entries\n");

  set[0] = new_entry("A A", "111 W Main St", "", "Kalamazoo", "MI", "49007");
  set[1] = new_entry("B B", "111 W Main St", "", "Kalamazoo", "MI", "49007");
  set[2] = new_entry("C C", "222 W Main St", "", "Kalamazoo", "MI", "49007");
  set[3] = new_entry("D D", "333 W Main St", "", "Kalamazoo", "MI", "49007");
  set[4] = new_entry("E E", "444 W Main St", "", "Kalamazoo", "MI", "49007");
  set[5] = new_entry("F F", "555 W Main St", "", "Kalamazoo", "MI", "49007");
  set[6] = new_entry("G G", "666 W Main St", "", "Kalamazoo", "MI", "49007");
  set[7] = new_entry("H H", "777 W Main St", "", "Kalamazoo", "MI", "49007");
  set[8] = new_entry("I I", "888 W Main St", "", "Kalamazoo", "MI", "49007");
  set[9] = new_entry("J J", "999 W Main St", "", "Kalamazoo", "MI", "49007");

  add_entry_to_list(set[0]);
  add_entry_to_list(set[1]);
  add_entry_to_list(set[2]);
  add_entry_to_list(set[3]);
  add_entry_to_list(set[4]);
  add_entry_to_list(set[5]);
  add_entry_to_list(set[6]);
  add_entry_to_list(set[7]);
  add_entry_to_list(set[8]);
  add_entry_to_list(set[9]);

  list_entries();

  printf("Search against address for '666 W Main St'\n");
  search_entries( "address1", "666 W Main St" );

  delete_entry( head );

  list_entries();

  // enter_address();

  list_entries();

  run_menu();

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

void run_menu() {

  int run = 1;
  
  char choice[10];

  printf("\nPlease enter a choice:\n");
  printf("1) List Addresses\n");
  printf("2) Enter Address\n");
  printf("3) Delete Address\n");
  printf("4) Quit\n");

  while (run) {

    gets(choice);

    if ( strncmp( choice, "1", 1 ) == 0 ) {
      list_entries();
    } else if ( strncmp( choice, "2", 1 ) == 0 ) {
      enter_address();
    } else if ( strncmp( choice, "3", 1 ) == 0 ) {
      printf("Chose 3\n");
    } else if ( strncmp( choice, "4", 1 ) == 0 ) {
      run = 0;
    } else {
      printf("Invalid choice\n");
    }

    if (run) {
      printf("\nPlease enter a choice:\n");
      printf("1) List Addresses\n");
      printf("2) Enter Address\n");
      printf("3) Delete Address\n");
      printf("4) Quit\n");
    }
    
  }

}

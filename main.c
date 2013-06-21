/*
 * A demo program in C for company X
 *
 * We wish to do a few things:
 *
 *   1. interact with the user on the command line
 *   2. create/remove/update/delete entries from a data structure
 *   3. persist that data structure to db tables
 *   4. load the data structure into memory from db table
 *
 */

#include "list.h"

char db_host[50];
char db_username[50];
char db_password[50];
char db_name[50];

void run_menu();
void enter_address();


int main(int argc, char *argv[]) {

  tail = head = NULL;

  if ( argc != 5 ) {
    printf("Usage: main DBHOST DBUSER DBPASS DATABASE\n");
    exit(-1);
  }

  strcpy( db_host,     argv[1] );
  strcpy( db_username, argv[2] );
  strcpy( db_password, argv[3] );
  strcpy( db_name,     argv[4] );

  dbconnect();

  run_menu();

  dbdisconnect();

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
  char name[50];
  struct entry *entry_to_delete;

  memset( choice, 0, 10 );
  memset( name,   0, 50 );

  printf("\nPlease enter a choice:\n");
  printf("1) List Addresses\n");
  printf("2) Enter Address\n");
  printf("3) Delete Address\n");
  printf("4) Wipe List from Memory\n");
  printf("5) Load List from Database\n");
  printf("6) Store List to Database\n");
  printf("7) Quit\n");

  while (run) {

    gets(choice);

    if ( strncmp( choice, "1", 1 ) == 0 ) {
      list_entries();
    } else if ( strncmp( choice, "2", 1 ) == 0 ) {
      enter_address();
    } else if ( strncmp( choice, "3", 1 ) == 0 ) {

      printf("Enter a name to delete from the list: ");
      gets(name);
      entry_to_delete = retrieve_entry( "name", name );
      delete_entry(entry_to_delete);

    } else if ( strncmp( choice, "4", 1 ) == 0 ) {
      delete_list();
    } else if ( strncmp( choice, "5", 1 ) == 0 ) {
      hydrate();
    } else if ( strncmp( choice, "6", 1 ) == 0 ) {
      persist();
    } else if ( strncmp( choice, "7", 1 ) == 0 ) {
      run = 0;
    } else {
      printf("Invalid choice\n");
    }

    if (run) {
      printf("\nPlease enter a choice:\n");
      printf("1) List Addresses\n");
      printf("2) Enter Address\n");
      printf("3) Delete Address\n");
      printf("4) Wipe List from Memory\n");
      printf("5) Load List from Database\n");
      printf("6) Store List to Database\n");
      printf("7) Quit\n");
    }
    
  }

}

/*
 *  Created by Wayne Lovely on 6/20/13.
 *  Copyright (c) 2013 Wayne Lovely. All rights reserved.
 *
 *  Adapting code from the docs for the MySQL C client library
 */

#include "dbclient.h"

/*
 * dbconnect - build the context for talking to mysql
 */
void dbconnect() {
  mysql_init(&mysql);
  mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"main");
  if (!mysql_real_connect(&mysql, db_host, db_username, db_password, db_name,0,NULL,0))
  {
    fprintf(stderr, "Failed to connect to database: Error: %s\n",
    mysql_error(&mysql));
  }
}

// dbdisconnect - close the connect and free the memory for the connection variable
void dbdisconnect() {
  // close out the connection
  mysql_close(&mysql);
}


/*
 * persist - save the list in memory to the database
 */
void persist() {

  struct entry *current=head;
  char query[1000],*end;

  memset( query, 0, 1000 );


  strcpy( query, "truncate table entries" );
  if (mysql_real_query(&mysql,query, strlen(query)))
  {
    fprintf(stderr, "Failed to run query, Error: %s\n",
    mysql_error(&mysql));
  }


  while (current) {
    memset( query, 0, 1000 );

    end = (char *)strmov(query,"INSERT INTO entries values(");

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->name,strlen(current->name));
    *end++ = '\'';
    *end++ = ',';

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->address1,strlen(current->address1));
    *end++ = '\'';
    *end++ = ',';

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->address2,strlen(current->address2));
    *end++ = '\'';
    *end++ = ',';

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->city,strlen(current->city));
    *end++ = '\'';
    *end++ = ',';

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->state,strlen(current->state));
    *end++ = '\'';
    *end++ = ',';

    *end++ = '\'';
    end += mysql_real_escape_string(&mysql, end,current->zip,strlen(current->zip));
    *end++ = '\'';
    *end++ = ')';

    if (mysql_real_query(&mysql,query,(unsigned int) (end - query)))
    {
      fprintf(stderr, "Failed to insert row, Error: %s\n",
      mysql_error(&mysql));
    }

    current = current->next;
  }

}

/*
 * hydrate - pull list from database table and create list in memory
 */
void hydrate() {

  MYSQL_RES *result;
  MYSQL_ROW row;
  unsigned int num_fields;
  unsigned int num_rows;
  unsigned int i;
  char query[1000];

  struct entry * entry_rec;


  delete_list();

  memset(query, 0, 1000);

  strcpy( query, "select * from entries order by name" );

  //printf("query = %s\n", query);

  if (mysql_query(&mysql,query))
  {
    fprintf(stderr, "Failed to run query, Error: %s\n", mysql_error(&mysql));
  }
  else // query succeeded, process any data returned by it
  {
    result = mysql_store_result(&mysql);
    if (result)  // there are rows
    {
        num_fields = mysql_num_fields(result);
        // retrieve rows, then call mysql_free_result(result)

        while ((row = mysql_fetch_row(result))) {
          entry_rec = new_entry(row[0], row[1], row[2], row[3], row[4], row[5]);
          add_entry_to_list(entry_rec);
        }

        mysql_free_result(result);
    }
    else  // mysql_store_result() returned nothing; should it have?
    {
        if(mysql_field_count(&mysql) == 0)
        {
            // query does not return data
            // (it was not a SELECT)
            num_rows = mysql_affected_rows(&mysql);
        }
        else // mysql_store_result() should have returned data
        {
            fprintf(stderr, "Error: %s\n", mysql_error(&mysql));
        }
    }

    if (!head) {
      printf("\nNOTICE: The database was empty, nothing restored\n");
    }

  }


}


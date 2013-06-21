/*
 * Adapting code from the docs for the MySQL C client library
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <m_string.h>
#include "list.h"

extern char db_host[50];
extern char db_username[50];
extern char db_password[50];
extern char db_name[50];

// context for talking to MySQL, this is opaque so you usually have to get a reference to it
MYSQL mysql;


void dbconnect();

void dbdisconnect();

void persist();

void hydrate();


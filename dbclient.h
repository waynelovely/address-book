/*
 *
 *  Created by Wayne Lovely on 6/20/13.
 *  Copyright (c) 2013 Wayne Lovely. All rights reserved.
 *
 *  Adapting code from the docs for the MySQL C client library
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <m_string.h>
#include "list.h"

// these are defined in main.c
extern char db_host[50];
extern char db_username[50];
extern char db_password[50];
extern char db_name[50];

// context for talking to MySQL, this is opaque so you usually have to get a reference to it
MYSQL mysql;

// connect to db
void dbconnect();

// disconnect from db
void dbdisconnect();

// truncate table then save data from memory into database table
void persist();

// wipe list in memory then load list from database table into memory
void hydrate();


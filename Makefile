
all:
	@echo ""
	@echo "To build and run, perform one set of commands:"
	@echo ""
	@echo "make nodb; ./main"
	@echo ""
	@echo "OR"
	@echo ""
	@echo "make dbsupport; ./main DBHOST DBUSER DBPASS DATABASE"
	@echo "(requires mysql client dev and a mysql database with addressbook.sql loaded and privs set)"
	@echo ""

nodb:
	cc -o main main.c list.c 

dbsupport:
	cc -o main main.c list.c dbclient.c `mysql_config --libs` `mysql_config --cflags` -DDBSUPPORT

clean:
	rm -f main


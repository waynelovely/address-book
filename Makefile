
all:
	gcc -o main main.c list.c dbclient.c `mysql_config --libs` `mysql_config --cflags`

dbclient:

	gcc -o dbclient dbclient.c list.c `mysql_config --libs` `mysql_config --cflags`

clean:
	rm main


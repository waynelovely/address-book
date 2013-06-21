address-book
============

A console-based address book.

Two build options.  

A simpler version for just running the in-memory linked list manager

and 

optional support for MySQL persistence of the list in memory.


Pretty simple, uses gets().  One change that should be made is to swap out gets() for something that is safe from buffer overflows.

Maybe a custom gets() that uses fgets() to hit STDIN for N bytes.

This is just a quick demo to demonstrate pointer usage in C.



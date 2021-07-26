# Socket server 1

A nearly useless shell of a server!

This program is designed to be a very simple baseline to start building a server around. It operates like a simple echo server, sending back whatever data it receives. It will perform `accept()`/`recv()`/`send()` for the first incoming connection, then closes all resources gracefully.

# Socket server 1

A nearly useless shell of a server!

This program is designed to be a very simple baseline to start building a server around. It operates like a simple echo server, sending back whatever data it receives. This server does not handle connections concurrently, a single client may connect at a time, the server will receive up to 1024 bytes of data in a single `recv()` call then echo the payload back to the client and close the connection. The server should run until receiving a `SIGINT` and then terminate cleanly with no leaks or dangling file handlers.

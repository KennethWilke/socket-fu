/* stdio for:
    printf
    fprintf
    stderr
*/
#include <stdio.h>

/* stdlib for:
    malloc
    free
*/
#include <stdlib.h>

/* netdb for:
    getaddrinfo
    freeaddrinfo
    gai_strerror
*/
#include <netdb.h>

/* errno for:
    errno
*/
#include <errno.h>

/* string for:
    strerror
*/
#include <string.h>

/* unistd for:
    close
*/
#include <unistd.h>

typedef enum {
    ERROR,
    LISTENING
} ListenSocketState;


typedef struct {
    ListenSocketState state;
    int socket;
    struct addrinfo *address;
} ListenSocket;

ListenSocket* ListenSocket_new(char *node, char *service);
void ListenSocket_free(ListenSocket* sock);
int ListenSocket_process(ListenSocket* sock);

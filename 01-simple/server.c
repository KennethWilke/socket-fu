#include "server.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <port>\n", argv[0]);
        return 1;
    }

    char *node = argv[1];
    char *service = argv[2];

    printf("Creating listening socket on %s:%s...\n", node, service);
    ListenSocket *listen = ListenSocket_new(node, service);
    if (!listen) {
        fprintf(stderr, "Failed to create listening socket, closing...\n");
        return 1;
    }

    int running = 1;
    while (running) {
        running = ListenSocket_process(listen);
    }

    ListenSocket_free(listen);
}


ListenSocket* ListenSocket_new(char *node, char* service) {
    ListenSocket *new = malloc(sizeof(*new));
    int error = getaddrinfo(node, service, NULL, &(new->address));
    if (error) {
        fprintf(stderr, "%s\n", gai_strerror(error));
        goto rollback_malloc;
    }

    new->socket = socket(new->address->ai_family,
                         new->address->ai_socktype,
                         new->address->ai_protocol);
    if (new->socket == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        goto rollback_resolution;
    }
    
    if (bind(new->socket,
             new->address->ai_addr,
             new->address->ai_addrlen) == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        goto rollback_socket;
    }

    if (listen(new->socket, 10) == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        goto rollback_socket;
    }

    new->state = LISTENING;
    return new;

rollback_socket:
    close(new->socket);
rollback_resolution:
    freeaddrinfo(new->address);
rollback_malloc:
    free(new);
    return NULL;
}


void ListenSocket_free(ListenSocket* sock) {
    if (sock) {
        if (sock->socket < 0) {
            close(sock->socket);
        }
        if (sock->address) {
            freeaddrinfo(sock->address);
        }
        free(sock);
    }
}

int ListenSocket_process(ListenSocket* sock) {
    struct sockaddr client_address;
    socklen_t addrlen = sizeof(client_address);
    int client = accept(sock->socket, &client_address, &addrlen);
    if (client == -1) {
        fprintf(stderr, "Error accepting client connection: %s\n",
                strerror(errno));
        return 0;
    }
    printf("Client connected>\n");

    char buffer[1024];
    ssize_t recvlen = recv(client, buffer, 1024, 0);
    printf("Received %ld bytes\n", recvlen); 
    send(client, buffer, recvlen, 0);
    close(client);
    return 0;
}

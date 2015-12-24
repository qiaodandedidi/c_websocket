#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_EVENTS 1024;

int main(void)
{
    char *ip = '127.0.0.1';
    int sock = socket(PF_INET, SOCK_STREAM & SOCK_NOBLOCK, 0);
    
    assert(sock > 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    inet_pton(AF_INET, ip, &addr.sin_addr);
    
    int ret = bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    assert(ret != -1);
    
    ret  = listen(sock, 5);
    assert(ret != -1);

    epoll_event evnets[MAX_EVENTS];
    int epollfd = epoll_create(5);

    
}

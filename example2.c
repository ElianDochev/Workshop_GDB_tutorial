#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define MEMORY_SIZE 10 // maybe this is the cause of the corruption/segfault
#define MAP_ANONYMOUS 0x20 // gotten from /usr/include/x86_64-linux-gnu/bits/mman-linux.h
#define CURRENT_PROCESS_FD -1
#define NO_OFFSET 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void corruptMemory(char *buffer) {
    // Writing beyond the allocated memory
    memcpy(buffer, "Hello, GDB!", 12);
}

int main() {
    char *buffer = (char *)malloc(18);

    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    void *addr = buffer;
    // Initialize the buffer
    strcpy(buffer, "Hello");

    // free the allocated memory
    free(buffer);

    // Allocate a new memory of the same address (Dont freak out, this for demo purposes only)
    buffer = (char *)mmap(addr, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, CURRENT_PROCESS_FD, NO_OFFSET);

    // Call a function that corrupts memory
    corruptMemory(buffer);

    // Accessing the corrupted memory
    printf("Buffer contents: %s\n", buffer);

    // Free the allocated memory
    munmap(buffer, MEMORY_SIZE);

    return 0;
}

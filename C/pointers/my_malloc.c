#include <stddef.h>

#define HEAP_SIZE 1024 * 1024 // 1 MB
static unsigned char my_heap[HEAP_SIZE];

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

static Block *free_list = (void*)my_heap;

void init_malloc() {
    free_list->size = HEAP_SIZE - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;
}

void* my_malloc(size_t size) {
    Block *curr = free_list;
    
    // Simple "First-Fit" search
    while (curr) {
        if (curr->free && curr->size >= size) {
            // Split the block if it's much larger than needed
            if (curr->size > size + sizeof(Block)) {
                Block *new_block = (void*)((char*)curr + sizeof(Block) + size);
                new_block->size = curr->size - size - sizeof(Block);
                new_block->free = 1;
                new_block->next = curr->next;
                
                curr->size = size;
                curr->next = new_block;
            }
            curr->free = 0;
            return (void*)(curr + 1); // Return pointer to memory after metadata
        }
        curr = curr->next;
    }
    return NULL; // Out of memory
}

void my_free(void* ptr) {
    if (!ptr) return;
    Block* block = (Block*)ptr - 1; // Move back to find the metadata
    block->free = 1;
    // Ideally, you would "coalesce" (merge) adjacent free blocks here to avoid fragmentation
}

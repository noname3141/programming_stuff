#include <stdio.h>
#include "Arena.h"

#define SIZE 200

void arena_init(Arena* arena){
    arena->start = malloc(SIZE*sizeof(char));
    arena->offset = 0;
    arena->size = SIZE;
}

void arena_grow(Arena* arena){
    char* ptr = realloc(arena->start, 2*arena->size*sizeof(char)); //reallocing twice the size of the original size
    if(!ptr) return; //if realloc fails
    arena->size *= 2;
    arena->start = ptr;
}

void arena_free(Arena* arena){
    if(arena == NULL) return;
    if(arena->start != NULL){
        free(arena->start);
        arena->start = NULL;
    }
}

void arena_reset(Arena* arena){
    arena->offset = 0;
}

int arena_offset(Arena* arena, int alignment){
    int misalign = arena->offset % alignment;
    if(misalign == 0) return arena->offset;
    return arena->offset + (alignment - misalign);
}

void* arena_alloc(Arena* arena, int size, int alignment){
    int arenaoffset = arena_offset(arena, alignment);
    while(arenaoffset + size > arena->size){
        arena_grow(arena);
        if(arena->start == NULL) return NULL;
    }
    char* buf = arena->start + arenaoffset;
    arena->offset = arenaoffset + size;
    return buf;
}

int arena_mark(Arena* arena){
    int mark = arena->offset;
    return mark;
}

void arena_release(Arena* arena,int mark){
    arena->offset = mark;
}

//Dummy implementation

int main(){
    Arena arena;
    arena_init(&arena);
    int* a = ARENA_PUSH(&arena, int, 1);       // aligned to 4 bytes
    double* d = ARENA_PUSH(&arena, double, 1); // aligned to 8 bytes
    //using all the implemented functions to simulate an arena
    *a = 10;
    *d = 20;
    int c = *a + *d;
    printf("%d + %f = %d\n", *a, *d, c);
    arena_reset(&arena);
    arena_free(&arena);
    return c;
}

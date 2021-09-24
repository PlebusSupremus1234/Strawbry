#ifndef sby_chunk_h
#define sby_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_POP,
    OP_JUMP,

    // Types
    OP_NULL,
    OP_TRUE,
    OP_FALSE,
    
    // Operators
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    
    // Comparisons
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,

    // Unary
    OP_NOT,
    OP_NEGATE,

    // Variables
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,

    // Loops
    OP_LOOP,
    OP_JUMP_IF_FALSE,
    
    // Functions
    OP_PRINT,
    OP_RETURN,
    OP_CALL,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,

    // Classes
    OP_CLASS,
    OP_METHOD,
    OP_GET_PROPERTY,
    OP_SET_PROPERTY,
    OP_INVOKE,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
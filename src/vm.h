#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "table.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Chunk *chunk;
  // ip always points to the next instruction
  uint8_t *ip; // instruction pointer (program counter)
  Value stack[STACK_MAX];
  // stackTop always points to where the next value to be pushed will go
  // stackTop = 0 means the stack is empty
  Value *stackTop;
  Table strings;
  Obj *objects;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

#endif

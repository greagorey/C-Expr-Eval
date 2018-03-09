#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "istack.h"

Node_t* nodeCreate(int value) {
    Node_t* node = malloc(sizeof(Node_t));
    node->data = value;
    node->next = NULL;
    return node;
}

IntStack_t istackCreate( )
{
   Node_t* dummy = nodeCreate(INT_MIN);
   IntStack_t stack = {dummy};
   
}

bool istackIsEmpty( IntStack_t stack )
{
  if(stack.head == NULL)
  {
      return true;
  }
}

int istackPush( IntStack_t *stack, int item)
{
    Node_t* newNode = nodeCreate(item);
    
    if(stack->head == NULL)
    {
        newNode->next = NULL;
        stack->head = newNode;
    }
    else
    {
        newNode->next = stack->head;
        stack->head = newNode;
    }
}


void istackPrint( IntStack_t stack  )
{
    Node_t* cur;
    cur = stack.head;
    
    if(stack.head == NULL)
    {
        printf("  Empy stack  \n");
    }
    else
    {
        while(cur->next != NULL)
        {
            printf(" %d \n",cur->data);
            cur = cur->next;
            
        }
    }
    
}
int istackPop( IntStack_t *stack )
{
    Node_t* cur;
    cur = stack->head;
    int a = cur->data;
    
    if(stack->head == NULL)
    {
        printf("  No  ");
    }
    else{
        stack->head = cur->next;
        free(cur);
    }
    return a;
}

int istackTop( IntStack_t stack )
{
    Node_t* cur = stack.head;
    return cur->data;
    
    
}

void istackDestroy( IntStack_t *stack )
{
    Node_t* cur;
    cur = stack->head;
    
    while(cur->next != NULL)
    {
        stack->head = cur->next;
        free(cur);
        cur = stack->head;
    }
}
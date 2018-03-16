#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "istack.h"

Node2_t* Node2Create(int value) {
    Node2_t* Node2 = malloc(sizeof(Node2_t));
    Node2->data = value;
    Node2->next = NULL;
    return Node2;
}

IntStack_t istackCreate( )
{
   Node2_t* dummy = Node2Create(INT_MIN);
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
    Node2_t* newNode2 = Node2Create(item);
    
    if(stack->head == NULL)
    {
        newNode2->next = NULL;
        stack->head = newNode2;
    }
    else
    {
        newNode2->next = stack->head;
        stack->head = newNode2;
    }
}


void istackPrint( IntStack_t stack  )
{
    Node2_t* cur;
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
    Node2_t* cur;
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
    Node2_t* cur = stack.head;
    return cur->data;
    
    
}

void istackDestroy( IntStack_t *stack )
{
    Node2_t* cur;
    cur = stack->head;
    
    while(cur->next != NULL)
    {
        stack->head = cur->next;
        free(cur);
        cur = stack->head;
    }
}
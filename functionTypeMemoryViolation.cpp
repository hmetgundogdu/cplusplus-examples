#include <iostream>
#include <pthread.h>

typedef void* (*Executer)(void*);

struct ProcessReq
{
  Executer func;
};

void* executerFunction (void * data)
{
    
};

void *task(void* pr)
{
  ProcessReq* prs = (ProcessReq*)(intptr_t*)pr;  
    int i = 999999;
    while(--i)
    {
    
        prs->func(nullptr);          
        
    };

};

int main ()
{
  
  ProcessReq *d1,*d2;
  
  d1 = new ProcessReq;
  d1->func = &executerFunction;
  
  
  d2 = new ProcessReq;
  d2->func = &executerFunction;
  
  pthread_t t1,t2;
  
  pthread_create(&t1, NULL, task, (void*)(intptr_t*)d1);
  pthread_create(&t2, NULL, task, (void*)(intptr_t*)d2);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  std::cout << d1 << std::endl << d2 << std::endl;
  
  return 0;
  
};

#include <xinu.h>
#include <future.h>

uint future_prod(future_t* fut, char* value) {
	  int* nptr = (int*) value;
	  future_set(fut, value);
	  kprintf("Produced %d\n", *nptr);
	  return OK;
}

uint future_cons(future_t* fut) {
	  int i, status;
	  status = (int) future_get(fut, (char*) &i);
	  if (status < 1) {
	     kprintf("future_get failed\n");
	     return -1;
	 }
	  kprintf("Consumed %d\n", i);
	  return OK;
}

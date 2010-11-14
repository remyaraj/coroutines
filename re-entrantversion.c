//Re-entrant version of co-routine
#include <stdio.h>
#include <stdlib.h>

#define ccrContParam void **ccrParam

#define ccrBeginContext struct ccrContextTag { int ccrLine

#define ccrEndContext(x) } *x = *ccrParam

#define ccrBegin(x) if(!x) {x= *ccrParam=malloc(sizeof(*x)); x->ccrLine=0;}\
                    if (x) switch(x->ccrLine) { case 0:;

#define ccrFinish(z) } free(*ccrParam); *ccrParam=0; return (z)
#define ccrFinishV  } free(*ccrParam); *ccrParam=0; return

#define ccrReturn(z) \
        do {\
            ((struct ccrContextTag *)*ccrParam)->ccrLine=__LINE__;\
            return (z); case __LINE__:;\
        } while (0)

#define ccrReturnV \
        do {\
            ((struct ccrContextTag *)*ccrParam)->ccrLine=__LINE__;\
            return; case __LINE__:;\
        } while (0)

#define ccrContext void *


int ascending (ccrContParam) {
    ccrBeginContext;
    int i;
    ccrEndContext(foo);
    ccrBegin(foo);
	for (foo->i=0; foo->i<10; foo->i++) {
       ccrReturn(foo->i);
	}
	   ccrFinish(-1);
}


void main(void) {
 	ccrContext z = 0;
    do {
       printf("got number %d\n", ascending (&z));
    } while (z);
}

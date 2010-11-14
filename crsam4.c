#include <stdio.h>

#define crBegin static int state=0; switch(state) { case 0:
#define crReturn(x) do { state=__LINE__; return x; \
                         case __LINE__:; } while (0)
#define crFinish }

int function(void) {
    static int i;
    crBegin;
    for (i = 0; i < 10; i++)
        crReturn(i);
    crFinish
	return 0;
}

main()
{
   	int j;
	for(j=0;j<10;j++){
		printf("%d\t",function());
	}
}

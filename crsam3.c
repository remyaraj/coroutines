#include <stdio.h>

#define crBegin static int state=0; switch(state) { case 0:
#define crReturn(i,x) do { state=i; return x; case i:; } while (0)
#define crFinish state=0; }

int function(void) {
    static int i;
    crBegin;
    for (i = 0; i < 6; i++)
        crReturn(1, i);
    crFinish;
	return 0;
}

main()
{
   	int j;
	for(j=0;j<10;j++){
		printf("%d\t",function());
	}
}

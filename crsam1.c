//#include <stdio.h>

int function()
{
	static int i,state=0;
	switch(state){
		case 0:
		for(i=0;i<10;i++){
			state=1;
			return i;
			case 1:;	
		}
	}
}

main()
{
	int j;
	for(j=0;j<10;j++){
		printf("%d\t",j+function());
	}
}


#include <stdio.h>

int	__real_main(int argc, char *argv[]);

int	__wrap_main(int argc, char *argv[])
{
	printf("Hello wrap\n");
	return (__real_main(argc, argv));
}

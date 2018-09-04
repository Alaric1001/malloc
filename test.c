#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
int main()
{
	struct stat stats;

	stat("Makefile", &stats);
	char* c = group_from_gid(stats.st_gid, 0);
	(void)c;
	return (0);
} 

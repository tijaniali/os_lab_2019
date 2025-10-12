#include "revert_string.h"
#include <string.h>
#include <stddef.h>

void RevertString(char *str)
{
	if (str == NULL) return;

	size_t len = strlen(str);
	if (len < 2) return;

	char *l = str;
	char *r = str + len - 1;
	while (l < r) {
		char tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}


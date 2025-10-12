#include "swap.h"
#include <stddef.h>

void Swap(char *left, char *right)
{
	/* Safety: ignore NULL pointers */
	if (left == NULL || right == NULL) return;

	char tmp = *left;
	*left = *right;
	*right = tmp;
}

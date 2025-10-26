#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* show address macro uses %p for pointer printing */
#define SHW_ADR(ID, I) (printf("ID %s\t is at virtual address: %p\n", ID, (void *)&(I)))

/* etext/edata/end may be provided by the linker; provide weak fallbacks if missing */
extern char etext, edata, end; /* Global symbols for process memory */
#if defined(__APPLE__)
/* On macOS these symbols may not be exported; provide weak aliases to avoid link errors */
__attribute__((weak)) char etext;
__attribute__((weak)) char edata;
__attribute__((weak)) char end;
#endif
char *cptr = "This message is output by the function showit()\n";
char buffer1[25];
void showit(const char *p);

int main(void) {
    int i = 0;

    printf("\nAddress etext: %p\n", (void *)&etext);
    printf("Address edata: %p\n", (void *)&edata);
    printf("Address end  : %p\n", (void *)&end);

    SHW_ADR("main", main);
    SHW_ADR("showit", showit);
    SHW_ADR("cptr", cptr);
    SHW_ADR("buffer1", buffer1);
    SHW_ADR("i", i);
    strcpy(buffer1, "A demonstration\n");
    write(1, buffer1, strlen(buffer1));
    showit(cptr);

    return 0;
}

void showit(const char *p)
{
    char *buffer2;
    SHW_ADR("buffer2", buffer2);
    buffer2 = malloc(strlen(p) + 1);
    if (buffer2 != NULL) {
        printf("Allocated memory at %p\n", (void *)buffer2);
        strcpy(buffer2, p);
        printf("%s", buffer2);
        free(buffer2);
    } else {
        printf("Allocation error\n");
        exit(1);
    }
}

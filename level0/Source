#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int val;

    /* If no argument is provided, just exit */
    if (argc < 2) {
        return 0;
    }

    /* Parse the first argument as an integer */
    val = atoi(argv[1]);

    /* Compare against the “magic” constant 423 (0x1a7) */
    if (val == 423) {
        /* strdup the literal "/bin/sh" */
        char *shell = strdup("/bin/sh");
        if (!shell) {
            perror("strdup");
            return 1;
        }

        /* Drop privileges to the real EUID/EGID (level1) */
        uid_t euid = geteuid();
        gid_t egid = getegid();
        setresgid(egid, egid, egid);
        setresuid(euid, euid, euid);

        /* Build argv for execv */
        char *const args[] = { shell, NULL };

        /* Execute /bin/sh (with EUID=level1) */
        execv(shell, args);

        /* If execv fails */
        perror("execv");
        return 1;
    }
    else {
        /* Wrong argument path: write 5 bytes from a static buffer */
        const char wrong_msg[5] = { 'N','o',' ','!','\n' };
        fwrite(wrong_msg, 1, 5, stdout);
    }

    return 0;
}

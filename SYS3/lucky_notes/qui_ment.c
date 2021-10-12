#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    printf("Qui ment?\n");
    pid = fork(); //Clone le process
    if (pid == 0) {
        // C'est le fils
        system("ps ajx | tail -n 7");
        exit(0);
    }
    
    // Ici les deux process vont effectuer le code suivant:
    
    system("ps ajx | tail -n 7");
    printf("Je suis %d et je viens de faire un fork!", getpid());
    
    // RAX <-- n° fork
    // RAX du père: pid du fils
    // RAX du fils: 0
    exit(0);
}
//
// Created by chen on 11/24/19.
//
#include "user.h"

struct cmd {
    int type;
};

void generate_pipes(struct cmd *cmd) {
    int p[10][2];
    pcmd = (struct pipecmd *) cmd;
    for (int i = 0; i < 10; ++i) {
        if (pipe(p[i]) < 0)
            panic("pipe");
    }
    //Input End for the pipe
    if (fork() == 0) {
        close(1);
        dup(p[0][1]);
        close(p[0][0]);
        close(p[0][1]);
        runcmd(pcmd->left);
    }

    for (int j = 1; j < 9; ++j) {
        if (fork() == 0) {
            close(0);
            dup(p[j][1]);
            close(1);
            dup(p[j][0]);
            close(p[j][0]);
            close(p[j][1]);
        }
    }

    //Output End for the pipe
    if (fork() == 0) {
        close(0);
        dup(p[9][0]);
        close(p[9][0]);
        close(p[9][1]);
        runcmd(pcmd->right);
    }
    for (int k = 0; k < 10; ++k) {
        close(p[k][0]);
        close(p[k][1]);
        wait();
        wait();
    }
}

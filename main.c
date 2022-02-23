#include "2cc.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "引数の個数が正しくありません\n");
        return 1;
    }

    user_input = argv[1];
    token = token_head = tokenize(argv[1]);
    Node *node = expr();

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    gen(node);

    printf("    pop rax\n");
    printf("    ret\n");

    // printf("    mov rax, %d\n", expect_number());

    // while (!at_eof()) {
    //     if (consume('+')) {
    //         printf("    add rax, %d\n", expect_number());
    //         continue;
    //     }

    //     expect('-');
    //     printf("    sub rax, %d\n", expect_number());
    // }

    // printf("    ret\n");
    return 0;
}
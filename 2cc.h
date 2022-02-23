#ifndef _2CC_H_
#define _2CC_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#define TEST_PRINT(...) printf(__VA_ARGS__)
#define DBG() {\
    printf("%s(%d) @ %s\n",\
        __func__, __LINE__, __FILE__);\
}

typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef struct Token Token;

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_NUM,
} NodeKind;

typedef struct Node Node;

struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;
};

struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
};

Token *token;
Token *token_head;
char *user_input;

Node *primary();
Node *mul();
Node *expr();

bool at_eof();
void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
Node *new_node(NodeKind kind, Node *lhs, Node *rhs);
Node *new_node_num(int val);
bool consume(char op);
int expect_number();
void expect(char op);
Token *new_token(TokenKind kind, Token *cur, char *str);
Token *tokenize(char *p);
Node *primary();
Node *mul();
Node *expr();
void gen(Node *node);

#endif //_2CC_H

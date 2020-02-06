#include <stdio.h>

#define N 10

typedef struct Node* link;

typedef struct Node{
    int value;
    link left;
    link right;
}Node;

void print_tree(Node tree[N], link t) {
    if (t->left != NULL) print_tree(tree, t->left);
    printf("%d ", t->value);
    if (t->right != NULL) print_tree(tree, t->right);
}

int main(int argc, char** argv) {
    int vec[N];
    for (int i = 0;i < N;++i) {
        printf("%d:", i+1);
        scanf("%d", &vec[i]);
    }
    Node tree[N];
    for (int i = 0;i < N;++i) {
        tree[i].value = vec[i];
        tree[i].left = NULL;
        tree[i].right = NULL;
    }

    link start = &tree[0];

    for (int i = 1;i < N;++i) {
        for (link now = start;now != NULL;) {
            if ((now->value) < (tree[i].value)) {
                if (now->right == NULL) {
                    now->right = &tree[i];
                    break;
                } else {
                    now = now->right;
                }
            } else {
                if (now->left == NULL) {
                    now->left = &tree[i];
                    break;
                } else {
                    now = now->left;
                }
            }
        }
    }

    print_tree(tree, start);
    printf("\n");

}

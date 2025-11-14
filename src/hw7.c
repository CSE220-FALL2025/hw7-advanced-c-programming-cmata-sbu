#include "hw7.h"

// My Helper Functions
int precedence(char c) {
    switch(c) {
        case '+': return 1;
        case '*':  return 2;
        default: return -1;
    }
}
inline void push(char* op_stack, int* top, char c) {
    op_stack[++(*top)] = c;
}
inline char pop(char* op_stack, int* top) {
    return op_stack[(*top)--];
}
// END My Helper Functions

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {
    return NULL;
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
    return NULL;
}

void free_bst_sf(bst_sf *root) {
    free(root->mat);
    free(root->left_child);
    free(root->right_child);
}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
    return NULL;
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {
   return NULL;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {
    return NULL;
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
    return NULL;
}

char* infix2postfix_sf(char *infix) {
    int len = strlen(infix);
    if (len > MAX_LINE_LEN) return NULL;

    char* result = malloc(len + 1);
    int pos = 0;
    char op_stack[len];
    int top = -1;
    const char* infix_ro = infix; // forces read only

    while (*infix_ro != '\0') {
        char c = *infix_ro;

        if (c == ' ' || c == '\n') {
            infix_ro++;
            continue;
        }

        // If the character is an operand or the transpose operator, append it to the result
        if ((c >= 'A' && c <= 'Z') || c == '\'') result[pos++] = c;
        // If the character is '(' push it to the stack
        else if (c == '(') push(op_stack, &top, c);
        else if(c == ')') {
            // dump the stack onto result
            while (top != -1 && op_stack[top] != '(') {
                result[pos++] = pop(op_stack, &top);
            }
            
            // pop the opening parenthesis
            (void)pop(op_stack, &top);
        }
        else { // This is an operator which is not '(' or ')'
            while (top != -1 && op_stack[top] != '(' && (precedence(op_stack[top]) > precedence(c) || (precedence(op_stack[top]) == precedence(c)))) {
                result[pos++] = pop(op_stack, &top);
            }
            push(op_stack, &top, c);
        }

        infix_ro++;
    }

    // Pop any remaining operators
    while (top != -1) {
        result[pos++] = pop(op_stack, &top);
    }

    result[pos] = '\0';
    return result;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    return NULL;
}

matrix_sf *execute_script_sf(char *filename) {
   return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}

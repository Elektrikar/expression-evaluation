#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double calculate(const char *expression) {
    int top_idx = -1;
    double values[100];
    char prev_token = '\n';
    int sign = 1;

    while (*expression != '\0') {
        char temp = *expression;
        
        if (temp == ' ') {
            expression++;
            continue;
        }

        if (temp >= '0' && temp <= '9') {
            char *endptr;

            values[++top_idx] = sign * strtod(expression, &endptr);
            sign = 1;
            
            // Update main expression pointer to where the double ended
            expression = endptr;

            prev_token = 'n';

            continue;
        }

        switch (temp) {
        case '-':
            if (prev_token == 'n' || prev_token == ')') {
                // TODO: subtraction logic
            } else {
                sign = -1;
            }

            prev_token = '-';
            break;
        
        default:
            break;
        }
        
        expression++;
    }

    return values[1];
}


int main() {
    int n = 0;
    scanf("%d", &n);

    while (getchar() != '\n');

    for (int i = 0; i < n; i++) {
        char expression[256];
        if (fgets(expression, sizeof(expression), stdin) == NULL) {
            break;
        }
        
        // strip trailing newline from expression
        size_t len = strlen(expression);
        if (len > 0 && expression[len-1] == '\n') {
            expression[len-1] = '\0';
        }

        printf("%s\n", expression);
        printf("%g\n\n", calculate(expression));
    }
    return 0;
}
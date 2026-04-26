#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);
    int count[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        if (count[s[i] - 'a'] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
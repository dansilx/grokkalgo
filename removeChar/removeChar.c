#include <stdio.h>
#include <string.h>

void remove_url(char *url) {
    for (int i = 0; url[i] != '\0'; i++) {
        if (url[i] == '#') {
            url[i] = '\0';
            break;
        }
    }
}

int main() {
    char url1[] = "www.codewars.com#about";
    char url2[] = "www.codewars.com?page=1";

    remove_url(url1);
    remove_url(url2);

    printf("%s\n", url1);
    printf("%s\n", url2);
}
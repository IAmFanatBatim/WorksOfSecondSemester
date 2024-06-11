#include <assert.h>
#include <signal.h>
#include "libs\data_structures\vector\vector.c"
#include "libs\data_structures\vectorVoid\vectorVoid.c"
#include "libs\data_structures\matrix\matrix.c"

#include "libs\data_structures\string\string_.c"
#include "libs\data_structures\string\string_.h"

int keep_enter = 1;

void enter(int sig) {
    keep_enter = 0;
}

int main() {
    signal(SIGINT, enter);

    char *read_pointer = _stringBuffer;
    char cur_char;

    while(keep_enter) {
        cur_char = getchar();
        if (!keep_enter) {
            break;
        }
        *read_pointer = cur_char;
        read_pointer++;
    }

    *read_pointer = '\0';

    getBagOfWords(&_bag, _stringBuffer);

    Glossarium gloss;
    gloss.amount_of_words = 0;

    sortBagOfWords(&_bag);
    getGlossBySortedBag(&_bag, &gloss);
    printGloss(gloss);

    return 0;
}

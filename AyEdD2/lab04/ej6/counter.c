#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c=NULL;
    c = malloc(sizeof (counter));
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count=c->count+1;
}

bool counter_is_init(counter c) {
    return (c->count == 0);
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count - 1;
}

counter counter_copy(counter c) {
    counter count2;
    count2 = c;
    return count2;
}

void counter_destroy(counter c) {
    free(c);
    c=NULL;
}

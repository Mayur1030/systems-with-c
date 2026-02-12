#include <stdlib.h>
#include "midterm.h"


ll_int *ll_remove_duplicates(ll_int *head) {
    ll_int *curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->value == curr->next->value) {
            ll_int *dup = curr->next;
            curr->next = dup->next;
            free(dup);
        } else {
            curr = curr->next;
        }
    }

    return head;
}


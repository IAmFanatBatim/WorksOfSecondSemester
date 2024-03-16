#include "bitset.h"
#include <stdio.h>
#include <assert.h>

bitset bitset_create (unsigned maxValue) {
    assert(maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_in (bitset set, unsigned int value) {
    return set.values & 1 << value;
}

bool bitset_isEqual (bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset (bitset subset, bitset set) {
    return set.values == (set.values | subset.values);
}

void bitset_insert (bitset *set, unsigned int value) {
    set->values = set->values | 1 << value;
}

void bitset_deleteElement (bitset *set, unsigned int value) {
    set->values = set->values & ~(1 << value);
}

bitset bitset_union (bitset set1, bitset set2) {
    bitset result;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    result.values = set1.values | set2.values;
    return result;
}

bitset bitset_intersection (bitset set1, bitset set2) {
    bitset result;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    result.values = set1.values & set2.values;
    return result;
}

bitset bitset_difference (bitset set1, bitset set2) {
    bitset result;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    result.values = set1.values & ~set2.values;
    return result;
}

bitset bitset_symmetricDifference (bitset set1, bitset set2) {
    bitset result;
    result.maxValue = (set1.maxValue > set2.maxValue) ? set1.maxValue : set2.maxValue;
    result.values = set1.values ^ set2.values;
    return result;
}

bitset bitset_complement (bitset set) {
    bitset result;
    result.maxValue = set.maxValue;
    int unused_bits = set.maxValue;
    int copy_set_values = set.values;
    while (copy_set_values > 0) {
        unused_bits--;
        copy_set_values >>= 1;
    }
    result.values = (~(set.values) << unused_bits) >> unused_bits;
    return result;
}

void bitset_print (bitset set) {
    printf ("{");
    if (set.values == 0) {
        printf("}\n");
    } else {
        for (int i = 0; i <= set.maxValue; ++ i) {
            if (bitset_in(set, i)) {
                printf("%d, ", i);
            }
        }
        printf("\b\b}\n");
    }
}

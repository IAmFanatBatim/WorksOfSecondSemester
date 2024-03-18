#ifndef INC_UNORDERED_ARRAY_SET_C
#define INC_UNORDERED_ARRAY_SET_C

#include "unordered_array_set.h"
#include "C:\Users\Анна\Desktop\сонины программы\second_semester\WorksOfSecondSemester\libs\algorithms\array\array.h"

unordered_array_set unordered_array_set_create (size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array (const int *a, size_t size) {
    unordered_array_set result = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++) {
        unordered_array_set_insert(&result, a[i]);
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
}

static void unordered_array_set_shrinkToFit (unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

static void unordered_array_set_increaseCapacity (unordered_array_set *a, size_t slots) {
    a->data = (int *) realloc(a->data, sizeof(int) * (a->size + slots));
    a->capacity += slots;
}


size_t unordered_array_set_in (unordered_array_set set, int value) {
    return linearSearch_(set.data, set.size, value);
}

bool unordered_array_set_isSubset (unordered_array_set subset, unordered_array_set set) {
    bool is_subset = 1;
    for (size_t i = 0; i < subset.size; i++) {
        if (unordered_array_set_in(set, subset.data[i]) == set.size) {
            is_subset = 0;
            break;
        }
    }
    return is_subset;
}

bool unordered_array_set_isEqual (unordered_array_set set1, unordered_array_set set2) {
    return unordered_array_set_isSubset(set1, set2) && set1.size == set2.size;
}

void unordered_array_set_isAbleAppend (unordered_array_set *set) {
    assert((set->size) < (set->capacity));
}

void unordered_array_set_insert (unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &(set->size), value);
    }
}

void unordered_array_set_deleteElement (unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) != set->size) {
        deleteByPosUnsaveOrder_ (set->data, &(set->size), unordered_array_set_in (*set, value));
    }
}

unordered_array_set unordered_array_set_union (unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.capacity + set2.capacity);
    for (int set1_index = 0; set1_index < set1.size; set1_index++) {
        unordered_array_set_insert(&result, set1.data[set1_index]);
    }
    for (int set2_index = 0; set2_index < set2.size; set2_index++) {
        unordered_array_set_insert(&result, set2.data[set2_index]);
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
}

unordered_array_set unordered_array_set_intersection (unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.capacity);
    for (int set1_index = 0; set1_index < set1.size; set1_index++) {
        if (unordered_array_set_in(set2, set1.data[set1_index]) < set2.size) {
            unordered_array_set_insert(&result, set1.data[set1_index]);
        }
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
}

unordered_array_set unordered_array_set_difference (unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.capacity);
    for (int set1_index = 0; set1_index < set1.size; set1_index++) {
        if (unordered_array_set_in(set2, set1.data[set1_index]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[set1_index]);
        }
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
}

unordered_array_set unordered_array_set_complement (unordered_array_set set, unordered_array_set universumSet){
    return unordered_array_set_difference(universumSet, set);
}

unordered_array_set unordered_array_set_symmetricDifference (unordered_array_set set1, unordered_array_set set2){
    unordered_array_set result = unordered_array_set_create(set1.capacity + set2.capacity);
    for (int set1_index = 0; set1_index < set1.size; set1_index++) {
        if (unordered_array_set_in(set2, set1.data[set1_index]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[set1_index]);
        }
    }
    for (int set2_index = 0; set2_index < set2.size; set2_index++) {
        if (unordered_array_set_in(set1, set2.data[set2_index]) == set1.size) {
            unordered_array_set_insert(&result, set2.data[set2_index]);
        }
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
}

void unordered_array_set_print (unordered_array_set set) {
    outputArray_(set.data, set.size);
}

void unordered_array_set_delete (unordered_array_set *set) {
    free(set->data);
    set->size = 0;
    set->capacity = 0;
}

#endif
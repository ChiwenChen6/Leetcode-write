/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

struct NestedIterator {
    int *a, i, n;
};

#define is_int(...) NestedIntegerIsInteger(__VA_ARGS__)
#define gi(...)     NestedIntegerGetInteger(__VA_ARGS__)
#define gl(...)     NestedIntegerGetList(__VA_ARGS__)
#define glsz(...)   NestedIntegerGetListSize(__VA_ARGS__)

void *fl(void** nl, int sz, struct NestedIterator *ni) {
    if (sz > 0) {
        if (is_int(*nl))
            ni->a[ni->n++] = gi(*nl);
        else
            fl(gl(*nl), glsz(*nl), ni);
        fl(++nl, --sz, ni);
    }
    return ni;
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *ni = calloc(1, sizeof *ni);
    ni->a = calloc(1, sizeof(int [100000]));
    return fl((void **)nestedList, nestedListSize, ni);
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->i < iter->n;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->a[iter->i++];
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->a), free(iter);
}



/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */




// Status: Accepted
// Runtime: 8 ms
// Memory Usage: 14.8 MB

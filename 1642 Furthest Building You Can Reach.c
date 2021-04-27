typedef struct node_t {
    int a;
} node_t;
typedef node_t heap_elem_t; // 元素的類型

/**
 * @struct
 * @brief 堆的結構體
 */
typedef struct heap_t {
    int size;                                             /* * 實際元素個數 */
    int capacity;                                         /* * 容量，以元素為單位 */
    heap_elem_t *elems;                                   /* * 堆的陣列 */
    int (*cmp)(const heap_elem_t *, const heap_elem_t *); /* * 元素的比較函數 */
} heap_t;

/* 基本類型（如int, long, float, double）的比較函數，小根堆 */
int cmp_int(const heap_elem_t *x, const heap_elem_t *y)
{
    node_t *p = x;
    node_t *q = y;
    return p->a - q->a;
}

/**
 * @brief 創建堆.
 * @param[out] capacity 初始容量
 * @param[in] cmp cmp 比較函數，小於返回-1，等於返回0
 * 大於返回1，反過來則是大根堆
 * @return 成功返回堆對象的指標，失敗返回NULL
 */
heap_t *heap_create(const int capacity, int (*cmp)(const heap_elem_t *, const heap_elem_t *))
{
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->size = 0;
    h->capacity = capacity;
    h->elems = (heap_elem_t *)malloc(capacity * sizeof(heap_elem_t));
    h->cmp = cmp;
    return h;
}
/**
 * @brief 銷毀堆.
 * @param[inout] h 堆對象的指標
 * @return 無
 */
void heap_destroy(heap_t *h)
{
    free(h->elems);
    free(h);
}
/**
 * @brief 判斷堆是否為空.
 * @param[in] h 堆對象的指標
 * @return 是空，返回1，否則返回0
 */
int heap_empty(const heap_t *h)
{
    return h->size == 0;
}
/**
 * @brief 獲取元素個數.
 * @param[in] s 堆對象的指標
 * @return 元素個數
 */
int heap_size(const heap_t *h)
{
    return h->size;
}
/*
 * @brief 小根堆的自上向下篩選演算法.
 * @param[in] h 堆對象的指標
 * @param[in] start 開始結點
 * @return 無
 */
void heap_sift_down(const heap_t *h, const int start)
{
    int i = start;
    int j;
    const heap_elem_t tmp = h->elems[start];
    for (j = 2 * i + 1; j < h->size; j = 2 * j + 1) {
        if (j < (h->size - 1) &&
            h->cmp(&(h->elems[j]), &(h->elems[j + 1])) > 0) {
            j++; /* j 指向兩子女中小者 */
        }
        if (h->cmp(&tmp, &(h->elems[j])) <= 0) {
            break;
        } else {
            h->elems[i] = h->elems[j];
            i = j;
        }
    }
    h->elems[i] = tmp;
}
/*
 * @brief 小根堆的自下向上篩選演算法.
 * @param[in] h 堆對象的指標
 * @param[in] start 開始結點
 * @return 無
 */
void heap_sift_up(const heap_t *h, const int start)
{
    int j = start;
    int i = (j - 1) / 2;
    const heap_elem_t tmp = h->elems[start];
    while (j > 0) {
        if (h->cmp(&(h->elems[i]), &tmp) <= 0) {
            break;
        } else {
            h->elems[j] = h->elems[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    h->elems[j] = tmp;
}
/**
 * @brief 添加一個元素.
 * @param[in] h 堆對象的指標
 * @param[in] x 要添加的元素
 * @return 無
 */
void heap_push(heap_t *h, const heap_elem_t x)
{
    if (h->size == h->capacity) { /* 已滿，重新分配記憶體 */
        heap_elem_t *tmp = (heap_elem_t *)malloc(h->capacity * 2 * sizeof(heap_elem_t));
        h->elems = tmp;
        h->capacity *= 2;
    }
    h->elems[h->size] = x;
    h->size++;
    heap_sift_up(h, h->size - 1);
}
/**
 * @brief 彈出堆頂元素.
 * @param[in] h 堆對象的指標
 * @return 無
 */
void heap_pop(heap_t *h)
{
    h->elems[0] = h->elems[h->size - 1];
    h->size--;
    heap_sift_down(h, 0);
}
/**
 * @brief 獲取堆頂元素.
 * @param[in] h 堆對象的指標
 * @return 堆頂元素
 */
heap_elem_t heap_top(const heap_t *h)
{
    return h->elems[0];
}

int furthestBuilding(int *heights, int heightsSize, int bricks, int ladders)
{
    int i;
    heap_t *h;
    node_t tmp, tmp_top;
    int brick_cnt = 0;

    // 梯子個數為0的特殊場景，只考慮磚塊累加
    if (ladders == 0) {
        for (i = 0; i < heightsSize - 1; i++) {
            // 如果當前高度比後一個小，需要磚塊
            if (heights[i] < heights[i + 1]) {
                brick_cnt += heights[i + 1] - heights[i];
                // 貪心，如果當前已使用磚塊大於總磚塊個數，停止進一步迴圈
                if (brick_cnt > bricks) {
                    break;
                }
            }
        }
    } else {  // 梯子個數不為0的場景
        // 創建一個大小為ladders的小根堆
        h = heap_create(ladders, cmp_int);
        for (i = 0; i < heightsSize - 1; i++) {
            if (heights[i] < heights[i + 1]) {
                tmp.a = heights[i + 1] - heights[i];
                // 如果堆未滿，則直接push進堆
                if (heap_size(h) != ladders) {
                    heap_push(h, tmp);
                } else { // 如果堆已滿
                    tmp_top = heap_top(h);
                    // 當前值和堆頂元素比，如果比堆頂元素大，則貪心當前值使用梯子，堆頂使用磚塊，將堆頂計入磚塊累加
                    // 然後彈出堆頂，將當前值push進堆
                    if (tmp.a > tmp_top.a) {
                        brick_cnt += tmp_top.a;
                        heap_pop(h);
                        heap_push(h, tmp);
                    } else {
                        brick_cnt += tmp.a; // 如果當前值比堆頂元素小，貪心使用磚塊
                    }
                    // 如果當前已使用磚塊大於總磚塊個數，停止進一步迴圈
                    if (brick_cnt > bricks) {
                        break;
                    }
                }
            }
        }
        heap_destroy(h);
    }

    return i;
}
// Accepted	80 ms	12.8 MB	

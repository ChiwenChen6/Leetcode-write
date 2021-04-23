
int max(int a,int b)
{
    return a>b ? a:b;
}

struct node{
    int key;
    int val;
    struct node *next;
};

struct table{
    int size;
    struct node **list;
};

struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}

int hashCode(struct table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}

int insert(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key == key){
            temp->val++;
            return temp->val;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = 1;
    newNode->next = list;
    t->list[pos] = newNode;
    return 1;
}

int leastBricks(int** wall, int wallSize, int* wallColSize){
    struct table *t = createTable(1000);
    int num;
    int Max = 0;
    for(int i=0; i < wallSize; i++)
    {
        num = 0;
        for(int j=0;j<wallColSize[i]-1;j++)
        {
            num += wall[i][j];
            Max = max(insert(t,num),Max);
            if(Max == wallSize)
                return 0;
        }
    }
    return wallSize - Max;
}

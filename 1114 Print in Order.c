typedef struct {
    // User defined data may be declared here.
    volatile bool a;
    volatile bool b;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    obj->a = obj->b = false;
    // Initialize user defined data here.
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj -> a = true;
}

void second(Foo* obj) {
   while(1)
   {
       if(obj->a == true)
       {
           break;
       }
   }
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->b = true;
}

void third(Foo* obj) {
 while(1)
   {
       if(obj->b == true)
       {
           break;
       }
   }    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    
    free(obj);
}

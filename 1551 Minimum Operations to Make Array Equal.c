
int minOperations(int n) {
  if(!n || n == 1){
    return 0;      
  }


  int first = 1; 
  int last = 2 * (n - 1) + 1;
  int avg = (last + first) / 2;
  int steps = 0;

  while(last > first){
    steps += avg - first;
    first += 2;
    last -= 2;
  }
  return steps;        
    
}

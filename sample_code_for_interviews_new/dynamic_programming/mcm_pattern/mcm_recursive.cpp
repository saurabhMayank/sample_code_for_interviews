// mcm recursive code

// input -> i and j pointers
// arr => elements containing matrix sizes

arr = [40, 20, 30, 10, 30]

int i = 1;
int j = n-1;

int mcm_recursive(int i , int j , vector<int> arr){
  
  if(i>=j){
    return 0;
  }
  
  // The GOAL -> is to find cost of each partition and then find minimum from it
  // when 1 loop iteration completes, cost of 1 paritition
  // For Loop changes the parititions with every iteration
  
  // In every iteration 
  // To calculate the temp_ans => i.e. cost of multiplying matrix using that partition
  
  // There are recursion calls
  // which give the result of a portion of temp_ans
  // mcm_recursive(i, k, arr) -> 1 recursion call, mcm_recursive(k + 1, j, arr) -> 2nd recursion call
  
  // Inn recursion calls ke lie -> wapis se function call hoga
  // Jo Inka result hoga wo ek portion ka result hoga temp_ans ka
  
  // Both the portions ke result aa jaaenge toh hme unhe add karke and (arr[i - 1] * arr[k] * arr[j]) add karke => temp_ans compute kar lenge
  // Joki -> for k=1 partition ke lie -> Aise hi baaki valid partitions ke lie temp_ans compute hoga
  
  // Ab min -> jo variable hain -> wo mcm_recursive function ke andar initialise hoga na ki Globally
  // Iska reason hain ki
  // Har Iteration ke baad jo cost aaya, usse compare karke min value store karwaao
  
  // But agar hm -> min variable ko globally declare kar denge -> toh recursive functions mein jo temp_ans nikaalta hain
  // joki ek portion ka result hain -> wo jaake global min mein store ho jaaega
  // wo poore partition ka result nahin hain -> sirf ek portion ka hain.
  // toh wrong min value store hone lagega
  
  // But if we intialise min inside mcm_recursive function before the loop then 
  // for loop ke ek iteration ke baad jo temp_ans hoga wo min mein store ho jaaega
  // that min will be stored and use to compare temp_ans in the 2nd iteration of for loop and so on.
  
   
  
  
  
   int min = Integer.MAX_VALUE;
  for(int k =i; k<=j-1; ++k){
    int temp_ans = mcm_recursive(i, k, arr) + mcm_recursive(k + 1, j, arr) + (arr[i - 1] * arr[k] * arr[j]);
    if (min > tempAns)
        min = tempAns;
     }
     return min;
  }
}


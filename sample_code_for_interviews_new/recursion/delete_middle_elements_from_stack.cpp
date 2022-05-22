

void delete_middle_element(vector<int> &st, int middle_index, int count){
  if(st.size() == 0){
    return st;
  } 
  int last_ele = st[st.size()-1];
//   vector<int> new_st = st;
//   new_st.pop_back();
  st.pop_back();
  count++;
  delete_middle_element(st, middle_index, count);
  
  if(count != middle_index){
    st.push_back(last_ele);
    count--;
  }
    
}


int main(){
  
  vector<int> st = {1, 2, 3, 4, 5};
  delete_middle_element(st, st.size()/2, 0);
}

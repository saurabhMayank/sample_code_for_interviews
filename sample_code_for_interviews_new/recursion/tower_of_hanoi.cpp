void Hanoi(int m, string start, string middle, string end){
    cout << "m is equal to: " << m << endl;
    if(m == 1){
        cout << "Move Disc " << " from " << start << "  to " << end << endl;
        return;
    }
    else{
        Hanoi(m-1,start,end,middle);
        cout << "Move disc " << m << " from " << start << " to " << end << endl;
        Hanoi(m-1,middle,start,end);
    }
}
int main(){
    int discs = 3;
    Hanoi(discs, "start","middle","end");

}

// If told to calculcate no of steps then
// to find that
// also pass a count variable in the hanoi function that is initialized to 0
// Jitne baar hanoi function call hoga utne baar count++ kar denge..
// intialize count = 0; and whenever Hanoi function is called
// at it on the top just do count++

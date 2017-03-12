

//keeps track of the total number of decrement operations in countdown_at_idx

int count = 0;


//counts down the integer value stored at the index idx of ptr until 0
//if idx odd: counted down by 1 in each step
//if idx even: counted down by 2
void countdown_at_idx(int* ptr, int idx){

    //even
    if(*(ptr+idx)%2 == 0){
        while(*(ptr+idx)!=0){
            *(ptr+idx) = *(ptr+idx) - 2;
            count = count + 1;
        }
    //odd
    }else if(*(ptr+idx)%2 != 0){
        while(*(ptr+idx)!=0){
            *(ptr+idx) = *(ptr+idx) - 1;
            count = count + 1;
        }
    }

}


//allocates memory for 20 integer values
//initializes that memory with increasing values 0,1,2...
//calls countdown_at_idx on each of the 20 values in memory --> all 20 values should be 0
//returns count as exit code
int main(){ //int argc, int* argv){
    int* array;
    int i;

    array = malloc(20*4);
    i = 0;
    while(i<20){
        *(array+i) = i;
        i = i + 1;
    }
    i = 0;
    while(i<20){
        countdown_at_idx(array, i);
        i = i + 1;
    }
    return count;
}




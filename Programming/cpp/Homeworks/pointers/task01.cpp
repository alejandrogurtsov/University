#include <iostream>
#include <ctime>
using namespace std;

int main(void){

    srand(time(NULL));

    int N = 10;
    int* p_arr = new int[N];

    cout<<"RAND_MAX = "<<RAND_MAX<<endl;
    cout<<"2^15-1 = "<<(1<<15)<<endl;

    int r_min=-50;
    int r_max=50;

    for(int i = 0; i<N; i++){
        *(p_arr + i) = r_min + rand() % (r_max - r_min + 1);
        cout<<"p_arr["<<i<<"] = "<< *(p_arr + i)<<endl;
    }

    int a_min=*(p_arr)= r_min + rand() % (r_max - r_min + 1);
    int c=0;
    for(int i = 1; i<N; i++){
        c = *(p_arr+i);
        if (c<a_min){
            a_min=c;
        }
    }
    cout<<a_min;

    return 0;
}
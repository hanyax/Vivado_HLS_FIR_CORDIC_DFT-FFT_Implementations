#include <iostream>

using namespace std;

void mul_test(int* out, int in);

int main(int argc, char *argv[]){
      int x=5;
      int y;
      mul_test(&y, x);
      if(y!=2*x){
              cout << "Test Failed: output(" << y << ") is not equal to 2x" << x << endl;
      }else{
              cout << "Test Passed" << endl;
      }
      return 0;
}

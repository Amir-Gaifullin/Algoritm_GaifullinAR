#include "fstream"
#include <iostream>
using namespace std;

int main(){ 
ofstream fout;
fout.open("test.txt");
for(int i = 0; i < 1000000; ++i){
    fout << i << endl;
    }
fout.close();
}
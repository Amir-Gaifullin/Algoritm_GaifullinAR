#include <iostream>
using namespace std; 
int main(){
    int cost, X;
    cout << "Число X равно:";
    cin >> X;
    int coins[] = {10, 5, 1};
    int change = X;
    int i = 0;
    int x10 = 0;
    int x5 = 0;
    int x1 = 0;
    int count = 0;
    while (change > 1){

        if (change / coins [i] != 0){
            change -= coins[i];
            count += 1;
            if (i == 0){
                x10 = count;
            }
            if (i == 1){
                x5 = count;
            }
            if (i == 2){
                x1 = count;
            }
        }else{
            ++i;
            count = 0;
        }

    }
            
            
    if (change == 1)
        x1 += 1;
    cout << x1 <<" "<< x5 <<" "<< x10<<std::endl;
    return 0;
}

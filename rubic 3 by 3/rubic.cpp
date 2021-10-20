#include<iostream>
#include"rubic.h"

using namespace std;


void Rubic::rotateArray270(int a[][3]){
    int n = 3;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n / 2; j += 1) {
            swap(a[i][j], a[n - 1 - i][j]);
        }
    }
}
void Rubic::rotateArray90(int a[][3]){
    int n = 3;
    for (int i = 0; i < n; i += 1) {
        for (int j = i + 1; j < n; j += 1) {
            swap(a[i][j], a[j][i]);
        }
    }
}






#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include <time.h>

using namespace std;

void rotateArray270(int a[][3]){
int n=3;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n/2; j += 1) {
            swap(a[i][j], a[n-1-i][j]);
        }
    }
}
void rotateArray90(int a[][3]){
int n=3;
    for (int i = 0; i < n; i += 1) {
        for (int j = i+1; j < n; j += 1) {
            swap(a[i][j], a[j][i]);
        }
    }
}


enum rubik {
    blue=1, red=2, white=3,orange=4 ,green=5,yellow=6
};

int main () {

    rubik mode;
    int a, b, c, d,e,f;
    srand(time(0));


    mode=blue;
    mode=white;
    mode=orange;
    mode=yellow;
    mode=red;
    mode=green;



    int face1[3][3];
    int face2[3][3];
    int face3[3][3];
    int face4[3][3];
    int face5[3][3];
    int face6[3][3];

    int help[3][3];

    ///full cube

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face1[i][j] = 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face2[i][j] = 2;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face3[i][j] = 3;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face4[i][j] = 4;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face5[i][j] = 5;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            face6[i][j] = 6;
    }


    a = rand() % 1000 + 250;
    cout << "the number of times you can move the rubiks cube : " << a << endl << endl;

    //all times of move
    cout << "the rotation in this program include :" << endl <<
         "1) rotate to the right in each row " << endl <<"2) rotate to the down in each row"<<endl<<
         "3) rotate to the left in each row "<<endl<<"4) rotate to the up in each row "<<
         endl;

    for (int i = 0; i < a; i++) {

        b = rand() % 4 + 1;

        if (b == 1) {

            d = rand() % 2 + 1;
            if (d == 1) { //1

                for (int j = 1; j < 4; j++) {
                    help[1][j] = face5[1][j];
                    face5[1][j] = face1[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face1[1][j] = face6[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face6[1][j] = face3[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face3[1][j] = help[1][j];
                }

                rotateArray270(face2);
            }


            if (d == 2) {//3
                for (int j = 1; j < 4; j++) {
                    help[3][j] = face5[3][j];
                    face5[3][j] = face1[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face1[3][j] = face6[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face6[3][j] = face3[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face3[3][j] = help[3][j];
                }

                rotateArray270(face4);
            }

        }


        if (b == 2) {
            c = rand() % 2 + 1;

            if (c == 1) { //1

                for (int i = 1; i < 4; i++) {
                    help[i][1] = face4[i][1];
                    face4[i][1] = face1[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face1[i][1] = face2[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face2[i][1] = face3[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face3[i][1] = help[i][1];
                }
                rotateArray90(face6);
            }


            if (c == 2)//3
                for (int i = 1; i < 4; i++) {
                    help[i][3] = face4[i][3];
                    face4[i][3] = face1[i][3];
                }
            for (int i = 1; i < 4; i++) {
                face1[i][3] = face2[i][3];
            }
            for (int i = 1; i < 4; i++) {
                face2[i][3] = face3[i][3];
            }
            for (int i = 1; i < 4; i++) {
                face3[i][3] = help[i][3];
            }
            rotateArray270(face5);
        }


        if (b == 3) {
            e = rand() % 2 + 1;

            if (e == 1) { //1

                for (int j = 1; j < 4; j++) {
                    help[1][j] = face6[1][j];
                    face6[1][j] = face1[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face1[1][j] = face5[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face5[1][j] = face3[1][j];
                }
                for (int j = 1; j < 4; j++) {
                    face3[1][j] = help[1][j];
                }

                rotateArray90(face2);
            }


            if (e == 2) {//3
                for (int j = 1; j < 4; j++) {
                    help[3][j] = face6[3][j];
                    face6[3][j] = face1[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face1[3][j] = face5[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face5[3][j] = face3[3][j];
                }
                for (int j = 1; j < 4; j++) {
                    face3[3][j] = help[3][j];
                }

                rotateArray270(face3);
            }

        }

        if (b == 4) {
            f = rand() % 2 + 1;

            if (f == 1) { //1

                for (int i = 1; i < 4; i++) {
                    help[i][1] = face2[i][1];
                    face2[i][1] = face1[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face1[i][1] = face4[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face4[i][1] = face3[i][1];
                }
                for (int i = 1; i < 4; i++) {
                    face3[i][1] = help[i][1];
                }
                rotateArray270(face5);
            }


            if (f == 2)//3
                for (int i = 1; i < 4; i++) {
                    help[i][3] = face4[i][3];
                    face4[i][3] = face1[i][3];
                }
            for (int i = 1; i < 4; i++) {
                face1[i][3] = face2[i][3];
            }
            for (int i = 1; i < 4; i++) {
                face2[i][3] = face3[i][3];
            }
            for (int i = 1; i < 4; i++) {
                face3[i][3] = help[i][3];
            }
            rotateArray90(face5);
        }


    }


    cout << endl << "*********************" << endl << endl << "the operation was done :" << endl;

    cout << "face 1 :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face1[i][j]==1)
                cout<<"blue"<<"\t";
            if( face1[i][j]==2)
                cout<<"red"<<"\t";
            if( face1[i][j]==3)
                cout<<"white"<<"\t";
            if( face1[i][j]==4)
                cout<<"orange"<<"\t";
            if( face1[i][j]==5)
                cout<<"green"<<"\t";
            if( face1[i][j]==6)
                cout<<"yellow"<<"\t";
        }
    cout << endl;
}

    cout<<endl << "face 2 :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face2[i][j]==1)
                cout<<"blue"<<"\t";
            if( face2[i][j]==2)
                cout<<"red"<<"\t";
            if( face2[i][j]==3)
                cout<<"white"<<"\t";
            if( face2[i][j]==4)
                cout<<"orange"<<"\t";
            if( face2[i][j]==5)
                cout<<"green"<<"\t";
            if( face2[i][j]==6)
                cout<<"yellow"<<"\t";
        }
        cout << endl;
    }

    cout<<endl << "face 3 :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face3[i][j]==1)
                cout<<"blue"<<"\t";
            if( face3[i][j]==2)
                cout<<"red"<<"\t";
            if( face3[i][j]==3)
                cout<<"white"<<"\t";
            if( face3[i][j]==4)
                cout<<"orange"<<"\t";
            if( face3[i][j]==5)
                cout<<"green"<<"\t";
            if( face3[i][j]==6)
                cout<<"yellow"<<"\t";
        }
        cout << endl;
    }

    cout<<endl << "face 4 :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face4[i][j]==1)
                cout<<"blue"<<"\t";
            if( face4[i][j]==2)
                cout<<"red"<<"\t";
            if( face4[i][j]==3)
                cout<<"white"<<"\t";
            if( face4[i][j]==4)
                cout<<"orange"<<"\t";
            if( face4[i][j]==5)
                cout<<"green"<<"\t";
            if( face4[i][j]==6)
                cout<<"yellow"<<"\t";
        }
        cout << endl;
    }

    cout<<endl << "face 5 :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face5[i][j]==1)
                cout<<"blue"<<"\t";
            if( face5[i][j]==2)
                cout<<"red"<<"\t";
            if( face5[i][j]==3)
                cout<<"white"<<"\t";
            if( face5[i][j]==4)
                cout<<"orange"<<"\t";
            if( face5[i][j]==5)
                cout<<"green"<<"\t";
            if( face5[i][j]==6)
                cout<<"yellow"<<"\t";
        }
        cout << endl;
    }

    cout<<endl << "face 6  :" << endl;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            if( face6[i][j]==1)
                cout<<"blue"<<"\t";
            if( face6[i][j]==2)
                cout<<"red"<<"\t";
            if( face6[i][j]==3)
                cout<<"white"<<"\t";
            if( face6[i][j]==4)
                cout<<"orange"<<"\t";
            if( face6[i][j]==5)
                cout<<"green"<<"\t";
            if( face6[i][j]==6)
                cout<<"yellow"<<"\t";
        }
        cout << endl;
    }
    cout<<endl << "this program was written by HEDIEH JAMILI , GOOD LUCK." << endl;


    system("pause");
    return 0;
}





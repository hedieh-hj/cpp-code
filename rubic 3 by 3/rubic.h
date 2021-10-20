#ifndef RUBIC_H
#define RUBIC_H


class Rubic {

public:

    Rubic(){
        int face1[3][3] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        int face2[3][3] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
        int face3[3][3] = { 3, 3, 3, 3, 3, 3, 3, 3, 3 };
        int face4[3][3] = { 4, 4, 4, 4, 4, 4, 4, 4, 4 };
        int face5[3][3] = { 5, 5, 5, 5, 5, 5, 5, 5, 5 };
        int face6[3][3] = { 6, 6, 6, 6, 6, 6, 6, 6, 6 };

    };

    ~Rubic();

    void rotateArray270(int a[][3]);
    void rotateArray90(int a[][3]);


private:
    int face1[3][3];
    int face2[3][3];
    int face3[3][3];
    int face4[3][3];
    int face5[3][3];
    int face6[3][3];

};

#endif //PROJECT_4_RUBIC_H

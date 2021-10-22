#include "dataset.h"
#include<ostream>
Dataset::Dataset()
{
}

Dataset::~Dataset()
{
    personFriends.~vector();
}
void Dataset::matrix(int &n , vector<vector<int>> &vec)
{
    int w, z;
    ifstream file("Text.txt");
    string temp, text;
    if (file.is_open())
    {
        getline(file, temp);
        text = temp;
        n = text.size();
    }
    else
    {
        cout << "I coudn't open file.";
    }
    file.close();

    ifstream filee("Text.txt");

    if (filee.is_open()) {
        for (int i = 0; i < n; i++) {
            getline(filee, temp);
            w = stoi(temp);
            vector<int> v1 , v2;
            for (int j = n - 1; j >= 0; j--) {
                z = w % 10;
                v1.push_back(z);
                w = w / 10;
            }
            for (int f = n-1; f >=0; f--) {
                v2.push_back(v1[f]);
            }
            vec.push_back(v2);
        }
    }
    
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    

}

void Dataset::personsConnection(int num, int name ) {
    ifstream file("Text.txt");
    string temp;
    int w{} , a ;
    vector<int> p , z , x;
    for (int i = 0; i <= name; i++) {
        if (file.is_open()) {
            getline(file, temp);
            if (i == name) {
                w = stoi(temp);
            }
        }
    }

    for (int j = num - 1; j >= 0; j--) {
        a = w % 10;
        z.push_back(a);
        w = w / 10;
    }
    for (int f = num - 1; f >= 0; f--) {
        x.push_back(z[f]);
    }
    int j = 0;
    for (int i = 0; i < num; i++) {
        if (x[i] == 1) {
            p.push_back(i) ;
            j++;
        }
    }
    personFriends.push_back(p);
    file.close();

}





void Dataset::personsConnection2(int num, int name) {
    ifstream file("f.txt");
    string temp;
    int w{}, a;
    vector<int> p, z, x;
    for (int i = 0; i <= name; i++) {
        if (file.is_open()) {
            getline(file, temp);
            if (i == name) {
                w = stoi(temp);
            }
        }
    }

    for (int j = num - 1; j >= 0; j--) {
        a = w % 10;
        z.push_back(a);
        w = w / 10;
    }
    for (int f = num - 1; f >= 0; f--) {
        x.push_back(z[f]);
    }
    int j = 0;
    for (int i = 0; i < num; i++) {
        if (x[i] == 1) {
            p.push_back(i);
            j++;
        }
    }
    personFriends.push_back(p);
    file.close();

}

void Dataset::vorodi(int& n, vector<vector<int>>& m)
{
    ofstream f1("f.txt", ios::trunc);
    if (f1.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            cout << "radif " << i + 1 << "om matrix ra vared konid:" << endl;
            vector<int>v;
            for (int j = 0; j < n; j++)
            {
                int t = 0, x = 0 , y = 0 ;
                while (x == 0)
                {
                    cout << "adad " << j + 1 << "om : ";
                    if (i == j) {
                        cout << "0\n";
                        t = 0;
                        f1 << t;
                        break;
                    }
                    else
                    {
                        cin >> t;
                    }
                    
                    while (y == 0)
                    {
                        if (t != 0 && t != 1) {
                            //int t1 = 0;
                            cout << "adad vared shode dorost nmibashad " << endl << "lotfan mojadd ada khod ra vared konid:" << endl;
                            cin >> t;
                            //t = t1;
                        }
                        else
                        {
                            y = 1;
                            f1 << t;
                            //break;
                        }
                    }
                    //f1 << t;
                    x = 1;
                    
                }
                x = 0;
                v.push_back(t);
            }
            if (i != n - 1) {
                f1 << endl;
            }
            m.push_back(v); 
        }
    }
    else
    {
        cout << "I coudn't open file.";
    }
    
    f1.close();
}

bool Dataset::chek(int& n, vector<vector<int>>& m)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != m[j][i]) {
                f = 1;
                break;
            }
        }
        if (f==1) {
            cout << "matris namotabar ; lotfan dobare adad vared konid ." << endl;
            ofstream f1("f.txt", ios::trunc);
            f1.close();
            m.clear();
            return false;
        }
    }

}

void Dataset::matrix2(int& n, vector<vector<int>>& m)
{
    cout << "tedad jame ra vared konid: " << endl;
    cin >> n;

    vorodi(n, m);

    while (!chek(n, m)) {
        vorodi(n, m);
    }
    system("cls");
    cout << "\n((( matrix ))\n" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}
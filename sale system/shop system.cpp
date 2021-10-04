#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

//product structure :
struct product {

    int product_code;
    string product_name;
    float product_price;
    int product_count;
    int code_seller;


};


//Seller structure :
struct seller {

    int seller_code;
    string seller_name;
    string seller_address;
    long int seller_phone;
    int code_product;
};


//shopper structure :
struct shopper {

    int shopper_code;
    string shopper_name;
    long int shopper_phone;
    int shopper_cash;

};

void search_product(product a[], int m, float price_from, float price_to) {
    for (int i = 0; i < m; i++) {
        if (a[i].product_price >= price_from && a[i].product_price <= price_to) {

            cout << "*** Product List[" << (i + 1) << "] ***" << endl;

            cout << "code  [" << (i + 1) << "] = " << a[i].product_code << endl;
            cout << "Name  [" << (i + 1) << "] = " << a[i].product_name << endl;
            cout << "Price  [" << (i + 1) << "] = " << a[i].product_price << endl;
            cout << "Count  [" << (i + 1) << "] = " << a[i].product_count << endl;
        } else {
            cout << "not found !" << endl;
        }
    }
}
void search_seller(seller b[], int n, int code) {
    for (int i = 0; i < n; i++) {
        if (code == b[i].code_product) {
            cout << "*** Seller [" << (i + 1) << "] ***" << endl;

            cout << "code  [" << (i + 1) << "] = " << b[i].seller_code << endl;
            cout << "name  [" << (i + 1) << "] = " << b[i].seller_name << endl;
            cout << "address [" << (i + 1) << "] = " << b[i].seller_address << endl;
            cout << "phone [" << (i + 1) << "] = " << b[i].seller_phone << endl;
        }
    }
}

void search_shopper(shopper c[], int o, float price_from, float price_to) {
    for (int i = 0; i < o; i++) {
        if (c[i].shopper_cash >= price_from && c[i].shopper_cash <= price_to) {

            cout << "*** Shopper [" << (i + 1) << "]  ***" << endl;

            cout << "code  [" << (i + 1) << "] = " << c[i].shopper_code << endl;
            cout << "Name  [" << (i + 1) << "] = " << c[i].shopper_name << endl;
            cout << "Phone [" << (i + 1) << "] = " << c[i].shopper_phone << endl;
            cout << "Cash [" << (i + 1) << "] = " << c[i].shopper_cash << endl;
        }
    }
}


   int  main() {

      int m, n, o;

    product *a;
    seller *b;
    shopper *c;


    int choice, count;
    int product_codee;
    float price_from;
    float price_to;
    int code;

    cout << "*****************************************************************\n";
    while (true) {

        cout <<endl<< "  (1) New Product " << endl ;

        cout << "  (2) New Seller" << endl ;

        cout << "  (3) New Shopper" << endl ;

        cout << "  (4) New Buy" << endl ;

        cout << "  (5) See All Product List" << endl ;

        cout << "  (6) See Product List (imported price range)" << endl ;

        cout << "  (7) See Sellers of Uniqe Product" << endl ;

        cout << "  (8) See All Shoppers" << endl ;

        cout << "  (9) See  Shoppers (imported price range)" << endl ;

        cout << "  (10) exit " << endl ;

        cout << "  Enter your choice : " << endl  ;

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "enter the count of your products : ";
                cin >> m;
                a = new product[m];
                //int i;
                for (int i = 0; i < m; i++) {
                    cout << "\n****  number of your products is : " << (i + 1) << " ****";

                    cout << "\nenter code of product :\n";
                    cin >> a[i].product_code;
                    cout << "\nenter name of product :\n";
                    cin >> a[i].product_name;
                    cout << "\nenter price of product :\n";
                    cin >> a[i].product_price;
                    cout << "\nenter code_seller of product :\n";
                    cin >> a[i].code_seller;
                    cout << "\nenter count of product :\n";
                    cin >> a[i].product_count;

                }
                cout << "\n*****************************************************************";
                break;

            case 2:
                cout<< "\nenter the count of your seller : ";
                cin >> n;
                b = new seller[n];


                for (int i = 0; i < n; i++) {
                    cout << "\n****  number of your seller is : " << (i + 1) << " ****";

                    cout << "\nenter code of seller :\n";
                    cin >> b[i].seller_code;
                    cout << "\nenter name of seller :\n";
                    cin >> b[i].seller_name;
                    cout << "\nenter address of seller :\n";
                    cin >> b[i].seller_address;
                    cout << "\nenter phone of seller :\n";
                    cin >> b[i].seller_phone;
                    cout << "\nenter code product of seller :\n";
                    cin >> b[i].code_product;

                }

                cout << "\n*****************************************************************";
                break;

            case 3:
                cout<< "\nenter the count of your shopper : ";
                cin >> o;
                c = new shopper[o];

                for (int i = 0; i < o; i++) {
                    cout << "\n****  number of your shopper is : " << (i + 1) << " ****";

                    cout << "\nenter code of shopper :\n";
                    cin >> c[i].shopper_code;
                    cout << "\nenter name of shopper :\n";
                    cin >> c[i].shopper_name;
                    cout << "\nenter phone of shopper :\n";
                    cin >> c[i].shopper_phone;
                    c[i].shopper_cash = 0;
                }
                break;

            case 4://Buy :
                cout << "\nHi dear shopper welcome to this program " << "\nEnter your code :\n";
                cin >> code;

                cout << "\nEnter code of Product that you want to buy :\n";
                cin >> product_codee;

                for (int i = 0; i < m; i++) {
                    if (product_codee == a[i].product_code) {
                        cout << "\nEnter Count Of your Product that you want to buy:\n";
                        cin >> count;

                        if (count <= a[i].product_count) {
                            a[i].product_count -= count;
                            c[i].shopper_cash += a[i].product_price * count;
                            cout << "you should pay :" << c[i].shopper_cash<<endl;
                        } else {
                            cout << "The Buy Is not Successful ! , this product is finished \n Please Try Again !\n";
                        }
                    }
                }

                break;

            case 5: //See All Product List :
                for (int i = 0; i < m; i++) {
                    cout << "*** Product List[" << i << "] ***" << endl;

                    cout << "code  [" << (i + 1) << "] = " << a[i].product_code << endl;
                    cout << "Name  [" << (i + 1) << "] = " << a[i].product_name << endl;
                    cout << "Price  [" << (i + 1) << "] = " << a[i].product_price << endl;
                    cout << "Count  [" << (i + 1) << "] = " << a[i].product_count << endl;
                }

                cout << "Product List finish !\n ";
                break;


            case 6: //See special Product List ( price range) :

                cout << "Enter Price Range : \n";
                //from :
                cout << "Price From :  ";
                cin >> price_from;

                //to:
                cout << "Price To :  ";
                cin >> price_to;

                search_product(a, m, price_from, price_to);

                break;


            case 7: //See Sellers of special Product :

                cout << "\nEnter product code: ";
                cin >> code; //pro code

                search_seller(b, n, code);

                break;


            case 8: //See All Shoppers :

                for (int i = 0; i < o; i++) {
                    cout << "Shopper[" << i << "] : " << endl;

                    cout << "code  [" << (i + 1) << "] = " << c[i].shopper_code << endl;
                    cout << "Name  [" << (i + 1) << "] = " << c[i].shopper_name << endl;
                    cout << "Phone [" << (i + 1) << "] = " << c[i].shopper_phone << endl;
                    cout << "Cash [" << (i + 1) << "] = " << c[i].shopper_cash << endl;
                }

                cout << "shopper List finish !\n";

                break;


            case 9:
                cout << "Enter Price Range : \n";
                //from :
                cout << "Price From :";
                cin >> price_from;

                //to:
                cout << "Price To :";
                cin >> price_to;

                search_shopper(c, o, price_from, price_to);

                break;

                case 10: //exit :
                   exit(0);

            default:
                cout << "Not Supported !" << endl;
                break;
        }
    }
    system("pause");
    getch();
    return 0;

}


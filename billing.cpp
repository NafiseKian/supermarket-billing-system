#include <iostream>
#include <fstream>

using namespace std;


class billing {
 
   private :

     int productCode;
     float price;
     float discount ;
     string productName ;

   public :

     void menu();
     void admin();
     void customer();
     void add();
     void edit();
     void removeProduct();
     void list();
     void bill();

};


void billing :: menu(){
 
    m:
    int choice ;
    string email ; 
    string password ;


    cout<<"\n\t\t\t        welcome to killer supermarket           \n\n\n";
    cout<<"\t\t\t        1)Admin\n\t\t\t        2)cuustomer\n\t\t\t        3)exit\n";
    cin>>choice;



    switch(choice){

        case 1 : cout<<"\t\t\t       please login to system\n";
                 cout<<"\t\t\t       enter your email:\n";
                 cin>>email ;
                 cout<<"\t\t\t       enter your password:\n";
                 cin>>password ;

                 if(email=="..." && password=="123" ) admin();
                 else cout<<"\t\t\t       invalid email or password\n";
                 break;

        case 2 : customer() ; break;
        case 3 : exit(0) ; break; 
        default : cout<<"\t\t\t      Wrong choice ! try again \n";
    }

    goto m ;

}



void billing :: admin (){

    m:
    int choice ;

    cout<<"\t\t\t                   Welcome Administrator        \n";
    cout<<"\n\t\t\t---------------------------------------------------------\n";
    cout<<"\t\t\t    1)add product\n\t\t\t    2)remove product\n\t\t\t    3)edit product\n\t\t\t    4)back to main menu\n";
    cin>>choice;


    switch (choice)
    {
    case 1: add(); break;
    case 2:removeProduct();break;
    case 3:edit();break;
    case 4:menu();break; 
    
    default:
        cout<<"\t\t\t       Wrong choice ! try again      \n";
        break;
    }

    goto m ;

}


void billing :: customer(){

    m:
    int choice ;

    cout<<"\t\t\t             welcome to killer supermarket    \n";
    cout<<"\n\t\t\t---------------------------------------------------------\n";
    cout<<"\t\t\t             eneter your choice               \n";
    cout<<"\t\t\t             1)buy product\n\t\t\t           2)back to menu\n";
    cin>>choice;


    switch(choice){

        case 1: bill(); break;
        case 2: menu();break;
        default:
        cout<<"\t\t\t       Wrong choice ! try again      \n";
        break;
    
    }

    goto m ;
}


void billing :: add(){

    m:
    fstream data ;
    int c ;
    int t =0 ;
    float p ; 
    float d ;
    string n ;

    cout<<"\t\t\t       Add the product         \n";
    cout<<"\t\t\t-----------------------------------\n";
    cout<<"\t\t\t     Enter the product code    \n";
    cin>>productCode;
    cout<<"\t\t\t     Enter the product name    \n";
    cin>>productName;
    cout<<"\t\t\t     Enter the product price    \n";
    cin>>price;
    cout<<"\t\t\t     Enter the product discount    \n";
    cin>>discount;

    data.open("database.txt" , ios::in);

    if(!data)
    {
        data.open("database.txt" , ios::app|ios::out);
        data<<"  "<<productCode<<"  "<<productName<<"  "<<price<<"   "<<discount<<"   \n";
        data.close();
    }else
    {

        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if(c==productCode)
               t++;
            data>>c>>n>>p>>d;


        }

        data.close();
        
    

    if(t==1)
      goto m ;
    else
    {
       data.open("database.txt" , ios::app|ios::out);
       data<<"  "<<productCode<<"  "<<productName<<"  "<<price<<"   "<<discount<<"   \n";
       data.close();
    }
    }

    cout<<"\t\t\t       Product has been inserted to file ! \n";

}


void billing :: edit(){

    fstream d1 , d2 ;
    int pc ;
    int t=0;
    int c ;
    float p;
    float d ;
    string n ;


    cout<<"\t\t\t     Edit the product      \n";
    cout<<"\t\t\t     Enter the product code :     \n";
    cin>>pc;
    

    d1.open("database.txt" , ios::in);

    if(!d1)
       cout<<"\t\t\t     ERORR ! file doesn't exists     \n";
    else
    {

        d2.open("database.txt" , ios::app|ios::out);

        d1>>productCode>>productName>>price>>discount;

        while(!d1.eof())
        {
            if(pc == productCode)
            {
                cout<<"\n\t\t\t     Enter the new product code    \n";
                cin>>c;
                cout<<"\n\t\t\t     Enter the new product name    \n";
                cin>>n;
                cout<<"\n\t\t\t     Enter the new product price    \n";
                cin>>p;
                cout<<"\n\t\t\t     Enter the new product discount    \n";
                cin>>d;

                d2<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
                cout<<"\t\t\t    edit is done    \n";
                t++;

            }else
            {
                d2<<productCode<<"  "<<productName<<"  "<<price<<"  "<<discount<<"\n";

            }

            d1>>productCode>>productName>>price>>discount;
        }

        d1.close();
        d2.close();

        remove("database.txt");
        rename("database1.txt" , "database.txt");


        if(t==0)
           cout<<"\t\t\t      product can not be found    \n";
    }
}



void billing :: removeProduct(){

    fstream d1 , d2 ;
    int pc ;
    int t=0;


    
    cout<<"\t\t\t     Edit the product      \n";
    cout<<"\t\t\t     Enter the product code :     \n";
    cin>>pc;
    

    d1.open("database.txt" , ios::in);

    if(!d1)
       cout<<"\t\t\t     ERORR ! file doesn't exists     \n";
    else
    {

        d2.open("database.txt" , ios::app|ios::out);

        d1>>productCode>>productName>>price>>discount;

        while(!d1.eof())
        {
            if(pc == productCode)
            {
                cout<<"\t\t\t     product has been removed !   \n";
                t++;
            }else
            {
                d2<<productCode<<"  "<<productName<<"  "<<price<<"  "<<discount<<"\n";
            }

            d1>>productCode>>productName>>price>>discount;

        }

        d1.close();
        d2.close();

        remove("database.txt");
        rename("database1.txt" , "database.txt");

        if(t==0)
           cout<<"\t\t\t      product can not be found    \n";

    }        

}




void billing :: list(){

    fstream data ;
    data.open("database.txt" , ios::in);

    do{

        data>>productCode>>productName>>price>>discount;
        cout<<"\t\t\t"<<productCode<<"\t\t"<<productName<<"\t\t"<<price<<"\t\t"<<discount<<"\n";

    }while (!data.eof());

    data.close();    


}


void billing::bill(){


    m:
	fstream data ;

    int arr1[99];
    int arr2[99];

    char ch ;
    int c = 0 ;
    float amount ;
    float total=0 ;
    float minus=0 ;

    cout<<"\n\t\t\t        Receipt          \n";

    data.open("database.txt" , ios::in);
    if(!data)
       cout<<"\t\t\t     file doesn't exists      \n";
    else
    {
        data.close();
        list();
        cout<<"\n\t\t\t---------------------------------------------------------\n";
        cout<<"\n\n\t\t\t               you can order now                     \n";
        cout<<"\n\t\t\t---------------------------------------------------------\n";

        do{
            cout<<"\t\t\t     Enter the product code          \n";
            cin>>arr1[c];
            cout<<"\t\t\t     Enter the quantity              \n";
            cin>>arr2[c];

            for(int i=0 ; i<c ; i++)
            {
                if(arr1[c]==arr1[i])
                {
                    cout<<"\t\t\t           this product already exists , try again          \n";
                    goto m;
                }

            }
            c++;
            cout<<"\n\t\t\t---------------------------------------------------------\n";
            cout<<"\t\t\t         Are you gonna continue shopping ? (y/n)           \n";
            cin>>ch;
        }while(ch == 'y');


        cout<<"\t\t\t                       RECEIPT                     \n\n";
         cout<<"\n\t\t\t------------------------------------------------\n";
        cout<<"\t\t\t product code\tproduct name\tquantity\tprice\tdiscount\t\n";


        for(int i=0 ; i<c+1 ; i++)
        {
            data.open("database.txt" , ios::in);
            data>>productCode>>productName>>price>>discount;
            while (!data.eof())
            {
                if(productCode==arr1[i])
                {
                    amount=price*arr2[i];
                    amount=amount-(amount*(discount/100));
                    total+=amount;
                    cout<<"\n\t\t\t"<<productCode<<"\t\t"<<productName<<"\t\t"<<arr2[i]<<"\t\t"<<price<<"\t"<<discount<<"\n";

                }

                data>>productCode>>productName>>price>>discount;
            }
            

        }

        data.close();

    }


    cout<<"\t\t\t-------------------------------------------\n";
    cout<<"\t\t\t     Total amount: "<<total<<"\n";



}



int main(void){

    billing c ;
    c.menu();

    return 0 ;
}
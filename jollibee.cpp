#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

string A_Food[4] = {"Beef Tapa","Corned Beef","Breakfast Burger Steak","Breakfast Shanghai"};
double A_Price[4] = {121.50,121.25,94.75,66.80};
string B_Food[4] = {"6-pc Chickenjoy Solo","8-pc Chickenjoy Solo","6-pc Burger Steak Family Pan","Honey Beef Rice Family Pan"};
double B_Price[4] = {439.65,539.75,286.50,825.90};
string C_Food[3] = {"1-pc Chickenjoy with Burger Steak","1-pc Chickenjoy with Shanghai","1-pc Chickenjoy with Spaghetti"};
double C_Price[3] = {182.65,182.85,109.55};
string D_Food[5] = {"Spicy Champ","Yumburger","Cheesy Yumburger","Bacon Champ","Pork-Free Aloha Champ"};
double D_Price[5] = {193.60,39.50,59.55,208.68,127.38};
string E_Food[4] = {"Jolly Spaghetti with Yumburger","Jolly Spaghetti with Burger Steak","Jolly Spaghetti Shanghai","Jolly Spaghetti"};
double E_Price[4] = {109.35,109.55,108.65,55.60};
string F_Food[4] = {"Chickenwich","Tuna Pie","Chessy Classic Jolly Hotdog","Regular Jolly Hotdog"};
double F_Price[4] = {143.65,50.55,55.65,52.85};
string G_drinks[9] = {"Iced Tea","Coke","Sprite","Royal","Sarsi","Pineapple Juice","Soda doubles","Coffee","Hot Chocolate"};
double G_Price[9] = {61.00,50.00,52.00,54.00,53.00,62.00,42.00,39.00,44.00};
vector<string> order_food;
vector<int> order_quantities;
vector<double> order_prices;
int isDineIn;

void show_menu()
{   
    int padding = 50;
    cout<<"========================================================="<<endl;
    cout<<"Menu"<<setw(padding)<<"Prices"<<endl;
    cout<<"========================================================="<<endl;
    // Show A1 - A4
    cout<<"Brealfast\n";
    for(int i = 0;i<sizeof(A_Food)/sizeof(A_Food[0]);i++)
    {   
        cout<<" A"<<i+1<<" "<<A_Food[i]<<setw(padding-A_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<A_Price[i]<<endl;
    }
    // Show B1 - B4
    cout<<"Family Meals\n";
    for(int i = 0;i<sizeof(B_Food)/sizeof(B_Food[0]);i++)
    {   
        cout<<" B"<<i+1<<" "<<B_Food[i]<<setw(padding-B_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<B_Price[i]<<endl;
    }
    // Show C1 - C3
    cout<<"Chicken Joy\n";
    for(int i = 0;i<sizeof(C_Food)/sizeof(C_Food[0]);i++)
    {   
        cout<<" C"<<i+1<<" "<<C_Food[i]<<setw(padding-C_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<C_Price[i]<<endl;
    }
    // Show D1 - D5
    cout<<"Burgers\n";
    for(int i = 0;i<sizeof(D_Food)/sizeof(D_Food[0]);i++)
    {   
        cout<<" D"<<i+1<<" "<<D_Food[i]<<setw(padding-D_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<D_Price[i]<<endl;
    }
    // Show E1 - E4
    cout<<"Jolly Spaghetti\n";
    for(int i = 0;i<sizeof(E_Food)/sizeof(E_Food[0]);i++)
    {   
        cout<<" E"<<i+1<<" "<<E_Food[i]<<setw(padding-E_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<E_Price[i]<<endl;
    }
    // Show F1 - F4
    cout<<"Sandwiches and Pies\n";
    for(int i = 0;i<sizeof(F_Food)/sizeof(F_Food[0]);i++)
    {   
        cout<<" F"<<i+1<<" "<<F_Food[i]<<setw(padding-F_Food[i].length()-4)<<"P "<<setprecision(2)<<fixed<<F_Price[i]<<endl;
    }
    // Show G1 - G9
    cout<<"Beverages\n";
    for(int i = 0;i<sizeof(G_drinks)/sizeof(G_drinks[0]);i++)
    {   
        cout<<" G"<<i+1<<" "<<G_drinks[i]<<setw(padding-G_drinks[i].length()-4)<<"P "<<setprecision(2)<<fixed<<G_Price[i]<<endl;
    }
    cout<<"End Transaction\n";
    cout<<" H1 Billout\n";
    cout<<"=========================================================\n";
}

void show_receipt()
{   
    int padding = 20;
    double totaldue = 0;
    double cash;
    cout<<"========================================================="<<endl;
	cout<<"OFFICIAL RECEIPT"<<endl;
	cout<<"========================================================="<<endl;
    if(isDineIn == 1)
    {
        cout<<"DINE IN\n";
    }
    else if(isDineIn == 0)
    {
        cout<<"TAKE OUT\n";
    }
    string cashier;
    cout<<"Cashier: ";
    cin.ignore();
    getline(cin,cashier);  
    cout<<"\n---------------------------------------------------------"<<endl;
    for(int i = 0;i<order_food.size();i++)
    {
        cout<<order_quantities[i]<<setw(padding)<<order_food[i]<<setw(padding)<<"P "<<setprecision(2)<<fixed<<order_prices[i]<<endl;
        totaldue = totaldue + order_quantities[i] * order_prices[i];

    }
    double vatablesales = totaldue / (0.12+1);
	double vat = totaldue - vatablesales;
    cout<<"========================================================="<<endl;
    cout<<order_food.size()<<" Items"<<setw(padding)<<"Total P "<<totaldue<<endl;
    cout<<"\n";
    cout<<"TOTAL DUE:"<<setw(padding-10)<<"P "<<totaldue<<endl;
    cout<<"CASH:"<<setw(padding-5)<<"P ";
    cin>>cash;
    cout<<"CHANGE:"<<setw(padding-7)<<"P "<<cash-totaldue<<endl;
    cout<<"\nVATable Sales:"<<setw(padding-14)<<"P "<<vatablesales<<endl;
    cout<<"VAT Amount:"<<setw(padding-11)<<"P "<<vat<<endl;
    cout<<"\n---------------------------------------------------------"<<endl;	

}

// returns index if repeat, -1 otherwise
int isOrderRepeat(string food)
{   
    for(int i = 0;i<order_food.size();i++)
    {   
        if(food.compare(order_food[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}


int main()
{   
    show_menu();
    string code;
    int loop_counter = 0;
    while(1)
    {
        cout<<"Item Code (A1-H1): ";
        cin>>code;
        if(code.length() > 2)
        {
            cout<<"Invalid code!\n";
            break;
        }
        else
        {
            if(code == "H1")
            {
                if(loop_counter == 0 || order_food.size() == 0)
                {
                    break;
                }
                // billout
                else
                {   
                    string dine;
                    cout<<"Dine in? (Y/N): ";
                    cin>>dine;
                    if(dine == "Y")
                    {
                        isDineIn = 1;
                    }
                    else if(dine == "N")
                    {
                        isDineIn = 0;
                    }
                    show_receipt();
                    break;
                }
            }
            else
            {
                char letter = code.at(0);
                int num = code.at(1) - 48;
                int quantity;
                string food;
                if(letter == 'A')
                {   
                    if(num > 0 && num < 5)
                    {   
                        food = A_Food[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {   
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(A_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'B')
                {
                    if(num > 0 && num < 5)
                    {
                        food = B_Food[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(B_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'C')
                {
                    if(num > 0 && num < 4)
                    {
                        food = C_Food[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(C_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'D')
                {
                    if(num > 0 && num < 6)
                    {
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(D_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'E')
                {
                    if(num > 0 && num < 5)
                    {
                        food = E_Food[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(E_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'F')
                {
                    if(num > 0 && num < 5)
                    {
                        food = F_Food[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(F_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else if(letter == 'G')
                {
                    if(num > 0 && num < 10)
                    {
                        food = G_drinks[num-1];
                        cout<<"Description: "<<food<<endl;
                        cout<<"Quantity: ";
                        cin>>quantity;
                        int target = isOrderRepeat(food);
                        if(target != -1)
                        {
                            order_quantities[target] = order_quantities[target] + quantity;
                        }
                        else
                        {
                            order_food.push_back(food);
                            order_quantities.push_back(quantity);
                            order_prices.push_back(G_Price[num-1]);
                        }
                    }
                    else
                    {
                        cout<<"Invalid code!\n";
                    }
                }
                else
                {
                    cout<<"Invalid code!\n";
                }
                loop_counter++;
                cout<<"\n";
            }
        }   
    }
    return 0;
} 
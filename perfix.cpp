#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string simple_unit;
string ou;


int amount;
int choice;

int index;

vector <string> other_unit = {"pico","nano","micro","milli","killo","mega","giga","tera"};
vector <int> vlues = {-12, -9, -6, -3,3, 6, 9, 12};

void show()
{

    cout<<"***********************prefix table***********************\n";

    cout<<"please enter simple unit: ";
    cin>>simple_unit;

    cout<<"\n"<<endl;

    cout<<"[1] "+simple_unit+" to other unit\n";
    cout<<"[2] other unit to  "+simple_unit+"\n";
    cout<<"[3] Exit\n";
}

long long convert(int index,int amount)
{
    return amount/pow(10,vlues[index]);
}
long long convert2(int index,int amount)
{
    return amount*pow(10,vlues[index]);
}



void process()
{
    do
    {
         show();
         cout<<"please enter your choice : ";
         cin>>choice;

        switch(choice)
        {
        case 1 :
            system("cls");
            cout<<"note enter small letters only,available units from pico to tera\n\n";
            cout<<"please enter other unit you want convert  "+simple_unit+" to it : ";
            cin>>ou;


            for(int i = 0; i<other_unit.size(); i++)
            {
                if(ou == other_unit[i])
                {
                    index = i;
                    cout<<"enter amount you want convert it from "+simple_unit+" to "+ou+" "+simple_unit<<" : ";
                    cin>>amount;
                    break;
                }//end if
                else if(i == 7)
                {
                    cout<<"input error please try again\n";
                    choice = 3;
                    break;

                }//end else if
            }// end loop
            cout<<"\n"<<amount<<" "+simple_unit+" = "<<convert(index,amount)<<" "+ou+" "+simple_unit+"\n";
            break;
        case 2 :
            system("cls");
            cout<<"note enter small letters only,available units from pico to tera\n\n";
            cout<<"please enter other unit you want convert it to "+simple_unit+" : ";
            cin>>ou;

            for(int i = 0; i<other_unit.size(); i++)
            {
                if(ou == other_unit[i])
                {
                    index = i;
                    cout<<"enter amount you want convert it from "+ou+" "+simple_unit+" to "<<simple_unit+" : ";
                    cin>>amount;
                    break;
                }
                else if(i == 7)
                {
                     cout<<"input error please try again\n";
                     choice = 3;
                     break;
                }


            }
            cout<<amount<<" "+ou+" "+simple_unit+" = "<<convert2(index,amount)<<" "<<simple_unit<<endl;
            break;
        case 3:
            cout<<"thanks for using prefix table app\n";
        break;

        default:
            cout<<"error in user input\n";
            choice = 3;
            break;




        }//end switch

    }while(choice < 3);



}

int main()
{
    process();
}

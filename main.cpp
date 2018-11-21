
//  main.cpp
//  EC2_base_converter

//  Created by Mordechai Bronfin on 11/20/18.
//  Copyright © 2018 Mordechai Bronfin. All rights reserved.


#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>
#include <istream>
#include <cmath>
#include <locale>
#include <cctype>
#include <vector>
#include <exception>
#include <stdexcept>
#include <typeinfo>

using namespace std;

void decimal_binary(int input);
int binary_decimal(int input);
void decimal_hex(int input);
int hex_decimal(char h_input[]);
void menu();

int main()
{
    int choice, input;
    char h1_input[100];
    
    cout<<endl<<"*********Number Base Converter*********"<<endl<<endl;
    
    while(1)
    {
        menu();
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                cout<<endl<<endl<<"...Decimal to Binary..."<<endl<<endl<<"Input Decimal Number: ";
                cin>>input;
                cout<<endl<<endl<<input<<" in Binary = ";
                decimal_binary(input);
                cout<<endl;
                
            }
                break;
                
            case 2:
            {
                cout<<endl<<endl<<"...Binary to Decimal..."<<endl<<endl<<"Input Binary Number: ";
                cin>>input;
                cout<<endl<<endl<<input<<" in Decimal = "<<binary_decimal(input)<<endl;
            }
                break;
                
            case 3:
            {
                cout<<endl<<endl<<"...Decimal to Hex..."<<endl<<endl<<"Input Decimal Number: ";
                cin>>input;
                cout<<endl<<endl<<input<<" in Hex = ";
                decimal_hex(input);
                cout<<endl;
            }
                break;
                
            case 4:
            {
                cout<<endl<<endl<<"...Hex to Decimal..."<<endl<<endl<<"Input Hex Number: ";
                cin>>h1_input;
                cout<<endl<<endl<<h1_input<<" in Decimal = "<<hex_decimal(h1_input)<<endl;
                
            }
                break;
                
            case 5:
            {
                cout<<endl<<"Exiting Program..."<<endl<<endl;
                exit(0);
            }
                
            default:
            
             cout<<endl<<"...Invalid Selection..."<<endl;
            
        
        }
    
    }
   
    return 0;
}

void menu()
{
    cout<<endl<<"Select from the Following Options"<<endl<<endl<<"1 - Decimal to Binary"<<endl<<endl<<"2 - Binary to Decimal"<<endl<<endl<<"3 - Decimal to Hex"<<endl<<endl<<"4 - Hex to Decimal"<<endl<<endl<<"5 - Exit Program"<<endl<<endl<<"Selection: ";
}

void decimal_binary(int input)
{
    int bin_number[10000];
    
    int i = 0;
    while(input>0)
    {
        bin_number[i]=input%2;
        input=input/2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--)
    
        cout<<bin_number[j];
    
}

int binary_decimal(int input)
{
    int decimal = 0,x = input,y=1,z=x;
    
    while(z)
    {
        int ld=z%10;
        z=z/10;
        
        decimal+=ld*y;
        
        y=y*2;
    }
    
    return decimal;
}

void decimal_hex(int input)
{
    char hn[1000];
    
    int i=0;
    while(input!=0)
    {
        int t=0;
        t=input%16;

        if(t<10)
        {
            hn[i]=t+48;
            i++;
        }
        else
        {
            hn[i]=t+55;
            i++;
        }
        
        input=input/16;
        
    }
    
    for(int j=i-1; j>=0; j--)
    {
        cout<<hn[j];
    }
    
    
}

int hex_decimal(char h_input[])
{
    int length=strlen(h_input),b=1,decimal_num = 0;
    
    for (int i=length-1; i>=0; i--)
    {
        if (h_input[i]>='0' && h_input[i]<='9')
        {
            decimal_num+=(h_input[i] - 48)*b;
            
            b=b*16;
        }
        
        else if (h_input[i]>='A' && h_input[i]<='F')
        {
            decimal_num+=(h_input[i] - 55)*b;
            
            b=b*16;
        }
    }
    return decimal_num;
}

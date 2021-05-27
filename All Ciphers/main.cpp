#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

string toBinary(int n);
int xor_f (int num1 , int num2);

int pow(int base , int power)
{
    int res=1;
    for(int i=0; i<power ; i++ )
    {
        res=res*base;
    }
    return res;
}
void shifting(char arr[] ,int n)
{
    int shift = 0 , endd = 0 ;
    cout << "enter how many times you want to shift : ";
    cin >> shift ; /// enter how many times you want to shift
    if(shift > n)
    {
        shift -= n;
    }
    for (int j = 0 ; j < shift ; ++j)
    {
        endd = arr[n-1] ;
        for (int k = n-1 ; k > 0 ; --k)
        {
            arr[k] = arr[k-1];
        }
        arr[0] = endd;
    }
}

int main()
{
    cout<<"0-Affine Cipher. "<<endl;
    cout<<"1-Caesar Cipher. "<<endl;
    cout<<"2-Atbash Cipher. "<<endl;
    cout<<"3-ROT13 Cipher.  "<<endl;
    cout<<"4-Baconian Cipher. "<<endl;
    cout<<"5-Simple Substitution Cipher. "<<endl;
    cout<<"6-Polybius Square Cipher. "<<endl;
    cout<<"7-Morse Code. "<<endl;
    cout<<"8-XOR Cipher. "<<endl;
    cout<<"9-Rail-fence Cipher. "<<endl;
    int NUMBER;
    cout<<">>>";
    cin>>NUMBER;
    if(NUMBER==0)
    {
        /// #NUMBER_0
        while (true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n, num1, num2, num3;
            cout<<">>>";
            cin>>n;
            if (n==1)
            {
                while (true)
                {
                    cout<<"Enter the three parameters : ";
                    cin>>num1>>num2>>num3;
                    if((num1*num3)%26 ==1)
                        break;
                }

                int num;
                int arrayOfnumbers[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
                string arrayOfletters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string name;
                cout<<"Please enter the message to cipher: ";
                cin.ignore();
                getline(cin,name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfletters[j])
                        {
                            num=(num1*(arrayOfnumbers[j])+num2)%26;
                            cout<<arrayOfletters[num];
                        }
                    }
                    if (name[i]== char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if (n==2)
            {
                while (true)
                {
                    cout<<"Enter the three parameters : ";
                    cin>>num1>>num2>>num3;
                    if((num1*num3)%26 ==1)
                        break;
                }

                int num;
                int arrayOfnumbers[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
                string arrayOfletters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string name;
                cout<<"Please enter the message to decipher: ";
                cin.ignore();
                getline(cin,name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfletters[j])
                        {
                            num=num3*(arrayOfnumbers[j]-num2 );
                            if(num<0)
                            {
                                num*=-1;
                            }
                            cout<<arrayOfletters[num%26];
                        }
                    }
                    if (name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if (n==3)
                break;
        }

    }


    else if (NUMBER==1)
    {
        /// #NUMBER_1
        while (true)
        {
            cout<<endl;
            char arrayOfchar[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            string arrayOfletters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n ;
            cout<<">>>";
            cin>> n;
            if(n==1)
            {
                shifting(arrayOfchar , 26);
                string name;
                cout<<"Please enter the message to cipher: ";
                cin.ignore();
                getline(cin, name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0 ; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfletters[j])
                        {
                            cout<<arrayOfchar[j];
                        }
                    }
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }

            }
            else if (n==2)
            {
                shifting(arrayOfchar , 26);
                string name;
                cout<<"Please enter the message to decipher: ";
                cin.ignore();
                getline(cin, name);
                cout<<name;
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]<97)
                    {
                        name[i]+=32;
                    }
                }
                for(int i=0 ; i<name.size(); i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfchar[j])
                        {
                            cout<<arrayOfletters[j];
                        }
                    }
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if(n==3)
                break;
        }

    }
    else if (NUMBER==2)
    {
        ///NUMBER#2
        while (true)
        {
            cout<<endl;
            string arrayOfletter_1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string arrayOfletter_2="ZYXWUVTSRQPONMLKJIHGFEDCBA";
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n ;
            cout<<">>>";
            cin>> n;
            if(n==1)
            {
                string name;
                cout<<"Please enter the message to cipher: ";
                cin.ignore();
                getline(cin,name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfletter_1[j])
                        {
                            cout<<arrayOfletter_2[j];
                        }
                    }
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if (n==2)
            {
                string name;
                cout<<"Please enter the message to decipher: ";
                cin.ignore();
                getline(cin,name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==arrayOfletter_2[j])
                        {
                            cout<<arrayOfletter_1[j];
                        }
                    }
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if(n==3)
                break;
        }


    }
    else if (NUMBER==3)
    {
        ///NUMBER#3
        while (true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n ;
            cout<<">>>";
            cin>> n;
            string name;
            if (n==1)
            {
                cout<<"Please enter the message to cipher: ";
            }
            else if (n==2)
            {
                cout<<"Please enter the message to decipher: ";
            }
            else if (n==3)
                break;
            cin.ignore();
            getline(cin,name);
            for(int i=0; i<name.size(); i++)
            {
                if (name[i]>=97)
                {
                    name[i]-=32;
                }
            }
            for(int i=0 ; i<name.size() ; i++)
            {
                if (int(name[i])>77)
                {
                    cout<<char(name[i]-13);
                }
                else if (char(name[i])<78)
                {
                    cout<<char(name[i]+13);
                }
                else if (name[i]==char(32))
                {
                    cout<<" ";
                }
            }
        }


    }
    else if (NUMBER==4)
    {
        ///NUMBER#4
        while (true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ua habibi. "<<endl;
            cout<<"What do you like to do today? "<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End "<<endl;
            int n;
            cout<<">> ";
            cin>>n;
            if (n == 1)
            {
                string arrayOfletters="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string name ;
                int num ;
                int arr[5];
                cout<<"Please enter the message to cipher: ";
                cin.ignore();
                getline(cin, name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0 ; i<name.size(); i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if (name[i]==arrayOfletters[j])
                        {
                            name[i]=int(name[i])-65;
                            num=name[i];
                            for( int k=0 ; k<5 ; k++)
                            {
                                if(num%2==1)
                                {
                                    arr[k]=1;
                                }
                                else
                                {
                                    arr[k]=0;
                                }
                                num/=2;
                            }
                            for(int q=0; q<5; q++)
                            {
                                if (arr[q]==1)
                                {
                                    arr[q]='b';
                                }
                                else if (arr[q]==0)
                                {
                                    arr[q]='a';
                                }
                            }
                            for(int i=4; i>=0; i--)
                            {
                                cout<<char(arr[i]);
                            }
                        }
                    }
                    if(name[i]== char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            if(n==2)
            {
                string name;
                int arr[5], q=0, sum=0;
                cout<<"Please enter the message to decipher : ";
                cin>>name;
                char test[name.size()];
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int i=0; i<name.size() ; i+=5)
                {
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                        i++;
                    }
                    for(int j=i; j<i+5 ; j++)
                    {
                        test[j]=name[j];
                    }
                    for(int k=i; k<(i+5) ; k++)
                    {
                        if(test[k]=='A')
                        {
                            arr[k-(i)]=0;
                        }
                        else if (test[k]=='B')
                        {
                            arr[k-(i)]=1;
                        }
                    }
                    for (int w=4 ; w>=0 ; w--)
                    {
                        arr[w]*=pow(2,q);
                        q++;
                    }

                    for(int x=0; x<5 ; x++)
                    {
                        sum+=arr[x];
                    }
                    cout<<char(sum+65);
                    for(int s=0 ; s<5 ; s++)
                    {
                        arr[s]=0;
                    }
                    sum=0;
                    q=0;
                }


            }
            else if (n==3)
                break;
        }

    }
    else if (NUMBER==5)
    {
        ///NUMBER#5
        while (true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n,counter=0;
            cout<<">>>";
            cin>>n;
            if (n==1)
            {
                string name;
                string letters="abcdefghijklmnopqrstuvwxyz";
                char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                string key, arr[26];
                cout<<"enter the key : ";
                cin>>key;
                while(key.size()!=5)
                {
                    cout<<"please enter a key with five letters : ";
                    cin>>key;
                }
                for (int i =0; i<key.size(); i++)
                {
                    for(int k=0; k<key.size(); k++)
                    {
                        if(key[i]==key[k])
                            counter++;
                    }
                    if(counter>=2)
                    {
                        cout<<"enter another key : ";
                        cin>>key;
                        counter=0;
                        i=0;
                    }
                    else
                        counter=0;
                }
                cout<<"please enter the message to cipher : ";
                cin.ignore();
                getline(cin,name);
                int x=0;
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]<97)
                    {
                        name[i]+=32;
                    }
                }
                for(int i=0; i<5 ; i++)
                {
                    arr[i]=key[i];
                }
                for(int s=0 ; s<5 ; s++)
                {
                    for(int j=0; j<26 ; j++)
                    {
                        if(key[s]==arrayOfletters[j])
                        {
                            arrayOfletters[j]=char(35);
                        }
                    }
                }
                for(int i=5; i<26 ; i++)
                {
                    if(arrayOfletters[x]!=char(35))
                        arr[i]=arrayOfletters[x];
                    else
                        i--;
                    x++;
                }
                for(int i=0 ; i<name.size() ; i++)
                {
                    for(int j=0 ; j<26 ; j++)
                    {
                        if(name[i]==letters[j])
                        {
                            cout<<arr[j];
                        }
                    }
                    if (name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }

            }
            else if (n==2)
            {
                string name;
                string letters="abcdefghijklmnopqrstuvwxyz";
                char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
                string key;
                char arr[26];
                cout<<"enter the key : ";
                cin>>key;
                while(key.size()!=5)
                {
                    cout<<"please enter a key with five letters : ";
                    cin>>key;
                }
                for (int i =0; i<key.size(); i++)
                {
                    for(int k=0; k<key.size(); k++)
                    {
                        if(key[i]==key[k])
                            counter++;
                    }
                    if(counter>=2)
                    {
                        cout<<"enter another key : ";
                        cin>>key;
                        counter=0;
                        i=0;
                    }
                    else
                        counter=0;
                }
                cout<<"please enter the message to decipher : ";
                cin.ignore();
                getline(cin,name);
                int x=0;
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]<97)
                    {
                        name[i]+=32;
                    }
                }
                for(int i=0; i<5 ; i++)
                {
                    arr[i]=key[i];
                }
                for(int s=0 ; s<5 ; s++)
                {
                    for(int j=0; j<26 ; j++)
                    {
                        if(key[s]==arrayOfletters[j])
                        {
                            arrayOfletters[j]=char(35);
                        }
                    }
                }
                for(int i=5; i<26 ; i++)
                {
                    if(arrayOfletters[x]!=char(35))
                        arr[i]=arrayOfletters[x];
                    else
                        i--;
                    x++;
                }
                for(int i=0 ; i<name.size() ; i++)
                {
                    for(int j=0; j<26 ; j++)
                    {
                        if (arr[j]==name[i])
                        {
                            cout<<letters[j];
                        }
                    }
                    if(name[i]==char(32))
                    {
                        cout<<" ";
                    }
                }
            }
            else if (n==3)
                break;
        }

    }
    else if (NUMBER==6)
    {
        ///NUMBER#6
        while (true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ua habibi."<<endl;
            cout<<"What do you like to do today?"<<endl;
            cout<<"1- Cipher a message"<<endl;
            cout<<"2- Decipher a message"<<endl;
            cout<<"3- End"<<endl;
            int n;
            cout<<">>>";
            cin>>n;
            if (n==1)
            {
                int arrayOfletter[6][6], x=0;
                for(int i=1; i<=5; i++)
                {
                    for(int j=1; j<=5 ; j++)
                    {
                        arrayOfletter[i][j]=97+x;
                        x++;
                    }

                }
                string name;
                int num1, num2, num3, num4, num5;
                cout<<"enter the key : ";
                cin>>num1>>num2>>num3>>num4>>num5;
                arrayOfletter[0][1]=num1;
                arrayOfletter[1][0]=num1;
                arrayOfletter[0][2]=num2;
                arrayOfletter[2][0]=num2;
                arrayOfletter[0][3]=num3;
                arrayOfletter[3][0]=num3;
                arrayOfletter[0][4]=num4;
                arrayOfletter[4][0]=num4;
                arrayOfletter[0][5]=num5;
                arrayOfletter[5][0]=num5;
                cout<<"please enter the message to cipher : ";
                cin.ignore();
                getline(cin,name);
                for(int i=0; i<name.size(); i++)
                {
                    if (name[i]>=97)
                    {
                        name[i]-=32;
                    }
                }
                for(int w=0 ; w<name.size() ; w++)
                {
                    for(int i=1 ; i<=5; i++)
                    {
                        for(int j=1 ; j<=5 ; j++)
                        {
                            if (name[w]==char(arrayOfletter[i][j]))
                            {
                                cout<<arrayOfletter[i][0]<<arrayOfletter[0][j];
                            }
                        }

                    }
                    if(name[w]==char(32))
                    {
                        cout<<" ";
                    }
                }

            }
            else if (n==2)
            {
                int arrayOfletter[6][6], x=0;
                for(int i=1; i<=5; i++)
                {
                    for(int j=1; j<=5 ; j++)
                    {
                        arrayOfletter[i][j]=97+x;
                        x++;
                    }

                }
                int num1, num2, num3, num4, num5;
                cout<<"enter the key : ";
                cin>>num1>>num2>>num3>>num4>>num5;
                arrayOfletter[0][1]=num1;
                arrayOfletter[1][0]=num1;
                arrayOfletter[0][2]=num2;
                arrayOfletter[2][0]=num2;
                arrayOfletter[0][3]=num3;
                arrayOfletter[3][0]=num3;
                arrayOfletter[0][4]=num4;
                arrayOfletter[4][0]=num4;
                arrayOfletter[0][5]=num5;
                arrayOfletter[5][0]=num5;
                string name;
                cout<<"please enter the message to decipher : ";
                cin.ignore();
                getline(cin,name);
                for(int j=0 ; j<name.size() ; j+=2)
                {
                    if(name[j]==char(32))
                    {
                        cout<<" ";
                        j++;
                    }
                    int n1=name[j]-'0';
                    int n2=name[j+1]-'0';
                    for(int i=1; i<=5 ; i++)
                    {
                        if(arrayOfletter[0][i]==n2)
                        {
                            n2=i;
                            break;
                        }
                    }
                    for(int w=1 ; w<=5 ; w++)
                    {
                        if(arrayOfletter[w][0]==n1)
                        {
                            n1=w;
                            break;
                        }
                    }
                    cout<<char(arrayOfletter[n1][n2]);
                }

            }
            else if (n==3)
                break;
        }

    }
    else if (NUMBER==7)
    {
        ///NUMBER#7
        while (true)
        {
            cout<<endl;
            cout <<"Ahlan ya user ua habibi."<<endl;;
            cout <<"What do you like to do today?"<<endl;
            cout <<"1- Cipher a message"<<endl;
            cout <<"2- Decipher a message "<<endl;
            cout <<"3- End "<<endl;
            int n ;
            cout<<">>>";
            cin >> n ;
            if (n == 1 )
            {
                string name ;
                cout <<"Please enter the message to cipher: " ;
                cin.ignore();
                getline(cin, name);
                string arrayOfletter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string cipher[] = {".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. ",".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. "};
                for (int  i = 0 ; i < name.size() ; i++)
                {
                    for (int j=0 ; j< 29; j++)
                    {
                        if (name[i] == arrayOfletter[j])
                        {
                            cout << cipher[j];
                        }
                        if (name[i] == ' ')
                        {
                            cout <<"   ";
                            break;
                        }

                    }
                }
            }
            else if (n == 2)
            {
                string arrayOfletter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string cipher[52] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
                string decryption;
                cin.ignore();
                string name ;
                cout <<"Enter your cipher (for example, ... --- ...  ... --- ...) :  "<<endl;
                getline(cin,name);
                string letter;
                for(int i=0; i< name.size(); i++)
                {
                    while (name[i]!=32)
                    {

                        letter+=name[i];
                        i++;
                    }
                    for(int j=0 ; j<26; ++j)
                    {
                        if(letter == cipher[j])
                        {
                            decryption += arrayOfletter[j];
                            letter="";
                        }
                    }
                    if (name[i]==32)
                    {
                        if ((name[i+1]==32 && name[i+2] == 32)||(name[i+1]==32))
                        {
                            decryption+=" ";
                        }
                    }


                }
                cout<<decryption;
            }
            else if (n==3)
                break;
        }

    }
    else if (NUMBER==8)
    {
        while (true)

        {
            cout<<endl;
            cout<<"What do you like to do? "<< endl;
            cout <<"1- Cipher a message" << endl ;
            cout<< "2- Decipher a message "<<endl;
            cout<<"3- End "<<endl;
            int n ;
            cout<<">>>";
            cin>> n ;
            if (n==1)
            {
                int k , c , cipher_d ;
                char cipher_ascii;
                char key;
                cout<<"Enter The secret key,please: ";
                cin>>  key;
                string m ;
                cout<<"Enter The massage , please : " ;
                cin>> m ;
                int l=m.length() ;
                cout <<"hexa: ";
                for (int i=0; i<l; i++)
                {
                    k=key ;
                    c=m[i] ;
                    cipher_d = k^c ;
                    cout << hex<< cipher_d ;
                }
                cout <<endl << "Cipher text: ";
                for (int i=0; i<l; i++)
                {
                    k=key ;
                    c=m[i] ;
                    cipher_d = k^c ;
                    cipher_ascii = cipher_d ;
                    cout<< cipher_ascii ;
                }
                cout << endl;
            }
            else if (n==2)
            {
                char key,word ;
                int k,w;
                cout <<"Enter The key character: "<<endl;
                cin>> key ;
                k=key;
                cout<< "Enter The message to cipher as : " <<endl;
                cout<< "1- hexa number      2- Cipher text " <<endl ;
                int n ;
                cin>> n ;
                if (n == 1)
                {
                    string hexa_num;
                    cout<<"Enter The hexa num: ";
                    cin >>hexa_num ;
                    int l=hexa_num.length() ;
                    for (int c=0; c<l; c=c+2)
                    {
                        string hexa_digit ;
                        hexa_digit=hexa_digit+hexa_num[c];
                        hexa_digit=hexa_digit+hexa_num[c+1];
                        int x;
                        stringstream ss;
                        ss << hex << hexa_digit;
                        ss >> x;
                        hexa_digit ="";
                        w=k^x;
                        word = w ;
                        cout <<word ;
                    }

                }
                else if (n==2)
                {
                    string cipher ;
                    cout << "Enter The massage to decipher : ";
                    cin >> cipher ;
                    int l=cipher.length() ;
                    for (int c=0; c<l; c=c+1)
                    {
                        char cha_cipher=cipher[c];
                        int c_c = cha_cipher;
                        w=k^c_c;
                        word = w ;
                        cout << word;
                    }
                }
            }
            else if (n==3)
                break;
        }
    }
    else if (NUMBER==9 )
    {
        ///NUMBER#9
        while(true)
        {
            cout<<endl;
            cout<<"Ahlan ya user ya habibi. \n";
            cout<<"What do you like to do today? \n";
            cout<<"1- Cipher a message \n";
            cout<<"2- Decipher a message \n";
            cout<<"3- End \n";
            cout<<">>>";
            float n;
            cin>>n;
            if(n==2)
            {
                string x;
                cout<<"please enter the message to decipher : ";
                cin.ignore();
                getline(cin,x);
                char y[x.length()];
                int i=0;
                int j=0;
                while(i<x.length())
                {
                    if(x.at(i)!=' ')
                    {
                        y[j]=x.at(i);
                        j++;
                    }
                    i++;
                }
                y[j]='\0';
                int key;
                int row=0;
                int column=0;
                int dir=-1;
                int h=0;
                cout<<"enter key \n";
                cin>>key;
                if(key==0 || key>j)
                {
                    cout<<"u can't use this key";
                    return 0;
                }
                if(key==1)
                {
                    cout<<y;
                    return 0;
                }
                char z[key][j];
                for(int i=0; i<key; ++i)
                {
                    for(int k=0; k<j; ++k)
                    {
                        z[i][k]=' ';
                    }
                }
                for(int i=0; i<j; ++i)
                {
                    z[row][column]='_';
                    if(row==0 || row==key-1)
                        dir=dir*(-1);
                    row=row+dir;
                    column++;
                }
                for(int i=0; i<key; ++i)
                {
                    for(int k=0; k<j; ++k)
                    {
                        if(z[i][k]=='_')
                            z[i][k]=y[h++];
                    }
                }
                column=row=0;
                dir=-1;
                for(int i=0; i<j; ++i)
                {
                    cout<<z[row][column];
                    if(row==0 || row==key-1)
                        dir=dir*(-1);
                    row=row+dir;
                    column++;
                }
                cout<<endl<<endl;
            }
            if(n==1)
            {
                string x;
                cout << "please enter the message to cipher : ";
                cin.ignore();
                getline(cin,x);
                char y[x.length()];
                int i=0;
                int j=0;
                while(i<x.length())
                {
                    if(x.at(i)!=' ')
                    {
                        y[j]=x.at(i);
                        j++;
                    }
                    i++;
                }
                y[j]='\0';
                int key;
                int row=0;
                int dir=-1;
                int h=0;
                cout<<"enter key : ";
                cin>>key;
                if(key==0 || key>j)
                {
                    cout<<"you can't use this key";
                    return 0;
                }
                if(key==1)
                {
                    cout<<y;
                    return 0;
                }
                char z[key][j];
                for(int i=0; i<key; i++)
                {
                    for(int l=0; l<j; l++)
                    {
                        z[i][l]=' ';
                    }
                }
                for(int col=0; col<j; col++)
                {
                    z[row][col]=y[h];
                    if(row==0 || row==key-1)
                    {
                        dir=dir*(-1);
                    }
                    row=row+dir;
                    h++;
                }
                for(int m=0; m<key; m++)
                {
                    for(int n=0; n<j; n++)
                    {
                        if(z[m][n]!=' ')
                            cout<<z[m][n];
                    }
                }
                cout<<endl<<endl;
            }
            if(n==3)
            {
                break;
            }
            while(n<=0 || n>3 || n!=1 || n!=2)
            {
                cout<<"This option does not exist "<<endl<<endl;
                break;
            }
        }
    }
    return 0;
}

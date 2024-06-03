#include <iostream>
#include <stdlib.h>
#define SIZE 11

using namespace std;

int hashingModule(int * index){

    *index %= 11;

    return *index;

}

int main(){

    system("cls");

    int * array;
    int * encryptedArray;

    encryptedArray = new int[SIZE]();

    array = new int[SIZE]();

    for(int i = 0 ; i < SIZE ; i++){
        cout<<"Enter "<<i + 1<<". elemen: ";
        cin>>array[i];
    }

    cout<<"Non-encrypted --> ";

    for(int i = 0 ; i < SIZE ; i++){
        cout<<array[i]<<" ";
    }

    cout<<endl;

    for(int i = 0 ; i < SIZE ; i++){
        int number = array[i];
        number = hashingModule(&number);

        while(encryptedArray[number] != 0){
            number++;
            if(number == SIZE){
                number = 0;
            }
        }

        encryptedArray[number] = array[i];
    }

    cout<<"Encrypted --> ";

    for(int i = 0 ; i < SIZE ; i++){
        
        cout<<encryptedArray[i]<<" ";
    }

    delete[] array;
    delete[] encryptedArray;

    return 0;
}
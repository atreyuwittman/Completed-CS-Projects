#include <iostream>

using namespace std;

int Strlen(const char arr[]){
    int i = 0;
    char n = '\0';
    while(arr[i] != n){
        i++;
    }
    return i;
}

char * mystrcat(char * arr1, const char * arr2){
    int i = Strlen(arr1);
    int j = Strlen(arr2);
    int x = 0;
    for(int g = i; g < i + j; g++){
        arr1[g] = arr2[x];
        x++;
    }
    arr1[i + j] = '\0';
    return arr1;
}

int main() {
   char cstr1[80];
   char cstr2[80];

   cstr1[0] = 'L';
   cstr1[1] = 'i';
   cstr1[2] = 'o';
   cstr1[3] = 'n';
   cstr1[4] = 'e';
   cstr1[5] = 'l';
   cstr1[6] = '\0';

   cstr2[0] = 'M';
   cstr2[1] = 'e';
   cstr2[2] = 's';
   cstr2[3] = 's';
   cstr2[4] = 'i';
   cstr2[5] = '\0';

   cout << cstr1 << endl;
   cout << cstr2 << endl;

   mystrcat(cstr1, " ");
   mystrcat(cstr1, cstr2);

   cout << cstr1 << endl;

   return 0;
}
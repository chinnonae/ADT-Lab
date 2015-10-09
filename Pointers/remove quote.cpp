#include <iostream>
using namespace std;

void remove_quotes(char* src, char *dest){
    int i = 0;
    int j = 0;
    while(src[i] != 0){
        if(src[i]=='\'' || src[i]=='\"'){
            i++;
            continue;
        }
        dest[j] = src[i];
        j++;
        i++;
    }
    dest[j] = 0;

}

main(){
    char st[1000];
    char out[1000];

    cin.getline(st,1000);
    remove_quotes(st,out);

    cout << out << endl;

}

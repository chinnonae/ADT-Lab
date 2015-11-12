#include <iostream>
using namespace std;


int main(){
    int T;
    cin >> T;

    for(int i = 1; i <= T; i++){
        int N, P;
        cin >> N;
        cin >> P;
        int Hs[P];
        int hartals = 0;
        bool closes[N];
        for(int a = 0; a < N;a++){
            closes[a] = 0;
        }
        for(int j = 0; j < P; j++){
            cin >> Hs[j];
            int mult = Hs[j];
            while(mult <= N){
                if(mult % 7 != 6 && mult % 7 != 0 && !closes[mult]){
                    closes[mult] = 1;
                    hartals += 1;
                    //cout << "-----" << mult << endl;
                }
                mult += Hs[j];
            }
        }
        cout << hartals << endl;
    }
}

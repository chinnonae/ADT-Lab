#include <iostream>
#include <stack>
using namespace std;
main(){
    while(!cin.eof()){
        int num = 1000;
        std::cin >> num;
        if(num == 0)break;
        int countInput = 0;
        int count = 0;
        int temp;
        int input[100][num];
        int order[num];
        for(int i = 0; i < num; i++){
            order[i] = i+1;
        }

        do{
            std::cin >> temp;
            if(temp != 0){
                input[countInput][count] = temp;
                count++;
            }
            if(count == num) {
                count = 0;
                countInput++;
            }

        }while(temp != 0);

        stack<int> stk;
        count = 0;
        for(int i = 0; i < countInput; i++){
            for(int j = num-1; j >= 0; j--){
                int temp = input[i][j];
                if(temp == order[num-count-1]){
                    count++;
                }else{
                    stk.push(temp);
                }
                if(!stk.empty()){
                    while(stk.top() == order[num-count-1]){
                        stk.pop();
                        count++;
                        if(stk.empty()) break;
                    }
                }
            }
            if(num != 0){
                if(count == num){
                    std::cout << "Yes" << endl;
                }else{
                    std::cout << "No" << endl;
                }
                count = 0;
            }
            while(!stk.empty()){
                stk.pop();
            }
        }

        if(num != 0) cout << "" << endl;
        if(cin.eof()) break;
    }

}

#include <iostream>
#include <set>
using namespace std;

int main(){
    int case_num;
    cin >> case_num;

    for(int i = 0; i < case_num; i++){
        int max = 0;
        int flakes_num;
        cin >> flakes_num;
        int flakes[flakes_num];
        set<int> subsq;
        for(int j = 0; j < flakes_num; j++){
            cin >> flakes[j];
        }

        int start = 0;
        for(int j = start; j < flakes_num; j++){
            pair<set<int>::iterator, bool> temp = subsq.insert(flakes[j]);
            if(!temp.second){
                j = start;
                start++;
                if(max < subsq.size()) max = subsq.size();
                subsq.clear();
            }
        }
        if(subsq.size() > max) max = subsq.size();
        cout << max << endl;
    }
}

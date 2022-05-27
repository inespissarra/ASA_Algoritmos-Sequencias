#include <iostream>
#include <vector>
#include <set>

using namespace std;

void problema1(vector<int> v_num, int len){
    int max=0, num_max=0;
    vector<int> v_tam, num_sub_tam_max;

    for (int i = 0; i < len; i++){
        v_tam.push_back(1);
        num_sub_tam_max.push_back(1);
        for (int j = i-1; j >= 0; j--){
            if(v_num[j] < v_num[i]){
                if (v_tam[j] + 1 > v_tam[i]){
                    v_tam[i] = v_tam[j] + 1;
                    num_sub_tam_max[i] = num_sub_tam_max[j];
                }
                else if(v_tam[j] + 1 == v_tam[i])
                    num_sub_tam_max[i] += num_sub_tam_max[j];
            }
        }
        if(v_tam[i]>max){
            max = v_tam[i];
            num_max = num_sub_tam_max[i];
        }
        else if(v_tam[i]==max)
            num_max += num_sub_tam_max[i];
    }

    printf("%d %d\n", max, num_max);
}

void problema2(vector<int> v_num1, vector<int> v_num2, int len1, int len2){
    int max = 0;
    vector<int> tam_sub_comum;
    
    for (int i = 0; i < len2; i++){
        tam_sub_comum.push_back(0);
    }

    for(int i=0; i<len1; i++){
        int maior = 0;
        for(int j=0; j<len2; j++){
            if(v_num1[i] == v_num2[j]){
                tam_sub_comum[j] = maior + 1;
                if(maior + 1 > max)
                    max = maior + 1;
            }
            else if(v_num1[i] > v_num2[j] && tam_sub_comum[j] > maior)
                maior = tam_sub_comum[j];
        }
    }
    printf("%d\n", max);
}

int main(){
    int n, num;
    int len = 0;
    char c= '\0';
    vector<int> v_num;

    scanf("%d", &n);

    if (n == 1){
        while(c != '\n' && c != '\t'){
            scanf("%d", &num);
            v_num.push_back(num);
            len++;
            c = getchar();
        }
        problema1(v_num, len);
    }
    else if (n == 2){
        int len2 = 0;
        set<int> v_num_set;
        vector<int> v_num2;

        while(c != '\n' && c != '\t'){
            scanf("%d", &num);
            v_num.push_back(num);
            v_num_set.insert(num);
            len++;
            c = getchar();
        }
        
        c = '\0';
        while(c != '\n' && c != '\t'){
            scanf("%d", &num);
            if(v_num_set.count(num)){
                v_num2.push_back(num);
                len2++;
            }
            c = getchar();
        }
        problema2(v_num, v_num2, len, len2);
    }
    return 0;
}
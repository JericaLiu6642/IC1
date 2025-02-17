#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

double GetCount(vector<int> t, vector<vector<int>>database) {
    int count = 0;
    for (auto& i : database) {
        bool meet = true;
        for (int j=0; j<5; j++) {
            if (t[j] == 1 && i[j] == 0) {                  
                meet = false;
                break;
            }
        }
        if (meet) {
            count++;
        }
    }
    return (double)count;
}


int main() {
    vector<int> basic = {0,0,0,0,0};
    vector< vector<int> > database;
    string inputName; //= "test.txt";
    cout << "Please input file name: ";
    cin >> inputName;

    double min_supp,min_conf;
    cout << "Please input min_supp: ";
    cin >> min_supp;
    cout << "Please input min_conf: ";
    cin >> min_conf;

    ifstream inputFile;
    inputFile.open(inputName.c_str());
    if (!inputFile.is_open())
    {
        cerr << inputName << " not open" << endl;
        return 0;
    }
    
    int num,i=0;
    string bought;
    while (inputFile >> num >> bought) {
        database.push_back(basic);
        for (auto& s : bought) {
            if (s==',') continue;
            database[i][s-65]++;
        }
        i++; 
    }

    inputFile.close();

    vector<int> t = {0,0,0,0,0};
    vector< vector<int> > freq_patt;
    
    for (t[4]=0; t[4]<=1; t[4]++) {
        for (t[3]=0; t[3]<=1; t[3]++) {
            for (t[2]=0; t[2]<=1; t[2]++) {
                for (t[1]=0; t[1]<=1; t[1]++) {
                    for (t[0]=0; t[0]<=1; t[0]++) {
                        if ( t[0]+t[1]+t[2]+t[3]+t[4]==0 ) continue;
                        if ( GetCount(t,database) / database.size() >= min_supp ) freq_patt.push_back(t);
                    }
                }
            }
        }
    }

    cout << "Frequent patterns" << endl;
    for (auto& i : freq_patt) {
        for (int j=0; j<5; j++) {
            if (i[j] == 0) continue;
            cout << (char) (j+65) << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector< vector< vector<int> > > strong_rule;
    for (auto& i : freq_patt) { 
        switch (i[0]+i[1]+i[2]+i[3]+i[4]) {
            case 1: continue;
            case 2:
                for (int j=0; j<5; j++) {
                    if (i[j] == 0) continue;
                    vector<int> pre,effect;
                    pre.assign(i.begin(), i.end()); pre[j]=0;
                    for (int k=0; k<5; k++) effect.push_back(i[k]-pre[k]);
                    if ( GetCount(i,database) / GetCount(pre,database) >= min_conf ) strong_rule.push_back({pre,effect});
                }
                break;
            case 3:
                for (int j=0; j<5; j++) {
                    if (i[j] == 0) continue;
                    vector<int> pre,effect;
                    pre.assign(i.begin(), i.end()); pre[j]=0;
                    for (int k=0; k<5; k++) effect.push_back(i[k]-pre[k]);
                    if ( GetCount(i,database) / GetCount(pre,database) >= min_conf ) strong_rule.push_back({pre,effect});
                    if ( GetCount(i,database) / GetCount(effect,database) >= min_conf ) strong_rule.push_back({effect,pre});
                }
                break;
            case 4:
                for (int j=0; j<5; j++) {
                    if (i[j] == 0) continue;
                    vector<int> pre,effect;
                    pre.assign(i.begin(), i.end()); pre[j]=0;
                    for (int k=0; k<5; k++) effect.push_back(i[k]-pre[k]);
                    if ( GetCount(i,database) / GetCount(pre,database) >= min_conf ) strong_rule.push_back({pre,effect});
                    if ( GetCount(i,database) / GetCount(effect,database) >= min_conf ) strong_rule.push_back({effect,pre});
                }
                for (int j=0; j<5; j++) {
                    if (i[j] == 0) continue;
                    for (int k=j+1; k<5; k++) {
                        if (i[k] == 0) continue;
                        vector<int> pre,effect;
                        pre.assign(i.begin(), i.end()); pre[j]=0; pre[k]=0;
                        for (int x=0; x<5; x++) effect.push_back(i[x]-pre[x]);
                        if ( GetCount(i,database) / GetCount(pre,database) >= min_conf ) strong_rule.push_back({pre,effect});
                        if ( GetCount(i,database) / GetCount(effect,database) >= min_conf ) strong_rule.push_back({effect,pre});
                    }
                    break;
                }
                break;
        }
    }

    cout << "Strong association rules" << endl;
    for (auto& i : strong_rule) {
        for (int j=0; j<5; j++) {
            if (i[0][j] == 0) continue;
            cout << (char) (j+65) << " ";
        }
        cout << "-> ";
        for (int j=0; j<5; j++) {
            if (i[1][j] == 0) continue;
            cout << (char) (j+65) << " ";
        }
        cout << endl;
    }

    return 0;
}
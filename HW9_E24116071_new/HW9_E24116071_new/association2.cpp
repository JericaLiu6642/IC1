#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

set<vector<string>> GetSub( set<string> sets ) {
    vector<vector<string>> v;
    vector<string> subset;
    v.push_back(subset);
    for (auto& i : sets) {
        int count = v.size();
        for (int j=0; j<count; j++) {
            v.push_back(v[j]);
            v[v.size()-1].push_back(i);
        }
    }
    set<vector<string>> ret(v.begin()+1, v.end());
    ret.erase(vector<string>(sets.begin(), sets.end()));
    return ret;
}

set<vector<string>> GetSub( vector<string> sets ) {
    vector<vector<string>> v;
    vector<string> subset;
    v.push_back(subset);
    for (auto& i : sets) {
        int count = v.size();
        for (int j=0; j<count; j++) {
            v.push_back(v[j]);
            v[v.size()-1].push_back(i);
        }
    }
    set<vector<string>> ret(v.begin()+1, v.end());
    ret.erase(sets);
    return ret;
}


int main() {
    string inputName= "Dataset.txt";
    // cout << "Please input file name: ";
    // cin >> inputName;
    ifstream inputFile;
    inputFile.open(inputName.c_str());
    if (!inputFile.is_open())
    {
        cerr << inputName << " not open" << endl;
        return 0;
    }

    double min_supp=0.5,min_conf=2./3.;
    // cout << "Please input min_supp: ";
    // cin >> min_supp;
    // cout << "Please input min_conf: ";
    // cin >> min_conf;

    vector<vector<string>> raw_data;
    string line;
    while (getline (inputFile,line)) {
        raw_data.push_back({});
        istringstream ss(line);
        string item;
        ss >> item; getline(ss,item,' ');
        while (getline(ss,item,',')) {
            raw_data[raw_data.size()-1].push_back(item);
        }
    }
    inputFile.close();
    int customers = raw_data.size();

    set<string> all_item;
    vector< set<vector<string>> > customer_sub_set;
    for (auto& i: raw_data) {
        for (auto& j: i) {
            all_item.insert(j);
        }
        customer_sub_set.push_back(GetSub(i));
        customer_sub_set[customer_sub_set.size()-1].insert(i);
    }
    raw_data.clear();

    // set<vector<string>> all_set = GetSub(all_item);
    map<vector<string> , int> frequency_count;
    vector<vector<string>> passed_set;
    for (auto& sets: GetSub(all_item)) { 
        frequency_count[sets] = 0;

        for (auto& i: customer_sub_set) {
            if (i.count(sets)) {
                frequency_count[sets]++;
            }
        }
        
        if ( (double)frequency_count[sets]/customers >= min_supp && sets.size()>1) {
            passed_set.push_back(sets);
        }
    }
    all_item.clear();

    vector< vector <vector <string>>> strong;
    for (auto& sets: passed_set) {
        for (auto& cause: GetSub(sets)) {
            if ( (double) frequency_count[sets] / frequency_count[cause] >= min_conf) {
                set<string> s(sets.begin(),sets.end());
                for (auto& minus: cause) {
                    s.erase(minus);
                }
                strong.push_back({cause,vector<string>(s.begin(),s.end())});
            }        
        }
    }

    // ofstream out;
    // out.open("Dataset_Output.txt");
    // if (!out.is_open())
    // {
    //     cerr << "OutputFile not open" << endl;
    //     return 0;
    // }

    // out << strong.size() << endl;
    // for (auto& st: strong) {
    //     for (int i=0; i < st[0].size(); i++) {
    //         out << st[0][i];
    //         if (i != st[0].size()-1) {
    //             out << ",";
    //         }
    //     }
    //     out << " => ";
    //     for (int i=0; i < st[1].size(); i++) {
    //         out << st[1][i];
    //         if (i != st[1].size()-1) {
    //             out << ",";
    //         }
    //     }
    //     out << endl;
    // }

    // out.close();
    
    
    cout << strong.size() << endl;
    for (auto& st: strong) {
        for (int i=0; i < st[0].size(); i++) {
            cout << st[0][i];
            if (i != st[0].size()-1) {
                cout << ",";
            }
        }
        cout << " => ";
        for (int i=0; i < st[1].size(); i++) {
            cout << st[1][i];
            if (i != st[1].size()-1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    
    return 0;
}
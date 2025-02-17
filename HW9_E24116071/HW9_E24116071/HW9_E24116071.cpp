// HW9_E24116071
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

// remove space and comma from string
vector<string> split(const string& s, vector<string>& help, const char delim1, const char delim2)
{
	help.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, delim1))
	{
		istringstream iss2(temp);
		while (getline(iss2, temp, delim2)) {
			help.push_back(temp);
		}
	}
	return help;
}


int main()
{
	double min_supp, min_conf;
	string filename;

	// opens the file
	cout << "Please input your file name(ex:Example.txt):";
	cin >> filename;
	ifstream inClientFile(filename, ios::in);
	if (!inClientFile.is_open())
	{
		cerr << filename << " can not be opened" << endl;
		exit(1);
	}

	cout << "Please input your min_supp:";
	cin >> min_supp;
	cout << "Please input your min_conf:";
	cin >> min_conf;

	vector<vector<string> > originalData;
	vector<string> help;
	string s;
	stringstream ss(s);
	string t;

	// char we don't want to be put into the vector
	const char delim1 = ',';
	const char delim2 = ' ';
	while (getline(inClientFile, s)) {
		stringstream ss(s);
		string data;
		while (ss >> data)
		{
			split(s, help, delim1, delim2);
		}
		// delete user index from vector
		help.erase(help.begin());
		originalData.push_back(help);
		help.clear();
	}

	// 找所有的item
	set<string> all_item_set;
	for (auto &i : originalData) {
		for (auto &j : i) {
			all_item_set.insert(j);
		}
	}

	// 把set找到的不重複的item存到vector當中
	vector<string> all_item_vec(all_item_set.begin(), all_item_set.end());

	map<vector<string>, int> combinFreq;

	// 找all_item_vec裡一個item存入map 
	vector<string> combin_temp_1;
	combin_temp_1.clear();
	for (int i = 0; i < all_item_vec.size(); i++) {
		combin_temp_1.push_back(all_item_vec[i]);
		combinFreq[combin_temp_1] = 0;
		combin_temp_1.clear();
	}

	// 找all_item_vec裡兩個item的所有組合存入map
	vector<string> combin_temp_2;
	combin_temp_2.clear();
	for (int i = 0; i < all_item_vec.size(); i++) {
		for (int j = i + 1; j < all_item_vec.size(); j++) {
			combin_temp_2.push_back(all_item_vec[i]);
			combin_temp_2.push_back(all_item_vec[j]);
			combinFreq.insert(pair<vector<string>, int>(combin_temp_2, 0));
			combin_temp_2.clear();
		}
	}

	// 找all_item_vec裡三個item的所有組合存入map
	vector<string> combin_temp_3;
	combin_temp_3.clear();
	for (int i = 0; i < all_item_vec.size(); i++) {
		for (int j = i + 1; j < all_item_vec.size(); j++) {
			for (int k = j + 1; k < all_item_vec.size(); k++) {
				combin_temp_3.push_back(all_item_vec[i]);
				combin_temp_3.push_back(all_item_vec[j]);
				combin_temp_3.push_back(all_item_vec[k]);
				combinFreq.insert(pair<vector<string>, int>(combin_temp_3, 0));
				combin_temp_3.clear();
			}
		}
	}

	// 單一商品出現的次數
	vector<string> freq_1;
	for (auto &i : originalData) {
		for (auto &j : i) {
			freq_1.push_back(j);
			combinFreq[freq_1]++;
			freq_1.clear();
		}
	}

	// user如果買了多於1個的商品，則把兩個組合和三個組合取出來，加到map裡
	vector<string> freq_2;
	freq_2.clear();
	vector<string> freq_3_2;
	freq_3_2.clear();
	vector<string> freq_3;
	freq_3.clear();

	for (int i = 0; i < originalData.size(); i++) {
		if (originalData[i].size() == 1) continue;
		if (originalData[i].size() == 2) {
			freq_2.push_back(originalData[i][0]);
			freq_2.push_back(originalData[i][1]);
			combinFreq[freq_2]++;
			freq_2.clear();
		}
		else {
			for (int a = 0; a < originalData[i].size(); a++) {
				for (int b = a + 1; b < originalData[i].size(); b++) {
					freq_3_2.push_back(originalData[i][a]);
					freq_3_2.push_back(originalData[i][b]);
					combinFreq[freq_3_2]++;
					freq_3_2.clear();
				}
			}

			for (int x = 0; x < originalData[i].size(); x++) {
				for (int y = x + 1; y < originalData[i].size(); y++) {
					for (int z = y + 1; z < originalData[i].size(); z++) {
						freq_3.push_back(originalData[i][x]);
						freq_3.push_back(originalData[i][y]);
						freq_3.push_back(originalData[i][z]);
						combinFreq[freq_3]++;
						freq_3.clear();
					}
				}
			}
		}
	}

	// 找通過min_supp的商品有哪些，包含組合
	// 有通過的把key值push back到一個vector
	vector<vector<string>> pass_supp;
	for (const auto& p : combinFreq) {
		if (p.second >= min_supp * originalData.size()) {
			pass_supp.push_back(p.first);
		}
	}

	// 計算strong association的數量
	int counter = 0;
	int molecular = 1;
	double denominator = 1;
	double diff_count = 1;

	vector<string> temp_m;
	vector<string> temp_d;
	vector<vector<vector<string>>> strong;

	/// 寫出檔案
	ofstream out(filename.substr(0, filename.find('.')) + "_Output.txt");

	for (int i = 0; i < pass_supp.size(); i++) {
		if (pass_supp[i].size() == 1) continue;
		if (pass_supp[i].size() == 3) {
			for (int j = 0; j < 3; j++) {
				temp_m.push_back(pass_supp[i][j]);
			}

			for (int a = 0; a < 3; a++) {
				for (int b = a + 1; b < 3; b++) {
					temp_d.push_back(pass_supp[i][a]);
					temp_d.push_back(pass_supp[i][b]);
					denominator = combinFreq[temp_d];
					molecular = combinFreq[temp_m];
					//把vector轉set 用set erase 的功能取差集
					set<string> temp_m_set(temp_m.begin(), temp_m.end());
					for (auto& minus : temp_d) {
						temp_m_set.erase(minus);
					}
					// 轉回vector
					vector<string> diff(temp_m_set.begin(), temp_m_set.end());
					// 反轉再做一次關係
					diff_count = combinFreq[diff];

					if (molecular / denominator >= min_conf) {
						counter++;
						if (!temp_d.empty()) {
							if (!diff.empty()) {
								strong.push_back({ temp_d, diff });
							}
						}
					}
					if (molecular / diff_count >= min_conf) {
						counter++;
						if (!temp_d.empty()) {
							if (!diff.empty()) {
								strong.push_back({ diff, temp_d });
							}
						}
					}
				}
			}
		}
		else {
			denominator = combinFreq[vector<string>{ pass_supp[i][0] }];
			molecular = combinFreq[pass_supp[i]];
			set<string> temp_m_set(pass_supp[i].begin(), pass_supp[i].end());
			temp_m_set.erase(pass_supp[i][0]);

			vector<string> diff(temp_m_set.begin(), temp_m_set.end());
			diff_count = combinFreq[diff];

			if (molecular / denominator >= min_conf) {
				counter++;
				if (!vector<string>{ pass_supp[i][0] }.empty()) {
					if (!diff.empty()) {
						strong.push_back({ vector<string>{ pass_supp[i][0] }, diff });
					}
				}
			}
			if (molecular / diff_count >= min_conf) {
				counter++;
				if (!vector<string>{ pass_supp[i][0] }.empty()) {
					if (!diff.empty()) {
						strong.push_back({ diff, vector<string>{ pass_supp[i][0] } });
					}
				}
			}
		}
		temp_m.clear();
		temp_d.clear();
	}

	out << counter << endl;
	for (auto& st : strong) {
		for (int i = 0; i < st[0].size(); i++) {
			out << st[0][i];
			if (i != st[0].size() - 1) {
				out << ",";
			}
		}
		out << " => ";
		for (int i = 0; i < st[1].size(); i++) {
			out << st[1][i];
			if (i != st[1].size() - 1) {
				out << ",";
			}
		}
		out << endl;
	}

	return 0;
}

/*
//HW9_E24116071
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

void print2DVector(vector<vector<string>>&);
void print1DVector(vector<string>&);
vector<vector<int>> createCombin(vector<vector<int>>& , vector<string> );
vector<string> split(const string& s, vector<string>& help, const char delim1, const char delim2);

int main()
{
	double min_supp, min_conf;
	string filename;

	// opens the file
	cout << "Please input your file name(ex:14963_formated.txt):";
	cin >> filename;
	ifstream inClientFile(filename,ios::in);
	if (!inClientFile.is_open())
	{
		cerr << filename << "can not be opened" << endl;
		exit(1);
	}

	cout << "Please input your min_supp:";
	cin >> min_supp;
	cout << "Please input your min_conf:";
	cin >> min_conf;

	vector<vector<string> > originalData;
	vector<string> help;
	string s;
	stringstream ss(s);
	string t;

	// char we don't want to be put into the vector
	const char delim1 = ',';
	const char delim2 = ' ';
	while (getline(inClientFile, s)) {
		stringstream ss(s);
		string data;
		while (ss >> data)
		{
			split(s, help, delim1, delim2);
		}
		// delete user index from vector
		help.erase(help.begin());
		originalData.push_back(help);
		help.clear();
	}
	
	
	// 找所有的item
	set<string> all_item_set;
	for (auto &i : originalData){
		for (auto &j : i) {
			all_item_set.insert(j);
		}
	}

	// 把set找到的不重複的item存到vector當中
	vector<string> all_item_vec;
	all_item_vec.assign(all_item_set.begin(), all_item_set.end());
	all_item_vec.insert(all_item_vec.begin(), "x"); 	// 讓商品編號和取組合的index對齊

	///開始找所有組合
	vector<vector<int>> a; //record all combination
	a = createCombin(a, all_item_vec);

	string tempCombination;
	tempCombination.clear();
	map <string, int> combinFrequency;

	// 把組合用字串相加的方式當作map的key
	for (vector<vector<int>>::iterator i = a.begin(); i != a.end(); i++){
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			tempCombination += all_item_vec[*j];
		}
		combinFrequency.insert(pair<string, int>(tempCombination, 0));
		tempCombination.clear();
	}
	
	vector<string> ori_row_combin;
	string ori_row_temp;
	ori_row_temp.clear();
	vector<vector<int>> k; //record all combination
	ori_row_combin.insert(ori_row_combin.begin(), "x");
	
	for (vector<vector<string>>::iterator i = originalData.begin(); i != originalData.end(); i++) {
		for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
			ori_row_combin.push_back(*j);
		}

		k = createCombin(k, ori_row_combin);

		for (vector<vector<int>>::iterator i = k.begin(); i != k.end(); i++) {
			for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
				ori_row_temp += ori_row_combin[*j];
			}
			combinFrequency[ori_row_temp]++;
			ori_row_temp.clear();
		}
		ori_row_combin.clear();
		ori_row_combin.insert(ori_row_combin.begin(), "x");
	}
	
	
	for (const auto& s : combinFrequency) {
	std::cout << "item: " << s.first << ", frequency: " << s.second << "\n";
	}
	


	
	// to find all item index
	set<string> all_item;
	vector<vector<int>> a; //record all combination
	for (vector<vector<string>>::iterator i = originalData.begin(); i != originalData.end(); i++)
	{
		for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
			all_item.insert(*j);
		}
	}

	vector<string> allElement;
	string tempCombination;
	map <string, int> combinFrequency;
	tempCombination.clear();
	allElement.assign(all_item.begin(), all_item.end());
	allElement.insert(allElement.begin(), "x"); 	// 讓商品編號和取組合的index對齊

	createCombin(a, allElement);

	// 把組合用字串相加的方式當作map的key
	for (vector<vector<int>>::iterator i = a.begin(); i != a.end(); i++)
	{
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			tempCombination += allElement[*j];
		}
		combinFrequency.insert(pair<string, int>(tempCombination, 0));
		tempCombination.clear();
	}

	// 跑原始資料，計算單一item出現的頻率
	for (vector<vector<string>>::iterator i = originalData.begin(); i != originalData.end(); i++){
		for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
			++combinFrequency[*j];
		}
	}
	

	///print set
	for (const auto &s : all_item) {
		std::cout << s << " ";
	}

	///print input file
	print2DVector(originalData);
	


	// output answer to new file
	ofstream outClientFile(filename + "_Output");

	
	if (!outClientFile)
	{
		cerr << "File can not be opened" << endl;
		exit(1);
	}
}


// print the vector to ensure there are values in it
void print2DVector(vector<vector<string>>& originalData)
{
	for (vector<vector<string>>::iterator i = originalData.begin(); i != originalData.end(); i++)
	{
		for (vector<string>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
}

void print1DVector(vector<string>& a)
{
	for (vector<string>::iterator i = a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	}
}

// remove space and comma from string
vector<string> split(const string& s, vector<string>& help, const char delim1, const char delim2)
{
	help.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, delim1))
	{
		istringstream iss2(temp);
		while (getline(iss2, temp, delim2)) {
			help.push_back(temp);
		}
	}
	return help;
}

vector<vector<int>> createCombin(vector<vector<int>>& a, vector<string> allElement)
{
	int n = allElement.size() - 1;
	vector<int> b;   // record one kind of combination

	int stateCount = 1 << n;
	for (int i = 0; i < stateCount; ++i) 
	{
		for (int j = 0; j < n; ++j) 
			if ((1 << j) & i)
				b.push_back(j + 1);
		if (!b.empty())
		{
			a.push_back(b);
		}
		b.clear();
	}
	return a;
}
*/
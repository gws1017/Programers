#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include <iostream>

using namespace std;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {

	vector<int> answer(id_list.size(), 0);

	unordered_map<string, int> count;
	unordered_map<string, unordered_set<string>> list;
	for (int i = 0; i < id_list.size(); ++i) // muzi frodo neo 0 1 2
		count[id_list[i]] = i;


	stringstream ss;
	vector<string> str;
	string first, second;
	for (const auto& info : report)
	{
		ss.clear();
		ss.str(info);
		ss >> first >> second;
		list[second].insert(first);
		str.clear();
	}

	for (const auto it : list) // frodo {muzi, neo} muzi {frodo}
	{
		int cnt = 0;
		if (it.second.size() >= k)
		{
			for (auto set_it : it.second) {
				answer[count[set_it]]++;
			}
		}

	}


	return answer;
}

int main()
{
	vector<string> id_list = {
		"muzi","frodo",
		"apeach", "neo"
	};
	vector<string> report = {
		"muzi frodo", "apeach frodo",
		"frodo neo", "muzi neo",
		"apeach muzi"
	};

	vector<string> id_list2 = {
		"muzi","frodo","neo"
	};
	vector<string> report2 = {
		"muzi frodo", "frodo muzi", "neo frodo"
	};


	/*vector<string> id_list2 = {
		"con","ryan"
	};
	vector<string> report2 = {
		"ryan con", "ryan con", "ryan con", "ryan con"
	};*/
	auto result = solution(id_list2, report2, 2);

	for (auto ret : result)
		cout << ret <<" ";
	cout << endl;
}
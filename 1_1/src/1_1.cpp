#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include <iostream>

using namespace std;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {

	vector<int> answer(id_list.size(),0);

	unordered_map<string, int> count;
	unordered_map<string, unordered_set<string>> list;
	for(int i = 0; i<id_list.size(); ++i)
		count[id_list[i]] = (0);


	stringstream ss;
	vector<string> str;
	string first, second;
	for (const auto& info : report)
	{
		ss.clear();
		ss.str(info);
		ss >> first >> second;
		auto ret = list[first].insert(second);
		if(ret.second)
			count[second]++;
		str.clear();
	}

	unordered_set<string> black_list;
	for (const auto [id, cnt] : count)
	{
		if (cnt >= k) black_list.insert(id);
	}

	unordered_map<string, int> mail;
	for (const auto& [id, o_ids] : list) // muzi frodo neo
	{
		int cnt = 0;
		for (const auto& o_id : o_ids) // frodo neo
		{
			for (const auto& b_id : black_list)
			{
				if (o_id == b_id)
				{
					cnt++;
					break;
				}
			}
		}
		mail.insert({ id,cnt });
	}
	int index = 0;
	for (auto [id, cnt] : mail)
	{
		answer[index++] = cnt;
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
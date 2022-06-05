#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

//함수를 위쪽에선언하기
int result(int value)
{
    switch (value)
    {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zero = 0;
    set<int> nums;

    for (auto value : lottos)
    {
        if (value == 0)
            zero++;
        else
            nums.insert(value);
    }

    int same = 0;
    for (auto value : win_nums)
    {
        if (nums.insert(value).second == false)
            same++;
    }

    answer.push_back(result(same+zero)); // 최고
    answer.push_back(result(same)); // 최저

    return answer;
}



int main()
{
    //vector<int> lottos = { 44,1,0,0,31,25 };
    vector<int> lottos = {0,0,0,0,0,0 };
    //vector<int> lottos = { 45,4,35,20,3,9};

    //vector<int> win_nums = { 31,10,45,1,6,19 };
    //vector<int> win_nums = { 20,9,3,45,4,35 };
    vector<int> win_nums = { 38,19,20,40,15,25 };

    auto ans = solution(lottos, win_nums);

    for (auto lank : ans)
        cout << lank << " ";
    cout << endl;
}
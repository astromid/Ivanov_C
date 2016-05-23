#include <thread>
#include <mutex>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

typedef string::iterator sIt;
mutex mut;

void thread_search(sIt begin, sIt end, vector<int>& ans, string sought)
{
	const sIt start_pos = begin;
	int len = sought.length() - 1;
	//перекрываем chunk'и
	advance(end, len);
	do
	{
		begin = search(begin, end, std::begin(sought), std::end(sought));
		if (begin != end)
		{
			mut.lock();
			ans.push_back(distance(begin, start_pos));
			mut.unlock();
			advance(begin, len);
		}
	} while (begin != end);
}

int search_count(sIt begin, sIt end, string sought, const int thread_num)
{
	vector<int> ans;
	vector<thread> threads(thread_num);
	int part_diff = distance(begin, end) / thread_num;
	int len = sought.length() - 1;
	for (int i = 0; i < thread_num - 1; ++i)
	{
		threads[i] = thread(thread_search, begin, begin + part_diff, ref(ans), sought);
		advance(begin, part_diff - len);
	}
	threads[thread_num-1] = thread(thread_search, begin, begin + part_diff - len, ref(ans), sought);
	for (int i = 0; i < thread_num; ++i)
	{
		threads[i].join();
	}
	return ans.size();
}

int main()
{
	ifstream text("text.txt");
	string buf;
	while (text.good())
	{
		string str;
		getline(text, str);
		buf += str;
	}
	text.close();
	string sought = "кольцо";
	for (int i = 1; i < 51; ++i)
	{
		clock_t cl1, cl2;
		cl1 = clock();
		int N = search_count(begin(buf), end(buf), sought, i);
		cl2 = clock();
		cout << i << " threads: N = " << N << ", time = " << (float)(cl2 - cl1) / CLOCKS_PER_SEC << "s" << endl;
	}
	system("pause");
	return 0;
}
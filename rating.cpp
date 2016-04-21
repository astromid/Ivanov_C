#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
	struct film
	{
		string film_name;
		unsigned int points = 0;
		list<int> first_users;
		list<int> second_users;
		list<int> third_users;
	};

	fstream films_file;
	fstream user_marks;
	films_file.open("films.txt", fstream::in);
	user_marks.open("rating.txt", fstream::in);
	vector<film> films;
	while (films_file.good())
	{
		film tmp_film;
		getline(films_file, tmp_film.film_name);
		films.push_back(tmp_film);
	}
	films_file.close();
	int film_count = films.size();
	int user_count = 0;
	while (user_marks.good())
	{
		int first, second, third;
		user_marks >> first >> second >> third;

		films[first].points += 3;
		films[second].points += 2;
		films[third].points += 1;

		films[first].first_users.push_back(user_count);
		films[second].second_users.push_back(user_count);
		films[third].third_users.push_back(user_count);

		user_count++;
	}
	user_marks.close();
	vector<int> film_points(film_count);
	for (int i = 0; i < film_count; i++)
	{
		film_points[i] = films[i].points;
	}
	
	//формирование списка победителей
	vector<int>::iterator f_beg = film_points.begin();
	vector<int>::iterator f_end = film_points.end();

	vector<int>::iterator first_place = max_element(f_beg, f_end);
	int first_place_num = count(f_beg, f_end, *first_place);
	vector<int> first_index(first_place_num);
	int index = 0;
	while (first_place_num > 0)
	{
		first_place = max_element(f_beg, f_end);
		first_index[index] = distance(f_beg, first_place);
		*first_place = 0;
		first_place_num--;
		index++;
	}

	vector<int>::iterator second_place = max_element(f_beg, f_end);
	int second_place_num = count(f_beg, f_end, *second_place);
	vector<int> second_index(second_place_num);
	index = 0;
	while (second_place_num > 0)
	{
		second_place = max_element(f_beg, f_end);
		second_index[index] = distance(f_beg, second_place);
		*second_place = 0;
		second_place_num--;
		index++;
	}

	vector<int>::iterator third_place = max_element(f_beg, f_end);
	int third_place_num = count(f_beg, f_end, *third_place);
	vector<int> third_index(third_place_num);
	index = 0;
	while (third_place_num > 0)
	{
		third_place = max_element(f_beg, f_end);
		third_index[index] = distance(f_beg, third_place);
		*third_place = 0;
		third_place_num--;
		index++;
	}

	//вывод победителей и заодно раздача поинтов юзерам
	vector<int> user_points(user_count);

	cout << "AND OUR OSCARS GO TO:" << endl;
	cout << "FIRST PLACES: " << endl;
	index = 0;
	for (int i : first_index)
	{
		index++;
		cout << index << ". " << films[i].film_name << endl;
		for (int j : films[i].first_users)
		{
			user_points[j] += 3;
		}
		for (int j : films[i].second_users)
		{
			user_points[j] += 2;
		}
		for (int j : films[i].third_users)
		{
			user_points[j] += 1;
		}
	}
	cout << "-------------------" << endl;
	cout << "SECOND PLACES: " << endl;
	index = 0;
	for (int i : second_index)
	{
		index++;
		cout << index << ". " << films[i].film_name << endl;
		for (int j : films[i].first_users)
		{
			user_points[j] += 2;
		}
		for (int j : films[i].second_users)
		{
			user_points[j] += 3;
		}
		for (int j : films[i].third_users)
		{
			user_points[j] += 2;
		}
	}
	cout << "-------------------" << endl;
	cout << "THIRD PLACES: " << endl;
	index = 0;
	for (int i : third_index)
	{
		index++;
		cout << index << ". " << films[i].film_name << endl;
		for (int j : films[i].first_users)
		{
			user_points[j] += 1;
		}
		for (int j : films[i].second_users)
		{
			user_points[j] += 2;
		}
		for (int j : films[i].third_users)
		{
			user_points[j] += 3;
		}
	}

	//формирование списка выдающихся юзеров
	vector<int>::iterator u_beg = user_points.begin();
	vector<int>::iterator u_end = user_points.end();

	vector<int>::iterator user_win = max_element(u_beg, u_end);
	int user_place_num = count(u_beg, u_end, *user_win);
	vector<int> user_index(user_place_num);
	index = 0;
	while (user_place_num > 0)
	{
		user_win = max_element(u_beg, u_end);
		user_index[index] = distance(u_beg, user_win);
		*user_win = 0;
		user_place_num--;
		index++;
	}
	cout << "-------------------" << endl;
	cout << "AND OUR USER WINNERS ARE:" << endl;
	index = 0;
	for (int i : user_index)
	{
		index++;
		cout << index << ". " << "User #" << i << endl;
	}
	cout << "Congratulations..." << endl;
	system("pause");
	return 0;
}
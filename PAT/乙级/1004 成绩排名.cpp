#include <iostream>
#include <cstring>
using namespace std;
struct stu
{
	char name[12];
	char number[12];
	int grade;
};
int main()
{
	int n;
	cin >> n;
	stu* arr = new stu[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i].name >> arr[i].number >> arr[i].grade;
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].grade > arr[x].grade)
			x = i;
		if (arr[i].grade < arr[y].grade)
			y = i;
	}
	cout << arr[x].name << ' ' << arr[x].number << endl;
	cout << arr[y].name << ' ' << arr[y].number << endl;
	delete[] arr;
	return 0;
}
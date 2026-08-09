#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct meeting {
	int idx;
	int start;
	int end;
};

bool cmp(meeting &a, meeting &b) { return a.end < b.end; }

void print_meeting(vector<meeting> &arr) {
	sort(arr.begin(), arr.end(), cmp);
	meeting last = arr[0];
	cout << last.idx << " ";
	for (int i = 1; i < arr.size(); i++) {
		if (last.end < arr[i].start) {
			cout << arr[i].idx << " ";
			last = arr[i];
		}
	}
}

int main() {
	int n;
	cout << "Total no of meetings \n";
	cin >> n;
	int i = 0;
	vector<meeting> arr;
	while (n--) {
		meeting m;
		i++;
		cout << "Enter the start and end of meeting \n";
		cin >> m.start;
		cin >> m.end;
		m.idx = i;
		arr.push_back(m);
	};

	print_meeting(arr);

	return 0;
}
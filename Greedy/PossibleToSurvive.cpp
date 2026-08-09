#include <cmath>
#include <iostream>
using namespace std;

using namespace std;

int main() {
	int S, M, N;
	cout << "Numbers of days you are require to survive\n";
	cin >> S;
	cout << "Maximum unit of food you can buy each day\n";
	cin >> N;
	cout << "Unit of food required each day to survive\n";
	cin >> M;
	int totalFoodRequired, maxAmountPossible;
	if (S <= 6) {
		totalFoodRequired = S * M;
		maxAmountPossible = S * N;
		if (totalFoodRequired > maxAmountPossible) {
			cout << "Insufficiient food survival not possible\n";
			return 0;
		}
		cout << "total days to buy food" << ceil((double)totalFoodRequired / N);
		return 0;

	} else {
		int x = S / 7;
		totalFoodRequired = S * M;
		maxAmountPossible = (S - x) * N;
		if (totalFoodRequired > maxAmountPossible) {
			cout << "Insufficiient food survival not possible\n";
			return 0;
		}
		cout << "total days to buy food" << ceil((double)totalFoodRequired / N);
	}

	return 0;
}
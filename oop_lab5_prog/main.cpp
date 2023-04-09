#include "CMultiSet.h"

int main() {
	CMultiSet arr(5);
	int set = 0;
	cout << "Input: " << endl;
	for (int i = 0; i < arr.cardinality(); i++) {
		cin >> set;
		arr.setElement(set, i);
	}

	cout << "Output first multiset: ";
	cout << arr;

	CMultiSet arr2(5);
	cout << "Input: " << endl;
	for (int i = 0; i < arr2.cardinality(); i++) {
		cin >> set;
		arr2.setElement(set, i);
	}

	cout << "Output: " << endl;
	for (int i = 0; i < arr2.cardinality(); i++) {
		cout << arr2.getElement(i);
		cout << "  ";
	}

	cout << endl;
	cout << "Max: " << arr.findMax() << endl;
	cout << "Min: " << arr.findMin() << endl;
	cout << "4: " << arr.countOfCertainElement(4) << endl;
	cout << "Power: " << arr.cardinality() << endl;

	//cout << "Add new element: " << endl;
	//cin >> set;
	//arr.addElement(set);
	//cout << "Output after adding: " << endl;
	//for (int i = 0; i < arr.cardinality(); i++) {
	//	cout << arr.getElement(i);
	//	cout << "  ";
	//}
	//cout << endl;

	//cout << "Delete element: " << endl;
	//cin >> set;
	//arr.deleteElement(set);
	//cout << "Output after deleting: " << endl;
	//for (int i = 0; i < arr.cardinality(); i++) {
	//	cout << arr.getElement(i);
	//	cout << "  ";
	//}

	CMultiSet unions = arr + arr2;
	cout << "Output: " << endl;
	for (int i = 0; i < unions.cardinality(); i++) {
		cout << unions.getElement(i);
		cout << "  ";
	}
	CMultiSet intersection = arr - arr2;
	cout << "Output: " << endl;
	for (int i = 0; i < intersection.cardinality(); i++) {
		cout << intersection.getElement(i);
		cout << "  ";
	}
}
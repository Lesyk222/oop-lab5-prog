#include "CMultiSet.h"

CMultiSet::CMultiSet(int capacity) {
	this->size = capacity;
	values = new int[size];
}

CMultiSet::~CMultiSet() {
	delete[] values;
}

void CMultiSet::setElement(int num, int index) {
	values[index] = num;
}

int CMultiSet::getElement(int index) const {
	return values[index];
}

int CMultiSet::countOfCertainElement(int value) const {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == value)
			count++;
	}
	return count;
}

int CMultiSet::cardinality() const {
	return size;
}

int CMultiSet::findMax() const {
	int max = values[0];
	for (int i = 0; i < size; i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}
	return max;
}

int CMultiSet::findMin() const {
	int min = values[0];
	for (int i = 0; i < size; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}
	return min;
}

void CMultiSet::addElement(int temp) {
	size++;
	int* newValues = new int[size];
	for (int i = 0; i < size; i++) {
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
	values[size-1] = temp;
}

void CMultiSet::deleteElement(int temp) {
	temp--;
	size--;
	for (int i = temp; i < size; i++) {
		values[i] = values[i + 1];
	}
	int* newValues = new int[size];
	for (int i = 0; i < size; i++) {
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
}

CMultiSet CMultiSet::operator+(const CMultiSet& other) const {
	CMultiSet unions(0);
	for (int i = 0; i < size; i++) {
		unions.addElement(values[i]);
	}
	for (int i = 0; i < other.cardinality(); i++) {
		unions.addElement(other.values[i]);
	}
	return unions;
}

CMultiSet CMultiSet::operator-(const CMultiSet& other) const {
	CMultiSet unions(0);
	return unions;
}

CMultiSet CMultiSet::operator/(const CMultiSet& other) const {
	return 0;
}

istream& operator>> (istream& input, CMultiSet value) {
	int set = 0;
	for (int i = 0; i < value.cardinality(); i++) {
		input >> set;
		value.setElement(set, i);
	}
	return input;
}

ostream& operator<< (ostream& output, CMultiSet value) {
	output << endl;
	for (int i = 0; i < value.cardinality(); i++) {
		output << value.values[i] << " ";
	}
	output << endl;
	return output;
}
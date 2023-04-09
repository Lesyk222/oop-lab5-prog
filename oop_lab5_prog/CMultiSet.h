#include <iostream>

using namespace std;

class CMultiSet
{
private: 
	int* values;
	int size;
public:
    CMultiSet(int capacity = 0);
    ~CMultiSet();

    void setElement(int num, int index);
    int getElement(int index) const;

    int countOfCertainElement(int value) const;
    int cardinality() const;
    int findMax() const;
    int findMin() const;
    void addElement(int temp);
    void deleteElement(int temp);

    CMultiSet operator+(const CMultiSet& value) const;
    CMultiSet operator-(const CMultiSet& value) const;
    CMultiSet operator/(const CMultiSet& value) const;
    friend istream& operator>> (istream& input, CMultiSet value);
    friend ostream& operator<< (ostream& output, CMultiSet value);
};
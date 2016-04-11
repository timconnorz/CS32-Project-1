
using namespace std;

typedef std::string ItemType;

const int DEFAULT_MAX_ITEMS = 100;

class Set
{
public:
	Set();         // Create an empty set.

	bool empty() const;  // Return true if the set is empty, otherwise false.

	int size() const;    // Return the number of items in the set.

	bool insert(ItemType& value);		//erased a const
	// Insert value into the set if it is not already present.  Return
	// true if the value was actually inserted.  Leave the set unchanged
	// and return false if the value was not inserted (perhaps because it
	// is already in the set or because the set has a fixed capacity and
	// is full).
	bool erase(ItemType& value);	//erased a const
	// Remove the value from the set if present.  Return true if the
	// value was removed; otherwise, leave the set unchanged and
	// return false.

	bool contains(const ItemType& value) const;
	// Return true if the value is in the set, otherwise false.

	bool get(int i, ItemType& value) const;
	// If 0 <= i < size(), copy into value an item in the set and
	// return true.  Otherwise, leave value unchanged and return false.
	// (See below for details about this function.)

	void swap(Set& other);
	// Exchange the contents of this set with the other one.

private: 
	ItemType m_array[DEFAULT_MAX_ITEMS];
	int m_array_size = 1;
};

Set::Set() {
	
}

bool Set::empty() const {
	if (m_array_size == 0)
		return 1;
	else
		return 0;
}

int Set::size() {
	return m_array_size;
}

bool Set::insert(ItemType& value) {	//erased a 'const'
	if (contains(value))
		return 0;
	ItemType newArray[m_array_size + 1];
	for (int i = 0; i < m_array_size; i++)
		m_array[i] = newArray[i];
	newArray[m_array_size + 1] = value;
	m_array_size = m_array_size + 1;
	m_array = newArray;
	return 1;
}

bool Set::erase(ItemType& value) {	//erased a 'const'
	if (!contains(value))
		return 0;
	int pos = 0;
	for (int j = 0; j < m_array_size; j++)
		if (m_array[j] == value) {
			pos = j;
			break;
		}
	ItemType newArray[m_array_size - 1];
	for (int i = 0; i < pos; i++)
		m_array[i] = newArray[i];
	for (int i = pos + 1; i < m_array_size - 1; i++)
		m_array[i] = newArray[i-1];
	m_array_size = m_array_size - 1;
}

bool Set::contains(const ItemType& value) const {
	int p = find(m_array, m_array + m_array_size; value);
	if (p)
		return 1;
	else
		return 0;
}

bool get(int i, ItemType& value) const {

}

void swap(Set& other){

}

using namespace std;

class string_set {
public:
	/*Purpose
		initialize the set to contain no elements
	* Preconditions
		none
	* Exceptions
		none
	*/
	string_set();

	/*Purpose
	*	add s to the set
	*	if s is successfully added, reset the iterator
	* Preconditions
	*	s is a legal string
	* Exceptions
	*	if s is already present then throw duplicate_exception
	*	else if s there is not enough memory to add s then throw memory_exception
	*/
	void add(const char *s);

	/*Purpose
	*	remove s from the set
	*	if s is successfully removed, reset the iterator
	* Preconditions
	*	s is a legal string
	* Exceptions
	*	if s is not present then throw not_found_exception
	*/
	void remove(const char *s);

	/*Purpose
	*	return 1 if s is in the set and 0 otherwise
	* Preconditions
	*	s is a legal string
	* Exceptions
	*	none
	*/
	int contains(const char *s);

	/*Purpose
	*	reset the iterator to the first element
	* Preconditions
	*	none
	* Exceptions
	*	none
	*/
	void reset();

	/*Purpose
	*	return a pointer to the next set element
	*	return NULL if no more elements remain
	* Preconditions
	*	none
	* Exceptions
	*	none
	*/
	const char *next();

	/*Purpose
	*	delete all dynamically allocated memory
	* Preconditions
	*	none
	* Exceptions
	*	none
	*/
	~string_set();
private:
	/*Purpose
	*	return the hash value h associated with s
	*	h must consist of: (sum of the characters in s) mod HASH_TABLE_SIZE
	* Preconditions
	*	s is a legal string
	* Exceptions
	*	none
	* Examples
	*	hash_function("a") returns 97
	*	hash_function("ab") returns 195
	*	hash_function("ba") returns 195
	*	hash_function("") returns 0
	*/
	int hash_function(const char *s);

	enum {HASH_TABLE_SIZE = 100};

	class node {
		public:
		char *s;
		node *next;
	};

	// hash_table[i] is the head of a linked list of nodes
	node *hash_table[HASH_TABLE_SIZE];

	// iterator position
	int iterator_index; // index in hash_table
	node *iterator_node; // node in hash_table[iterator_index];
};

// MOVE TO INNER CLASSES?
class duplicate_exception { };
class memory_exception { };
class not_found_exception { };

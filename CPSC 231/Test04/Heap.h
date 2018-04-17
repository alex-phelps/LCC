/*********************************
 * Heap class declaration
 *********************************/

#define HEAP_MAX 31

template <class item>
class heap
{ public:
    heap();                   // Constructor
    int  size();              // Return size
    void dump(ostream &out);  // Dump data to output
    bool insert(item);        // Insert data
    item remove();            // Remove data
  private:
    int n;                    // Number of items
    item data[HEAP_MAX];      // Data storage
};

/*********************************
 * Constructor
 *********************************/
template <class item>
heap<item>::heap()
{ n = 0;
}

/*********************************
 * Size
 *********************************/
template <class item>
int heap<item>::size()
{ return n;
}

/*********************************
 * Dump
 *********************************/
template <class item>
void heap<item>::dump(ostream &out)
{ int i;
  for(i=0;i<n;i++)
    { cout << setw(4) << left << i;
      cout << data[i];
      cout << endl;
    };
}

/*********************************
 * Insert
 *********************************/
template <class item>
bool heap<item>::insert(item arg)
{ 
	if (n >= HEAP_MAX) // no room
		return false;

	data[n] = arg;
	int i = n++; //item index; also increment n
	int parent = (i - 1) / 2; // parent index

	while (data[parent] < data[i])
	{
		swap(data[parent], data[i]);
		i = parent;
		parent = (i - 1) / 2;
	}


	return true;
}

/*********************************
 * Remove
 *********************************/
template <class item>
item heap<item>::remove()
{ return data[0];
}

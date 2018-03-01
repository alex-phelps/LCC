// Box class definition

class box
{ public:
    box(int h=0,int w=0);           // Constructor
    ~box();                         // Destructor
    bool   get(istream &in);        // Input dimensions
    void   put(ostream &out);       // Output dimensions
    float  area();                  // Calculate area
    float  perimeter();             // Calculate perimeter
	bool operator==(const box &b);

  private:
    int height,width;               // Dimensions
};

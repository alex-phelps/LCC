/*********************************
 * Bag header
 * Created by Mark Bowman
 *********************************/

#define BAG_COLOR_MAX  5

class bag
{ enum color_type { Red,Yellow,Green,Blue,Purple };

  public:
    bag(int r=0,int y=0,int g=0,int b=0,int p=0);  // Constructor with defaults
    bool get(istream &);                           // Input
    void put(ostream &);                           // Output
    bag operator + (const bag &b);                 // Add two bags together

  private:
    int color[BAG_COLOR_MAX];                      // Candy in bag
};

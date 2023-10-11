#include <iostream>

using namespace std;

//#define SPRING
//#define SUMMER
#define AUTUMN
// WINTER
#define TRANSFORM(x) #x

void season(){

#ifdef SPRING
     cout << TRANSFORM(SPRING)<<endl;
#endif
#ifdef SUMMER
    cout << TRANSFORM(SUMMER)<<endl;
#endif
#ifdef AUTUMN
    cout << TRANSFORM(AUTUMN)<<endl;
#endif
#ifdef WINTER
    cout << TRANSFORM(WINTER)<<endl;
#endif
}

int main() {

    season();
}
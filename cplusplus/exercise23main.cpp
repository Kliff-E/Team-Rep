#include "exercise23.h"

int main()
{
    Point p1(0, 0);
    Circle c1(p1, 5.0f);
    Circle c2(p1, 5.0f);
    Circle c3(p1, 3.0f);

    Square s1(3.0f);

    if (c1 == c2)
    {
        std::cout << "c1 and c2 are equal!" << std::endl;
    }
    else
    {
        std::cout << "c1 and c2 are not equal!" << std::endl;
    }

    printAreaOfShape(c1);
    printAreaOfShape(c2);
    printAreaOfShape(c3);
    printAreaOfShape(s1);

    return 0;
}

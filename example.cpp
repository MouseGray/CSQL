#include <iostream>

#include "csql.h"

using namespace std;

int main()
{
    using namespace CSQL;

    const char* sql;

    {
        sql = select("dog", "cat")
            .from("animal", "pet")
            .where()
                .equals("mouse", "rat")
                .And()
                .equals("width", "height")
                .go();
    }

    cout << sql << endl;

    return 0;
}

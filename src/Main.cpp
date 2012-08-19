// A trivial file to print the current time and the square of 3.

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "MyMath.hpp"

using namespace std;
using namespace boost::posix_time;

int main(void)
{
    ptime currentTime = second_clock::local_time();

    cout << "The current time is: " << currentTime << endl;
    cout << "The square of 3 is: " << mySquare(3) << endl;

    return 0;
}

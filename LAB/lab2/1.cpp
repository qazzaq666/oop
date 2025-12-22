#include <iostream>

using namespace std;

struct Time
{
    double hours;
    double minutes;
    double seconds;
};

double timeInSeconds(const Time& t)
{
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

int main()
{
    Time t{2, 15, 29};

    cout << "Time in seconds: " << timeInSeconds(t) << endl;

    return 0;
}

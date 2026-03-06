#include <iostream>
#include <string>

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

struct Train
{
    int number;
    Time arrival;
    Time departure;
    string direction;
    double distance;
};

double averageSpeed(const Train& t)
{
    double travelSeconds = timeInSeconds(t.departure) - timeInSeconds(t.arrival);
    if (travelSeconds <= 0)
        return 0;

    return t.distance / (travelSeconds / 3600.0);
}

int main()
{
    Train trains[10] =
    {
        {1, {8,0,0}, {10,0,0}, "Moscow", 300},
        {2, {9,30,0}, {12,0,0}, "Kazan", 450},
        {3, {6,0,0}, {9,0,0}, "Sochi", 600},
        {4, {7,15,0}, {8,45,0}, "Tver", 180},
        {5, {11,0,0}, {15,0,0}, "Samara", 900},
        {6, {5,30,0}, {7,30,0}, "Ryazan", 200},
        {7, {14,0,0}, {18,0,0}, "Ufa", 1000},
        {8, {10,0,0}, {13,0,0}, "Voronezh", 400},
        {9, {16,0,0}, {20,0,0}, "Perm", 1100},
        {10, {18,30,0}, {22,30,0}, "Omsk", 1300}
    };

    for (int i = 0; i < 10; i++)
    {
        cout << "Train " << trains[i].number
             << " average speed: "
             << averageSpeed(trains[i])
             << " km/h" << endl;
    }

    return 0;
}


#include <iostream>

using namespace std;

enum Season { Winter, Spring, Summer, Autumn };

double averageTemperature(Season s)
{
    double temperatures[4][4] =
    {
        { -12, -8, -5, -10 },   // Winter
        { 5, 8, 12, 15 },       // Spring
        { 20, 25, 22, 30 },     // Summer
        { 5, 7, 10, 12 }        // Autumn
    };
    
    double sum = 0;
    for (int i = 0; i < 4; i++)
    sum += temperatures[s][i];
    
    return sum / 4;
}

int main()
{
    Season s = Summer;
    
    cout << "Average temperature: "
    << averageTemperature(s) << " C" << endl;
    
    return 0;
}

// #include <iostream>

// using namespace std;

// enum Season { Winter, Spring, Summer, Autumn };

// double averageTemperature(Season s)
// {
//     switch (s)
//     {
//         case Winter: return -10.0;
//         case Spring: return 10.0;
//         case Summer: return 28.0;
//         case Autumn: return 8.0;
//         default: return 0.0;
//     }
// }

// int main()
// {
//     Season s = Summer;

//     cout << "Average temperature: "
//          << averageTemperature(s) << " C" << endl;

//     return 0;
// }
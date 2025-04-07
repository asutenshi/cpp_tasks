#include <iostream>
#include <iomanip>

using namespace std;

void printWayTime(int time, int check)
{
    if (check == 0)
    {
        cout << setw(2) << time / 60 << ":";
        cout << setw(2) << time % 60 << "   ->   ";
    }
    else
    {
        cout << setw(2) << time / 60 << ":";
        cout << setw(2) << time % 60 << "   <-   ";
    }
}
void printRestTime(int time)
{
        cout << setw(2) << time / 60 << ":";
        cout << setw(2) << time % 60 << endl;
}

int main(void)
{
    int way_h, way_m, rest_h, rest_m;
    int curr_time, way_time, rest_time;
    const int start_time = 7 * 60;
    const int end_time = 19 * 60;

    curr_time = start_time;
    cout << "Building a bus timetable" << endl;
    cout << "Enter the travel time from A to B (hh mm): ";
    cin >> way_h >> way_m;
    if (way_h > 0 && way_m >> 0)
    {
        way_time = way_h * 60 + way_m;
    }
    else
    {
        cout << "The wrong time was entered";
        return 0;
    }

    cout << "Enter the rest time at bus stops (hh mm): ";
    cin >> rest_h >> rest_m;
    rest_time = rest_h * 60 + rest_m;

    cout << endl << "   Bus Timetable" << endl;
    cout << "Point A    Point B" << setfill('0') << endl;

    while (curr_time + 2 * way_time + rest_time < end_time)
    {
        // получился красивый вывод, но не совсем красивый код...
        printWayTime(curr_time, 0);
        curr_time += way_time;
        printRestTime(curr_time);
        curr_time += rest_time;
        printWayTime(curr_time + way_time, 1);
        printRestTime(curr_time);
        curr_time += way_time + rest_time;
    }
    return 0;
}


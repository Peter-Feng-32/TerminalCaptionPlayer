// Tiny Console App

#include <iostream>
#include <fstream>
#include <string.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <thread>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

class timer
{
    // alias our types for simplicity
    using clock = std::chrono::system_clock;
    using time_point_type = std::chrono::time_point<clock, std::chrono::milliseconds>;

public:
    // default constructor that stores the start time
    timer()
    {
        start = std::chrono::time_point_cast<std::chrono::milliseconds>(clock::now());
    }

    // gets the time elapsed from construction.
    long /*milliseconds*/ getTimePassed()
    {
        // get the new time
        auto end = clock::now();

        // return the difference of the times
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

private:
    time_point_type start;
};

int main()
{

    cout << "\033[2J";
    cout << "\033[H";
    cout << "Please pass in the number of the caption json file you want to play (1-4): ";
    int num;
    cin >> num;
    if (num != 1 && num != 2 && num != 3 && num != 4)
    {
        cout << "Num must be 1-4";
        cin >> num;
    }

    std::ifstream i("../captions/merged_captions." + to_string(num) + ".json");

    json j;
    i >> j;

    int fileSize = j.size();

    timer t;
    int index = 0;
    double elapsed = 0.0;

    int MAXCHARSPERCAPTION = 40;

    while (index < fileSize)
    {
        double currDelay = j[index]["delay"];
        int messageID = j[index]["message_id"];
        elapsed = t.getTimePassed();
        string message = "";
        int charsInMessage = 0;
        if (elapsed >= currDelay)
        {
            // Move cursor to line 5, col 1
            while (messageID == j[index]["message_id"] && charsInMessage < MAXCHARSPERCAPTION)
            {
                string fragment = j[index]["text"].dump();

                fragment = fragment.substr(1);
                fragment = fragment.substr(0, fragment.size() - 1);
                fragment.erase(remove(fragment.begin(), fragment.end(), '\\'), fragment.end());
                message = message + fragment + " ";
                charsInMessage = message.size();
                index++;
                if (fragment[fragment.size() - 1] == '.' || fragment[fragment.size() - 1] == '?')
                {
                    // End of sentence.
                    break;
                }
            }
            cout << "\033[2J";
            cout << "\033[H";
            cout << "\033[5B";
            cout << "\033[2K";

            cout << message << '\n';
            // cout << t.getTimePassed() << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int convertMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(2, 2));

    return hours * 60 + minutes;
}

int main() {

    string input_arr[] = {"0900", "0940", "0950", "1100", "1500", "1800"};
    string input_dep[] = {"2000", "2000", "2000", "2000", "2000", "2000"};

    int n = sizeof(input_arr) / sizeof(input_arr[0]);

    int arrival[n];
    int departure[n];

    for (int i = 0; i < n; i++) {
        arrival[i] = convertMinutes(input_arr[i]);
        departure[i] = convertMinutes(input_dep[i]);
        
    }
    
    

    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int platforms_needed = 1;
    int max_platforms = 1;

    int i = 1;
    int j = 0;

    while (i < n && j < n) {

        if (arrival[i] <= departure[j]) {
            platforms_needed++;
            i++;
        }
        else {
            platforms_needed--;
            j++;
        }

        max_platforms = max(max_platforms, platforms_needed);
    }

    cout << max_platforms << endl;

    return 0;
}
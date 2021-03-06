#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'carParkingRoof' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY cars
 *  2. INTEGER k
 */

long carParkingRoof(vector<long> cars, int k) {
    sort(cars.begin(), cars.end());
    int st = 0, ed = k - 1;
    long mini = cars[ed] - cars[st] + 1;
    while(ed + 1 < cars.size()){
        st ++, ed ++;
        mini = min(mini, cars[ed] - cars[st] + 1);
    }
    return mini;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cars_count_temp;
    getline(cin, cars_count_temp);

    int cars_count = stoi(ltrim(rtrim(cars_count_temp)));

    vector<long> cars(cars_count);

    for (int i = 0; i < cars_count; i++) {
        string cars_item_temp;
        getline(cin, cars_item_temp);

        long cars_item = stol(ltrim(rtrim(cars_item_temp)));

        cars[i] = cars_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long result = carParkingRoof(cars, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

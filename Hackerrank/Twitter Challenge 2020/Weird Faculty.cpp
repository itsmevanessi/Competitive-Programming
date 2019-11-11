#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'exam' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY v as parameter.
 */

int exam(vector<int> arr) {
  int res2 = 0;
  for(int i = 0; i < arr.size(); ++i){
    if(arr[i])res2++;
    else res2--;
  }
  int res1 = 0;
  for(int i = 0; i < arr.size(); ++i){
    if(res1 > res2){
        return i;
    }
    if(arr[i])res1++;
    else res1--;
    if(arr[i])res2--;
    else res2++;
  }
  return arr.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string v_count_temp;
    getline(cin, v_count_temp);

    int v_count = stoi(ltrim(rtrim(v_count_temp)));

    vector<int> v(v_count);

    for (int i = 0; i < v_count; i++) {
        string v_item_temp;
        getline(cin, v_item_temp);

        int v_item = stoi(ltrim(rtrim(v_item_temp)));

        v[i] = v_item;
    }

    int result = exam(v);

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

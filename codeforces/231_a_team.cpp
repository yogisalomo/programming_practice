// URL : https://codeforces.com/contest/231/problem/A
// Difficulty : 800
// Related Topic : Brute Force, Greedy
// Personal Note :
// - Learning proper way to receive input (have been automatically handled by Leetcode before)

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n_problems;
    int solution_problems = 0;
    int cur_confidence;

    string input;
    getline(cin, input);

    for(int i=0;i< stoi(input);i++) {
        string input;
        getline(cin, input);
        istringstream is(input);
        int num;
        int sum_confidence = 0;
        while(is >> num) {
            sum_confidence+=num;
        }

        if(sum_confidence>=2) {
            solution_problems++;
        }
    }

    cout << solution_problems << endl;
    return 0;
}

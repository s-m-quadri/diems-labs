#include <iostream>
#include <vector>
using namespace std;

float solve(vector<float> input){
    // Convert to cents
    vector<int> cents;
    for (auto& x : input) cents.push_back(x*100);
    
    // Calculate average
    long long int sum = 0;
	for (auto& element: cents) sum += element;
	int avg = sum / cents.size();
	
	// Calculate sum of positive diffrences
	int pos_diff = 0;
	int neg_diff = 0;
	for (auto& x : cents) {
	    int cur_diff = x - avg;
	    if (cur_diff > 0) pos_diff += cur_diff;
	    else neg_diff += -cur_diff;
	}
	int diff = min(pos_diff, neg_diff);

	// Convert to dollar
	float dollar_exchange = float(diff) / 100;
	return dollar_exchange;
}

int main() {
    while (true){
        // Get number of persons
        int n_persons;
        cin >> n_persons;
        if (n_persons == 0) break;
        
        // Get the costs
        vector<float> input;
        for (int i = 0 ; i < n_persons ; i++){
            float x = 0.0;
            cin >> x;
            input.push_back(x);
        }
        
        // Solve and done
    	printf("$%.2f\n", solve(input));
    }
    
	return 0;
}


/*
INPUT:
3   10.00   20.00   30.00
3   0.00    50.00   100.00
4   15.00   15.01   3.00    3.01
0

OUTPUT:
$10.00
$50.00
$12.01
*/

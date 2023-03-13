#include <iostream>
using namespace std;

int get_count(long int n){
    int count = 1;
    while (n > 1){
        // For even number: divide by 2
        // For odd number: 3 * num plus 1
        if (n % 2 == 0) n = n / 2;
        else n = 3 * n + 1;
        count++;
    }
    return count;
}

int main() {
    // Get the lower and higher limits
    int low = 0, high = 0;
    cin >> low >> high;

    // Ensure correct range
    if (low < 1 || high >= 10000000) {
        cout << "Invalid range: must be between 1 and 10M.\n";
        return 1;
    }
    
    // Calculate maximum count
    int max_count = 0;
    for (int i = low ; i <= high ; i++){
	    int cur_count = get_count(i);
	    if (cur_count > max_count) max_count = cur_count;
    }
    
    // Print max count and done!
    cout << max_count;
	return 0;
}
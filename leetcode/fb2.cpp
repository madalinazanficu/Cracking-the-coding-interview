#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector <int> compute(vector <int> v) {
  
  std::vector <int> result(v.size(), 0);
  for (int i = 1; i < v.size(); i++) {
    
    // in this case the previous element is maximum with the maxim i
    if (v[i - 1] > v[i]) {
      result[i] = i;
    } else {
      
      // caut elementul maxim pana in el
      int j = result[i - 1];
      while (j != 0 && v[j - 1] < v[i]) {
        j = result[j - 1];  
      }
      if (j == 0) {
        result[i] = 0;
      } else {
        result[i] = j;
      }
    }
  }
  return result;
}


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  vector <int> v1 = compute(arr);
  vector <int> result(arr.size(), 0);
  
  for (int i = 0; i < v1.size(); i++) {
   v1[i] = i + 1 - v1[i];
  }
  reverse(arr.begin(), arr.end());
  vector <int> v2 = compute(arr);

  for (int i = 0; i < v1.size(); i++) {
    v2[i] = i + 1 - v2[i];
    
  }
  reverse(v2.begin(), v2.end());
  for (int i = 0; i < v1.size(); i++) {
    result[i] = v1[i] + v2[i] - 1;

  }
  return result;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
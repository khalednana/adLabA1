//
//  main.cpp
//  A1
//
//  Created by Khaled  Nana  on 04/03/2024.


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> mergeV(const  vector<int>& v1, const  vector<int>& v2) {
     vector<int> result;
    result.reserve(v1.size() + v2.size());
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }
    return result;
}


int main() {
     ifstream inputFile("/Users/khalednana/Desktop/Input1.txt");
    if (!inputFile) {
        cout<<"Error"<<endl;
        return 0;
    }
     vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();
    ifstream inputFile2("/Users/khalednana/Desktop/Input2.txt");
   if (!inputFile2) {
       cout<<"Error"<<endl;
       return 0;
   }
    vector<int> numbers2;
   int num2;
   while (inputFile2 >> num2) {
       numbers2.push_back(num2);
   }
   inputFile2.close();
    
    
    
    vector<int> sorted=mergeV(numbers, numbers2);
     ofstream outputFile("/Users/khalednana/Desktop/output.txt");
        if (!outputFile) {
             cout << "Error" <<  endl;
            return 1;
        }

        for (int num : sorted) {
            outputFile << num << " ";
        }
        outputFile.close();

    return 0;
}

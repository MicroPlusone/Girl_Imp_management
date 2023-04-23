#include <iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person{
    string name;
    int gender;
    long long age;
    string address;
};
struct Excel{
    struct Person PersonArray[MAX];
    int number;
};
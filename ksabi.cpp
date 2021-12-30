#include <iostream> 
#include <string> 
#include <iomanip> 
#include <vector>

using std::cout;
using std::cin; 
using std::string;
using std::ifstream;
//using std::string; 


struct text{ 
    string punc;
    string Nopunc;
};


void selection(std::vector<text> &b, int k);
void insertion(std::vector<text> &b, int k); 
void bubble(std::vector<text> &b, int k);
void mergesort(std::vector<text> &b, int from, int to);
void quick(std::vector<text> &text, int from, int to);
void SkipPunc(std::vector<text> &text); 
std::vector<text>ReadFromFile(int b);
void printTimes(double *arr, int i, int j);

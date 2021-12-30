#include <iostream> 
#include "ksabi.h"
#include "ksabi.cpp"
#include <fstream>
#include <iomanip>
#include <vector>

int main() {

text object;
std::string text1 = {"Purity",  "purity.txt"};
std::string text2 = {"Piracy", "piracy.txt"};
std::string text3 = {"BBS","BBS.txt "};

	std::vector<text>temp;
    double duration[5][5] = {0};
    double DoubleDuration[2][2] = {0};
    int a=0;
    std::string username; 
    int j=0;
    int b;
    auto rng = std::default_random_engine{}; //To shuffle the text file after each sort
    std::string temporary;
    std::cout << "Hello there! What's your name?";
    std::cin >> username;
    std::cout << "Hey " << username << "!" <<std::endl; 

    std::cout << "Now you get to choose! Would you like to 1) Compare times between 2 sorts you choose or 2) Sort by the size of the file?" << std::endl;
    std::cout << "Please enter 1 or 2" << std::endl;
    std::cin >> b;
    switch case(b){ 
        case 1: //starts clock on 2 sorts chosen by user 
        temp = ReadFromFile(1);
        SkipPunc (temp); 
        char k;
        char s;
        std::cout << "Great! Now you get to choose any 2 sorts to run!"
        std::cout << "Choose any sorts from:"<<std::endl;
        std::cout<< "A)Quick Sort \nB)Selection Sort \nC)Merge Sort \nD)Insertion Sort \nE)Bubble Sort"<<std::endl;
        std::cout << "Please use capital letters when entering your choice :) "
        std::cin >> k >> s;
        if ((k =='A'&& s=='B') || (k == 'B' && s == 'A')){
                // A-B B-A
                for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='A'&& s=='C') || (k == 'C' && s == 'A')){
                // A-C  C-A
                for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='A'&& s=='D') || (k == 'D' && s == 'A')){ //quicksort and insertion sort A-D
                for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='A'&& s=='E') || (k == 'E' && s == 'A')){ //Quicksort and BubbleSort A-E ********************************1st phase done 
              for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  

            }
            else if ((k =='B' && s=='C') || (k == 'C' && s == 'B')){
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='B' && s=='D') || (k == 'D' && s == 'B')){
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='B' && s=='E') || (k == 'E' && s == 'B')){
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
            }
            else if ((k =='C' && s=='D') || (k == 'D' && s == 'C')){
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else if ((k =='C' && s=='E') || (k == 'E' && s == 'C')){
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
            }
            else if ((k =='E' && s=='D') || (k == 'D' && s == 'E')){
                for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
            }
            else {
                std::cout<<"Sorry those options are invalid :( "<<std::endl;
            }
            break;
            case 2: //Case 1- Runs all sorts on the file depending on the option of file size  chosen by the user
            {  int b;
            std::cout<<"Please choose a file size!"<<std::endl;
            std::cout<<" Type 1 for the file with approximately 8,000 words"<<std::endl;
            std::cout<<" Type 2 for the file with approximately 10,000 words"<<std::endl;
            std::cout<<" Type 3 for the file with approximately 25,000 words"<<std::endl;
            std::cin>>b;
            //Upon the choice of the user, this part of the code decides which text file to open and read.
            if(b==1){
                temp = ReadFromFile(b);
                SkipPunc(temp);
            }else if(b==2){
                temp = ReadFromFile(b);
                SkipPunc(temp);
            }else {
                temp = ReadFromFile(b);
                SkipPunc(temp);
            }
            switch(a){ //Nested Switch case to run all sorting algorithms on the different file sizes
                case 1:{
                    std::cout<<"Great! You have chosen the file with 8,000 words"<<std::endl;
                    std::cout<<"The file name is "<<text1<<".txt "<<std::endl;
                    std::cout<<"Let the sorts begin..."<<std::endl;
                    a=0;
                    for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                    
                }
                 j = 0; a++;
                 for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                printTimes((double *)times, a, j);
                    break;
                }
                case 2:{
                    std::cout<<"Great! You have chosen the file size with about 10,000 words!"<<std::endl;
                    std::cout<<"The file name is "<<text2<<".txt "<<std::endl;
                    std::cout<<"Let the sorts begin..."<<std::endl;
                    a = 0;
                    for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                    
                }
                 j = 0; a++;
                 for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                printTimes((double *)times, a, j);
                    break;
                }
                case 3:{
                    std::cout<<"Great! You have chosen the file size with about 25,000 words!"<<std::endl;
                    std::cout<<"The file name is "<<text3<<".txt "<<std::endl;
                    std::cout<<"Let the sorts begin..."<<std::endl;
                    a = 0;
                    for(int i = 0; i < 5 ; i++){ //quick
                    auto start = std::chrono::system_clock::now(); 
                    quick(temp, 0 ,temp.size()-1);
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                    
                }
                 j = 0; a++;
                 for(int i = 0; i < 5 ; i++){//bubble 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    bubble(temp, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now(); 
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }  
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //insertion 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    insertion(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //merge 
                    auto start = std::chrono::high_resolution_clock::now(); 
                    mergesort(temp, 0, temp.size()-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                j = 0; a++;
                for(int i = 0; i < 5 ; i++){ //selection
                    auto start = std::chrono::high_resolution_clock::now(); 
                    selection(temp, temp.size());
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;
                    DoubleDuration[a][j]=elapsed_seconds.count();
                    std::shuffle(std::begin(temp), std::end(temp), rng);
                }
                printTimes((double *)times, a, j);
                    break;
                }
            }
            break;
            }
		}
	}

#include "ksabi.cpp"
#include "main.cpp"
#include <iostream> 
#include <string> 
#include <iomanip>
#include <cmath> 
#include <vector> 


void bubblesort(std::vector<text> &b, int k){
    bool organized = true; while (organized){
        organized = false; 
        for (int i=0; i<k; i++){
            if (b[i].Nopunc > b[i+1].Nopun){
                string tempvar;
                b[i].Nopunc = tempvar;
                b[i].Nopunc = b[i+1].Nopunc;
                b[i+1].Nopunc = tempvar;
                organized = true;
            }
        }
    }
}


int min_position(std::vector<text> &b, int from, int to)
{
   int min_pos = from;
   for (int i = from + 1; i <= to; i++)
   {
      if (b[i].Nopunc < b[min_pos].Nopunc) { min_pos = i; }
   }
   return min_pos;
}
void swap(string& x, string& y)
{
   string temp = x;
   x = y;
   y = temp;
}
void selection(std::vector<text> &b, int k);
{
   int next; 
   for (next = 0; next < k - 1; next++)
   {
      int min_pos = min_position(b, next, k - 1);
      if(a[next].Nopunc > a[min_pos].Nopunc)
        {
            string n; b[next].wordsWOpunct=n;
            b[next]=a[min_pos]; b[min_pos].Nopunc=n; }
   }
}
/*void print(string a[], int size)
{
   for (int i = 0; i < size; i++)
   {
      std::cout << a[i] << " ";
   }
   std::cout << endl;
} */
//merge sort **************************************************************************************check
void merge(std::vector<text> &text, int from, int mid, int to)
{  
   string n = to - from + 1; 
   string* b = new string[n];

   string i1 = from;
   string i2 = mid + 1;
   string j = 0; // Next open position in b 
   while (i1 <= mid && i2 <= to)
   {  
      if (text[i1].NoPunc < text[i2].Nopunc)
      {  
         b[j] = text[i1].Nopunc;
         i1++;
      }
      else
      {  
         b[j] = text[i2].Nopunc;
         i2++;
      }
      j++;
   }
   while (i1 <= mid)
   {  
      b[j] = text[i1].Nopunc;
      i1++;
      j++;
   }

   while (i2 <= to)
   {  
      b[j] = text[i2].Nopunc;
      i2++;
      j++;
   }

   for (j = 0; j < n; j++)
   {
      text[from + j].Nopunc = b[j];
   }

   delete[] b;
}

void mergesort(std::vector<text> &text, int from, int to)
{  
   if (from == to) { return; }
   int mid = (from + to) / 2;
   // Sort the first and the second half
   mergesort(text, from, mid);
   mergesort(text, mid + 1, to);
   merge(text, from, mid, to);
}
//*****************************************************************************************************print check
void printTimes(double *array, int i, int j);
{  
   int a = 0
   b = 0;
    double average[5] = {0} ;
    for( a = 0; a<=i; a++){
        for( b=0; b<j; b++){
            average[a] += *((array+a*j) + b);
        }
    }
    string SortName[5] = {"Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort", "Bubble Sort"};
    char space = '';
    cout<< left <<SortName[0]<<setfill(space)<<setw(5)<<space <<SortName[1]
    <<setfill(space)<<setw(5)<<space<<SortName[2]<<setfill(space)<<setw(5)
    <<space<<SortName[3]<<setfill(space)<<setw(5)<<space<<SortName[4]<<setfill(space)
    <<setw(5)<<space<<endl;
    cout<<"\n";
    
    for( a = 0; a<=i; a++){
        for( b=0; b<j; b++){
            cout<< left <<*((array+a*j) + b)<<setfill(space)<<setw(5)<<space<<endl;
        }
        cout<< left <<"Average is: "<< average[a]<<setfill(space)<<setw(5)<<space<<endl;
        cout<<"\t";
        cout<<"\n";
    }
}
//insertion sort**************************************************************************************check
void insertion(std::vector<text> &b, int k)
{
    for (int i = 1; i < k; i++)
    {
        string next = b[i].Nopunc;
        int j = i;
        while (j > 0 && b[j - 1].Nopunc > next)
        {
            b[j].Nopunc = b[j - 1].Nopunc;
            j--;
        }
        b[j].Nopunc = next;
    }
}

//quicksort ********************************************************************************************check 
void swap(string& x, string& y)
{  int temp = x;  x = y;  y = temp;  }

int partition(vector<text> &text, int from, int to)
{
   int pivot = text[from].Nopunc;
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (text[i].Nopunc > pivot) { i++; }
      j--; while (text[j].Nopunc < pivot) { j--; }
      if (i < j) { swap(text[i].Nopunc, text[j].Nopunc); }
   }
   return j;
}

void quick(std::vector<text> &text, string from, string to){
   if (from >= to) { return; }
   int p = partition(a, from, to);
   quick(a, from, p);
   quick(a, p + 1, to);
}

void SkipPunc(std::vector<text>){ //**********************************************************************check 
   for (int i = 0, length = text.size(); i < length; i++)
    {
        if (punc(text[i]))
        {
            text.erase(i--, 1);
            length = text.size();
        }
    }

    std::cout << text;
    return 0;
}

std::vector<text>ReadFromFile(int b){
    std::vector<text>words;
    text object; 
    ifstream readfile;
	if(b==1) { 
        readfile.open("purity.txt"); }
    else if(b==2) { 
        readfile.open("piracy.txt"); }
    else { 
        readfile.open("BBS.txt"); }
        if(!readfile.is_open()){ cout<<"Whoops! There was an eror opening the file :( "<<std::endl;  }
    else
    {
        while(!readfile.eof())
        {
            std::string line;
            readfile>>line;
            object.punc = line;
            object.Nopunc = line;
            text.push_back(object);
        }
        readfile.close();
    }
    return words;
}

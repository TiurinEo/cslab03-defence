#include "histogram.h"
#include <iostream>
using namespace std;
void
find_minmax(vector<double> numbers, double& min, double& max)  {

    min = numbers[0];max=numbers[0];

    for (double x:numbers){
        if(x<min) {
            min=x;
        }
        else if (x>max){
            max=x;
        }
    }
    }
vector<size_t>
make_histogram(vector<double> numbers,size_t bin_count){
double min,max;
find_minmax(numbers,min,max);
double bin_size= (max-min)/bin_count;
    double max_count=0;

vector<size_t> bins(bin_count);
size_t number_count=numbers.size();
    for (size_t i=0;i<number_count;i++){
        bool found = false;
    for (size_t j=0;(j<bin_count) && !found;j++){
            auto low=min+j*bin_size;
            auto hi=min+(1+j)*bin_size;
        if((numbers[i]>=low)&&(numbers[i]<hi)){
            bins[j]++;
            found=true;
           }
           if (bins[j]>max_count) max_count=bins[j];
        }
        if (!found) {
        bins[bin_count - 1]++;
    }
    }
    return bins;
}
void
show_histogram_text(vector<size_t> bins){

    size_t bin_count=bins.size();
    for (size_t i=0;i<bin_count;i++){
            if (bins[i]<100)
            cout<<" ";
    if (bins[i]<10)
        cout<<" ";
    cout<<bins[i]<<"|";
        for (size_t j=0;j<bins[i];j++)
cout<<"*";
            cout<<endl;
    }
}



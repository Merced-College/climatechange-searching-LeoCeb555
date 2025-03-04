// BinarySearch.h
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <vector>
#include "StateClimate.h"

class BinarySearch {

public:

    int myBinarySearch(std::vector<StateClimate>& data, int stateNumber){
        //Sets low to index 0
        int low = 0;
        //Sets high to total length of data - 1
        int high = data.size() - 1;

        while(high >= low){
            int mid = (high + low) / 2;
            //Compares the fip number of state at index value to the user's input
            if (data[mid].getFips() < stateNumber){
                low = mid + 1;
            }
            else if (data[mid].getFips() > stateNumber){
                high = mid - 1;
            }
            else{
                //If fips number is at index, returns index value
                return mid;
            }
        }
        return -1;
    }
};

#endif

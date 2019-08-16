#include <vector>
#include <algorithm>
#include <iostream>




 template <class T, class Comparator>
 void mergeSort (std::vector<T>& myArray, int k, Comparator comp){
 		
 	mergeSortHelper(myArray, k, comp, 0, myArray.size()-1);

 };

 template <class T, class Comparator>
 void mergeSortHelper (std::vector<T>& myArray, int k, Comparator comp, int first, int last){

 	std::vector<std::pair<int,int>> indexVec; //vector of index pairs 
 
	if (first<last) {
		int numParts = (last-first+1)/k; //num of stuff to put in
		int partRemainder = (last-first+1)%k;
		int initFirst = 0;
		int initLast = first+initFirst;  //index of ending item
		for (int i = 0; i < k; i++) {
			int modParts;
			if(i<partRemainder){ // add one remainder elem if i< the remainder
				modParts=numParts+1;
			}
			else{
				modParts=numParts;
			}
			mergeSortHelper(myArray, k, comp, first+initFirst, initLast+modParts-1); //recursive call to helper;
			indexVec.push_back(std::make_pair(first+initFirst, initLast+modParts-1)); //push into indexVec
			initFirst += modParts; //increment inital first index by modified parts to keep track of index
			initLast+= modParts;  //increment inital last index by modified parts to keep track of index
			
		}
		merge(myArray, comp, indexVec); //merge indexs
	}
	
 }

 template <class T, class Comparator>
 void merge (std::vector<T>& myArray, Comparator comp, std::vector<std::pair<int,int>> index){
 	unsigned int counter=0;    // to go through all index
 	std::pair<int,int> sortIndex=index[0]; //set first sort to first pair
 	while(counter<index.size()-1){
 		std::vector<T> temp;   //temp array to modify each iteration
 		std::pair<int,int> currentIndex=index[counter+1]; 
 		//create ints to keep track of beginning and end of comparing pairs of indecies 
        int leftBegin = sortIndex.first;
        int rightBegin = currentIndex.first;
        int leftEnd = sortIndex.second;
        int rightEnd = currentIndex.second;


        while (leftBegin <= leftEnd || rightBegin <= rightEnd) { //while we dont overstep bounds
            if (leftBegin <= leftEnd && (rightBegin > rightEnd || comp(myArray[leftBegin], myArray[rightBegin]))) {
         			//if still going thru first pair and left begin smaller than right begin push back lower val
                temp.push_back(myArray[leftBegin]);
                leftBegin++; //increment to next comparison
                
            }
            else {
                temp.push_back(myArray[rightBegin]); //push back else
                rightBegin++;
               
            }
        }
        unsigned int i=0;
        int j= sortIndex.first;   //set j to already sorted first index
        while(i<temp.size() && j<= currentIndex.second){
        	myArray[j]=temp[i];  //copy temp to myArray making sure the order is correct
        	i++;
        	j++;
        }
        sortIndex.second = currentIndex.second; //increment sorted index
        counter++;
 }
}


 	

 	
 

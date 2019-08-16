#include <string>
#include <map>

struct AlphaStrComp {
  bool operator() (const std::string& lhs, const std::string& rhs)
  { // Uses string's built in operator<
    // to do lexicographic (alphabetical) comparison
    return (lhs < rhs);
  }
};

struct LengthStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs)
  { // Compares strings by size;
    // Breaks ties by lexicographic comparison
    return (   (lhs.size() < rhs.size())
            || (lhs.size() == rhs.size() && lhs < rhs));
  }
};

struct NumStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs)
  { // Compares strings by size;
    // Breaks ties by lexicographic comparison
    int aSum=0;
    int bSum=0;
    for(unsigned int i=0; i<lhs.length();i++){
    	if((int)lhs[i]<=57 && (int)lhs[i]>=48){
    		aSum+=(int)lhs[i]-48;
    	}
    	else if((int)lhs[i]<=90 && (int)lhs[i]>=65){
    		aSum+=(int)lhs[i]-65+10;
    	}
    	else if((int)lhs[i]<=122 && (int)lhs[i]>=97){
    		aSum+=(int)lhs[i]-97+10;
    	}
    }
     for(unsigned int i =0; i<rhs.length();i++){
    	if((int)rhs[i]<=57 && (int)rhs[i]>=48){
    		bSum+=(int)rhs[i]-48;
    	}
    	else if((int)rhs[i]<=90 && (int)rhs[i]>=65){
    		bSum+=(int)rhs[i]-65+10;
    	}
    	else if((int)rhs[i]<=122 && (int)rhs[i]>=97){
    		bSum+=(int)rhs[i]-97+10;
    	}
    }
    return (aSum<bSum || (aSum == bSum && lhs < rhs));
  }
};
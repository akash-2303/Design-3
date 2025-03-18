// Time Complexity: O(1) for next and hasNext operations
// Space Complexity: O(n) where n is the number of elements in the nested list
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. We will use a stack to maintain the iterators of the nested list.
// 2. We will push the begin and end iterators of the nested list into the stack.
// 3. In hasNext() function, we will iterate through the stack until it is empty.
// 4. If the begin and end iterators are equal, we will pop them from the stack.
// 5. If the current iterator is an integer, we will return true and store the integer in nextVal.
// 6. If the current iterator is a list, we will push the begin and end iterators of the list into the stack.
// 7. In next() function, we will return the nextVal and set it to -1.
// 8. If the stack is empty, we will return false.

class NestedIterator {
    private: 
        int nextVal;
        stack<vector<NestedInteger>::iterator> begins, ends;
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            begins.push(nestedList.begin());
            ends.push(nestedList.end());
        }
        
        int next() {
            int result = nextVal;
            nextVal = -1;
            return result;
        }
        
        bool hasNext() {
            while(!begins.empty()){
                if(begins.top() == ends.top()){
                    begins.pop();
                    ends.pop();
                }else{
                    auto it = begins.top();
                    begins.top()++;
    
                    if(it -> isInteger()){
                        nextVal = it -> getInteger();
                        return true;
                    }
                    vector<NestedInteger> &nestedList = it -> getList();
                    begins.push(nestedList.begin());
                    ends.push(nestedList.end());
                }
            }
            return false;
        }
    };
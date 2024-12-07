#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int halfSize = n / 2;
    
    // Create an auxiliary queue to store the first half
    queue<int> firstHalf;
    
    // Push the first half of the elements into the auxiliary queue
    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    
    // Interleave the two halves
    while (!firstHalf.empty()) {
        // First element from the first half
        q.push(firstHalf.front());
        firstHalf.pop();
        
        // Next element from the second half
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    
    // Sample input: 4 7 11 20 5 9
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    
    // Function to interleave the queue
    interleaveQueue(q);
    
    // Output the interleaved queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
public:
    vector<int> heap;
    int count;

    HeapSort() {
        // Heap[0] will store the size, similar to the Java version
        heap.push_back(0); // heap[0] is reserved for size
    }

    void downadjust(int i) {
        int j, temp, n;
        n = heap[0];
        if (2 * i <= n) {
            j = 2 * i; // left child
            if (j + 1 <= n && heap[j + 1] > heap[j])
                j = j + 1; // j points to the larger of the two children
            if (heap[i] < heap[j]) {
                temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
                downadjust(j);
            }
        }
    }

    void upadjust(int i) {
        int temp;
        while (i > 1 && heap[i] > heap[i / 2]) {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    void insert(int x) {
        heap.push_back(x);
        heap[0]++;
        upadjust(heap[0]);
    }

    void create() {
        int i, x, n;
        cout << "\nEnter No. of elements: ";
        cin >> n;
        count = n;
        heap[0] = 0; // Reset heap size
        cout << "\nEnter heap data: ";
        for (i = 0; i < n; i++) {
            cin >> x;
            insert(x);
        }
    }

    void sort() {
        int last, temp;
        while (heap[0] > 1) {
            last = heap[0];
            temp = heap[1];
            heap[1] = heap[last];
            heap[last] = temp;
            heap[0]--;
            downadjust(1);
        }
    }

    void print() {
        int n = count;
        cout << "\nSorted data: ";
        for (int i = 1; i <= n; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    HeapSort myobject;
    myobject.create();
    myobject.sort();
    myobject.print();
    return 0;
}

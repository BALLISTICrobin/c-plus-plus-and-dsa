#include <iostream>
#include <vector>

// Function to swap two elements in a vector
void swap(std::vector<int>& heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Function to restore the max heap property after deleting the root element
void maxHeapify(std::vector<int>& heap, int idx, int heapSize) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;

    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != idx) {
        swap(heap, idx, largest);
        maxHeapify(heap, largest, heapSize);
    }
}

// Function to delete the maximum element (root) from the max heap
void deleteMax(std::vector<int>& heap) {
    if (heap.empty())
        return;

    int heapSize = heap.size();
    swap(heap, 0, heapSize - 1); // Move the last element to the root
    heap.pop_back(); // Remove the last element (max element) from the heap
    maxHeapify(heap, 0, heapSize - 1); // Restore the max heap property
}

// Function to print the elements of the heap
void printHeap(const std::vector<int>& heap) {
    for (int value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> maxHeap = {36,15,16,4,1,7,9,3};

    std::cout << "Original Max Heap: ";
    printHeap(maxHeap);

    // Deleting the maximum element (root) from the max heap
    deleteMax(maxHeap);

    std::cout << "Max Heap after Deletion: ";
    printHeap(maxHeap);

    return 0;
}

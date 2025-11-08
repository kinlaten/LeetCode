// ========== WITH STL==========
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto i : freq)
        {
            pq.push({i.second, i.first});
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

// =============== USING CUSTOM MAXHEAP

template <typename T>
class MaxHeap
{
private:
    vector<T> heap;

    // indexer
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return i * 2 + 1; }
    int rightChild(int i) { return i * 2 + 2; }

    // sifter
    void siftUp(int i)
    {
        while (i > 0 && heap[i] > heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i)
    {
        int max = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[max])
        { // use default comparator >
            max = left;
        }
        if (right < heap.size() && heap[right] > heap[max])
        {
            max = right;
        }

        if (max != i)
        {
            swap(heap[i], heap[max]);
            siftDown(max);
        }
    }

public:
    void push(T value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty!");
        }

        // swap back to top
        heap[0] = heap.back();
        heap.pop_back();

        // make heap
        siftDown(0);
    }

    T top()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty!");
        }
        return heap[0];
    }

    bool empty() const
    {
        return heap.empty();
    }

    size_t size() const
    {
        return heap.size();
    }
};

class Solution
{

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        MaxHeap<pair<int, int>> pq;
        for (auto i : freq)
        {
            pq.push({i.second, i.first});
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
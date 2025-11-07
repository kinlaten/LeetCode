class Solution
{
public:
    void siftDown(vector<int> &both, int n, int i)
    {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && both[left] > both[largest])
        {
            largest = left;
        }

        if (right < n && both[right] > both[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(both[i], both[largest]);

            siftDown(both, n, largest);
        }
    }

    vector<int> makeHeap(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            siftDown(arr, n, i);
        }
        return arr;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> heap = makeHeap(nums);
        vector<int> res;
        int n = heap.size();
        stack<int> st; // to reverse the order bc we extract max first
        while (!heap.empty())
        {
            swap(heap[0], heap[n - 1]);
            st.push(heap.back());
            heap.pop_back();
            siftDown(heap, --n, 0);
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

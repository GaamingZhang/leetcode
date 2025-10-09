class Solution
{
public:
    vector<int> arrangeBookshelf(vector<int> &order, int limit)
    {
        vector<int> st;
        unordered_map<int, int> count, used, removed, visited;
        for (int i = 0; i < order.size(); ++i)
            ++count[order[i]];
        for (int i = 0; i < order.size(); ++i)
        {
            if (used[order[i]] == limit)
            {
                ++removed[order[i]];
                continue;
            }
            while (!st.empty() && st.back() > order[i] && count[st.back()] - removed[st.back()] > limit)
            {
                ++removed[st.back()];
                --used[st.back()];
                st.pop_back();
            }
            ++used[order[i]];
            st.push_back(order[i]);
        }
        vector<int> result;
        for (int i = 0; i < st.size(); ++i)
        {
            result.push_back(st[i]);
        }
        return result;
    }
};
// 901. Online Stock Span

// 2. Stack approach 

class StockSpanner {
public:
    stack<pair<int, int>> st; // pair of {price, span}

    StockSpanner() {

    }

    int next(int price) {
        int span = 1; // currently span of price is 1 which is itself

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            s.pop();
        }

        st.push({price, span});
        return span;
    }
};

//Time complexity: O(1) amortized per next call
//Space complexity: O(N)
// 901. Online Stock Span

// 1. Brute force approach

class StockSpanner {
public:
    vector<int> prices; // Vector to store historical prices

    StockSpanner() {
    }

    int next(int price) {
        prices.push_back(price); // Add the current price to the prices vector
        int span = 1; // Initialize the span to 1
        int i = prices.size() - 2; // Start iterating from the second-to-last element in prices

        while (i >= 0 && prices[i] <= price) {
            span++; // Increment the span for each smaller or equal price to the left
            i--; // Move to the left in the prices vector
        }

        return span; // Return the calculated span
    }
};

//Time complexity: O(N) 
//Space complexity: O(N)

/*-------------------------------------------------------------------*/

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
class Solution {
public:
    struct Project {
        int profit;
        int capital;
    };

    struct CompareProfit {
        bool operator()(const Project& a, const Project& b) const {
            return a.profit < b.profit; 
        }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<Project> projects(n);

        for (int i = 0; i < n; i++) {
            projects[i] = {profits[i], capital[i]};
        }

        sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
            return a.capital < b.capital;
        });

        priority_queue<Project, vector<Project>, CompareProfit> pq;

        int i = 0;
        while (k--) {
            while (i < n && projects[i].capital <= w) {
                pq.push(projects[i]);
                i++;
            }

            if (pq.empty()) break;

            w += pq.top().profit;
            pq.pop();
        }

        return w;
    }
};

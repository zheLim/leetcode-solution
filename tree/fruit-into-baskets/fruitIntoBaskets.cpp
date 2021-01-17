class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int max_amount = 0;
		auto left = 0;
		unordered_set<int> basket_type;

		for (auto right = 0; right < tree.size(); right++) {
			if (basket_type.size() < 2) {
				basket_type.insert(tree[right]);
				if (right - left + 1> max_amount) {
					max_amount = (int)(right - left + 1);
				}
			}
			else if (basket_type.find(tree[right]) == basket_type.end()) {
				bool exit_for = false;
				auto jter = right - 1;
				while (jter > 0) {
					if (tree[jter] == tree[jter-1]) {
						jter--;
					}
					else {
						break;
					}

				}
				left = jter;
		
					
				basket_type.clear();
				basket_type.insert(tree[left]);
				basket_type.insert(tree[right]);
			}
			else if (basket_type.find(tree[right]) != basket_type.end()) {
				// TODO
				if (right - left + 1 > max_amount) {
					max_amount = (int)(right - left + 1);
				}
			}
		}
		return max_amount;
	}
};
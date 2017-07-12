/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include <cstdlib>
int* twoSum(int* nums, int numsSize, int target) {
	int* sums = (int*)calloc(2, sizeof(int));
	for (int i = 0; i<numsSize; i++) {
		for (int j = i + 1; j<numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				sums[0] = i;
				sums[1] = j;
			}
		}
	}
	return sums;
}
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		typedef unordered_multimap<int, int> Myhash_t;
		Myhash_t my_hash;
		int i = 0;
		for (auto num : nums)
		{
			my_hash.insert(Myhash_t::value_type(num, i++));
		}
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			auto  equ_range = my_hash.equal_range(target - num);
			if (((target - num) != num) && (my_hash.count(target - num) == 1))
				return { my_hash.find(num)->second, my_hash.find(target - num)->second };
			if (((target - num) == num) && (my_hash.count(num) == 2)) {
				auto its = my_hash.equal_range(num);
				int a = its.first->second;
				its.first++;
				int b = its.first->second;
				return { a,b };
			}
		}
		return vector<int>();
	}
};


#include <cassert>
int main(char* argv, int argc) {
	int target = 9;
	vector<int> nums= { 2, 7, 11, 15 };
	vector<int> ret_wanted = { 0,1 };
	int* pab=twoSum(nums.data(), nums.size(), target);
	vector<int> ret=Solution::twoSum(nums, target);
	for (size_t i = 0; i < 2; i++)
	{
		assert(pab[i] == ret_wanted[i]);
		assert(ret[i] == ret_wanted[i]);
	}
	printf("ok No 1\r\n");
	return EXIT_SUCCESS;
}
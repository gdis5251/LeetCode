// 方法一： 先排序，如果中间的数字和临近它左右两边的数字相同就返回该数字
//         否则返回 0
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 1)
            return numbers[0];
        
        std::sort(numbers.begin(), numbers.end());
        
        if (numbers[numbers.size() / 2] == numbers[numbers.size() / 2 - 1] &&
           numbers[numbers.size() / 2] == numbers[numbers.size() / 2 + 1])
               return numbers[numbers.size() / 2];
        return 0;
    }
};
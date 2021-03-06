"""
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

提示：

各函数的调用总次数不超过 20000 次

注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class MinStack:
    # 要实现min函数时间复杂度也为O(1)，需要建立辅助栈
    # 辅助栈为不严格单调栈，push(x)时x小于栈顶元素时也将x压入辅助栈，pop(x)时x等于栈顶元素时弹出栈顶元素
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.mainStack = []
        self.supStack = []

    def push(self, x: int) -> None:
        self.mainStack.append(x)
        if not self.supStack or (self.supStack and x <= self.supStack[-1]):
            self.supStack.append(x)

    def pop(self) -> None:
        x = self.mainStack.pop()
        if x == self.supStack[-1]:
            self.supStack.pop()
        return x

    def top(self) -> int:
        return self.mainStack[-1]

    def min(self) -> int:
        return self.supStack[-1]

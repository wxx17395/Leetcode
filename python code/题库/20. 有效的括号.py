class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        length = len(s)
        for i in range(length):
            if s[i] in ['(', '[', '{']:
                stack.append(s[i])
            else:
                if len(stack) == 0:
                    return False
                left = stack.pop()
                if ord(left) == ord(s[i]) - 1 or ord(left) == ord(s[i]) - 2:
                    continue
                else:
                    return False
        return True if len(stack) == 0 else False

if __name__ == '__main__':
    print(Solution().isValid("()[]{}"))
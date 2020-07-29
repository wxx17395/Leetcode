# 时间复杂度不是O(1)
class LRUCache_1:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.keyl = []
        self.valuel = {}

    def get(self, key: int) -> int:
        if key in self.keyl:
            self.keyl.remove(key)
            self.keyl.append(key)
            return self.valuel[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if self.get(key) != -1:
            self.valuel[key] = value
        else:
            if len(self.keyl) == self.cap:
                delkey = self.keyl.pop(0)
                del self.valuel[delkey]
            self.keyl.append(key)
            self.valuel[key] = value

# hash表 + 双向链表
class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None
        self.pre = None

class LRUCache:
    # hashmap保存节点
    def __init__(self, capacity: int):
        self.cap = capacity
        self.hashmap = {}
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.pre = self.head

    def move_to_tail(self, key):
        node = self.hashmap[key]
        node.pre.next = node.next
        node.next.pre = node.pre
        self.tail.pre.next = node
        node.pre = self.tail.pre
        node.next = self.tail
        self.tail.pre = node

    def get(self, key: int) -> int:
        if key in self.hashmap:
            res = self.hashmap[key].value
            self.move_to_tail(key)
            return res
        else:
            return -1


    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            self.hashmap[key].value = value
            self.move_to_tail(key)
        else:
            if len(self.hashmap) == self.cap:
                self.hashmap.pop(self.head.next.key)
                self.head.next = self.head.next.next
                self.head.next.pre = self.head
            newnode = ListNode(key, value)
            self.hashmap[key] = newnode
            newnode.pre = self.tail.pre
            newnode.pre.next = newnode
            newnode.next = self.tail
            self.tail.pre = newnode

if __name__ == '__main__':
    obj = LRUCache(2)
    obj.put(2,1)
    obj.put(1,2)
    obj.put(2,3)
    obj.put(4,1)
    print(obj.get(2))
    obj.put(1,1)
    obj.put(4,1)
    print(obj.get(2))


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
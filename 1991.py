# 1991 트리 순회
import sys

input = sys.stdin.readline


# 전위 순회
def preorder(root, node, tree, preList):
    if node[ord(root) - 65] != '.':
        preList.append(root)
        if tree[ord(root) - 65][0] != '.':
            preorder(tree[ord(root)-65][0], node, tree, preList)
        if tree[ord(root) - 65][1] != '.':
            preorder(tree[ord(root)-65][1], node, tree, preList)

    return preList


# 중위 순회
def inorder(root, node, tree, inList):
    if node[ord(root) - 65] != '.':
        if tree[ord(root) - 65][0] != '.':
            inorder(tree[ord(root)-65][0], node, tree, inList)
        inList.append(root)
        if tree[ord(root) - 65][1] != '.':
            inorder(tree[ord(root)-65][1], node, tree, inList)

    return inList


# 후위 순회
def postorder(root, node, tree, postList):
    if node[ord(root) - 65] != '.':
        if tree[ord(root) - 65][0] != '.':
            postorder(tree[ord(root)-65][0], node, tree, postList)
        if tree[ord(root) - 65][1] != '.':
            postorder(tree[ord(root)-65][1], node, tree, postList)
        postList.append(root)

    return postList


n = int(input())

tree = [['.'] * 2 for _ in range(n)]
node = ['.'] * n
for i in range(n):
    now, left, right = map(str, input().split())
    node[ord(now) - 65] = now
    if left != '.':
        tree[ord(now) - 65][0] = left
    if right != '.':
        tree[ord(now) - 65][1] = right

preList = []
inList = []
postList = []
for i in preorder('A', node, tree, preList):
    print(i, end = '')
print()
for j in inorder('A', node, tree, inList):
    print(j, end = '')
print()
for k in postorder('A', node, tree, postList):
    print(k, end = '')
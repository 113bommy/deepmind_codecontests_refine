#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
input:
8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
print

output: in_order + pre_order
1 12 17 20 25 30 88
30 12 1 20 17 25 88

"""

import sys


class Node(object):
    def __init__(self, data):
        self.data = data
        self.left, self.right = None, None

    def insert(self, data):
        """
        insert data according to BST rules
        """
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        else:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)

        return None

    def pre_order(self, node):
        if node is not None:
            print('', node.data, end='')
            self.pre_order(node.left)
            self.pre_order(node.right)
        return None

    def in_order(self, node):
        if node is not None:
            self.in_order(node.left)
            print('', node.data, end='')
            self.in_order(node.right)
        return None


def action(command, content):
    if command.startswith('in'):
        tree_root.insert(data=int(content))

    if command.startswith('pr'):
        tree_root.in_order(node=tree_root)
        print('')
        tree_root.pre_order(node=tree_root)
        print('')

    return None


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    array_length = int(_input[0])
    command_list = list(map(lambda x: x.split(), _input[1:]))
    # assert len(command_list) == array_length
    # print(array_length, *command_list)

    flag, tree_root = False, None
    for each in command_list:
        command, content = each[0], each[-1]
        if (not flag) and command.startswith('in'):
            tree_root = Node(data=int(content))
            flag = True
            continue
        action(command=command, content=content)
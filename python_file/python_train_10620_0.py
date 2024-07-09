#!/usr/bin/env python3
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
            if not self.left:
                self.left = Node(data)
            else:
                self.left.insert(data)
        # insert duplicate value to right
        else:
            if not self.right:
                self.right = Node(data)
            else:
                self.right.insert(data)

        return self.data


def pre_order(node):
    if node is not None:
        print('', node.data, end='')
        pre_order(node.left)
        pre_order(node.right)
    return None


def in_order(node):
    if node is not None:
        in_order(node.left)
        print('', node.data, end='')
        in_order(node.right)
    return None


def action(command, content):
    if command.startswith('in'):
        tree_root.insert(int(content))
    # print tree walk
    else:
        in_order(tree_root)
        print('')
        pre_order(tree_root)
        print('')

    return None


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    array_length = int(_input[0])
    command_list = list(map(lambda x: x.split(), _input[1:]))
    # assert len(command_list) == array_length

    flag, tree_root = False, None
    for each in command_list:
        command, content = each[0], each[-1]
        if (not flag) and command.startswith('in'):
            tree_root = Node(data=int(content))
            flag = True
            continue
        action(command, content)
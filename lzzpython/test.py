#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
hellopython.py
A simple Python script demonstrating basic syntax.
"""


def greet(name):
    """Return a greeting message."""
    return f"Hello, {name}!"


def main():
    # 获取用户输入
    user_name = input("What's your name? ").strip()

    # 调用函数并打印结果
    message = greet(user_name)
    print(message)

    # 示例：其他基础操作
    numbers = [1, 2, 3]
    squares = [n ** 2 for n in numbers]
    print(f"Squares of {numbers}: {squares}")


if __name__ == "__main__":
    main()
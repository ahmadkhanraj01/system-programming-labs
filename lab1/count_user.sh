#!/bin/bash
echo "Users:"
who |awk '{print $1}' |sort|uniq
echo "Total Users: "
who |awk '{print $1}' |sort|uniq| wc -l


